#include <stdio.h>

#define Nmax 100 // Maksimum ukuran array

typedef struct {
    int Tab[Nmax + 1]; // Array dengan indeks 1 sampai Nmax
    int Neff;          // Banyaknya elemen efektif
} TabInt;

void InputTerurut(TabInt *T, int X) {
    int i, pass, temp;
    
    if (T->Neff < Nmax) {
        T->Neff += 1;
        T->Tab[T->Neff] = X;
        
        if (T->Neff > 1) {
            pass = T->Neff;
            temp = T->Tab[pass];
            i = pass - 1;
            
            while (i >= 1 && temp < T->Tab[i]) {
                T->Tab[i + 1] = T->Tab[i];
                i--;
            }
            
            T->Tab[i + 1] = temp;
        }
    } else {
        printf("Tabel sudah penuh\n");
    }
}

void PrintArray(TabInt T) {
    for (int i = 1; i <= T.Neff; i++) {
        printf("%d ", T.Tab[i]);
    }
    printf("\n");
}

int main() {
    TabInt T;
    T.Neff = 0; // Inisialisasi jumlah elemen
    
    InputTerurut(&T, 5);
    InputTerurut(&T, 2);
    InputTerurut(&T, 8);
    InputTerurut(&T, 1);
    InputTerurut(&T, 6);
    
    PrintArray(T);
    
    return 0;
}
