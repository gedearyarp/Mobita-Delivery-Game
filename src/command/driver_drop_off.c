#include "drop_off.h"
#include "in_progress.h"
#include "../ADT/queue/queue.h"
int main(){

    Tas tas;
    List to_do_list, in_progress_list;
    POINT X, Y;
    int currTime=1;
    int speedBoostTime = 0;
    int uang = 0;
    boolean speedBoostActive = false;
    Pesanan psn1,psn2,psn3,psn4;
    Queue queue_pesanan;

    CreateQueue(&queue_pesanan);
    CreateTas(&tas);
    CreateList(&to_do_list);
    CreateList(&in_progress_list);

    Y=MakePOINT(3,4,'Y');
    X=MakePOINT(1,2,'X');

    psn1=createPesanan(1, 1, 2, 'X', 5, 6, 'A', 'V', -1, 1);
    psn2=createPesanan(1, 1, 2, 'X', 7, 8, 'B', 'P', 20, 1);
    psn3=createPesanan(1, 1, 2, 'X', 9, 10, 'C', 'H', -1, 1);
    psn4=createPesanan(1, 1, 2, 'X', 11, 12, 'D', 'N', -1, 1);

    /* Pengiriman barang gagal jika tidak ada barang di tas */
    drop_OffCommand(&tas,&in_progress_list,X,&uang,currTime,&speedBoostTime,&speedBoostActive);

    pushTas(&tas, psn1);
    updateInProgress(&in_progress_list, tas, 1, &currTime);
    pushTas(&tas, psn2);
    updateInProgress(&in_progress_list, tas, 1, &currTime);
    pushTas(&tas, psn3);
    updateInProgress(&in_progress_list, tas, 1, &currTime);
    pushTas(&tas, psn4);
    updateInProgress(&in_progress_list, tas, 1, &currTime);

    /* Pengiriman barang gagal jika tidak ada barang yang dapat dikirim di lokasi */
    drop_OffCommand(&tas,&in_progress_list,Y,&uang,currTime,&speedBoostTime,&speedBoostActive);

    /* Pengriman 4 barang yang ada di tas */
    drop_OffCommand(&tas,&in_progress_list,X,&uang,currTime,&speedBoostTime,&speedBoostActive);
    printf("uang = %d, speedboost = %d\n", uang, speedBoostActive);

    drop_OffCommand(&tas,&in_progress_list,X,&uang,currTime,&speedBoostTime,&speedBoostActive);
    printf("uang = %d, speedboost = %d\n", uang, speedBoostActive);

    drop_OffCommand(&tas,&in_progress_list,X,&uang,currTime,&speedBoostTime,&speedBoostActive);
    printf("uang = %d, speedboost = %d\n", uang, speedBoostActive);

    drop_OffCommand(&tas,&in_progress_list,X,&uang,currTime,&speedBoostTime,&speedBoostActive);
    printf("uang = %d, speedboost = %d\n", uang, speedBoostActive);

    return 0;
}
