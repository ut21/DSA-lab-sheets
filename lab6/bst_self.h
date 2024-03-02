typedef struct node{
    struct node* parent;
    struct node* left;
    struct node* right;
    int value;
} node;

typedef node* nodeptr;

typedef struct bst{
    nodeptr root;
} bst;

typedef bst* bstptr;