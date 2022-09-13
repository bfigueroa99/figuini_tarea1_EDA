#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int split_qs(int i, int j, float* array);
void QuickSort(float* array, int i, int j);
void PrintArray(float* array, int size);
void InsertionSort(float* array, int size);
void SelectionSort(float* array, int size_of_array);
void MergeSort(float* array, int start, int end);
void merge(float* array, int p, int q, int r);

void TimeTest(int size);

double InsertTime(float* array, int size);
double SelectTime(float* array, int size);
double QuickTime(float* array, int size);
double MergeTime(float* array, int size);

int main(int argc, char **argv){

    int size_of_array = 1000000; //tamaño del arreglo
   
    TimeTest(size_of_array);
    return 0;
}

void TimeTest(int size)
{
    double TestResults[4] = {0.0, 0.0, 0.0, 0.0};
    
    float array[size];
    srand(time(NULL));
   
    for(int j = 0; j < 3; j++)
    {
        for(int i=0;i<=size;i++){
            array[i]=rand() / (RAND_MAX + 1.0f); //entre que numeros quiere que varien
        }

        /* PrintArray(array, size); */
        TestResults[0] += InsertTime(array, size);
        TestResults[1] += SelectTime(array, size);
        TestResults[2] += QuickTime(array, size);
        TestResults[3] += MergeTime(array, size);
    }

    cout << "InsertSort: " << TestResults[0] / 3 << endl;
    cout << "SelectSort: " << TestResults[1] / 3 << endl;
    cout << "QuickSort: " << TestResults[2] / 3 << endl;
    cout << "MergeSort: " << TestResults[3] / 3 << endl;
}

double InsertTime(float* array, int size)
{
    float tmp[size];
    for(int ar = 0; ar < size; ar++)
    {
        tmp[ar] = array[ar];
    }
    
    /* PrintArray(tmp, size); */
    clock_t Insertstart = clock();
    InsertionSort(tmp, size);
    /* PrintArray(tmp, size); */

    return (((double)(clock() - Insertstart) / CLOCKS_PER_SEC) * 1000);
}

double SelectTime(float* array, int size)
{
    float tmp[size];
    for(int ar = 0; ar < size; ar++)
    {
        tmp[ar] = array[ar];
    }
    
    clock_t Selectstart = clock();
    SelectionSort(tmp, size);
    return (((double)(clock() - Selectstart) / CLOCKS_PER_SEC) * 1000);
}

double QuickTime(float* array, int size)
{
    float tmp[size];
    for(int ar = 0; ar < size; ar++)
    {
        tmp[ar] = array[ar];
    }

    /* PrintArray(tmp, size); */
    clock_t Quickstart = clock();
    QuickSort(tmp, 0, size - 1);
    /* PrintArray(tmp, size); */
    return (((double)(clock() - Quickstart) / CLOCKS_PER_SEC) * 1000);
}

double MergeTime(float* array, int size)
{
    float tmp[size];
    for(int ar = 0; ar < size; ar++)
    {
        tmp[ar] = array[ar];
    }

    clock_t Mergestart = clock();
    MergeSort(tmp, 0, size - 1);
    return (((double)(clock() - Mergestart) / CLOCKS_PER_SEC) * 1000);
}

void PrintArray(float* array, int size)
{
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout << endl << endl;
}

void InsertionSort(float* array, int size)
{
    float temp;
    int j;
    for(int i=0;i<size;i++){
        temp = array[i];
        j = i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

void SelectionSort(float* array, int size_of_array)
{
    float temp = 0.0f;
    int small;
    for(int i=0;i<size_of_array;i++){
        small = i;
        for(int j=i;j<size_of_array;j++){
            if(array[j]<array[small]){
                small = j;
            }
        }
        temp = array[i];
        array[i] = array[small];
        array[small] = temp;
    }
}

void Merge(float* array, int p, int q, int r) {
  
    int n1 = q - p + 1; //tamaño del subarray de la izquierda
    int n2 = r - q; //tamaño del subarray de la derecha

    float * Left = new float[n1];
    float * Right = new float[n2];

    //guardar valores del array en subarrays
    for (int i = 0; i < n1; i++)
        Left[i] = array[p + i]; 
    for (int j = 0; j < n2; j++)
        Right[j] = array[q + 1 + j];

    int i, j, k;
    i = 0; //indice del subarray izquierdo
    j = 0; //indice del subarray derecho
    k = p;

    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            array[k] = Left[i];
            i++;
            } 
        else {
            array[k] = Right[j];
            j++;
            }
        k++;
        }

    while (i < n1) {
        array[k] = Left[i];
        i++;
        k++;
        }

    while (j < n2) {
        array[k] = Right[j];
        j++;
        k++;
        }

    delete[] Right;
    delete[] Left;

    
    }

void MergeSort(float* array, int start, int end) {
    if (start < end) {
        int m = start + (end - start) / 2; // en donde corto

        MergeSort(array, start, m); //el array de la izquierda
        MergeSort(array, m + 1, end); //el array de la derecha

        Merge(array, start, m, end);

        }
    }

/* Split for QuickSort */
int split_qs(int i, int j, float* array)
{
    int p = rand() % (j - i) + i;
    float tmp;
    while(i < j)
    {
        while(i < p && array[i] <= array[p])
        {
            i++;
        }
        while(j > p && array[j] >= array[p])
        {
            j--;
        }
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

        if(i == p)
        {
            p = j;
        }else
        {
            if(j == p)
            {
                p = i;
            }
        }
    }

    return p;
}

/* QuickSort */
void QuickSort(float* array, int i, int j)
{
    if(i < j)
    {
        int k = split_qs(i, j, array);
        QuickSort(array, i, k);
        QuickSort(array, k + 1, j);
    }
}
