/* File: pesanan.c */

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