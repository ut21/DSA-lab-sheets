#include "cycle.h"
bool hasCycle(list l){
    if (l->head == NULL) {
        return false;
    }

    nodeptr fast = l->head->next;
    nodeptr slow = l->head;

    while(fast != NULL && fast->next != NULL){
        if(fast == slow){
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}