typedef struct occupants{
    char name[10];
    int age;
    char address[100];
} occupant;

typedef struct hotel{
    char name[30];
    char address[100];
    int occupied_rooms;
    occupant* arr;
} hotel;

void addAtEnd(hotel* h, occupant* o){
    (*h).arr = realloc((*h).occupied_rooms+1, sizeof(occupant));
    (*h).arr[(*h).occupied_rooms]=*o;
    (*h).occupied_rooms++;
}

void addAtStart(hotel* h, occupant* o){
    (*h).arr = realloc((*h).occupied_rooms+1, sizeof(occupant));
    (*h).occupied_rooms++;
    for(int i=(*h).occupied_rooms-1; i>0; i--){
        (*h).arr[i]=(*h).arr[i-1];
    }
    (*h).arr[0]=*o;
}

void removeOccupant(hotel* h, occupant* o){
    
}