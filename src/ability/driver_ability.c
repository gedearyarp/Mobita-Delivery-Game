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
    int currTime=0, uang=0, speedBoostTime=0;
    boolean speedBoostActive=false;
    Pesanan psn;
    Queue queue_pesanan;
    MAP M;
    
    readFile(&M);

    CreateQueue(&queue_pesanan);
    CreateTas(&tas);
    CreateList(&to_do_list);
    CreateList(&in_progress_list);

    MakePOINT(3,8, 'G');
    MakePOINT(8,6, 'N');

    pickUpCommand(&tas, G, &to_do_list, &in_progress_list, &currTime);
    drop_OffCommand(&tas, &in_progress_list, N, &uang, &currTime, &speedBoostTime, &speedBoostActive);
    printf("Current max tas capacity: %d", currMaxCapaxity(tas));
    for (int i=1; i<=10;i++){
        moveCommand(M, &currTime, tas, &P, &speedBoostActive, &speedBoostTime);
        printf("Waktu: %d", currTime);
    }
}