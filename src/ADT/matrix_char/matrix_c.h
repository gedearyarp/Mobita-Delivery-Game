/* ********** Definisi TYPE Matriks dengan Index dan elemen integer ********** */

#ifndef Matrix_c_H
#define Matrix_c_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int Index; /* Index baris, kolom */
typedef struct
{
   char contents[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matriks;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matriks *** */
void CreateMatriks(int nRow, int nCol, Matriks *m);
/* Membentuk sebuah Matriks "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define ELMT(M, i, j) (M).contents[(i)][(j)]

/* *** Selektor "DUNIA Matriks" *** */
boolean isIdxValid_C(int i, int j);
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow_C(Matriks m);
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol_C(Matriks m);
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff_C(Matriks m, Index i, Index j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
char getElmtDiagonal_C(Matriks m, Index i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matriks ********** */
void copyMatriks(Matriks mIn, Matriks *mRes);
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatriks(Matriks *m, int nRow, int nCol);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatriks(Matriks m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/


#endif
