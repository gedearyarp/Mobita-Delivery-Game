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
#include "point.h"
#include "ListDin.h"

typedef struct { 
	POINT loc[CAPACITY]; /* Koordinat lokasi*/
	int m.nEff; /* >=0 banyaknya elemen efektif*/
	int hub[CAPACITY][CAPACITY]; /* list yang berhubungan dengan lokasi */
} MAP;
/* *** Notasi Akses: Selektor MAP *** */
#define NAMA(M) (M).loc.label
#define ABSIS(M) (M).loc.X
#define ORDINAT(M) (M).loc.Y
#define ELMT(M, i, j) (M).hub[(i)][(j)]
/* Jika m adalah : MAP, cara deklarasi dan akses: */
/* Deklarasi : m : MAP */
/* Maka cara akses:
   m.nama  untuk mengetahui char atau nama karakter dari lokasi
   m.idx    untuk mengakses indeks lokasi
   m.loc untuk mengakses koordinat lokasi dengan POINT
   m.hub untuk mengakses list yang berhubungan dengan lokasi */
/* Definisi :
  Map kosong: m.nEff = 0
  Definisi elemen pertama : m.loc[i] dengan i=Point
  Definisi elemen terakhir yang terdefinisi: m.loc[i] dengan i=l.nEff */


void CreateMap (MAP *m);
	/*  Membentuk map menjadi map kosong*/
void addMap(MAP *m,int X, int Y);
	/* Menambah koordinat pada matrix*/
int getElmt(Matrix m, int i,int j);
	/* Mengirimkan elemen m(i,j) */

void BacaKoordinat(MAP *m);
	/*Membaca masukan koordinat*/
void BacaAdjMatrix(MAP *m);
	/*Membaca adjency matrix*/

void BacaPesanan();
	/*Membaca pesanan*/











#endif
