#include <stdlib.h>
#include <stdio.h>

void merge(int a[], int l, int mid, int r){
    int temp[r-l+1];
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            temp[k]=a[i];
            i++;
            k++;
        }
        else{
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=a[j];
        j++;
        k++;
    }
    for(int i=l; i<=r; i++){
        a[i]=temp[i-l];
    }
}

void mergeSort(int a[], int l, int r){
    int length = r-l+1;
    if (length<=1){
        return;
    }
    int mid = l + (r-l)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);

    merge(a, l, mid, r);
}

int main(){
    int a[]={1,4,2,4,213,6,2,6,96,47};
    mergeSort(a, 0, 9);
    for(int i=0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}