/* File : queue.C */
/* Implementasi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>
#include "queue.h"
#include "../pesanan/pesanan.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyQ(Queue q) {
/* Mengirim true jika q kosong: lihat definisi di atas */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}
boolean isFullQ(Queue q) {
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == QCAPACITY - 1));
}
int lengthQ(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* KAMUS LOKAL */
    int len = 0;
    /* ALGORITMA */
    if (!isEmptyQ(q)) {
        len = IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    return len;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val) {
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    if (isEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
    }
    if (IDX_TAIL(*q) == QCAPACITY-1 && !isFullQ(*q)){
        j = 0;
        for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
            (*q).buffer[j] = (*q).buffer[i];
            j++;
        }
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = j - 1;
    }
    IDX_TAIL(*q) += 1;
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val) {
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_TAIL(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    } else {
        IDX_HEAD(*q) += 1;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    printf("[");
    for (i = IDX_HEAD(q); i <= IDX_TAIL(q); i++) {
        displayPesanan((q).buffer[i]);
        if (i != IDX_TAIL(q)) {
            printf(",");
        }
    }
    printf("]");
}