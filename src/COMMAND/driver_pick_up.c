#include "pick_up.h"
#include "../ADT/queue/queue.h"
int main(){
    Tas tas;
    List to_do_list, in_progress_list;
    POINT X, Y;
    int currTime=1;
    Pesanan psn1,psn2,psn3,psn4;
    Queue queue_pesanan;

    CreateQueue(&queue_pesanan);
    CreateTas(&tas);
    CreateList(&to_do_list);
    CreateList(&in_progress_list);

    Y=MakePOINT(3,4,'Y');
    X=MakePOINT(1,2,'X');

    psn1=createPesanan(1, 1, 2, 'X', 5, 6, 'A', 'N', -1, 1);
    psn2=createPesanan(1, 1, 2, 'X', 7, 8, 'B', 'N', -1, 1);
    psn3=createPesanan(1, 1, 2, 'X', 9, 10, 'C', 'N', -1, 1);
    psn4=createPesanan(1, 1, 2, 'X', 11, 12, 'D', 'N', -1, 1);

    // masukkan pesanan pada to do list
    enqueue(&queue_pesanan, psn1);
    enqueue(&queue_pesanan, psn2);
    enqueue(&queue_pesanan, psn3);
    enqueue(&queue_pesanan, psn4);

    insertToDo(&to_do_list, &queue_pesanan, currTime);
    insertToDo(&to_do_list, &queue_pesanan, currTime);
    insertToDo(&to_do_list, &queue_pesanan, currTime);
    insertToDo(&to_do_list, &queue_pesanan, currTime);

    // gagal karena tidak ada item pada list
    pickUpCommand(&tas, Y, &to_do_list, &in_progress_list, &currTime);

    // berhasil
    pickUpCommand(&tas, X, &to_do_list, &in_progress_list, &currTime);
    pickUpCommand(&tas, X, &to_do_list, &in_progress_list, &currTime);
    pickUpCommand(&tas, X, &to_do_list, &in_progress_list, &currTime);

    // gagal karena tas sudah penuh
    pickUpCommand(&tas, X, &to_do_list, &in_progress_list, &currTime);
}

// to run: 
// 1. cd src
// 2. ./driver_pick_up