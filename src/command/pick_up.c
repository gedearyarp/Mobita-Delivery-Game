#include "pick_up.h"

// BIKIN hapus to do list dan pickup utk jenis tertentu
void pickUpCommand(Tas *Tas, POINT P, List *to_do_list, List *in_progress_list, int *currTime){
    Address q;
    int ctr;
    Pesanan val;
    boolean found;
    q=FIRST(*to_do_list);
    ctr=0;
    found=false;
    while (!found && q!=NULL){
        if (EQ(P, PICK_P(INFO(q)))){
            found=true;
        }
        else{
            q=NEXT(q);
            ctr++;
        }
    }

    if (found){
        if (currCAPACITY(*Tas)<currMaxCapaxity(*Tas)){
            pushTas(Tas, INFO(q));
            T_PICK(INFO(q))=*currTime;
            updateInProgress (in_progress_list, *Tas, 1, currTime);
            deleteAt(to_do_list, ctr, &val);
            printf("Pesanan berupa ");
            switch(TYPE(TOP_TAS(*Tas))){
                case 'N': printf("Normal Item"); break;
                case 'H': printf("Heavy Item"); break;
                case 'P':printf("Perishable Item"); break;
                default: break;
            }
            printf(" berhasil diambil!\n");
            printf("Tujuan Pesanan: %c\n", Label(DROP_P(TOP_TAS(*Tas))));
        }
        else{
            printf("Tas sudah penuh, tidak bisa mengambil pesanan!\n");
        }
    }
    else {
        printf("Pesanan tidak ditemukan!\n");
    }
}

    
