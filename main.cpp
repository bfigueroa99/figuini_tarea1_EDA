
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int split_qs(int i, int j, float* array);
void QuickSort(float* array, int i, int j);
void PrintArray(float* array, int size);

int main(int argc, char **argv){

    //variables para medir el tiempo
    unsigned t0, t1, t2, t3;

    //crear arreglo aleatorio
    int size_of_array = 1000000; //tamaño del arreglo
    float array[size_of_array];
    srand(time(NULL));
   
    //llenar arreglo
    for(int i=0;i<=size_of_array;i++){
        array[i]=rand()%100; //entre que numeros quiere que varien
    }

    //imprimir arreglo
    PrintArray(array, size_of_array);
    
    cout << endl << endl;

/* TODO:(stefano): Make it into a function*/
    //---------------------------------------------------------------------------------------------
    //Inserccion
    //t0=clock() //parte el tiempo
    /* int temp; */
    /* int j; */
    /* for(int i=0;i<size_of_array;i++){ */
    /*     temp = array[i]; */
    /*     j = i-1; */
    /*     while(j>=0 && array[j]>temp){ */
    /*         array[j+1]=array[j]; */
    /*         j--; */
    /*     } */
    /*     array[j+1] = temp; */
    /* } */
    /* cout<<"\n\n"<<endl; */
    //t1 = clock(); //termina el tiempo
    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Inserccion Time: " << time << endl;
    //---------------------------------------------------------------------------------------------------

/* TODO:(stefano): Make it into a function*/
    //------------------------------------------------------------------------------------------------------
    //Seleccion
    //t2=clock() //parte el tiempo
    /* temp=0; */
    /* int small; */
    /* for(int i=0;i<size_of_array;i++){ */
    /*     small = i; */
    /*     for(j=i;j<size_of_array;j++){ */
    /*         if(array[j]<array[small]){ */
    /*             small = j; */
    /*         } */
    /*     } */
    /*     temp = array[i]; */
    /*     array[i] = array[small]; */
    /*     array[small] = temp; */
    /* } */
    //t3 = clock(); //termina el tiempo
    //double time = (double(t3-t2)/CLOCKS_PER_SEC);
    //cout << "Saleccion Time: " << time << endl;
    //------------------------------------------------------------------------------------------------------

    int i = 0;
    int j = size_of_array;
    
/* WARN:(stefano): Commented functions not implemented yet*/
    /* InsertionSort(); */
    /* SelectionSort(); */
    QuickSort(array, i, j);
    /* MergeSort(); */

    PrintArray(array, size_of_array);
    //MergeSort

    return 0;
}

void PrintArray(float* array, int size)
{
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
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


