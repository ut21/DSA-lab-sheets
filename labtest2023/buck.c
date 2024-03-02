#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct wordsLLNode{
    struct wordsLLNode* next;
    char word[100];
} wordsLLNode;

typedef wordsLLNode* wordsLLNodePtr;

typedef struct wordsLLHeader{
    int count;
    wordsLLNodePtr head;
} wordsLLHeader;

typedef wordsLLHeader* wordsLLHeaderPtr;

typedef struct record{
    wordsLLHeaderPtr l;
} record;

void insert_at_start(wordsLLHeaderPtr l, wordsLLNodePtr w){
    if(l->head==NULL){
        l->head=w;
        l->count++;
        return;
    }
    wordsLLNodePtr temp = l->head;
    l->head=w;
    w->next=temp;
    l->count++;
    return;
}

wordsLLHeaderPtr create_list(){
    wordsLLHeaderPtr l = (wordsLLHeaderPtr) malloc(sizeof(wordsLLHeader));
    l->count=0;
    l->head=NULL;
    return l;
}

record create_record(){
    record r;
    r.l=create_list();
    return r;
}

wordsLLNodePtr create_node(char* c){
    wordsLLNodePtr n = (wordsLLNodePtr) malloc(sizeof(wordsLLNode));
    n->next=NULL;
    strcpy(n->word, c);
    return n;
}

record* readData(char* filename){
    record* arr = (record*) malloc(26*sizeof(record));
    for(int i=0; i<26; i++){
        arr[i]=create_record();
    }
    FILE* f = fopen(filename, "r");
    char buffer[100];
    int size=100;
    while(fgets(buffer, size, f)!=NULL){
        insert_at_start(arr[buffer[0]-'a'].l, create_node(buffer));
        // printf("%s ", arr[buffer[0]-'a'].l->head->word);
    }
    return arr;
}

int findMaxGap(record* arr){
    int gap=0;
    int localCount=0;
    for(int i=0; i<26; i++){
        if(arr[i].l->head!=NULL){
            localCount++;
            gap=(gap>localCount)?gap:localCount;
        }
        else{
            localCount=0;
        }
    }
    return gap;
}

void printList(wordsLLHeaderPtr l){
    if(l->head==NULL){
        return;
    }
    else{
        wordsLLNodePtr temp = l->head;
        while(temp->next!=NULL){
            printf("%s", temp->word);
            temp=temp->next;
        }
        printf("\n");
        printf("%s", temp->word);
    }
}

void partitionLists(record* arr){
    for(int i=0; i<26; i++){
        wordsLLHeaderPtr l1 = create_list();
        wordsLLHeaderPtr l2 = create_list();
        wordsLLNodePtr curr = (arr[i].l)->head;
        if(curr==NULL){
            continue;
        }
        while(curr!=NULL){
        wordsLLNodePtr newNode = create_node(curr->word);
        if(13-(curr->word[2])>=0){
            insert_at_start(l1, newNode);
        }
        else{
            insert_at_start(l2, newNode);
        }
        curr=curr->next;
    }
        printList(l1);
        printList(l2);
    }
}

void printData(record* arr){
    for(int i=0; i<26; i++){
        printList(arr[i].l);
    }
}

int main(int noOfArgs, char* args[]){
    record* r = readData("file1.txt");
    printf("Maximum gap is: %d\n", findMaxGap(r));
    printf("Printing wordBuckets array after partitioning:\n");
    partitionLists(r);
    // printData(r);
}