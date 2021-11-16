#include "ability.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/queue/queue.h"
#include "../command/pick_up.h"
#include "../command/drop_off.h"
#include "../konfigurasi/konfigurasi.h"
#include "../command/move.h"
#include <stdio.h>

int main(){
    Tas tas;
    List to_do_list, in_progress_list;
    POINT P, G,N;
    int currTime=1, uang=0, speedBoostTime=0;
    boolean speedBoostActive=false;
    Pesanan psn;
    Queue queue_pesanan;
    MAP M;
    
    readFile(&M);

    CreateQueue(&queue_pesanan);
    CreateTas(&tas);
    CreateList(&to_do_list);
    CreateList(&in_progress_list);

    G=MakePOINT(3,8, 'G');
    N=MakePOINT(8,6, 'N');
    QueuePesanan(M, &queue_pesanan);
    displayQueue(queue_pesanan);
    insertToDo(&to_do_list, &queue_pesanan, currTime);

    pickUpCommand(&tas, G, &to_do_list, &in_progress_list, &currTime);
    drop_OffCommand(&tas, &in_progress_list, N, &uang, currTime, &speedBoostTime, &speedBoostActive);
    printf("Current max tas capacity: %d\n", currMaxCapaxity(tas));
    startWord(); // isi dengan 1
    printf("\n");
    for (int i=1; i<=12;i++){
        moveCommand(M, &currTime, tas, &G, &speedBoostActive, &speedBoostTime);
        printf("Waktu: %d\n", currTime);
    }
    // speedboostactive akan berhenti pada interasi ke i=10
}

// to run: 
// 1. cd src
// 2. ./driver_ability