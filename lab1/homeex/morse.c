#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char* english_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    FILE* f = fopen("/Users/apple/Downloads/Lab1,2/msg.txt", "r");
    char buffer[500];
    char* token;
    int size=500;
    char msg[500];
    while(fgets(buffer, size, f)){
        token = strtok(buffer, "/");
        while(token!=NULL){
           char* letter = strtok(token, " ");
           while(letter!=NULL){
                for(int i = 0; i < 26; i++){
                    if(strcmp(letter, morse_code[i]) == 0){
                        strncat(msg, &english_letters[i], 1);
                        break;
                    }
                }
                letter = strtok(NULL, " ");
           } 
           strncat(msg, " ", 1);
           token = strtok(NULL, "/");
        }
    }
    printf("%s\n", msg);

    return 0;
}