#include "../stack/stack.h"
#include "../list_linked/list_linked.h"
#include "../point/point.h"

void pick_up(Stack *Tas, POINT P, List *to_do_list, List *in_progress_list, int curr_time, float *time_incr, int *cap_incr, int *uncompleted){
    Address q;
    q=FIRST(*to_do_list);
    while (!EQ(P, PICK_P(INFO(q))) && q!=NULL){
        q=NEXT(q);
    }
    if (EQ(P, PICK_P(INFO(q)))){
        push(Tas, INFO(q));
        updateInProgress (in_progress_list, *Tas, 0, curr_time, *time_incr, *cap_incr, *uncompleted);
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

    