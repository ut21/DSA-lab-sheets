#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process{
    int pid;
    int arrival_time;
    int burst_time;
} process;

typedef struct node{
    process p;
    struct node* next;
} node;

typedef struct ll{
    int count;
    node* head;
} ll;

typedef ll* linkedList;

int isLLEmpty(linkedList l){
    return (l->head==NULL);
}

node* createNode(process p){
    node* n = (node*) malloc(sizeof(node));
    n->p=p;
    n->next=NULL;
    return n;
}

void insert(process p, linkedList l){
    if(l->head==NULL){
        l->head=createNode(p);
        l->count++;
        return;
    }
    node* curr = l->head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=createNode(p);
    l->count++;
}

linkedList populatell(process p[], int l){
    linkedList list = (linkedList) malloc(sizeof(ll));
    list->count=0;
    list->head=NULL;
    for(int i=0; i<l; i++){
        insert(p[i], list);
    }
    return list;
}

void deleteNodeAtFront(linkedList l){
    node* temp = l->head;
    l->head=l->head->next;
    free(temp);
    l->count--;
    return;
}

int main(){
    FILE* f = fopen("fcfs_input.txt", "r");
    char buffer[50];
    int size = 50;
    char* token;
    token = fgets(buffer, size, f);
    int len = atoi(buffer);
    process p_array[len];
    int i=0;
    while(fgets(buffer, size, f)!=NULL){
        process p;
        token = strtok(buffer, " ");
        p.pid=atoi(token);
        token = strtok(NULL, " ");
        p.arrival_time = atoi(token);
        token = strtok(NULL, " ");
        p.burst_time = atoi(token);
        p_array[i] = p;
        i++;
    }
    fclose(f);
    linkedList l = populatell(p_array, len);
    int time=0;
    while(!isLLEmpty(l)){
        while(l->head->p.burst_time!=0){
            printf("Time is: %d\n", time);
            time++;
            l->head->p.burst_time--;
        }
        printf("process with ID %d ended at %d \n", l->head->p.pid, time);
        deleteNodeAtFront(l);
    }

    return 0;
}