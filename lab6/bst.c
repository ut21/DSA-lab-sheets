#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

typedef struct bst {
    Node *root;
} BST;

BST *new_bst() 
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *new_node(int value) 
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct ll_node{
    Node val;
    struct ll_node* next;
} ll_node;

typedef ll_node* nodeptr;

typedef struct ll{
    int count;
    nodeptr head;
} list;

typedef list* listptr;

typedef struct stack{
    listptr l;
} stack;

typedef stack* stackptr;

typedef struct queue{
    listptr l;
} queue;

typedef queue* queueptr;

void addatfront(listptr l, nodeptr n){
    n->next=l->head;
    l->head=n;
    l->count++;
    return;
}

void removefromfront(listptr l){
    nodeptr temp = l->head;
    l->head=l->head->next;
    free(temp);
    l->count--;
    return;
}

void push(stackptr s, Node* n){
    nodeptr n_l = malloc(sizeof(ll_node));
    n_l->val = *n;
    n_l->next=NULL;
    addatfront(s->l, n_l);
}

void pop(stackptr s){
    removefromfront(s->l);
}

stackptr createStack(){
    stackptr s = (stackptr) malloc(sizeof(stack));
    listptr ll = (listptr) malloc(sizeof(list));
    s->l=ll;
    return s;
}

void addAtLast(listptr l, nodeptr n) {
    if (l->head == NULL) {
        l->head = n;
    } else {
        nodeptr temp = l->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
    l->count++;
}

void enqueue(queueptr q, Node* n) {
    nodeptr n_l = malloc(sizeof(ll_node));
    n_l->val = *n;
    n_l->next = NULL;
    addAtLast(q->l, n_l);
}

Node* dequeue(queueptr q) {
    if (q->l->head == NULL) {
        return NULL;
    }
    nodeptr temp = q->l->head;
    Node* node = &(temp->val);
    removefromfront(q->l);
    return node;
}

void traverse_in_order(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    traverse_in_order(node->left);
    printf("%d ", node->value);
    traverse_in_order(node->right);
}

// void inorder_itr (Node* node){
//     if (node == NULL) return;
//     stackptr s = createStack();
//     push(s, node);
//     Node* temp = node;
//     while(s->l->head!=NULL){
//         if(temp->left!=NULL){
//             push(s, temp->left);
//             temp=temp->left;
//         }
//         printf("%d \t", temp->value);
//         pop(s);
//         if(temp->right!=NULL){
//             push(s, temp->right);
//             temp=temp->right;
//         }
//     }
// }

void insert(BST *bst, int value)
{
    Node *node = new_node(value);
    if (bst->root == NULL) 
    {
        bst->root = node;
        return;
    }
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (value < current->value) 
        {
            if (current->left == NULL) 
            {
                current->left = node;
                return;
            }
            current = current->left;
        } 
        else 
        {
            if (current->right == NULL) 
            {
                current->right = node;
                return;
            }
            current = current->right;
        }
    }
}

void levelOrder(BST *bst){
    queueptr q = (queueptr)malloc(sizeof(queue));
    listptr l = (listptr)malloc(sizeof(list));
    l->count=0;
    l->head=NULL;
    q->l=l;
    enqueue(q, bst->root);
    while(q->l->head!=NULL){
        Node* temp = dequeue(q);
        printf("%d ", temp->value);
        if(temp->left != NULL) {
            enqueue(q, temp->left);
        }
        if(temp->right != NULL) {
            enqueue(q, temp->right);
        }
    }
}

int search(BST *bst, int key)
{
    Node *current = bst->root;
    while (current != NULL) 
    {
        if (key == current->value) 
        {
            return 1;
        } 
        else if (key < current->value) 
        {
            current = current->left;
        } 
        else 
        {
            current = current->right;
        }
    }
    return 0;
}

int find_min(BST *bst)
{
    Node *current = bst->root;
    while (current->left != NULL) 
    {
        current = current->left;
    }
    return current->value;
}

int find_max(BST *bst)
{
    Node *current = bst->root;
    while (current->right != NULL) 
    {
        current = current->right;
    }
    return current->value;
}

Node *predecessor(Node *node)
{
    if (node->left == NULL)
    {
        return NULL;
    }
    Node *current = node->left;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current;
}

Node *successor(Node *node)
{
    if (node->right == NULL)
    {
        return NULL;
    }
    Node *current = node->right;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void delete(BST *bst, Node *node)
{
    if (node == NULL)
        return;
    if (node->left == NULL && node->right == NULL)
    {
        // Node is a leaf
        Node* current = bst->root;
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = NULL;
                break;
            }
            if (current->right == node)
            {
                current->right = NULL;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }
    
    if (node->left == NULL)
    {
        // Node only has right child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->right;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->right;
                break;
            }
            if (current->right == node)
            {
                current->right = node->right;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    if (node->right == NULL)
    {
        // Node only has left child
        Node* current = bst->root;
        if (current == node)
        {
            bst->root = node->left;
            free(node);
            return;
        }
        while (current != NULL)
        {
            if (current->left == node)
            {
                current->left = node->left;
                break;
            }
            if (current->right == node)
            {
                current->right = node->left;
                break;
            }
            if (node->value < current->value)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        free(node);
        return;
    }

    // Node has both children
    Node *temp = successor(node);
    node->value = temp->value;
    delete(bst, temp);
    return;
}

// Driver program to test the above functions (feel free to play around with this)
int main()
{
    BST *bst = new_bst();
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 4);
    insert(bst, 5);
    insert(bst, 6);
    insert(bst, 7);
    insert(bst, 8);
    levelOrder(bst);
    printf("\n");
    traverse_in_order(bst->root);
    printf("\n");
    printf("Max = %d\n", find_max(bst));
    printf("Min = %d\n", find_min(bst));
    printf("Predecessor of root = %d\n", predecessor(bst->root)->value);
    printf("Successor of root = %d\n", successor(bst->root)->value);
    delete(bst, bst->root->left);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root->right);
    traverse_in_order(bst->root);
    printf("\n");
    delete(bst, bst->root);
    traverse_in_order(bst->root);
    printf("\n");
    return 0;
}