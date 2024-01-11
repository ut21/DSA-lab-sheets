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

list createNewList(){
    list mylist;
    mylist = (list) malloc(sizeof(struct linkedlist));
    mylist->count=0;
    mylist->head=NULL;
    return mylist;
}

nodeptr createNewNode(int val){
    nodeptr myptr = (nodeptr) malloc(sizeof(struct node));
    myptr->ele = val;
    myptr->next = NULL;
    return myptr;
}

void insertAfter(int searchEle, nodeptr n1, list l1){
    if(l1->head==NULL){
        l1->head=n1;
        l1->count++;
        return;
    }
    nodeptr temp = l1->head;
    while(temp!=NULL){
        if(temp->ele==searchEle){
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("element not found");
        return;
    }
    n1->next=temp->next;
    temp->next=n1;
    l1->count++;
    return;
}

void printList(list l1) {
nodeptr temp = l1->head; printf("[HEAD] ->"); while(temp != NULL)
{
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

void deletAt(list l, int position){
    //assuming that a linked list with only a head and no nodes has count==0
    //will update after confirming
    nodeptr temp = l->head;
    int i=0;
    if(position>l->count || l->count==0 || position==0){
        return;
    }
    while(i!=position-1){
        temp=temp->next;
        i++;
    }
    nodeptr t = temp->next;
    temp->next=t->next;
    free(t);
    l->count--;
}

void insertFirst(nodeptr n, list l){
    n->next=l->head;
    l->head=n;
    l->count++;
    return;
}

void deleteFirst(list l){
    nodeptr temp = l->head;
    l->head=l->head->next;
    free(temp);
    l->count--;
    return;
}

int search(list l, int data){
    //assuming position of head is 0
    int position=1;
    nodeptr temp = l->head;
    while(temp!=NULL){
        if(temp->ele==data){
            return position;
        }
        position++;
        temp=temp->next;
    }
    return -1;
}