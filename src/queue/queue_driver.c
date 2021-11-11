/* File: pesanan_driver.c */
/* *** Driver ABSTRACT DATA TYPE Pesanan *** */

/* Note:
    Compile:    gcc queue.c queue_driver.c ../pesanan/pesanan.c ../point/point.c ../konfigurasi/konfigurasi.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c -o queue_d
*/

#include <stdio.h>
#include "queue.h"

int main () {
    /* KAMUS */
    Queue q1, q_pesanan;
    Pesanan p1, p2, p3, p4, temp;
    MAP M;

    /* ALGORITMA */
    p1 = createPesanan(1, 3, 8, 'G', 8, 6, 'N', 'N', T_UNDEF, T_UNDEF);     // t=1, G(3,8)->N(8,6), Normal
    p2 = createPesanan(2, 8, 2, 'M', 1, 15, 'B', 'H', T_UNDEF, T_UNDEF);    // t=2, M(8,2)->B(1,15), Heavy
    p3 = createPesanan(9, 10, 3, 'Q', 7, 10, 'L', 'V', T_UNDEF, T_UNDEF);   // t=9, Q(10,3)->L(7,10), VIP
    p4 = createPesanan(10, 9, 13, 'P', 10, 3, 'Q', 'P', 20, T_UNDEF);       // t=10, P(9,13)->Q(10,3), Perishable(20)
    
    // PEMBUATAN QUEUE KOSONG DAN DISPLAY QUEUE
    CreateQueue(&q1);
    displayQueue(q1); printf("\n");


    // TEST LIST KOSONG ATAU PENUH
    if (isEmptyQ(q1)) printf("Queue kosong.\n");
    else printf("Queue tidak kosong.\n");

    if (isFullQ(q1)) printf("Queue penuh.\n");
    else printf("Queue tidak penuh.\n");


    // PRIMITIF ADD ELEMENT
    enqueue(&q1, p4);   displayQueue(q1); printf("\n");
    enqueue(&q1, p1);   displayQueue(q1); printf("\n");
    enqueue(&q1, p3);   displayQueue(q1); printf("\n");
    enqueue(&q1, p2);   displayQueue(q1); printf("\n");



    // PANJANG QUEUE
    printf("Panjang q1 = %d\n", lengthQ(q1));


    // PRIMITIF DELETE ELEMENT
    dequeue(&q1, &temp);    displayQueue(q1); printf("\n");
    dequeue(&q1, &temp);    displayQueue(q1); printf("\n");


    // CREATE QUEUE PESANAN
//  QueuePesanan(M, &q_pesanan);

    return 0;
}