/* DRIVER IN PROGRESS */
#include <stdio.h>
#include "in_progress.h"
#include "to_do.h"
#include "../ADT/queue/queue.h"

// Compile
// gcc driver_in_progress.c in_progress.c ../ADT/queue/queue.c ../ADT/list_linked/node.c ../ADT/list_linked/list_linked.c ../ADT/point/point.c ../pesanan/pesanan.c ../tas/tas.c to_do.c -o driver_in_progress

int main() {
    /* KAMUS */
    Pesanan psn1,psn2,psn3,psn4;
    Pesanan val;
    Queue queue_pesanan;
    Tas tas;
    List to_do_list, in_progress_list;
    int currTime;
    int uncompleted = 0;
    
    /* ALGORITMA */
    // Inisialisasi pesanan, queue_pesanan, to_do_list, dan tas
    psn1 = createPesanan(1, 3, 8, 'G', 8, 6, 'N', 'N', T_UNDEF, T_UNDEF);     // t=1, G(3,8)->N(8,6), Normal
    psn2 = createPesanan(1, 8, 2, 'M', 1, 15, 'B', 'H', T_UNDEF, T_UNDEF);    // t=2, M(8,2)->B(1,15), Heavy
    psn3 = createPesanan(2, 10, 3, 'Q', 7, 10, 'L', 'V', T_UNDEF, T_UNDEF);   // t=2, Q(10,3)->L(7,10), VIP
    psn4 = createPesanan(3, 9, 13, 'P', 10, 3, 'Q', 'P', 5, T_UNDEF);        // t=3, P(9,13)->Q(10,3), Perishable(5)
    CreateQueue(&queue_pesanan);
    enqueue(&queue_pesanan, psn1);
    enqueue(&queue_pesanan, psn2);
    enqueue(&queue_pesanan, psn3);
    enqueue(&queue_pesanan, psn4);
    CreateList(&to_do_list);
    insertToDo(&to_do_list, &queue_pesanan, 3);
    CreateTas(&tas);

    // Inisialisasi in_progress_list
    currTime = 0;
    CreateList(&in_progress_list);
    in_progressCommand(in_progress_list, currTime);
    printf("\n");

    // Waktu = 5, pick_up pesanan psn4 (top of tas = psn4)
    currTime = 5;
    pushTas(&tas, psn4);
    deletePerishable(&in_progress_list,currTime, &uncompleted);
    updateInProgress(&in_progress_list, tas, 1, &currTime);
    in_progressCommand(in_progress_list, currTime);
    printf("\n");
    // Waktu = 7, pick up pesanan psn2 (top of tas = psn2) 
    currTime += 2;
    pushTas(&tas, psn2);
    deletePerishable(&in_progress_list,currTime, &uncompleted);
    updateInProgress(&in_progress_list, tas, 1, &currTime);
    in_progressCommand(in_progress_list, currTime);
    printf("\n");
    // Waktu = 11, hapus psn4 karena lewat batas waktu (top of stack = psn2)
    currTime += 4;
    deletePerishable(&in_progress_list,currTime, &uncompleted);
    in_progressCommand(in_progress_list, currTime);
    printf("\n");
    // Waktu = 12, drop off pesanan psn 2 (tas kosong)
    currTime += 1;
    deletePerishable(&in_progress_list,currTime, &uncompleted);
    updateInProgress(&in_progress_list, tas, 2, &currTime);
    in_progressCommand(in_progress_list, currTime);
    printf("\n");

    return 0;
}