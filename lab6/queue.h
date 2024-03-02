#include <stdio.h>
#include <stdlib.h>
#include "bst_self.h"

typedef struct ll_node{
    struct ll_node* next;
    nodeptr val;
} ll_node;

typedef ll_node* ll_nodeptr;

typedef struct ll{
    ll_nodeptr head;
    int count;
} ll;

typedef ll* llptr;

typedef struct queue{
    llptr l;
} queue;

typedef queue* queueptr;

llptr create_ll();
ll_nodeptr create_ll_node(nodeptr val);
queueptr create_queue();
void add_at_last(llptr l, nodeptr val);
ll_nodeptr remove_from_front(llptr l);
void enqueue(queueptr q, nodeptr val);
nodeptr dequeue(queueptr q);