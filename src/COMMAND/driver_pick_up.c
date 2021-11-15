#include "pick_up.h"

int main(){
    Tas tas;
    List to_do_list, in_progress_list;
    POINT X, Y;
    int currTime=0;
    Pesanan psn;
    Queue queue_pesanan;

    CreateQueue(&queue_pesanan);
    CreateTas(&tas);
    CreateList(&to_do_list);
    CreateList(&in_progress_list);

    MakePOINT(3,4,'X');
    MakePOINT(1,2,'Y');

    psn=createPesanan(1, 1, 2, 'A', 3, 4, 'B', 'N', -1, -1);

    enqueue(&queue_pesanan, psn);
    insertToDo(&to_do_list, &queue_pesanan, currTime);
    pickUpCommand(&tas, X, &to_do_list, &in_progress_list, &currTime);

    enqueue(&queue_pesanan, psn);
    insertToDo(&to_do_list, &queue_pesanan, currTime);
    pickUpCommand(&tas, Y, &to_do_list, &in_progress_list, &currTime);
}