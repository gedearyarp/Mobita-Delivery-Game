/* File: pesanan.h */
/* *** Definisi ABSTRACT DATA TYPE Pesanan *** */

#ifndef PESANAN_H
#define PESANAN_H

#include "boolean.h"
#include "../point/point.h"

#define T_UNDEF (-1)

typedef struct {
    int tMasuk;             // waktu pesanan masuk
    POINT pickUpPoint;      // tempat pick up (x,y,label)
    POINT dropOffPoint;     // tempat drop off (x,y,label)
    char type;              // jenis barang (N/H/P/V)
    int tPerish;            // waktu barang hangus (hanya untuk perishable item, jenis lainnya bernilai T_UNDEF)
    int tPick;              // waktu saat barang di-pick up, nilai awal = T_UNDEF
} Pesanan;

/* *** Selektor *** */
#define T_MASUK(p) (p).tMasuk
#define PICK_P(p) (p).pickUpPoint
#define DROP_P(p) (p).dropOffPoint
#define TYPE(p) (p).type
#define T_PERISH(p) (p).tPerish
#define T_PICK(p) (p).tPick

/* *** Konstruktor *** */
Pesanan createPesanan(int t0, int xP, int yP, char pick, int xD, int yD, char drop, char type, int tP, int tPick);
/* Membentuk sebuah data pesanan dari komponen-komponennya */

/* *** Display Pesanan *** */
void displayPesanan(Pesanan p);
/* Mencetak pesanan ke layar dengan format [t0,(pick,xP,yP),(drop,xD,yD),type,tP]

/* *** Fungsi Boolean *** */
boolean isPesananEqual(Pesanan p1, Pesanan p2);
/* Menghasilkan true jika pesanan 1 = pesanan 2 */

#endif
