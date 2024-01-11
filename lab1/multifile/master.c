#include <stdio.h>
#include "count.h"

int main(void){
    char s[100];
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    int n = count(s);
    printf("vowels = %d", n);
}