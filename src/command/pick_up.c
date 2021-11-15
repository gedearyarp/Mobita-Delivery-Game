#include "pick_up.h"
#include "to_do.h"
#include "../ADT/point/point.h"
#include "in_progress.h"
#include <stdio.h>
// BIKIN hapus to do list dan pickup utk jenis tertentu
void pickUpCommand(Tas *Tas, POINT P, List *to_do_list, List *in_progress_list){
    Address q;
    int ctr;
    Pesanan val;
    q=FIRST(*to_do_list);
    ctr=0;
    while (!EQ(P, PICK_P(INFO(q))) && q!=NULL){
        q=NEXT(q);
        ctr++;
    }
    if (EQ(P, PICK_P(INFO(q)))){
        pushTas(Tas, INFO(q));
        updateInProgress (in_progress_list, *Tas, 1);
        deleteAt(to_do_list, ctr, &val);
        printf("Pesanan berupa ");
        switch(TYPE(TOP_TAS(*Tas))){
            case 'N': printf("Normal Item"); break;
            case 'H': printf("Heavy Item"); break;
            case 'P':printf("Perishable Item"); break;
            default: break;
        }
        printf(" berhasil diambil!\n");
        printf("Tujuan Pesanan: %c", Label(DROP_P(TOP_TAS(*Tas))));
    }
    else {
        printf("Pesanan tidak ditemukan!");
    }
}

    
