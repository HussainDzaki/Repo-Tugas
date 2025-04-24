#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include <stdio.h>
#include <math.h>
/* Definisi type POINT */
typedef struct
{
    float X; /* absis (sumbu X) */
    float Y; /* ordinat (sumbu Y) */
} POINT;

/* Macro selektor komponen */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y)
{
    P->X = X;
    P->Y = Y;
}
/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P)
{
    scanf("%f", &P->X);
    scanf("%f", &P->Y);
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P)
{
    return P.X;
}
float GetY(const POINT P)
{
    return P.Y;
}
void SetX(POINT *P, float X)
{
    P->X = X;
}
void SetY(POINT *P, float Y)
{
    P->Y = Y;
}
/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P)
{
    printf("(%f,%f)", GetX(P), GetY(P));
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P)
{
    if (GetX(P) == 0 && GetY(P) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

} /* true jika P = (0,0) */
boolean IsOnSbX(POINT P)
{
    if (GetY(P) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

} /* true jika Y = 0 */
boolean IsOnSbY(POINT P)
{
    if (GetX(P) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

} /* true jika X = 0 */
int Kuadran(POINT P)
{
    if (GetX(P) > 0 && GetY(P) > 0)
    {
        return 1;
    }
    else if (GetX(P) < 0 && GetY(P) > 0)
    {
        return 2;
    }
    else if (GetX(P) < 0 && GetY(P) < 0)
    {
        return 3;
    }
    else if (GetX(P) > 0 && GetY(P) < 0)
    {
        return 4;
    }

} /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2)
{
    if (GetX(P1) == GetX(P2) && GetY(P1) == GetY(P2))
    {
        return 1;
    }
    else
        return 0;

} /* true jika X dan Y identik */
boolean NonEquals(POINT P1, POINT P2)
{
    return !Equals(P1, P2);
}; /* negasi Equals */

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float Distance(POINT P1, POINT P2)
{
    return sqrt(((GetX(P1) - GetX(P2)) * (GetX(P1) - GetX(P2)) + ((GetY(P1) - GetY(P2)) * (GetY(P1) - GetY(P2)))));
}
/* Menghasilkan titik tengah P1 dan P2 */
POINT MidPoint(POINT P1, POINT P2)
{
    POINT P3;
    P3.X = (GetX(P1) + GetX(P2)) / 2;
    P3.Y = (GetY(P1) + GetY(P2)) / 2;
    return P3;
}

#endif /* POINT_H */