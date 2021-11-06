#include "../tas/tas.h"
#include "../list_linked/list_linked.h"
#include "../point/point.h"
// BIKIN hapus to do list dan pickup utk jenis tertentu
void pickUpCommand(Stack *Tas, POINT P, List *to_do_list, List *in_progress_list, int curr_time, float *time_incr, int *cap_incr, int *uncompleted){
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
        push(Tas, INFO(q));
        updateInProgress (in_progress_list, Tas, 0, curr_time, time_incr, cap_incr, uncompleted);
        deleteAt(to_do_list, ctr, &val);
        printf("Pesanan berupa ");
        switch(TYPE(TOP(*Tas)) == 'H'){
            case 'N': printf("Normal Item"); break;
            case 'H': printf("Heavy Item"); break;
            case 'P':printf("Perishable Item"); break;
            default: break;
        }
        printf(" berhasil diambil!\n");
        printf("Tujuan Pesanan: %c", label(DROP_P(TOP(*Tas))));
    }
    else {
        printf("Pesanan tidak ditemukan!");
    }
}

    