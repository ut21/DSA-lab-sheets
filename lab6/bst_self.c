#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "bst_self.h"

nodeptr creat_node(int val){
    nodeptr n = (nodeptr)malloc(sizeof(node));
    n->parent = NULL;
    n->left=NULL;
    n->right=NULL;
    n->value=val;
    return n;
}

bstptr create_bst(){
    bstptr b = (bstptr)malloc(sizeof(bst));
    b->root=NULL;
    return b;
}

void traverse_in_order(nodeptr n){
    if(n==NULL){
        printf(" NULL ");
        return;
    }
    traverse_in_order(n->left);
    printf("%d ", n->left->value);
    traverse_in_order(n->right);
}

void traverse_pre_order(nodeptr n){
    if(n==NULL){
        printf(" NULL ");
        return;
    }
    printf("%d ", n->left->value);
    traverse_pre_order(n->left);
    traverse_pre_order(n->right);
}

void traverse_post_order(nodeptr n){
    if(n==NULL){
        printf(" NULL ");
        return;
    }
    traverse_pre_order(n->left);
    traverse_pre_order(n->right);
    printf("%d ", n->left->value);
}

void traverse_level_order(nodeptr n){
    queueptr q = (queueptr)malloc(sizeof(queue));
    enqueue(q, n);
    while(q->l->head!=NULL){
        nodeptr temp = dequeue(q);
        printf("% d ", temp->value);
        if(temp->left!=NULL){
            enqueue(q, temp->left);
        }
        if(temp->right!=NULL){
            enqueue(q, temp->right);
        }
    }
}

void insert(bstptr b, nodeptr n){
    if(b->root==NULL){
        b->root=n;
        return;
    }
    nodeptr temp = b->root;
    while(temp!=NULL){
        if(n->value < temp->value){
            if(temp->left==NULL){
                temp->left=n;
                n->parent = temp;
                return;
            }
            else{
                temp=temp->left;
            }
        }
        else{
            if(temp->right==NULL){
                temp->right=n;
                n->parent=temp;
                return;
            }
            else{
                temp=temp->right;
            }
        }
    }
}

int find_max(nodeptr n){
    nodeptr temp = n;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->value;
}

int find_min(nodeptr n){
    nodeptr temp = n;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->value;
}

int check_bst(nodeptr n){
    if(n == NULL) {
        return 1;
    }
    if(!(n->value > find_max(n->left) && n->value <= find_min(n->right))){
        return 0;
    }
    else{
        return check_bst(n->left) && check_bst(n->right);
    }
}

int height_bst(nodeptr n){
    if(n->left==NULL && n->right==NULL){
        return 1;
    }
    if(n->left==NULL){
        return(height_bst(n->right)+1);
    }
    if(n->right==NULL){
        return(height_bst(n->left)+1);
    }
    else{
        return((height_bst(n->left)>height_bst(n->right))?height_bst(n->left)+1 : height_bst(n->right)+1);
    }
}

void flatten(nodeptr n){
    if(n==NULL || n->left==NULL && n->right==NULL){
        return;
    }
    flatten(n->left);
    nodeptr r = n->right;
    n->right = n->left;
    n->left=NULL;
    nodeptr t = n->right;
    while (t->right!=NULL){
        t=t->right;
    }
    t->right=r;
    flatten(t->right);
}

nodeptr k_smallest(nodeptr n, int* k){
    if(n==NULL){
        return NULL;
    }
    nodeptr l = k_smallest(n->left, k);
    if(l!=NULL){
        
    }
}