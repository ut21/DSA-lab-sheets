#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef node* nodeptr;

typedef struct linkedlist{
    nodeptr head;
    int count;
} linkedlist;

typedef linkedlist* listptr;

typedef struct stack{
    listptr list;
} stack;

typedef stack* stackptr;

stackptr createStack();
void push(stackptr s, int i);
void pop(stackptr s);
int peek(stackptr s);
