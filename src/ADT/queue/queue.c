/* File : queue.C */
/* Implementasi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    IDX_HEAD(*q) = I_UNDEF;
    IDX_TAIL(*q) = I_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmptyQ(Queue q) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((IDX_HEAD(q) == I_UNDEF) && (IDX_TAIL(q) == I_UNDEF));
}
boolean isFullQ(Queue q) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return ((IDX_HEAD(q) == 0) && (IDX_TAIL(q) == QCAPACITY - 1));
}
int lengthQ(Queue q) {
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
    /* KAMUS LOKAL */
    int i, j;
    /* ALGORITMA */
    if (isEmptyQ(*q)) {
        IDX_HEAD(*q) = 0;
        HEAD(*q) = val;
    } else {
        if (IDX_TAIL(*q) == QCAPACITY-1 && !isFullQ(*q)){
            j = 0;
            for (i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                (*q).buffer[j] = (*q).buffer[i];
                j++;
            }
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = j - 1;
        }
        i = IDX_TAIL(*q);
        while ((T_MASUK(val) < T_MASUK((*q).buffer[i])) && (i > IDX_HEAD(*q))) {
            (*q).buffer[i+1] = (*q).buffer[i];
            i--;
        }
        if (T_MASUK(val) >= T_MASUK((*q).buffer[i])) {
            (*q).buffer[i+1] = val; 
        } else {
            (*q).buffer[i+1] = (*q).buffer[i];
            (*q).buffer[i] = val;
        }
    }
    IDX_TAIL(*q) += 1;
}

void dequeue(Queue *q, ElType *val) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_TAIL(*q) = I_UNDEF;
        IDX_TAIL(*q) = I_UNDEF;
    } else {
        IDX_HEAD(*q) += 1;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
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

void QueuePesanan (MAP m, Queue *q_pesanan) {
    /* KAMUS LOKAL */
    int i;
    /* ALGORITMA */
    for (i = 0; i < nOrder(m); i++) {
    	displayPesanan(ORDER(m,i));
        enqueue(q_pesanan, ORDER(m,i));
    }
}
