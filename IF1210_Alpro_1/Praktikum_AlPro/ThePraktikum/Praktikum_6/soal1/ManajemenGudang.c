#include <stdio.h>
#define CAPACITY 100
#define MARK -999

typedef struct 
{
    int ARR[CAPACITY];

} statiklist;

void createlist(statiklist *l){
    for (int i = 0; i < CAPACITY; i++){
        l->ARR[i] = MARK;
    }
}

int listlength(statiklist l){
    int cnt = 0;
    for (int i = 0; i < CAPACITY && l.ARR[i] != MARK; i++){
        cnt++;
    }
    return cnt;
    
}


void insertdi(statiklist *l, int idx, int val){
    int len = listlength(*l);
    if (len == 0 && idx == 0){
        l->ARR[0] = val;
    }
    else{
        if (0 <= idx && idx <= len && l->ARR[0])
        {
            for (int i = len; i > idx; i++){
                l->ARR[i] = l->ARR[i-1];
            }
            l->ARR[idx] = val; 
        }
        else{
            printf("Aw, gabisa ngelakuin aksi itu\n");
        }
        
    }
}

void deletedi(statiklist *l, int idx){
    int len = listlength(*l);
    if (0 <= idx && idx < len && l->ARR[0] != MARK){
        for (int i = idx; i < len; i++){
            l->ARR[i] = l->ARR[i + 1];
        }
        l->ARR[len - 1] = MARK;
    }
    else{
        printf("Aw, gabisa ngelakuin aksi itu\n");
    }
    
    
    
}


void printlist(statiklist l){
    int len = listlength(l);
    printf("[");
    for (int i = 0; i < len; i++){
        printf("%d", l.ARR[i]);
        if (i < len - 1){
            printf(",");
        }
    }
    printf("]");
}


int main(){
    int program_berjalan = 1;
    int perintah = 1;
    int berat = 0;
    int index = 0;
    statiklist listpisang;
    createlist(&listpisang);
    while (perintah != -1){   
        scanf("%d", &perintah);
        if (perintah == -1){
            program_berjalan = 0;
        }
        else if (perintah == 1){
            scanf("%d %d", &berat, &index);
            insertdi(&listpisang, index, berat); 
            printlist(listpisang);
            printf("\n");  
        }
        else if ( perintah == 0){
            scanf("%d", &index);
            deletedi(&listpisang, index);
            printlist(listpisang);
            printf("\n");
        }
        else{
            printf("Aw, gabisa ngelakuin aksi itu\n");
        }
        
    }
    return 0;
    
}