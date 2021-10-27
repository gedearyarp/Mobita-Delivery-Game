#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "konfigurasi.h"
#include "point.h"
#include "pesanan.h"
#include <stdio.h>


void CreateMap (MAP *m){
	/*  Membentuk map menjadi map kosong*/
	//kamus
	int y,x;
	//algoritma
	for(x=0;x<CAPACITY;x++ ){
		NAMA(*m,x) = '/';
		ABSIS(*m,x) = VAL_UNDEF;
		ORDINAT(*m,x) = VAL_UNDEF;
	}
	for(y=0;y<CAPACITY;y++){
		for(x=0;x<CAPACITY;x++){
			ELMT_M(*m, y, x) = VAL_UNDEF;
			PETA(*m,y,x)='/';
		}
	}
	nEff(*m) = 0;
	
}
void CreatePeta (MAP *m,int i,int j){
	/* Membentuk peta menjad peta kosong dengan ukuran i,j*/
	int x,y;
	for(y=0;y<i;y++){
		for(x=0;x<j;x++){
			PETA(*m,y,x)=' ';
		}
	}
}
	
int LengthMAP(MAP m){
	/*Membaca panjang map*/
	return m.nEff;
}	


int ConvertInt(){
	/*Mengkonvert input char dari mesin kata menjadi int*/
	int val =0,i;
	for(i=0;i<currentWord.length;i++) {
		val = val*10 + (currentWord.contents[i]-48);
	}
	return val;
}
	
	
void addLastMap(MAP *m,int X, int Y,char name){
	/* Menambah koordinat pada matrix*/
	int i = LengthMAP(*m);
	NAMA(*m,i) = name;
	ABSIS(*m,i) = X;
	ORDINAT(*m,i) = Y;
}

void BacaKoordinat(MAP *m){
	/*Membaca masukan koordinat*/
	//kamus
	int i,x,y;
	//algoritma
	startWord();
	int val = ConvertInt();
	advWord();
	int N = ConvertInt();
	advWord();
	int M = ConvertInt();
	CreatePeta(m,N,M);
	advWord();
	NAMA(*m,0) = '8';
	advWord();
	ABSIS(*m,0) = ConvertInt();
	x = ABSIS(*m,0);
	advWord();
	ORDINAT(*m,0) = ConvertInt();
	y= ORDINAT(*m,0);
	PETA(*m,x,y) = '/';
	advWord();
	nEff(*m) = ConvertInt();
	for(i=0;i<nEff(*m);i++){
		advWord();
		NAMA(*m,i) = currentWord.contents[0];
		advWord();
		ABSIS(*m,i) = ConvertInt();
		x = ABSIS(*m,0);
		advWord();
		ORDINAT(*m,i) = ConvertInt();
		y= ORDINAT(*m,0);
		PETA(*m,x,y) = NAMA(*m,i);
	}
}
	
void BacaAdjMatrix(MAP *m){
	/*Membaca adjency matrix*/
	int i,j;
	startWord();
	for(i=0;i<nEff(*m);i++){
		for(j=0;j<nEff(*m);j++){
			ELMT_M(*m, i, j) = ConvertInt();
			advWord;
		}
	}
}

void BacaPesanan(MAP *m){
	/*Membaca pesanan*/
	startWord();
	int i,x,n = ConvertInt();
	for(i=0;i<n;i++){
		advWord();
		O_MASUK(*m,i) = ConvertInt();
		advWord();
		O_PICK_LABEL(*m,i) = currentWord.contents[0];
		x=0;
		while(NAMA(*m,x) != currentWord.contents[0] &&NAMA(*m,x)!= 'y')x++;
		if(NAMA(*m,x)==currentWord.contents[0]){
			O_PICK_X(*m,i) = ABSIS(*m,x);
			O_PICK_Y(*m,i) = ORDINAT(*m,x); 
		}
		advWord();
		O_DROP_LABEL(*m,i) = currentWord.contents[0];
		while(NAMA(*m,x) != currentWord.contents[0] &&NAMA(*m,x)!= 'y')x++;
		if(NAMA(*m,x)==currentWord.contents[0]){
			O_DROP_X(*m,i) = ABSIS(*m,x);
			O_DROP_Y(*m,i) = ORDINAT(*m,x); 
		}
		advWord();
		O_TYPE(*m,i) =  currentWord.contents[0];
		if(O_TYPE(*m,i)=='P'){
			advWord();
			O_T_PERISH(*m,i) = currentWord.contents[0];;
		}
	}
	
}
	
	
	

