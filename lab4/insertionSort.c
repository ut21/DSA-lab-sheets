#include <stdlib.h>
#include <stdio.h>
#include "insertionSort.h"

void insertInOrder(int v, int A[], int j){

    int last = j-1;
    int idxInsrt=0;
    while(v >= A[idxInsrt] && idxInsrt<=last){
        idxInsrt++;
    }
    for(int i=j; i>idxInsrt; i--){
        A[i]=A[i-1];
    }
    A[idxInsrt]=v;
}

void insertionSort(int A[], int n){
for(int j=1; j<n; j++){
    insertInOrder(A[j], A, j);
}
}

int main(){
    int A[]={1,5,2,5,46,1,9285,23,1,41,44,731,7,5,7455,3};
    insertionSort(A, 16);
    for(int i=0; i<16; i++){
        printf("%d ",A[i]);
    }
}