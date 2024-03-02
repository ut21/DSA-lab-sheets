#include <stdio.h>
#include <stdlib.h>

// int main(){
//     FILE* f = fopen("n_integers.txt", "r");
//     FILE* ftwo = fopen("copy.txt", "w");
//     int len;
//     char buffer[500];
//     while(fgets(buffer, 500, f)){
//         fscanf(f, "%d,[", &len);
//         int arr[len];
//         for(int i=0; i<len; i++){
//             fscanf(f, "%d ", &arr[i]);
//         }
//         for(int i=0; i<len; i++){
//             fprintf(ftwo, "%d ", arr[i]);
//         }
//         fscanf(f, "]\n");
//         fprintf(ftwo, "\n");
//     }
// }

int main(){
    FILE* f = fopen("test.txt", "r");
    char c[10];
    while(fscanf(f, c)!=EOF){
        char c1[10];
        fscanf(f, "%s", c1);
        printf("%s\n", c1);
    }
}