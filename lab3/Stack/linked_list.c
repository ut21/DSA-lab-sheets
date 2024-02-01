#include "linked_list (1).h"
#include <stdlib.h>

LIST createNewList(){
    LIST l = malloc(sizeof(linked_list));
    l->count=0;
    l->head=NULL;
    return l;
}

NODE createNewNode(Element data){
    NODE n = malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    return n;
}

void insertNodeIntoList(NODE n, LIST l){
    n->next=l->head;
    l->head=n;
    l->count++;
    return;
}

void removeFirstNode(LIST l){
    NODE temp = l->head;
    l->head=l->head->next;
    free(temp);
    l->count--;
}

void destroyList(LIST l){
    NODE curr = l->head;
    while(curr != NULL){
        NODE temp = curr;
        curr = curr->next;
        free(temp);
    }
}