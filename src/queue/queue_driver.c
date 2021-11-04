/* File: pesanan_driver.c */
/* *** Driver ABSTRACT DATA TYPE Pesanan *** */

/* Note:
    Compile:    gcc pesanan.c pesanan_driver.c ../point/point.c -o d_pesanan
*/

#include <stdio.h>
#include "queue.h"

int main () {
    /* KAMUS */
    Queue q1;
    Pesanan p1, p2, temp;

    /* ALGORITMA */
    p1 = createPesanan(1, 3, 8, 'G', 8, 6, 'N', 'N', T_UNDEF, T_UNDEF);     // t=1, G(3,8)->N(8,6), Normal
    p2 = createPesanan(2, 8, 2, 'M', 1, 15, 'B', 'H', T_UNDEF, T_UNDEF);    // t=2, M(8,2)->B(1,15), Heavy
    
    // PEMBUATAN QUEUE KOSONG DAN DISPLAY QUEUE
    CreateQueue(&q1);
    displayQueue(q1); printf("\n");


    // TEST LIST KOSONG ATAU PENUH
    if (isEmptyQ(q1)) printf("Queue kosong.\n");
    else printf("Queue tidak kosong.\n");

    if (isFullQ(q1)) printf("Queue penuh.\n");
    else printf("Queue tidak penuh.\n");


    // PRIMITIF ADD ELEMENT
    enqueue(&q1, p1);   displayQueue(q1); printf("\n");
    enqueue(&q1, p2);   displayQueue(q1); printf("\n");


    // PANJANG QUEUE
    printf("Panjang q1 = %d\n", lengthQ(q1));


    // PRIMITIF DELETE ELEMENT
    dequeue(&q1, &temp);    displayQueue(q1); printf("\n");
    dequeue(&q1, &temp);    displayQueue(q1); printf("\n");

    return 0;
}