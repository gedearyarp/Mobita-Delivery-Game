/*
NIM				: 13520030
Nama			: Fitrah Ramadhani Nugroho
Tanggal			: 14-09-2021
Topik Praktikum : List
Deskripsi		: Buat implementasi dari listdin.h 
*/
#include "listdin.h"
#include <stdio.h>
#include "boolean.h"
#include <stdlib.h>
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
	/* I.S. l sembarang, capacity > 0 */
	/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
	BUFFER(*l) = (int*) malloc(sizeof(int) * capacity);
	CAPACITY(*l) = capacity;
}


void dealocate(ListDin *l){
	/* I.S. l terdefinisi; */
	/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
	free(BUFFER(*l));
	CAPACITY(*l) = 0;
	NEFF(*l) =0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
	/* Mengirimkan banyaknya elemen efektif list */
	/* Mengirimkan nol jika list l kosong */
	/* *** Daya tampung container *** */
	return l.nEff;
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
	/* Prekondisi : List l tidak kosong */
	/* Mengirimkan indeks elemen l terakhir */
	//kamus
	return l.nEff-1;
}


/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i){
	/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
	/* yaitu antara indeks yang terdefinisi utk container*/
	return (i>=0 && i< l.capacity);
}

boolean isIdxEff(ListDin l, IdxType i){
	/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
	/* yaitu antara 0..NEFF(l) */
	return (i>=0 && i<l.nEff);
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
	/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
	return (l.nEff==0);
}
/* *** Test list penuh *** */
boolean isFull(ListDin l){
	/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
	return (l.capacity == l.nEff);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
	/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
	/* F.S. List l terdefinisi */
	/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
	/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
	/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
	/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
	/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
	      0 satu per satu diakhiri enter */
	/*    Jika N = 0; hanya terbentuk l kosong */
	//kamus
	int isi,x=0,n=-1;
	//algoritma
	while(n<0 || n>CAPACITY(*l)){
		scanf("%d",&n);
	}
	NEFF(*l) = n;
	for(x=0;x<n;x++){
		scanf("%d",&isi);
		ELMT(*l, x) = isi;
	}	
}

void displayList(ListDin l){
	/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
	/* I.S. l boleh kosong */
	/* F.S. Jika l tidak kosong: [e1,e2,...,en] */	
	/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
	/* Jika list kosong : menulis [] */
	//kamus
	int x=0;
	//algoritma
	printf("[");
	for(x=0;x<l.nEff;x++){
		printf("%d",l.buffer[x]);
		if(x<l.nEff-1)printf(",");
	}
	printf("]");
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
	/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
	/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
	/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
	//kamus
	int x=0;
    ListDin l3;
	//algoritma
	if(length(l2)==length(l1) && !isEmpty(l1)){
		CreateListDin(&l3,l1.capacity);
		l3.nEff = l1.nEff;
		if(plus){
	       	for(x=0;x<l1.nEff;x++){
	    		l3.buffer[x] = l1.buffer[x]+l2.buffer[x];
			}
		}
		else {
	       	for(x=0;x<l1.nEff;x++){
	    		l3.buffer[x] = l1.buffer[x]-l2.buffer[x];
			}
		}
		return l3;
	}
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
	/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
	int x=0;
	//algoritma
	if(length(l2)==length(l1) && !isEmpty(l1)){		
		while(x <l1.nEff){
    		if(l1.buffer[x]!=l2.buffer[x])return false;
    		x++;
		}
		return true;
	}
	else if(length(l2)==length(l1) && isEmpty(l1))return true;
	else return false;
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
	/* Search apakah ada elemen List l yang bernilai val */
	/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
	/* Jika tidak ada, mengirimkan IDX_UNDEF */
	/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
	/* Skema Searching yang digunakan bebas */
	int x=0;
	//algoritma
	while(x <l.nEff){
		if (l.buffer[x]== val)return x;
		x++;
	}
	return IDX_UNDEF;
}


/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
	/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    int maks = -99999999;
    int mins = 99999999;
    int x=0;
    while(x <l.nEff){
		if (l.buffer[x]>maks)maks = l.buffer[x];
		if (l.buffer[x]<mins)mins = l.buffer[x];
		x++;
	}
	if(length(l)>0){
		*max = maks;
		*min = mins;
	}
}


/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
	/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
	/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
	/* Proses : Menyalin isi lIn ke lOut */
	//kamus
	int x =0;
	//algoritma
	CAPACITY(*lOut) = lIn.capacity;
	NEFF(*lOut) = lIn.nEff;
	for(x=0;x<lIn.nEff;x++){
		ELMT(*lOut, x) = lIn.buffer[x];
	}
}

