#include <stdio.h>
int main(void){
    FILE* ptr = fopen(__FILE__, "r");
    char str1;
    str1 = fgetc(ptr);
    while(str1 != EOF){
        printf("%c", str1);
        str1 = fgetc(ptr);
    }
    fclose(ptr);
}