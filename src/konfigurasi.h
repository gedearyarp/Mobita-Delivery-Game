/* File: point.h */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef KONFIGURASI_H
#define KONFIGURASI_H

#define CAPACITY 100
#define VAL_UNDEF -999

#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "pesanan.h"
#include "point.h"

typedef struct { 
	POINT loc[CAPACITY]; /* Koordinat lokasi*/
	int nEff; /* >=0 banyaknya elemen efektif*/
	int hub[CAPACITY][CAPACITY]; /*  matrix adjency yang berhubungan dengan lokasi */
	char peta[CAPACITY][CAPACITY];/* matrix untuk menampilkan koordinat lokasi*/
	Pesanan pesan[CAPACITY];
} MAP;
/* *** Notasi Akses: Selektor MAP *** */
#define NAMA(M,i) (M).loc[i].label
#define ABSIS(M,i) (M).loc[i].X
#define ORDINAT(M,i) (M).loc[i].Y
#define ELMT_M(M, i, j) (M).hub[(i)][(j)]
#define PETA(M, i, j) (M).peta[(i)][(j)]
#define nEff(M) (M).nEff
#define ORDER(M,i) (M).pesan[(i)]
#define O_MASUK(M,i) (M).pesan[(i)].tMasuk
#define O_PICK_P(M,i) (M).pesan[(i)].pickUpPoint
#define O_DROP_P(M,i) (M).pesan[(i)].dropOffPoint
#define O_TYPE(M,i) (M).pesan[(i)].type
#define O_T_PERISH(M,i) (M).pesan[(i)].tPerish
/* Jika m adalah : MAP, cara deklarasi dan akses: */
/* Deklarasi : m : MAP */
/* Maka cara akses:
   m.loc[i].label  untuk mengetahui char atau nama karakter dari lokasi
   m.loc[i].X  untuk mengakses absis lokasi dengan POINT
   m.loc[i].Y untuk mengakses ordinat lokasi dengan POINT
   m.hub untuk mengakses matrix adjency yang berhubungan dengan lokasi 
   m.nEff untuk mengaksis ukuran MAP
   m.peta untuk mengakses gambaran peta*/
   
/* Definisi :
  Map kosong: m.nEff = 0
  Definisi elemen pertama : m.loc[i] dengan i=Point
  Definisi elemen terakhir yang terdefinisi: m.loc[i] dengan i=l.nEff */

int ConvertInt();
	/*Mengkonvert input char dari mesin kata menjadi int*/
void CreateMap (MAP *m);
	/*  Membentuk map menjadi map kosong*/
void CreatePeta (MAP *m,int i,int j);
	/* Membentuk peta menjad peta kosong dengan ukuran i dan j*/

void addMap(MAP *m,int X, int Y);
	/* Menambah koordinat pada matrix*/

void BacaKoordinat(MAP *m);
	/*Membaca masukan koordinat*/
void BacaAdjMatrix(MAP *m);
	/*Membaca adjency matrix*/
int LengthMAP(MAP m);
	/*Membaca panjang map*/

void BacaPesanan();
	/*Membaca pesanan*/











#endif
