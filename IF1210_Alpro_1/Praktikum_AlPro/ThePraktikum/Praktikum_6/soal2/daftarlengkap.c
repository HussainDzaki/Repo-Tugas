#include "Boolean.h"
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
            printf(", ");
        }
    }
    printf("]");
}

void sorting(statiklist *l){
    int len = listlength(*l);
    if (len > 0){
        for (int i = 1; i < len; i++){
            int key = l->ARR[i];
            int k = i - 1;
            while (k >= 0 && key < l->ARR[k]){
                l->ARR[k + 1] = l->ARR[k];
                k--;
            }
            l->ARR[k+1] = key;
            
        }
        
    }
    
}

void append(statiklist *l1, statiklist l2 ){
    int len1 = listlength(*l1);
    int len2= listlength(l2);
    if (len1 + len2 <= CAPACITY){
        for (int i = 0; i < len2; i++){
            l1->ARR[len1 + i] = l2.ARR[i];
        }
    }
}

void readlist(statiklist *l) {
    createlist(l);
    int n;
    do{
        scanf("%d", &n);
    } while (!( 0<=n && n <= CAPACITY));

    for (int i = 0; i < n; i++){
        scanf("%d", &l->ARR[i]);
    }
    
    
}
int main(){
    statiklist l1;
    statiklist l2;
    createlist(&l1);
    createlist(&l2);
    readlist(&l1);
    readlist(&l2);
    append(&l1, l2);
    sorting(&l1);
    printlist(l1);
    printf("\n");

    

}
    
    
    
    

