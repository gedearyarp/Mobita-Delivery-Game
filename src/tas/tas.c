/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */
#include "../ADT/boolean.h"
#include <stdio.h>
#include "tas.h"
/* *** Konstruktor/Kreator *** */
void CreateTas(Tas *s){
	Tas st;
	IDX_TAS(st)=INDEX_UNDEF;
	currCAPACITY(st)=0;
	currMaxCapacity(st)=3;
	*s=st;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean TasIsEmpty(Tas s){
	return IDX_TAS(s) == INDEX_UNDEF;
}
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean TasIsFull(Tas s){
	return IDX_TAS(s) == currMaxCapacity(s)-1;
}
/* Mengirim true jika tabel penampung nilai s stack penuh dengan kapasitas saat ini */
boolean isMax(Tas s){
	return IDX_TAS(s) == MAXCAPACITY-1;
}
/* Mengirim true jika tabel penampung nilai s stack penuh dengan kapasitas maks(100) */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void pushTas(Tas *s, Pesanan val){
	IDX_TAS(*s)++;
	TOP_TAS(*s) = val;
	currCAPACITY(*s)++;
}
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void popTas(Tas *s, Pesanan *val){
	*val = TOP_TAS(*s);
	IDX_TAS(*s)--;
	currCAPACITY(*s)--;
}
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

