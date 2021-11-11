/*
NIM				: 13520030
Nama			: Fitrah Ramadhani Nugroho
Tanggal			: 20-09-2021
Topik Praktikum : matrix
Deskripsi		: Buat implementasi dari matrix.h
*/

#include "matrix_c.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>



/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void CreateMatriks(int nRow, int nCol, Matriks *m){
	/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
	/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
	/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
	//kamus
	int y,x;
	//algoritma
	if(nRow<=ROW_CAP && nCol<=COL_CAP&&nRow>0&&nCol>0){
		for(y=0;y<nRow;y++){
			for(x=0;x<nCol;x++){
				ELMT(*m, y, x) = '0';
			}
		}
		ROWS(*m) = nRow;
		COLS(*m) = nCol;
	}
}

/* *** Selektor "DUNIA Matriks" *** */
boolean isIdxValid_C(int i, int j){
	/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
	return (i<ROW_CAP && j<COL_CAP && i>=0 && j>=0);
}
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow_C(Matriks m){
	/* Mengirimkan Index baris terbesar m */
	//kamus
	return m.rowEff-1;
}

Index getLastIdxCol_C(Matriks m){
	/* Mengirimkan Index kolom terbesar m */
	return m.colEff-1;
}

boolean isIdxEff_C(Matriks m, Index i, Index j){
	/* Mengirimkan true jika i, j adalah Index efektif bagi m */
	return (i<m.rowEff && j<m.colEff&& i>=0 &&j>=0);
}

char getElmtDiagonal_C(Matriks m, Index i){
	/* Mengirimkan elemen m(i,i) */
	if(isIdxEff(m,i,i))return (m.contents[i][i]);
}

/* ********** Assignment  Matriks ********** */
void copyMatriks_C(Matriks mIn, Matriks *mRes){
	/* Melakukan assignment MRes = MIn */
	//kamus
	int y,x;
	//algoritma
	CreateMatrix(mIn.rowEff,mIn.colEff,mRes);
	for(y=0;y<mIn.rowEff;y++){
		for(x=0;x<mIn.colEff;x++){
			ELMT(*mRes, y, x) = mIn.contents[y][x];
		}
	}
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatriks(Matriks *m, int nRow, int nCol){
	/* I.S. isIdxValid(nRow,nCol) */
	/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
	/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
	/* Selanjutnya membaca nilai elemen per baris dan kolom */
	/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
	1 2 3
	4 5 6
	8 9 10 
	*/
	if(isIdxValid(nRow,nCol)){
		CreateMatrix(nRow,nCol,m);
		//kamus
		int y,x,isi;
		//algoritma
		for(y=0;y<nRow;y++){
			for(x=0;x<nCol;x++){
				scanf("%c",&isi);
				ELMT(*m, y, x) = isi;
			}
		}
	}
}

void displayMatriks(Matriks m){
	/* I.S. m terdefinisi */
	/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
	   dipisahkan sebuah spasi */
	/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
	/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
	1 2 3
	4 5 6
	8 9 10
	*/
	//kamus
	int y,x,isi;
	//algoritma
	for(y=0;y<m.rowEff;y++){
		for(x=0;x<m.colEff;x++){
			printf("%c",m.contents[y][x]);
			if(x<m.colEff-1)printf(" ");
		}
		if(y<m.rowEff-1)printf("\n");
	}
}








