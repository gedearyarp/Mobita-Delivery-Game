/* DRIVER TO_DO */
#include <stdio.h>
#include "to_do.h"

// Compile: 
// gcc to_do.c to_do_driver.c ../ADT/queue/queue.c ../ADT/list_linked/list_linked.c ../ADT/list_linked/node.c ../pesanan/pesanan.c ../ADT/point/point.c -o driver

int main() {
    /* KAMUS */
    Pesanan psn1,psn2,psn3,psn4;
    Pesanan val;
    List to_do_list;
    Queue queue_pesanan;
    int currTime;
    int idx;
    
    /* ALGORITMA */
    // Inisialisasi pesanan dan queue pesanan
    psn1 = createPesanan(1, 3, 8, 'G', 8, 6, 'N', 'N', T_UNDEF, T_UNDEF);     // t=1, G(3,8)->N(8,6), Normal
    psn2 = createPesanan(1, 8, 2, 'M', 1, 15, 'B', 'H', T_UNDEF, T_UNDEF);    // t=2, M(8,2)->B(1,15), Heavy
    psn3 = createPesanan(2, 10, 3, 'Q', 7, 10, 'L', 'V', T_UNDEF, T_UNDEF);   // t=2, Q(10,3)->L(7,10), VIP
    psn4 = createPesanan(3, 9, 13, 'P', 10, 3, 'Q', 'P', 20, T_UNDEF);        // t=3, P(9,13)->Q(10,3), Perishable(20)
    CreateQueue(&queue_pesanan);
    enqueue(&queue_pesanan, psn1);
    enqueue(&queue_pesanan, psn2);
    enqueue(&queue_pesanan, psn3);
    enqueue(&queue_pesanan, psn4);

    // Inisialisasi to_do_list
    currTime = 0;
    CreateList(&to_do_list);
    to_doCommand(to_do_list, currTime);
    printf("\n");

    // Insert to do list (t = 1): add psn 1,2
    currTime = 1;
    insertToDo(&to_do_list, &queue_pesanan, currTime);
    to_doCommand(to_do_list, currTime);
    printf("\n");
    
    // Insert to do list (t = 3): add psn 3,4
    currTime = 3;
    insertToDo(&to_do_list, &queue_pesanan, currTime);
    to_doCommand(to_do_list, currTime);
    printf("\n");
    
    // Delete to do list: del psn 3 (idx = 2)
    deleteToDo(&to_do_list, 2, &val);
    to_doCommand(to_do_list, currTime);
    printf("\n");
    
    return 0;
}