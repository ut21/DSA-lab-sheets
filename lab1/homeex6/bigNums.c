#include <stdlib.h>
#include <stdio.h>

typedef struct node* nodeptr;

typedef struct node{
    int ele;
    nodeptr next;
} node;

typedef struct list{
    int count;
    nodeptr head;
} list;

typedef struct list* listptr;

nodeptr createNewNode(int ele){
    nodeptr n = malloc(sizeof(node));
    n->ele=ele;
    n->next=NULL;
    return n;
}

void addAtFront(listptr l, nodeptr n){
    n->next=l->head;
    l->head=n;
    l->count++;
    return;
}

void appendZeroes(listptr l1, listptr l2){
    if(l1->count>l2->count){
        int c = l1->count-l2->count;
        while(c--){
            addAtFront(l2, createNewNode(0));
        }
    }
    else{
       int c = l2->count-l1->count;
        while(c--){
            addAtFront(l1, createNewNode(0));
        } 
    }
    return;
}

listptr add(listptr l1, listptr l2){
    listptr l = malloc(sizeof(list));
    appendZeroes(l1, l2);
    l->count=0;
    l->head=NULL;
    nodeptr temp1 = l1->head;
    nodeptr temp2 = l2->head;
    int carry_value=0;
    while(temp1!=NULL && temp2!=NULL){
        nodeptr n = malloc(sizeof(node));
        int s = (temp1->ele + temp2->ele + carry_value)%10;
        if(temp1->ele + temp2->ele + carry_value > 9){
            carry_value=1;
        }
        else{
            carry_value=0;
        }
        n->ele=s;
        addAtFront(l,n);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return l;
}

//copilot generated main function
int main(){
    listptr l1 = malloc(sizeof(list));
    listptr l2 = malloc(sizeof(list));
    l1->count = 0;
    l1->head = NULL;
    l2->count = 0;
    l2->head = NULL;

    // Create linked list for l1 with 32 elements
    for(int i = 0; i < 32; i++) {
        addAtFront(l1, createNewNode(i % 10));  // Use i % 10 to keep the values within single digits
    }

    // Create linked list for l2 with 32 elements
    for(int i = 0; i < 32; i++) {
        addAtFront(l2, createNewNode(i*2));  // Use i % 10 to keep the values within single digits
    }

    // Add the two linked lists
    listptr l = add(l1, l2);

    // Print the result
    nodeptr temp = l->head;
    while(temp != NULL) {
        printf("%d", temp->ele);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}