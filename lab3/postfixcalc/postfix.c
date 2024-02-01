#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

typedef struct Stack{
    int str[MAX_SIZE];
    int top;
} Stack;

Stack* newStack(){
    Stack* s = malloc(sizeof(Stack));
    s->top = -1; // Initialize top to -1
    return s;
}

int pop(Stack* s){
    if(s->top == -1) {
        printf("Stack underflow. Exiting...\n");
        exit(1);
    }
    return s->str[s->top--];
}

void push(Stack* s, int i){
    if(s->top == MAX_SIZE - 1) {
        printf("Stack overflow. Exiting...\n");
        exit(1);
    }
    s->str[++s->top] = i;
}

int isOperator(char symbol) {  
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
        return 1;  
    }  
    return 0;  
} 

int solve(char* c){
    int i=0;
    Stack* s = newStack();
    while(c[i]!='\0'){
        char symbol = c[i];
        int num = symbol - '0';
        if(!isOperator(symbol) && num >= 0 && num <= 9){
            push(s, num);
        }
        else if(isOperator(symbol)){
            int a = pop(s);
            int b = pop(s);
            int result;
            switch(symbol){
                case '+':
                    result = b+a;
                    break;
                case '-':
                    result = b-a;
                    break;
                case '*':
                    result = b*a;
                    break;
                case '/':
                    if(a == 0) {
                        printf("Division by zero. Exiting...\n");
                        exit(1);
                    }
                    result = b/a;
                    break;
            }
            push(s, result);
        }
        i++;
    }
    return pop(s);
}

int main() {  
    char expression[] = "1 2 3 4 5 + * - -";  
    int result = solve(expression);  
    printf("Result= %d\n", result);  
    return 0;  
}  