ElType sumList(ListDin l){
	/* Menghasilkan hasil penjumlahan semua elemen l */
	/* Jika l kosong menghasilkan 0 */
	//kamus
	int x=0, sum=0;
	for(x=0;x<l.nEff;x++){
		sum = sum + l.buffer[x];
	}
	return sum;
}

int countVal(ListDin l, ElType val){
	/* Menghasilkan berapa banyak kemunculan val di l */
	/* Jika l kosong menghasilkan 0 */
	int x=0, sum=0;
	for(x=0;x<l.nEff;x++){
		if(l.buffer[x] ==val) sum++;
	}
	return sum;
}

boolean isAllEven(ListDin l){
	/* Menghailkan true jika semua elemen l genap. l boleh kosong */
	int x=0;
	//algoritma
	while(x <l.nEff){
		if (l.buffer[x]%2 ==1)return false;
		x++;
	}
//	if(l.nEff>0)
	return true;
//	else return false;
}


/* ********** SORTING **********	 */
void sort(ListDin *l, boolean asc){
	/* I.S. l boleh kosong */
	/* F.S. Jika asc = true, l terurut membesar */
	/*      Jika asc = false, l terurut mengecil */
	/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
   int x,y;
   if(asc){
    	for(x=NEFF(*l)-1;x>=0;x--){
    		for(y=0;y<x;y++){
    			if(ELMT(*l, y)>ELMT(*l, y+1)){
    				int swap = ELMT(*l, y);
    				ELMT(*l, y) = ELMT(*l, y+1);
    				ELMT(*l, y+1) = swap;
				}
			}
		}
   }
   else {
    	for(x=NEFF(*l)-1;x>=0;x--){
    		for(y=0;y<x;y++){
    			if(ELMT(*l, y)<ELMT(*l, y+1)){
    				int swap = ELMT(*l, y);
    				ELMT(*l, y) = ELMT(*l, y+1);
    				ELMT(*l, y+1) = swap;
				}
			}
		}
   }
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
	/* Proses: Menambahkan val sebagai elemen terakhir list */
	/* I.S. List l boleh kosong, tetapi tidak penuh */
	/* F.S. val adalah elemen terakhir l yang baru */
	if(NEFF(*l)<CAPACITY(*l)){
		ELMT(*l,NEFF(*l)) = val;
		NEFF(*l) = NEFF(*l) +1 ;
	}
	else{
		growList(l, CAPACITY(*l));
		ELMT(*l,NEFF(*l)) = val;
		NEFF(*l) = NEFF(*l) +1 ;
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
	/* Proses : Menghapus elemen terakhir list */
	/* I.S. List tidak kosong */
	/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
	/*      Banyaknya elemen list berkurang satu */
	/*      List l mungkin menjadi kosong */
	if( NEFF(*l)>0){
		NEFF(*l) = NEFF(*l) -1 ;
		*val = ELMT(*l,NEFF(*l));
	}
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
	/* Proses : Menambahkan capacity l sebanyak num */
	/* I.S. List sudah terdefinisi */
	/* F.S. Ukuran list bertambah sebanyak num */
	int x;
	ListDin lCopy;
	int *newArr = (int*) malloc(sizeof(int) * (num+CAPACITY(*l)));
	for(x=0;x<NEFF(*l);x++){
		newArr[x] = ELMT(*l,x);
	}
	int *oldArray = BUFFER(*l);
	BUFFER(*l) = newArr;
	free(oldArray);
	CAPACITY(*l) = num+CAPACITY(*l);
	
}


void shrinkList(ListDin *l, int num){
	/* Proses : Mengurangi capacity sebanyak num */
	/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
	/* F.S. Ukuran list berkurang sebanyak num. */
	int x;
	ListDin lCopy;
	int *newArr = (int*) malloc(sizeof(int) * (CAPACITY(*l)-num));
	for(x=0;x<NEFF(*l);x++){
		newArr[x] = ELMT(*l,x);
	}
	int *oldArray = BUFFER(*l);
	BUFFER(*l) = newArr;
	free(oldArray);
	CAPACITY(*l) = CAPACITY(*l)-num;
}


void compactList(ListDin *l){
	/* Proses : Mengurangi capacity sehingga nEff = capacity */
	/* I.S. List lidak kosong */
	/* F.S. Ukuran nEff = capacity */	
	int x;
	ListDin lCopy;
	int *newArr = (int*) malloc(sizeof(int) * NEFF(*l));
	for(x=0;x<NEFF(*l);x++){
		newArr[x] = ELMT(*l,x);
	}
	int *oldArray = BUFFER(*l);
	BUFFER(*l) = newArr;
	free(oldArray);
	CAPACITY(*l) = NEFF(*l);
}













