/* File: pesanan.h */
/* *** Definisi ABSTRACT DATA TYPE Pesanan *** */

#ifndef PESANAN_H
#define PESANAN_H

#include <point.h>

typedef struct {
    int tMasuk;             // waktu pesanan masuk
    POINT pickUpPoint;      // tempat pick up (x,y)
    POINT dropOffPoint;     // tempat drop off (x,y)
    char type;              // jenis barang (N/H/P/V)
    int tPerish;            // waktu barang hangus (hanya untuk perishable item)
} Pesanan;

/* *** Selektor *** */
#define T_MASUK(p) (p).tMasuk
#define PICK_P(p) (p).pickUpPoint
#define DROP_P(p) (p).dropOffPoint
#define TYPE(p) (p).type
#define T_PERISH(p) (p).tPerish

/* *** Konstruktor *** */
Pesanan createPesanan(int t0, int xP, int yP, char pick, int xD, int yD, char drop, char type, int tP);
/* Membentuk sebuah data pesanan dari komponen-komponennya */

/* Fungsi Boolean */
boolean isEqual(Pesanan P1, Pesanan P2);
/* Menghasilkan true jika P1 = P2 */

#endif