#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addStringEnd(char*** p, int* size) {
    *p = realloc(*p, (*size+1)*sizeof(char*));
    (*p)[*size] = malloc(10*sizeof(char));
    printf("enter new string: ");
    scanf("%s", (*p)[*size]);
    (*size)++;
}

void addStringStart(char*** p, int* size) {
    *p = realloc(*p, (*size+1)*sizeof(char*));
    for(int i=*size; i>0; i--){
        (*p)[i] = (*p)[i-1];
    }
    (*p)[0] = malloc(10*sizeof(char));
    printf("enter a string: ");
    scanf("%s", (*p)[0]);
    (*size)++;
}

void deleteString(char*** p, int* size) {
    printf("what index do you want to delete: ");
    int x;
    scanf("%d", &x);
    if(x<0 || x>=*size){
        printf("incorrect index, try again\n");
        return;
    }
    free((*p)[x]);
    for(int i=x; i<*size-1; i++){
        (*p)[i] = (*p)[i+1];
    }
    *p = realloc(*p, (*size-1) * sizeof(char*));
    (*size)--;
}

int main(){
    printf("Enter length: ");
    int n=0;
    scanf("%d", &n);
    char** p = calloc(n, sizeof(char*));
    for(int i=0; i<n; i++){
        p[i] = malloc(10 * sizeof(char));
        scanf("%s", p[i]);
    }
    int size=n;
    while(size>0){
        printf("1 for adding a string at the end \n2 for adding at the start \n3 for deleting ele at index x \n4 for displaying the length \n5 for displaying all elements \n6 for quitting program\n");
        int selection;
        scanf("%d", &selection);
        if(selection==1){
            addStringEnd(&p, &size);
        }
        else if(selection==2){
            addStringStart(&p, &size);
        }
        else if(selection==3){
            deleteString(&p, &size);
        }
        else if(selection==4){
		printf("%d\n", size);
        }
        else if(selection==5){
            for(int i=0; i<size; i++){
                printf("%s\t", p[i]);
            }
        }
        else if(selection==6){
            printf("fin :*");
            break;
        }
        else{
            printf("invalid selection");
        }
    }
    free(p);
    return 0;
}