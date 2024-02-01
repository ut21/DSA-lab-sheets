#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100
typedef struct Stack{
    int str[MAX_SIZE];
    int top;
} Stack;

Stack* newStack(){
    Stack* s = malloc(sizeof(Stack));
    return s;
}

int top(Stack* s){
    return s->str[s->top];
}

void push(Stack* s, int i){
    s->top++;
    s->str[s->top]=i;
}