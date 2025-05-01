/**
 * File: polynomial.h
 * Deskripsi: Definisi ADT Polynomial untuk representasi polynomial dengan elemen integer
 */

#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_DEGREE 100

/**
 * Definisi dari ADT Polynomial
 * Sebuah Polynomial direpresentasikan oleh sebuah array of coefficients
 * dimana sebuah index menunjukkan eksponennya
 * Contoh: 3^2 + 2x + 1 direpresentasikan sebagai coeff[0] = 1, coeff[1] = 2, coeff[2] = 3
 */

typedef struct
{
    int coeff[MAX_DEGREE + 1]; // Array untuk menyimpan koefisien polynomial
    int degree;                // Derajat tertinggi sebuah polynomial
} Polynomial;

/* ==================== Polynomial Operations ==================== */

/* Konstruktor */
void CreatePolynomial(Polynomial *p)
{
    for (int i = 0; i <= MAX_DEGREE; i++)
    {
        p->coeff[i] = 0;
    }
    p->degree = 0;
}
/**
 * I.S. -
 * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi dengan 0.0
 * dan degree juga diinisialisasi dengan 0
 */

void CreatePolynomialFromArray(Polynomial *p, int coeffArray[], int size)
{
    p->degree = size - 1;

    for (int i = 0; i < size; i++)
    {
        p->coeff[i] = coeffArray[i];
    }
    while (p->coeff[p->degree] == 0 && p->degree > 0)
    {
        p->degree--;
    }
}
/**
 * I.S. CoeffArray adalah array of coefficients yang terdefinisi,
 * size adalah ukuran dari coeffArray yang terdefinisi
 * F.S. Terbentuk polynomial p dengan semua koefisien diinisialisasi berdasarkan coeffArray
 * dan degree diinisialisasikan dengan index tertinggi dari elemen coeffArray yang tidak nol
 */

/* Selektor */
int GetCoefficient(Polynomial *p, int exponent)
{
    return p->coeff[exponent];
}
/**
 * Mengembalikan nilai koefisien pada suku dengan eksponen = exponent
 */

int GetDegree(Polynomial *p)
{
    return p->degree;
}
/**
 * Mengembalikan derajat tertinggi dari polynomial dengan koefisien tak nol
 */

int Evaluate(Polynomial *p, int x)
{
    int sums = 0;
    for (int i = 0; i <= p->degree; i++)
    {
        sums += GetCoefficient(p, i) * pow(x, i);
    }
    return sums;
}
/**
 * Mengembalikan hasil evaluasi polynomial p dengan masukan x
 * Contoh:
 * p = 3x^2 + 3x + 1
 * Evaluate(p, 1) = 3(1^2) + 3(1) + 1 = 7
 */

/* Mutator */
void SetCoefficient(Polynomial *p, int exponent, int coefficient)
{
    p->coeff[exponent] = coefficient;
    if (p->degree < exponent)
    {
        p->degree = exponent;
    }
    while (p->coeff[p->degree] == 0 && p->degree > 0)
    {
        p->degree--;
    }
}
/**
 * I.S. Polynomial p, exponent, dan coefficient terdefinisi
 * F.S. Polynomial p diupdate dengan koefisien baru (coefficient)
 * pada suku dengan eksponen yang diberikan (exponent)
 */

/* Operasi Baca/Tulis */
void ReadPolynomial(Polynomial *p)
{
    int deg;
    scanf("%d", &deg);
    CreatePolynomial(p);
    p->degree = deg - 1;

    for (int i = 0; i < deg; i++)
    {
        scanf("%d", &p->coeff[i]);
    }
    while (p->coeff[p->degree] == 0 && p->degree > 0)
    {
        p->degree--;
    }
}
/**
 * I.S. Polynomial p belum terdefinisi
 * F.S. Polynomial p terdefinisi dan diisi dengan nilai-nilai yang dibaca dari input
 * - Meminta input size yang merupakan banyak koefisien yang akan dimasukkan (dari koefisien 0)
 * - Meminta input koefisien sebanyak size dan menginisialisasi p berdasarkan nilai ini (dari koefisien 0)
 */

