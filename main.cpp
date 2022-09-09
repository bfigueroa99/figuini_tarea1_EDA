
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

    int temp;
    int j;
    //Inserccion (lo tengo como las weas)(no funciona)
    for(int i=0;i<size_of_array;i++){
        temp = array[i];
        j = i-1;
        while((j>0)&&(array[i]<array[j])){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
    cout<<"\n\n"<<endl;

    //Seleccion

    //QuickSort

    //MergeSort

    return 0;
}

