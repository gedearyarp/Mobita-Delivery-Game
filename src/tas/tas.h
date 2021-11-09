/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef TAS_H
#define TAS_H

#include "../ADT/boolean.h"
#include "../pesanan/pesanan.h"

#define INDEX_UNDEF -1
#define MAXCAPACITY 100

typedef struct {
  Pesanan buffer[MAXCAPACITY]; /* tabel penyimpan elemen */
  int idxTop;              /* alamat TOP: elemen puncak */
  int currCAPACITY;
} Tas;
// normal, heavy, perishable

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]
#define currCAPACITY(s) (s).currCAPACITY

/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean TasIsEmpty(Tas s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean TasIsFull(Tas s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushTas(Tas *s, Pesanan val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popTas(Tas *s, Pesanan *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

#endif
