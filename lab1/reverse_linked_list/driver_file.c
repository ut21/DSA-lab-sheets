#include "reverse.h"
#include "printList.h"

int main(){
    list myList = malloc(sizeof(list));
    myList->head = NULL;
    myList->count = 0;


    for(int i = 0; i < 5; i++) {
        nodeptr newNode = malloc(sizeof(struct node));
        newNode->ele = i;
        newNode->next = myList->head;
        myList->head = newNode;
        myList->count++;
    }

    printf("Before reversing: ");
    printList(myList);

    reverse(myList);

    printf("After reversing: ");
    printList(myList);

    nodeptr temp;
    while(myList->head != NULL) {
        temp = myList->head;
        myList->head = myList->head->next;
        free(temp);
    }
    free(myList);

    return 0;
}