#include "set.h"

int answer_checker(char* ans){
    int count=0;
    char answer_key[] = {'a', 'a', 'c', 'c', 'b'};
    for(int i=0; i<strlen(ans); i++){
        if(ans[i]==answer_key[i]){
            count=count+4;
        }
        else if (ans[i]!='n'){
            count--;
        }
    }
    return count;
}