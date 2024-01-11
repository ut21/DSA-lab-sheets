#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>
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

#endif // STRUCTS_H