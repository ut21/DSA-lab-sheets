#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

struct timeval t1, t2;
double time_taken;

typedef struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
} person;

void insertInOrder(person v, person A[], int j){

    int last = j-1;
    int idxInsrt=0;
    while(strcmp(v.name,A[idxInsrt].name)>0 && idxInsrt<=last){
        idxInsrt++;
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
int main(){
    FILE* f = fopen("../dat1000.csv", "r");
    if(f==NULL){
        printf("no open");
        return 1;
    }

    char buffer[500];
    char* token;

    person* array = (person*) malloc(1000*sizeof(person));

    int i=0;

    while(fgets(buffer, 500, f)!= NULL){
        person p;
        token = strtok(buffer, ",");
        p.id = atoi(token);
        token = strtok(NULL, ",");
        p.name = (char*)malloc(100*sizeof(char));
        strcpy(p.name, token);
        token = strtok(NULL, ",");
        p.age = atoi(token);
        token = strtok(NULL, ",");
        p.height = atoi(token);
        token = strtok(NULL, ",");
        p.weight = atoi(token);

        array[i]=p;
        i++;
    }

    // printf("%d", i);
    gettimeofday(&t1, NULL);
    insertionSort(array, i);
    gettimeofday(&t2, NULL);

    printf("%d \n", i);

    // for(int j=0; j<i; j++){
    //     printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", array[j].id, array[j].name, array[j].age, array[j].height, array[j].weight);
    // }

    time_taken = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken = (time_taken + (t2.tv_usec - t1.tv_usec)) * 1e-6;

    free(array);
    fclose(f);

    return 0;
}