#include <stdlib.h>
#include <stdio.h>

typedef struct person{
    int id;
    char* name;
    int age;
    int height;
    int weight;
} person;

void insertInOrder(person v, person A[], int j){

    int last = j-1;
    int idxInsrt=0;
    while(idxInsrt<=last){
        if(A[idxInsrt].height<=v.height){
            idxInsrt++;
        }
        else{
            break;
        }
    }
    for(int i=j; i>idxInsrt; i--){
        A[i]=A[i-1];
    }
    A[idxInsrt]=v;
}

void insertionSort(person A[], int n){
for(int j=1; j<n; j++){
    insertInOrder(A[j], A, j);
}
}
