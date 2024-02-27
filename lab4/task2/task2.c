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

person* readData(char* filename, int* n){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Cannot open file\n");
        return NULL;
    }

    fscanf(file, "%d", n);
    person* A = malloc((*n) * sizeof(person));

    for(int i=0; i<*n; i++){
        A[i].name = malloc(100 * sizeof(char));
        fscanf(file, "%d,%[^,],%d,%d,%d", &A[i].id, A[i].name, &A[i].age, &A[i].height, &A[i].weight);
    }

    fclose(file);
    return A;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    int n;
    person* A = readData(argv[1], &n);

    clock_t start = clock();
    insertionSort(A, n);
    clock_t end = clock();

    double time_taken = ((double)end-start)/CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    for(int i=0; i<n; i++){
        free(A[i].name);
    }
    free(A);

    return 0;
}