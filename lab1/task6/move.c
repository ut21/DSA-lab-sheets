#include <stdio.h>
int main(void){
    FILE* ptr1 = fopen("test1.txt", "r");
    FILE* ptr2 = fopen("test2.txt", "w");
    char str1;
    str1=fgetc(ptr1);
    while(str1 != EOF){
        fprintf(ptr2, "%c", str1);
        str1=fgetc(ptr1);
    }
    fclose(ptr1);
    fclose(ptr2);
    ptr1 = fopen("test1.txt", "w");
    fclose(ptr1);
}