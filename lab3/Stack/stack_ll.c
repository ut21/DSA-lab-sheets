#include "linked_list (1).h"
#include "stack.h"
#include <stdlib.h>
struct Stack{
    LIST l;
};

Stack *newStack(){
    Stack* s = malloc(sizeof(Stack));
    s->l = createNewList();
    return s;
}

bool push(Stack* stack, Element element){
    NODE n = createNewNode(element);
    insertNodeIntoList(n, stack->l);
    stack->l->count++;
    return true;
}

Element* top(Stack* stack){
    if (isEmpty(stack)) {
        return NULL; 
    }
    return &(stack->l->head->data); 
}

bool pop(Stack* stack){
    if (isEmpty(stack)) {
        return false;
    }
    removeFirstNode(stack->l);
    return true;
}

bool isEmpty(Stack* stack){
    return (stack->l->count==0);
}

void freeStack(Stack *stack){
    destroyList(stack->l);
    free(stack);
}