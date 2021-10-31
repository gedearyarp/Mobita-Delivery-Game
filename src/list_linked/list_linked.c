/* 
NIM             : Hansel Valentino Tanoto
Nama            : 13520046
Tanggal         : 28 Oktober 2021
Topik praktikum : ADT Linked List
Deskripsi       : Implementasi fungsi/prosedur primitif ADT Linked List
                  yang sudah didefinisikan di file header (list_linked.h)
*/

#include <stdio.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyList(List l) {
/* Mengirim true jika list kosong */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (FIRST(l) ==  NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmtList(List l, int idx) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (ctr < idx) {
        ctr++;
        p = p->next;
    }
    return (p->info);
}

void setElmtList(List *l, int idx, ElType val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = *l;
    while (ctr < idx) {
        ctr++;
        p = p->next;
    }
    p->info = val;
}

int indexOfList(List l, ElType val) {
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    /* KAMUS LOKAL */
    int idx;
    boolean found;
    Address p;
    /* ALGORITMA */
    idx = 0;
    found = false;
    p = l;
    while ((p != NULL) && (!found)) {
        if (isPesananEqual(INFO(p), val)){
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        p->next = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p, last;
    /* ALGORITMA */
    if (isEmptyList(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = *l;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS LOKAL */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = *l;
            while (ctr < idx-1) {
                ctr++;
                loc = loc->next;
            }
            p->next = loc->next;
            loc->next = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = *l;
    *val = p->info;
    *l = p->next;
    free(p);
}
void deleteLast(List *l, ElType *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS LOKAL */
    Address p, loc;
    /* ALGORITMA */
    p = *l;
    loc = NULL;
    while (p->next != NULL) {
        loc = p;
        p = p->next;
    }
    if (loc == NULL) {
        *l = NULL; 
    } else {
        loc->next = NULL;
    }
    *val = p->info; 
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS LOKAL */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        ctr =0;
        loc = *l;
        while (ctr < idx-1) {
            ctr++;
            loc = loc->next;
        }
        p = loc->next;
        *val = p->info;
        loc->next = p->next;
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = l;
    printf("[");
    while (p != NULL) {
        displayPesanan(INFO(p));
        if (p->next != NULL) {
            printf(",");
        }
        p = p->next;
    }
    printf("]");
}

int lengthList(List l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS LOKAL */
    Address p;
    int ctr;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (p != NULL) {
        ctr++;
        p = p->next;
    }
    return ctr;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    /* KAMUS LOKAL */
    Address loc;
    boolean found;
    /* ALGORITMA */
    found = false;
    loc = FIRST(L);
    while (loc != NULL) {
        if (P == loc) {
            found = true;
        }
        loc = NEXT(loc);
    }
    return found;
}
Address searchPrec(List L, ElType X) {
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
    /* KAMUS LOKAL */
    int idxX, i;
    Address loc, result;
    ElType prev;
    /* ALGORITMA */
    idxX = indexOfList(L, X);
    result == NULL;
    if (idxX != IDX_UNDEF && idxX != 0) {
        loc = FIRST(L);
        i = 0;
        while (i < idxX-1) {
            i++;
            loc = NEXT(loc);
        }
        result = loc;
    }
    return result;
}

/****************** PROSES TERHADAP LIST ******************/
List concatList(List l1, List l2) {
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    /* KAMUS LOKAL */
    List l3;
    Address p;
    /* ALGORITMA */
    CreateList(&l3);
    p = l1;
    while (p != NULL) {
        insertLast(&l3, p->info);
        p = p->next;
    }
    p = l2;
    while (p !=  NULL) {
        insertLast(&l3, p->info);
        p = p->next;
    }
    return l3;
}

void delAll(List *l) {
/* Delete semua elemen list dan alamat elemen di-dealokasi */
    /* KAMUS LOKAL */
    Address loc;
    ElType p;
    /* ALGORITMA */
    loc = FIRST(*l);
    while (loc != NULL) {
        deleteFirst(l, &p);
        loc = NEXT(loc);
    }
    FIRST(*l) = NULL;
}

void inverseList(List *l) {
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
    /* KAMUS LOKAL */
    Address loc, last, prev;
    /* ALGORITMA */
    if (!isEmptyList(*l)) {
        loc = FIRST(*l);
        while (NEXT(loc) != NULL) {
            loc = NEXT(loc);
        }
        last = loc;
        while (loc != FIRST(*l)) {
            prev = FIRST(*l);
            while (NEXT(prev) != loc) {
                prev = NEXT(prev);
            }
            NEXT(loc) = prev;
            loc = NEXT(loc);
        }
        NEXT(loc) = NULL;
        FIRST(*l) = last;
    }
}

List fInverseList(List l) {
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* KAMUS LOKAL */
    List l2;
    /* ALGORITMA */
    l2 = fCopyList(l);
    inverseList(&l2);
    return l2;
}

void copyList(List *l1, List *l2) {
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    FIRST(*l2) = FIRST(*l1);
}

List fCopyList(List l) {
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
    /* KAMUS LOKAL */
    List l2;
    Address loc, p;
    /* ALGORITMA */
    CreateList(&l2);
    boolean success = true;
    loc = FIRST(l);
    while (success && loc != NULL){
        p = newNode(INFO(loc));
        if (p == NULL){
            success = false;
        } else {
            insertLast(&l2, INFO(p));
        }
        loc = NEXT(loc);
    }
    if (!success){
        delAll(&l2);
    }
    return l2;
}

void cpAllocList(List lIn, List *lOut) {
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *lOut = fCopyList(lIn);
}

void splitList(List *l1, List *l2, List l) {
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */
    /* KAMUS LOKAL */
    int len, ctr;
    Address loc, p;
    /* ALGORITMA */
    CreateList(l1);
    CreateList(l2);
    len = lengthList(l)/2;
    ctr = 0;
    loc = FIRST(l);
    while (loc != NULL) {
        ctr++;
        p = newNode(INFO(loc));
        if (p != NULL) {
            if (ctr <= len) {
                insertLast(l1, INFO(p));
            } else {
                insertLast(l2, INFO(p));
            }
        }
        loc = NEXT(loc);
    }
}