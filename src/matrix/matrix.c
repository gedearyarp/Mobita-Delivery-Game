/*
NIM				: 13520030
Nama			: Fitrah Ramadhani Nugroho
Tanggal			: 20-09-2021
Topik Praktikum : matrix
Deskripsi		: Buat implementasi dari matrix.h
*/

#include "matrix.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>



/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
	/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
	/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
	/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
	//kamus
	int y,x;
	//algoritma
	if(nRow<=ROW_CAP && nCol<=COL_CAP&&nRow>0&&nCol>0){
		for(y=0;y<nRow;y++){
			for(x=0;x<nCol;x++){
				ELMT(*m, y, x) = 0;
			}
		}
		ROWS(*m) = nRow;
		COLS(*m) = nCol;
	}
}

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
	/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
	return (i<ROW_CAP && j<COL_CAP && i>=0 && j>=0);
}
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
	/* Mengirimkan Index baris terbesar m */
	//kamus
	return m.rowEff-1;
}

Index getLastIdxCol(Matrix m){
	/* Mengirimkan Index kolom terbesar m */
	return m.colEff-1;
}

boolean isIdxEff(Matrix m, Index i, Index j){
	/* Mengirimkan true jika i, j adalah Index efektif bagi m */
	return (i<m.rowEff && j<m.colEff&& i>=0 &&j>=0);
}

int getElmtDiagonal(Matrix m, Index i){
	/* Mengirimkan elemen m(i,i) */
	if(isIdxEff(m,i,i))return (m.contents[i][i]);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
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
void readMatrix(Matrix *m, int nRow, int nCol){
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
				scanf("%d",&isi);
				ELMT(*m, y, x) = isi;
			}
		}
	}
}

void displayMatrix(Matrix m){
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
			printf("%d",m.contents[y][x]);
			if(x<m.colEff-1)printf(" ");
		}
		if(y<m.rowEff-1)printf("\n");
	}
}


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
	/* Prekondisi : m1 berukuran sama dengan m2 */
	/* Mengirim hasil penjumlahan matriks: m1 + m2 */
	//kamus
	int y,x;
	//algoritma
	Matrix m3;
	if(m1.colEff==m2.colEff && m1.rowEff==m2.rowEff){
		CreateMatrix(m1.rowEff,m1.colEff,&m3);
		for(y=0;y<m1.rowEff;y++){
			for(x=0;x<m1.colEff;x++){
				m3.contents[y][x] = m1.contents[y][x] + m2.contents[y][x];
			}
		}
		return m3;
	}
	
}

Matrix subtractMatrix(Matrix m1, Matrix m2){
	/* Prekondisi : m1 berukuran sama dengan m2 */
	/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
	//kamus
	int y,x;
	//algoritma
	Matrix m3;
	if(m1.colEff==m2.colEff && m1.rowEff==m2.rowEff){
		CreateMatrix(m1.rowEff,m1.colEff,&m3);
		for(y=0;y<m1.rowEff;y++){
			for(x=0;x<m1.colEff;x++){
				m3.contents[y][x] = m1.contents[y][x] - m2.contents[y][x];
			}
		}
		return m3;
	}
	
}

Matrix multiplyMatrix(Matrix m1, Matrix m2){
	/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
	/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
	//kamus
	int y,x,z,sum;
	//algoritma
	Matrix m3;
	if(m1.colEff==m2.rowEff){
		CreateMatrix(m1.rowEff,m2.colEff,&m3);
		for(y=0;y<m1.rowEff;y++){
			for(x=0;x<m2.colEff;x++){
				sum=0;
				for(z=0;z<m1.colEff;z++) sum = sum + (m1.contents[y][z] *m2.contents[z][x]); 
				m3.contents[y][x] = sum;
			}
		}
		return m3;
	}
	
}

Matrix multiplyConst(Matrix m, int x){
	int i,j;
	//algoritma
	Matrix m3;
	CreateMatrix(m.rowEff,m.colEff,&m3);
	for(i=0;i<m.rowEff;i++){
		for(j=0;j<m.colEff;j++){
			m3.contents[i][j] = m.contents[i][j] * x;
		}
	}
	return m3;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyConst(Matrix *m, int k){
	/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
	int i,j;
	//algoritma
	for(i=0;i<ROWS(*m);i++){
		for(j=0;j<COLS(*m);j++){
			ELMT(*m, i, j) = ELMT(*m, i, j) * k;
		}
	}
}


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
	/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
	/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
	/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
	//kamus
	int y=0,x=0;
	//algoritma
	if(count(m1)==count(m2) && getLastIdxCol(m1) == getLastIdxCol(m2)){
		while(y<m1.rowEff){
			while(x<m1.colEff){
				if(m1.contents[y][x]!=m2.contents[y][x])return false;
				x++;
			}
			y++;
		}
		return true;
	}	
	else return false;
}
boolean isNotEqual(Matrix m1, Matrix m2){
	/* Mengirimkan true jika m1 tidak sama dengan m2 */
	return(!isEqual(m1,m2));
}

