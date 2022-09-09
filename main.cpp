
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(int argc, char **argv){

    //crear arreglo aleatorio
    int size_of_array = 100000; //tamaño del arreglo
    float array[size_of_array];
    srand(time(NULL));
   
    //llenar arreglo
    for(int i=0;i<=size_of_array;i++){
        array[i]=rand()%100; //entre que numeros quiere que varien
    }

    //imprimir arreglo
    for(int i=0;i<size_of_array;i++){
        cout<<array[i]<<" ";
    }

    //---------------------------------------------------------------------------------------------
    //Inserccion
    int temp;
    int j;
    for(int i=0;i<size_of_array;i++){
        temp = array[i];
        j = i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1] = temp;
    }
    cout<<"\n\n"<<endl;
    //---------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------
    //Seleccion
    temp=0;
    int small;
    for(int i=0;i<size_of_array;i++){
        small = i;
        for(j=i;j<size_of_array;j++){
            if(array[j]<array[small]){
                small = j;
            }
        }
        temp = array[i];
        array[i] = array[small];
        array[small] = temp;
    }
    //------------------------------------------------------------------------------------------------------

    //QuickSort

    //MergeSort

    return 0;
}

