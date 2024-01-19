#include <stdlib.h>
#include <stdio.h>
typedef struct node* nodeptr;

struct node{
    int ele;
    nodeptr next;
};

struct listt{
    nodeptr head;
    int count;
};

typedef struct listt* list;