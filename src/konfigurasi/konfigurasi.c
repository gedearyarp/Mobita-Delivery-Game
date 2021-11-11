#include "boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "konfigurasi.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include <stdio.h>
#include <stdlib.h>


void readFile(MAP *M){
	 // read mode
   	startKonf();
   	CreateMap (M);
	BacaKoordinat(M);
	BacaAdjMatrix(M);
	BacaPesanan(M);

}


void CreateMap (MAP *m){
	/*  Membentuk map menjadi map kosong*/
	//kamus
	int y,x;
	//algoritma
	for(x=0;x<CAP;x++ ){
		NAMA(*m,x) = '/';
		ABSIS(*m,x) = VAL_UNDEF;
		ORDINAT(*m,x) = VAL_UNDEF;
	}
	for(y=0;y<CAP;y++){
		for(x=0;x<CAP;x++){
			ELMT_M(*m, y, x) = VAL_UNDEF;
			PETA(*m,y,x)='/';
		}
	}
	nEff(*m) = 0;
	
}
void CreatePeta (MAP *m,int i,int j){
	/* Membentuk peta menjad peta kosong dengan ukuran i,j*/
	int x,y;
	ROWS_P(*m) = i+1;
	COLS_P(*m) = j+1;
	for(y=0;y<=i+1;y++){
		for(x=0;x<=j+1;x++){
			if(y==0 || x==0 || y== i+1 || x==j+1)PETA(*m,y,x)='*';
			else PETA(*m,y,x)=' ';
		}
	}
}
	
int LengthMAP(MAP m){
	/*Membaca panjang map*/
	return m.nEff;
}	


int ConvertInt(char angka[50],int length){
	/*Mengkonvert input char dari mesin kata menjadi int*/
	int val =0,i;
	for(i=0;i<length;i++) {
		val = val*10 + ((int)angka[i]-48);
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
//	int val = ConvertInt();
//	advWord();
	int N = ConvertInt(currentWord.contents,currentWord.length);
	PETA_Y(*m) = N;
	advWord();
	int M = ConvertInt(currentWord.contents,currentWord.length);
	PETA_X(*m) = M;
	CreatePeta(m,N,M);
	NAMA(*m,0) = '8';
//	printf("%d %d\n",N,M);
	advWord();
	ABSIS(*m,0) = ConvertInt(currentWord.contents,currentWord.length);
	x = ABSIS(*m,0);
	advWord();
	ORDINAT(*m,0) = ConvertInt(currentWord.contents,currentWord.length);
	y= ORDINAT(*m,0);
	PETA(*m,x,y) = '8';
//	printf("%d %d\n",x,y);
	advWord();
	nEff(*m) = ConvertInt(currentWord.contents,currentWord.length);
	ROWS_M(*m) = nEff(*m);
	COLS_M(*m) = nEff(*m);
//	printf("%d\n",ConvertInt(currentWord.contents,currentWord.length));
	for(i=1;i<=nEff(*m);i++){
		advWord();
		NAMA(*m,i) = currentWord.contents[0];
		advWord();
		ABSIS(*m,i) = ConvertInt(currentWord.contents,currentWord.length);
		x = ABSIS(*m,i);
		advWord();
		ORDINAT(*m,i) = ConvertInt(currentWord.contents,currentWord.length);
		y= ORDINAT(*m,i);
		PETA(*m,x,y) = NAMA(*m,i);
//		printf("%d %d %c \n",x,y,NAMA(*m,i));
	}
}
	
void BacaAdjMatrix(MAP *m){
	/*Membaca adjency matrix*/
	int i,j;
	for(i=0;i<=nEff(*m);i++){
		for(j=0;j<=nEff(*m);j++){
			advWord();
			ELMT_M(*m, i, j) = ConvertInt(currentWord.contents,currentWord.length);
			
		}
	}
}

void BacaPesanan(MAP *m){
	/*Membaca pesanan*/
	advWord();
	int i,x,n = ConvertInt(currentWord.contents,currentWord.length);
	nOrder(*m) =  n;
//	printf("%d\n",n);
	for(i=0;i<n;i++){
		advWord();
		O_MASUK(*m,i) = ConvertInt(currentWord.contents,currentWord.length);
		advWord();
		O_PICK_LABEL(*m,i) = currentWord.contents[0];
		x=0;
		while(NAMA(*m,x) != currentWord.contents[0] &&NAMA(*m,x)!= '/')x++;
		if(NAMA(*m,x)==currentWord.contents[0]){
			O_PICK_X(*m,i) = ABSIS(*m,x);
			O_PICK_Y(*m,i) = ORDINAT(*m,x); 
		}
		advWord();
		O_DROP_LABEL(*m,i) = currentWord.contents[0];
		x=0;
		while(NAMA(*m,x) != currentWord.contents[0] &&NAMA(*m,x)!= '/')x++;
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
	//	printf("%c",currentWord.contents[0]);
	//	printf("%d %c %c %c\n",O_MASUK(*m,i),O_PICK_LABEL(*m,i),O_DROP_LABEL(*m,i),O_TYPE(*m,i));
	}
	
}
	
	
	

