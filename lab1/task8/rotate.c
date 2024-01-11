#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
struct node{
    int ele;
    nodeptr next;
};

struct linkedlist{
    int count;
    nodeptr head;
};
typedef struct linkedlist* list;

void makecircular(list l){
    nodeptr temp = l->head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=l->head;
    return;
}

void rotate(list l, int k){
    makecircular(l);
    k=k%l->count;
    nodeptr temp = l->head;
    nodeptr prev = l->head;
    for(int i=0; i<k; i++){
        prev=temp;
        temp=temp->next;
    }
    l->head = temp;
    prev->next=NULL;
    return;
}