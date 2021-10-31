/* File: pesanan.c */

#include <stdio.h>
#include "pesanan.h"

/* *** Implementasi Fungsi createPesanan *** */
Pesanan createPesanan(int t0, int xP, int yP, char pick, int xD, int yD, char drop, char type, int tP) {
    /* KAMUS LOKAL */
    Pesanan P;
    /* ALGORITMA */
    T_MASUK(P) = t0;
    PICK_P(P) = MakePOINT(xP, yP, pick);
    DROP_P(P) = MakePOINT(xD, yD, drop);
    TYPE(P) = type;
    T_PERISH(P) = tP;
    return P;
}

/* *** Implementasi Display Pesanan *** */
void displayPesanan(Pesanan p) {
    /* ALGORITMA */
    printf("[%d,", T_MASUK(p));
    TulisPOINT(PICK_P(p));
    printf(",");
    TulisPOINT(DROP_P(p));
    printf(",%c,%d]", TYPE(p), T_PERISH(p));
}

/* *** Implementasi Fungsi Boolean *** */
boolean isPesananEqual(Pesanan P1, Pesanan P2) {
    /* ALGORITMA */
    return ( (T_MASUK(P1) == T_MASUK(P2)) && 
             (EQ(PICK_P(P1), PICK_P(P2))) &&
             (EQ(DROP_P(P1), DROP_P(P2))) && 
             (TYPE(P1) == TYPE(P2))       &&
             (T_PERISH(P1) == T_PERISH(P2)) );
}