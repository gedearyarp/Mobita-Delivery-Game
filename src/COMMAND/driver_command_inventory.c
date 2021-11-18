#include "command_inventory.h"
#include "buy.h"

int main(){
    Inventory inv;
    Tas tas;
    int currTime=0, uang=5000, speedBoostTime=0;
    boolean speedBoostActive=false;
    Pesanan psn;
    MAP M;
    List in_progress_list;
    POINT user;

    CreateList(&in_progress_list);
    readFile(&M);
    CreateTas(&tas);
    inv=createInventory();
    startWord(); // isi dengan 7
    buyCommand(&uang, &inv, M, getUsersPoint(M));

    inventoryCommand(&inv, &currTime, &tas, &in_progress_list,M, &user);
}