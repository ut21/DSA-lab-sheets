#include "stack.h"

listptr createlist(){
    listptr l = (listptr) malloc(sizeof(linkedlist));
    l->head=NULL;
    l->count=0;
    return l;
}

void insert(listptr l, int i){
    nodeptr n = malloc(sizeof(node));
    n->data=i;
    n->next=l->head;
    l->head=n;
    l->count++;
}

void delete(listptr l){
    nodeptr temp = l->head;
    l->head=l->head->next;
    free(temp);
    l->count--;
}

void push(stackptr s, int i){
    insert(s->list, i);
}

void pop(stackptr s){
    delete(s->list);
}

stackptr createStack(){
    stackptr s = malloc(sizeof(stack));
    s->list = createlist();
    return s;
}

int peek(stackptr s){
    if (s->list->head==NULL){
        return NULL;
    }
    return s->list->head->data;
}