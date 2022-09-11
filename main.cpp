
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int split_qs(int i, int j, float* array);
void QuickSort(float* array, int i, int j);
void PrintArray(float* array, int size);
void InsertionSort(float* array, int size);
void SelectionSort(float* array, int size_of_array);
void MergeSort(float* array, int size);

int main(int argc, char **argv){

    //variables para medir el tiempo
    unsigned t0, t1, t2, t3;

    //crear arreglo aleatorio
    int size_of_array = 100; //tamaño del arreglo
    float array[size_of_array];
    srand(time(NULL));
   
    //llenar arreglo
    for(int i=0;i<=size_of_array;i++){
        array[i]=rand()%100; //entre que numeros quiere que varien
    }

    //imprimir arreglo
    /* PrintArray(array, size_of_array); */
    
    cout << endl << endl;

    //---------------------------------------------------------------------------------------------------

    int i = 0;
    int j = size_of_array;
    
/* WARN:(stefano): Commented functions not implemented yet*/
    clock_t start = clock();
    /* InsertionSort(array, size_of_array); */
    /* SelectionSort(array, size_of_array); */
    /* QuickSort(array, i, j); */
    MergeSort(array, size_of_array);
    cout << "Time taken: " << ((double)(clock() - start) / CLOCKS_PER_SEC);
    
    /* PrintArray(array, size_of_array); */
    
    return 0;
}

void PrintArray(float* array, int size)
{
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
}

void InsertionSort(float* array, int size)
{
    int temp;
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
    int temp=0;
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

void MergeSort(float* array, int size)
{
    float array_tmp[size];
    int q = 1;
    int p1 = 0;
    int k = size/2;
    int p2 = k+1;
    int j = size;
    for(int i = 0; i < size; i++)
    {
        array_tmp[i] = 0;
    }
    cout << sizeof(array_tmp) << endl;
    while((p1<=k)&&(p2<=j)){
        if(array[p1]<=array[p2]){
            array_tmp[q] = array[p1];
            p1++;
        }
        else{
            array_tmp[q] = array[p2];
            p2++;
        }
        q++;
    }
    while(p1<=k){
        array_tmp[q] = array[p1];
        p1++;
        q++;
    }
    while(p2<=j){
        array_tmp[q] = array[p2];
        p2++;
        q++;
    }   
    for(int i=0;i<=size;i++){
        array[i]=array_tmp[i]; //entre que numeros quiere que varien
    }
}

/* Split for QuickSort */
int split_qs(int i, int j, float* array)
{
    int p = rand() % (j - i) + i;
    int tmp;
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


