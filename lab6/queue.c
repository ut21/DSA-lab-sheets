#include "queue.h"

llptr create_ll(){
    llptr ll = (llptr)malloc(sizeof(ll));
    ll->count=0;
    ll->head=NULL;
    return ll;
}

ll_nodeptr create_ll_node(nodeptr val){
    ll_nodeptr n = (ll_nodeptr)malloc(sizeof(ll_node));
    n->next=NULL;
    n->val=val;
    return n;
}

queueptr create_queue(){
    queueptr q = (queueptr)malloc(sizeof(queue));
    q->l=create_ll();
    return q;
}

void add_at_last(llptr l, nodeptr val){
    if(l->head==NULL){
        l->head=create_ll_node(val);
        l->count++;
        return;
    }
    ll_nodeptr temp = l->head;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = create_ll_node(val);
    l->count++;
    return;
}

ll_nodeptr remove_from_front(llptr l){
    ll_nodeptr temp = l->head;
    l->head=l->head->next;
    l->count--;
    return temp;
}

void enqueue(queueptr q, nodeptr val){
    add_at_last(q->l, val);
}

nodeptr dequeue(queueptr q){
    ll_nodeptr l = remove_from_front(q->l);
    return l->val;
}