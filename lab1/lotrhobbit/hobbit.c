#include <stdio.h>
#include <ctype.h>

int main(){
    FILE* ptr = fopen("LOTR.txt", "r");
    int count = 0;
    char str1;
    char word[] = "hobbit";
    int index = 0;

    while((str1 = fgetc(ptr)) != EOF){
        str1 = tolower(str1);
        if(str1 == word[index]){
            index++;
        } else {
            index = 0;
        }
        if(index == 6){
            count++;
            index = 0;
        }
    }
    printf("%d", count);
    fclose(ptr);
    return 0;
}