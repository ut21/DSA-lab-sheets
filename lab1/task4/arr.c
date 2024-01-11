#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    printf("Enter length: ");
    int n=0;
    scanf("%d", &n);
    char** p = calloc(n, sizeof(char*));
    for(int i=0; i<n; i++){
		p[i]=malloc(10*sizeof(char));
		scanf("%s", p[i]);
    }
	int size=n;
    while(size>0){
	 printf(" 1 for adding a string at the end \n 2 for adding at the start \n 3 for deleting ele at index x \n 4 for diplaying the length \n 5 for diplaying all elements \n 6 for quitting program");
    int selection;
    scanf("%d", &selection);
	if(selection==1){
		p = realloc(p, (size+1)*sizeof(char*));
		p[size]=malloc(10*sizeof(char));
		printf("enter new string: ");
		scanf("%s", p[size]);
		size++;
	}
	else if(selection==2){
	    p = realloc(p, (size+1)*sizeof(char*));
		for(int i=size; i>0; i--){
			p[i]=p[i-1];
		}
		p[0]=malloc(10*sizeof(char));
		printf("enter a string: ");
		scanf("%s", p[0]);
		size++;
	}
	else if(selection==3){
		printf("what index do you want to delete: ");
		int x;
		scanf("%d", &x);
		if(x<0 || x>=size){
			printf("incorrect index, try again");
			continue;
		}
		free(p[x]);
		for(int i=x; i<size-1; i++){
			p[i]=p[i+1];
		}
		p = realloc(p, (size-1)*sizeof(char*));
		size--;
	}
	else if(selection==4){
		printf("%d\n", size);
	}
	else if(selection==5){
		for(int i=0; i<size; i++){
			printf("%s\n", p[i]);
		}
	}
	else if(selection==6){
		printf("fin :*");
		break;
	}
	else{
		printf("invalid selection");
	}
	}
	free(p);
    return 0;
}
