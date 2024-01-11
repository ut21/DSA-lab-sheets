#include "reverse.h"

void reverse(list l){
    nodeptr t1;
    nodeptr t2;
    nodeptr nextnode;
    t1 = l->head;
    t2= l->head->next;
    l->head->next=NULL;
    while(t2!=NULL){
        nextnode = t2->next;
        t2->next=t1;
        t1=t2;
        t2=nextnode;
    }
    l->head=t1;
    return;
}