#include "set.h"

int main(void){
    printf("Enter 5 answers: ");
    char ans[5];
    for(int i=0; i<5; i++){
        scanf(" %c", &ans[i]);
    }
    printf("%d", answer_checker(ans));
}