#include "cycle.h"
void free_list(list l) {
    nodeptr current = l->head;
    nodeptr next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    free(l);
}
int main(){
    printf("creating acyclic linked list \n");
    list l = malloc(sizeof(list));
    l->head=NULL;
    l->count=0;
    for(int i=0; i<5; i++){
        nodeptr n = malloc(sizeof(nodeptr));
        n ->ele = i;
        n->next=NULL;
        if(l->head==NULL){
            l->head=n;
        }
        else{
            nodeptr curr = l->head;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = n;
        }
        l->count++;
    }
    printf("checking cycle \n");
    if(hasCycle(l)){
        printf("cycle found\n");
    }
    else{
        printf("no cycle\n");
    }
    printf("creating cyclic linked list\n");
    nodeptr curr = l->head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next=l->head->next->next;
   printf("checking cycle \n");
    if(hasCycle(l)){
        printf("cycle found\n");
    }
    else{
        printf("no cycle\n");
    }

    printf("creating circular linked list \n");

    list ll = malloc(sizeof(list));
    ll->head=NULL;
    ll->count=0;
    for(int i=0; i<5; i++){
        nodeptr n = malloc(sizeof(nodeptr));
        n ->ele = i;
        n->next=NULL;
        if(ll->head==NULL){
            ll->head=n;
        }
        else{
            nodeptr curr = ll->head;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = n;
        }
        ll->count++;
    }
    nodeptr last = ll->head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=ll->head;
        printf("checking cycle\n");
        if(hasCycle(ll)){
        printf("cycle found\n");
    }
    else{
        printf("no cycle\n");
    }
    free_list(l);
    free_list(ll);
    return 0;
}