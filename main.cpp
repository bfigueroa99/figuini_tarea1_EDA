
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;


int main(int argc, char **argv){

    //crear arreglo aleatorio
    int size_of_array = 10;
    int array[size_of_array];
    srand(time(NULL));
   
    //llenar arreglo
    for(int i=0;i<=size_of_array;i++){
        array[i]=rand()%100;
    }

    //imprimir arreglo
    for(int i=0;i<size_of_array;i++){
        cout<<array[i]<<" ";
    }

    //imprimir arreglo



    //Inserccion

    //Seleccion

    //QuickSort

    //MergeSort

    return 0;
}

