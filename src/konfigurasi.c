#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "point.h"
#include "ListDin.h"
#include <stdio.h>


void CreateMap (MAP *m){
	/*  Membentuk map menjadi map kosong*/
	//kamus
	int y,x;
	//algoritma
	for(x=0;x<CAPACITY;x++ ){
		NAMA(*m) = '/';
		ABSIS(M) = VAL_UNDEF;
		ORDINAT(M) = VAL_UNDEF;
	}
	for(y=0;y<CAPACITY;y++){
		for(x=0;x<CAPACITY;x++){
			ELMT(*m, y, x) = VAL_UNDEF;
		}
	}
	
}
	
void addMap(MAP *m,int X, int Y);
	/* Menambah koordinat pada matrix*/
int getElmt(Matrix m, int i,int j);
	/* Mengirimkan elemen m(i,j) */

