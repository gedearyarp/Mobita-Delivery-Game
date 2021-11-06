/* File: point.c */
/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#include <math.h>
#include "point.h"

/* *** IMPLEMENTASI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y, char Label) {
    /* KAMUS LOKAL */
    POINT p;
    /* ALGORITMA */
    Absis(p) = X;
    Ordinat(p) = Y;
    Label(p) = Label;
    return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P) {
    /* KAMUS LOKAL */
    int x, y;
    char label;
    /* ALGORITMA */
    scanf("%d %d %c", &x, &y, &label);
    *P = MakePOINT(x,y,label);
} 
void TulisPOINT (POINT P) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    printf("%c(%d,%d)", Label(P), Absis(P), Ordinat(P));
}                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}
boolean NEQ (POINT P1, POINT P2){
    return (!EQ(P1,P2));
    // return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}
boolean IsOnSbX (POINT P) {
    return (Ordinat(P) == 0);
}
boolean IsOnSbY (POINT P) {
    return (Absis(P) == 0);
}
int Kuadran (POINT P) {
    /* KAMUS LOKAL */
    int x = Absis(P);
    int y = Ordinat(P);
    int kuadran = 0;
    /* ALGORITMA */
    if (x > 0 && y > 0) kuadran = 1;
    else if (x < 0 && y > 0) kuadran = 2;
    else if (x < 0 && y < 0) kuadran = 3;
    else if (x > 0 && y < 0) kuadran = 4;
    return kuadran;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P) {
    /* KAMUS LOKAL */
    POINT result = P;
    /* ALGORITMA */
    Absis(result) += 1;
    return result;
}              
POINT NextY (POINT P) {
    /* KAMUS LOKAL */
    POINT result = P;
    /* ALGORITMA */
    Ordinat(result) += 1;
    return result;
}
POINT PlusDelta (POINT P, int deltaX, int deltaY) {
    /* KAMUS LOKAL */
    POINT result = P;
    /* ALGORITMA */
    Absis(result) += deltaX;
    Ordinat(result) += deltaY;
    return result;
}
POINT MirrorOf (POINT P, boolean SbX) {
    /* KAMUS LOKAL */
    POINT result = P;
    /* ALGORITMA */
    if (SbX) Ordinat(result) *= -1;
    else Absis(result) *= -1;
    return result;
}
float Jarak0 (POINT P) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    // Rumus jarak terhadap origin adalah jarak = (x^2 + y^2)^0.5
    return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}
float Panjang (POINT P1, POINT P2) {
    /* KAMUS LOKAL */
    int difX, difY;
    /* ALGORITMA */
    // Rumus jarak antara 2 titik adalah panjang = ((x1-x2)^2 + (y1-y2)^2)^0.5
    difX = Absis(P1) - Absis(P2);       // Selisih x1 dan x2
    difY = Ordinat(P1) - Ordinat(P2);   // Selisih y1 dan y2
    return (sqrt(pow(difX, 2) + pow(difY, 2)));
}
void Geser (POINT *P, int deltaX, int deltaY) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void GeserKeSbX (POINT *P) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (SbX) Ordinat(*P) *= -1;
    else Absis(*P) *= -1;
}
void Putar (POINT *P, float Sudut) {
    /* KAMUS LOKAL */
    float sudutRad;
    int x = Absis(*P);
    int y = Ordinat(*P);
    /* ALGORITMA */
    // Konversi sudut derajat menjadi sudut radian (faktor konversi : pi/180)
    // Rumus: sudutRad = - Sudut / 180 * pi. Tanda negatif agar rotasi yang dilakukan searah jarum jam
    sudutRad = - Sudut / 180 * acos(-1);
    // Rumus rotasi: x' = x*cos(teta) - y*sin(teta); y' = x*sin(teta) + y*cos(teta)
    Absis(*P) = cos(sudutRad) * x - sin(sudutRad) * y;
    Ordinat(*P) = sin(sudutRad) * x + cos(sudutRad) * y; 
}