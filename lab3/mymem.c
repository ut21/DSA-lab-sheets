#include <stdio.h>
#include <stdlib.h>

size_t heapMemoryAllocated=0;

void* myalloc(size_t size){
    void *ptr = malloc(size + sizeof(int));
    if(ptr==NULL){
        return NULL;
    }
    heapMemoryAllocated+=size;
    *((int *)ptr) = size; //store size in the first sizeof(int) memory locations. doing (int*) takes only sizeof(int) memory locations into account
    return ptr + sizeof(int); //return ptr after offsetting for sizeof(int)
}

void myfree(void* ptr){
    int size = *((int*)(ptr-sizeof(int)));
    heapMemoryAllocated-=size;
    free(ptr-sizeof(int));
}

int main(){
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    int *ptr = myalloc(sizeof(int));
    *ptr = 10;
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    myfree(ptr);
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    float *ptr2 = myalloc(sizeof(float));
    *ptr2 = 10.0;
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    char *ptr3 = myalloc(sizeof(char));
    *ptr3 = 'e';
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    myfree(ptr3);
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    double *arr;
    arr = myalloc(sizeof(double) * 40);
    printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
        for (int i = 0; i < 40; i++)
        {
            arr[i] = i * 3.14;
        }
        myfree(arr);
        printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
        myfree(ptr2);
        printf("Heap memory allocated: %zu\n", heapMemoryAllocated);
    return 0;
    }