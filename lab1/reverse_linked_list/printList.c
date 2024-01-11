#include "printList.h"
void printList(list l) {
    nodeptr temp = l->head;
    while(temp != NULL) {
        printf("%d ", temp->ele);
        temp = temp->next;
    }
    printf("\n");
}