/* Operator Aritmatika */
void AddPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result)
{
    CreatePolynomial(result);
    if (GetDegree(p1) > GetDegree(p2))
    {
        result->degree = GetDegree(p1);
    }
    else
        result->degree = GetDegree(p2);
    for (int i = 0; i < MAX_DEGREE; i++)
    {
        result->coeff[i] = p1->coeff[i] + p2->coeff[i];
    }
    while (result->coeff[result->degree] == 0 && result->degree > 0)
    {
        result->degree--;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Hasil penjumlahan p1 dan p2 (p1 + p2) disimpan di polynomial result
 */

void SubtractPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result)
{
    CreatePolynomial(result);
    for (int i = 0; i < MAX_DEGREE; i++)
    {
        result->coeff[i] = p1->coeff[i] - p2->coeff[i];
    }
    if (GetDegree(p1) > GetDegree(p2))
    {
        result->degree = GetDegree(p1);
    }
    else
        result->degree = GetDegree(p2);
    while (result->coeff[result->degree] == 0 && result->degree > 0)
    {
        result->degree--;
    }
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Hasil pengurangan p1 dan p2 (p1 - p2) disimpan di polynomial result
 */

int IsEqual(Polynomial *p1, Polynomial *p2)
{
    int hasil = 1;
    int i = 0;
    if (GetDegree(p1) == GetDegree(p2))
    {
        while (i <= GetDegree(p1) && hasil)
        {
            if (GetCoefficient(p1, i) != GetCoefficient(p2, i))
            {
                hasil = 0;
                break;
            }
            i++;
        }
    }
    else
        hasil = 0;

    return hasil;
}
/**
 * I.S. Polynomial p1 dan p2 terdefinisi
 * F.S. Mengembalikan 1 jika kedua polynomial adalah sama, dan 0 jika sebaliknya
 * Dua polynomial dianggap sama jika keduanya memiliki derajat yang sama dan semua koefisiennya bernilai sama
 */

/* Operasi Lain */
void PrintPolynomial(Polynomial *p)
{
    int pertama = p->degree;
    int terakhir = 0;
    while (p->coeff[terakhir] == 0 && terakhir < p->degree)
    {
        terakhir++;
    }
    for (int i = pertama; i >= terakhir; i--)
    {
        if (p->coeff[i] != 0){
            // Print Koefisien
            if (p->coeff[i] > 0)
            {
                if (i != pertama){
                    printf("+ ");
                }
                if (p->coeff[i] != 1 || i == 0){
                    printf("%d", p->coeff[i]);
                }
            }   
            else if (p->coeff[i] < 0){
                if (i != pertama){
                    printf("- ");
                }
                else
                {
                    printf("-");
                }
                if (p->coeff[i] != -1 || i == 0)
                {
                    printf("%d", -p->coeff[i]);
                }
            }
            // print x atau x^n
            if (i > 1){
                printf("x^%d", i);
            }
            else if (i == 1){
                printf("x");
            }

            if (i != terakhir){
                printf(" ");
            }
            else{
                printf("\n");
            }

            if (pertama == i && i == terakhir &&  p->coeff[i] ==0 )
            {
                printf("0\n");
            }
        }
    }
}

/**
 * I.S. P terdefinisi
 * F.S. Polynomial p ditampilkan dengan aturan sebagai berikut:
 * - Elemen ditampilkan dari derajat paling tinggi ke derajat paling rendah
 * - Hanya tampilkan elemen dengan koefisien tak nol
 * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien positif, tidak perlu berikan tanda + di depan
 * - Untuk suku derajat tertinggi (pertama ditampilkan) dengan koefisien negatif, tidak perlu berikan spasi antara tanda - dan suku (-x^n)
 * - Untuk suku yang bukan derajat tertinggi, tampilkan tanda + dan - dengan diberikan spasi (x^3 + 6x)
 * - Untuk koefisien 1, hanya tampilkan x^n (bukan 1x^n), kecuali untuk suku konstan
 * - Untuk koefisien -1, hanya tampilkan -x^n atau - x^n (bukan -1x^n dan - 1x^n), kecuali untuk suku konstan
 * - Untuk suku derajat 1, tampilkan x (bukan x^1)
 * - Untuk suku derajat 0, tampilkan koefisiennya saja
 * - Berikan newline (\n) di akhir baris
 * Contoh: -4x^3 + 3x^2 - 2x + 1
 */
#endif