boolean isSizeEqual(Matrix m1, Matrix m2){
	/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
	return(m1.colEff==m2.colEff && m1.rowEff == m2.rowEff);
}


/* ********** Operasi lain ********** */
int count(Matrix m){
	/* Mengirimkan banyaknya elemen m */
	//kamus
	int y,x,z,sum;
	//algoritma
	return (m.colEff * m.rowEff);
}


/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
	/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
	return (m.colEff==m.rowEff);
}

boolean isSymmetric(Matrix m){
	/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
   //kamus
	int y=0,x=0;
	//algoritma
	if(isSquare(m)){
		while(y<m.rowEff){
			while(x<m.colEff){
				if(m.contents[y][x]!=m.contents[x][y])return false;
				x++;
			}
			y++;
		}
		return true;
	}	
	else return false;
}

boolean isIdentity(Matrix m){
	/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   //kamus
	int y=0,x=0;
	//algoritma
	if(isSquare(m)){
		while(y<m.rowEff){
			while(x<m.colEff){
				if(m.contents[y][x]!=0 && y!=x)return false;
				else if(y==x && m.contents[y][x] != 1) return false;
				x++;
			}
			y++;
		}
		return true;
	}	
	else return false;
}
boolean isSparse(Matrix m){
	/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
	int y,x,add=0;
	float sum;
	//algoritma
	for(y=0;y<m.rowEff;y++){
		for(x=0;x<m.colEff;x++){
			if (m.contents[y][x] !=0) add++; 
		}
	}
	sum = add*100/count(m);
	return(sum<=5.0);
}	
Matrix inverse1(Matrix m){
	/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
	return multiplyConst(m, -1);
	
}

void pInverse1(Matrix *m){
	/* I.S. m terdefinisi */
	/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
	pMultiplyConst(m, -1);
}

float determinant(Matrix m){
	/* Prekondisi: isSquare(m) */
	/* Menghitung nilai determinan m */
	//kamus
	int x,y,i,j,a,b;
	float sum = 0;
	
	//algoritma
	if(isSquare(m)){
		if(m.colEff == 2 && m.rowEff ==2){
			return ((m.contents[0][0] * m.contents[1][1]) - (m.contents[0][1] * m.contents[1][0]));
		}
		else if(m.colEff ==1 && m.rowEff==1){
			return m.contents[0][0] ;
		}
		else {
			for(x=0;x<m.colEff;x++){
				Matrix mCopy;
				CreateMatrix(m.rowEff-1,m.colEff-1,&mCopy);
				b=0;
				for(i=1;i<m.rowEff;i++){
					a=0;
					for(j=0;j<m.colEff;j++){
						if(j!=x){
							mCopy.contents[i-1][a] = m.contents[i][j];
							a++;
						}  	
					}
				}
				/*displayMatrix(mCopy);
				printf("\n");*/
				if(x%2 ==0)sum = sum + determinant(mCopy)*m.contents[0][x];
				else sum = sum + determinant(mCopy)*(-1)*m.contents[0][x];
				//if(m.colEff==4)printf("%f\n",sum);
			}
		
		}
		return sum;
	}
}

void transpose(Matrix *m){
	/* I.S. m terdefinisi dan isSquare(m) */
	/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
	//kamus
	Matrix mCopy;
	int y,x;
	//algoritma
	CreateMatrix(COLS(*m),ROWS(*m),&mCopy);
	for(y=0;y<COLS(*m);y++){
		for(x=0;x<ROWS(*m);x++){
			mCopy.contents[y][x] = ELMT(*m, x, y);
		}
	}
	CreateMatrix(ROWS(mCopy),COLS(mCopy),m);
	for(y=0;y<ROWS(*m);y++){
		for(x=0;x<COLS(*m);x++){
			ELMT(*m, y, x) = mCopy.contents[y][x];
		}
	}
}








