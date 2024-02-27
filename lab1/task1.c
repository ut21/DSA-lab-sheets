#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

struct timeval t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
double time_taken1;
double time_taken2;
double time_taken3;
double time_taken4;
double time_taken5;
double time_taken6;

typedef struct{
    char* ID;
    float CGPA;
} student;

typedef struct node{
    student data;
    struct node* next;
} node;

typedef node* nodeptr;

typedef struct list{
    int count;
    nodeptr head;
} list;

typedef list* listptr;

student* populatingArray(){
    student* s_arr = (student*)calloc(10, sizeof(student));
    FILE* f = fopen("data.txt", "r");
    char buffer[100];
    char* token;
    int size = 100;
    int i=10;
    while(fgets(buffer, size, f)){
        student s;
        token = strtok(buffer, ",");
        s.ID = malloc(100*sizeof(char));
        strcpy(s.ID, token);
        token = strtok(NULL, ",");
        s.CGPA = atof(token);
        s_arr = realloc(s_arr, (++i)*sizeof(student));
        s_arr[i-1]=s;
    }
    return s_arr;
}

listptr populatingList(){
    listptr l = (listptr)malloc(sizeof(list));
    l->count=0;
    l->head=NULL;
    FILE* f = fopen("data.txt", "r");
    char buffer[100];
    char* token;
    int size = 100;
    int i=0;
    while(fgets(buffer, size, f)){
        student s;
        token = strtok(buffer, ",");
        s.ID = malloc(100*sizeof(char));
        strcpy(s.ID, token);
        token = strtok(NULL, ",");
        s.CGPA = atof(token);
        nodeptr n = (nodeptr) malloc(sizeof(node));
        n->data = s;
        n->next=l->head;
        l->head=n;
        l->count++;
    }
    return l;
}

void addInArray(student** s_arr, student s, int idx, int *size){
    *s_arr = realloc(*s_arr, (*size)+1);
    (*size)++;
    for(int i=(*size)-1; i>idx; i--){
        (*s_arr)[i] = (*s_arr)[i-1];
    }
    (*s_arr)[idx] = s;
}

void addInList(listptr l, student s, int idx){
    int i=0;
    nodeptr temp = l->head;
    while(i<idx){
        if(temp==NULL){
            return;
        }
        temp = temp->next;
        i++;
    }
    nodeptr n = malloc(sizeof(node));
    n->data = s;
    n->next = temp->next;
    temp->next=n;
    l->count++;
}

void retrieveFromArray(student* s, int idx){
    printf("student ID is %s, and CGPA is %f ", s[idx].ID, s[idx].CGPA);
}

void retrieveFromList(listptr l, int idx){
    nodeptr temp = l->head;
    while(idx--){
        temp=temp->next;
    }
    printf("student ID is %s, and CGPA is %f ", temp->data.ID, temp->data.CGPA);
}

int main(){
    gettimeofday(&t1, NULL);
    student* s = populatingArray();
    gettimeofday(&t2, NULL);
    time_taken1 = (t2.tv_sec - t1.tv_sec) * 1e6;
    time_taken1 = (time_taken1 + (t2.tv_usec - t1.tv_usec)) * 1e-6;
    printf("time taken to populate dynamically allocated array: %f\n", time_taken1);


    gettimeofday(&t3, NULL);
    listptr l= populatingList();
    gettimeofday(&t4, NULL);
    time_taken2 = (t3.tv_sec - t4.tv_sec) * 1e6;
    time_taken2 = (time_taken2 + (t4.tv_usec - t3.tv_usec)) * 1e-6;
    printf("time taken to populate linked list: %f\n", time_taken2);

    int size=10000;
    student s_new[3];

    for(int i=0; i<3; i++){
        char* c = malloc(100*sizeof(char));
        float cg;
        printf("enter string and float value: ");
        scanf("%s %f", c, &cg);
        student s;
        s.CGPA=cg;
        s.ID = (char*) malloc(100*sizeof(char));
        s.ID=c;
        s_new[i]=s;
    }
    gettimeofday(&t5, NULL);
    for(int i=0; i<3; i++){
        addInArray(&s, s_new[i], i+200, &size);
    }
    gettimeofday(&t6, NULL);
    time_taken3 = (t5.tv_sec - t6.tv_sec) * 1e6;
    time_taken3 = (time_taken3 + (t6.tv_usec - t5.tv_usec)) * 1e-6;
    printf("time taken to add to array: %f\n", time_taken3);

    gettimeofday(&t7, NULL);
    for(int i=0; i<3; i++){
        addInList(l, s_new[i], i+200);
    }
    gettimeofday(&t8, NULL);
    time_taken4 = (t7.tv_sec - t8.tv_sec) * 1e6;
    time_taken4 = (time_taken4 + (t8.tv_usec - t7.tv_usec)) * 1e-6;
    printf("time taken to add to array: %f\n", time_taken4);

    int idx=0;
    while(!(idx>4000 && idx<6000)){
    printf("Enter a index to retrieve data from: ");
    scanf("%d", &idx);
    if(idx<4000 || idx>6000){
        printf("pick something closer to 5000\n");
        }   
    }

    gettimeofday(&t9, NULL);
    retrieveFromArray(s, idx);
    gettimeofday(&t10, NULL);
    time_taken5 = (t9.tv_sec - t10.tv_sec) * 1e6;
    time_taken5 = (time_taken5 + (t10.tv_usec - t9.tv_usec)) * 1e-6;
    printf("time taken to retrieve element from index %d from array: %f\n", idx, time_taken5);

    gettimeofday(&t11, NULL);
    retrieveFromList(l, idx);
    gettimeofday(&t12, NULL);
    time_taken6 = (t11.tv_sec - t12.tv_sec) * 1e6;
    time_taken6 = (time_taken6 + (t12.tv_usec - t11.tv_usec)) * 1e-6;
    printf("time taken to retrieve element from index %d from list: %f\n", idx, time_taken6);

}