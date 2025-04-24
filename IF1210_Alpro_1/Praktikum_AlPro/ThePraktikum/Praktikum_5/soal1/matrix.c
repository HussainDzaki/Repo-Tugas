/* File : matrix.h */
/* Deskripsi : Definisi ADT Matrix untuk representasi matriks dengan elemen float */
#ifndef MATRIX_H
#define MATRIX_H
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct
{
    float data[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
} Matrix;

/* Konstruktor */
/* I.S. rows dan cols terdefinisi dan valid (1 <= rows,cols <= MAX) */
/* F.S. Terbentuk matrix M dengan ukuran rows x cols */
/* Semua elemen diinisialisasi dengan 0.0 */
void CreateMatrix(int rows, int cols, Matrix *M)
{
    for (int i = 1; i < MAX_ROWS; i++)
    {
        for (int j = 1; j < MAX_COLS; j++)
        {
            M->data[i][j] = 0.0;
        }
    }
    M->cols = cols;
    M->rows = rows;
}

/* Selector */
int GetRows(Matrix M)
{
    return M.rows;
}
/* Mengembalikan jumlah baris matrix M */

int GetCols(Matrix M)
{
    return M.cols;
}
/* Mengembalikan jumlah kolom matrix M */

float *GetElement(Matrix *M, int row, int col)
{
    if (row == 0 || col == 0)
    {
        return NULL;
    }
    else
        return &M->data[row][col];
}
/* Mengembalikan pointer ke elemen matrix M pada baris row dan kolom col */
/* Mengembalikan NULL jika row atau col tidak valid untuk matrix M */

/* Mutator */
bool SetElement(Matrix *M, int row, int col, float value)
{
    if (*GetElement(M, row, col) == value)
    {
        return true;
    }
    else
        return false;
}
/* I.S. M terdefinisi */
/* F.S. Jika row dan col valid, elemen M pada baris row dan kolom col bernilai value, mengembalikan true */
/*      Jika row atau col tidak valid, mengembalikan false */

/* Operasi Baca/Tulis */
void ReadMatrix(Matrix *M)
{
    int row, col;
    while (true)
    {
        scanf("%d %d", &row, &col);
        if (row >= 1 && col >= 1)
        {
            break;
        }
    }

    CreateMatrix(row, col, M);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%f", &M->data[i][j]);
        }
    }
}
/* I.S. M belum terdefinisi */
/* F.S. M terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input */
/*      Meminta input ukuran matrix (rows, cols) hingga valid
        Valid: 0 < rows < MAX_ROWS and 0 < cols < MAX_COLS */
/*      Meminta input elemen matrix M sebanyak rows * cols
        Format input: Setiap elemen dipisahkan oleh spasi
        Contoh input:
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
        Contoh input tidak valid:
        -1 -1
        2 3
        1.0 2.0 3.0
        4.0 5.0 6.0
*/

void PrintMatrix(Matrix M)
{
    for (int i = 0; i < M.rows; i++)
    {
        for (int j = 0; j < M.cols; j++)
        {
            printf("%.2f", *GetElement(M.data, i, j));
            if (j < M.cols - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
/* I.S. M terdefinisi */
/* F.S. Seluruh elemen M tertulis ke layar dalam format matrix */
/* Baris dipisahkan oleh newline, kolom dipisahkan oleh spasi */
/* Format output: Setiap elemen diformat "%.2f" */

/* Operator Relasional */
bool IsSquare(Matrix M)
{
    return M.cols == M.rows;
}
/* Mengembalikan true jika M adalah matrix persegi (rows = cols) */

bool IsSymmetric(Matrix M)
{
    bool hasil = true;
    if (IsSquare(M))
    {
        for (int i = 1; i < M.rows; i++)
        {
            for (int j = 1; j < M.cols; j++)
            {
                if (*GetElement(M.data, i, j) != *GetElement(M.data, j, i))
                {
                    hasil = false;
                }
            }
        }

        return hasil;
    }
    else return hasil = false;
}
/* Mengembalikan true jika M adalah matrix simetrik terhadap diagonal */
/* Matrix simetrik adalah matrix yang memiliki elemen tercermin oleh diagonal*/
/* Prekondisi: M adalah matrix persegi */

bool IsDiagonallyDominant(Matrix M){
    bool hasil = true;
    
    for (int i = 1; i < M.rows; i++)
    {   
        float sums = 0;
        float diag = 0;
        for (int j = 1; j < M.cols; j++)
        {
            
            if (i != j)
            {
               sums += fabs(*GetElement(M.data, M.cols, M.rows));
            }
            
        }
        diag = fabs(*GetElement(M.data, i,i));

        if (diag <= sums)
        {
            hasil = false;
            break;
        }
        
    }
    return hasil;
    
}
/* Mengembalikan true jika M adalah matrix diagonal dominant */
/* |a[i][i]| > sum(|a[i][j]|) untuk j != i pada setiap baris i */
/* Hint: Gunakan fabs untuk melakukan abs terhadap float */

/* Operator Aritmatika */
Matrix *MultiplyMatrix(Matrix M1, Matrix M2){
    Matrix M3;
}
/* Menghasilkan hasil perkalian matrix M1 dan M2 */
/* Mengembalikan NULL jika jumlah kolom M1 != jumlah baris M2 */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *AddMatrix(Matrix M1, Matrix M2);
/* Menghasilkan hasil penjumlahan matrix M1 dan M2 */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix *SubtractMatrix(Matrix M1, Matrix M2);
/* Menghasilkan hasil pengurangan matrix M1 dan M2 (M1 - M2) */
/* Mengembalikan NULL jika ukuran matrix M1 dan M2 berbeda */
/* Hint: Gunakan Matrix* pointer = (Matrix *)malloc(sizeof(Matrix)) untuk menghasilkan pointer ke Matrix baru */
/* Jika anda membuat driver sendiri, jangan lupa di free ya -> free(pointer) */

Matrix MultiplyScalar(Matrix M, float scalar){
    Matrix M3;
    for (int i = 1; i < M.rows; i++)
    {
        for (int j = 1; i < M.cols; j++)
        {
            M3.data[i][j] = *GetElement(M.data, i,j) * scalar; 
        }
        
    }
    M3.cols = M.cols;
    M3.rows = M.rows;
    return M3;
    
}
/* Menghasilkan hasil perkalian matrix M dengan skalar scalar */
/* Prekondisi: M terdefinisi dan skalar terdefinisi */
/* Hint: Buat matrix baru untuk menyimpan hasil */

Matrix GetTranspose(Matrix M){
        Matrix M3;
    for (int i = 1; i < M.rows; i++)
    {
        for (int j = 1; i < M.cols; j++)
        {
            M3.data[j][i] = *GetElement(M.data, i,j) ; 
        }
        
    }
    M3.cols = M.cols;
    M3.rows = M.rows;
    return M3;
}
/* Menghasilkan matrix transpose dari M */
/* Hint: Buat matrix baru untuk menyimpan hasil */

#endif