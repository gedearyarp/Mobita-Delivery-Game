#include "buy.h"

int main(){
    Inventory inv;
    Tas tas;
    int currTime=0, uang=1000, speedBoostTime=0;
    boolean speedBoostActive=false;
    Pesanan psn;
    MAP M;
    
    readFile(&M);
    CreateTas(&tas);
    inv=createInventory();
    startWord(); // isi dengan 7
    buyCommand(&uang, &inv, M, getUsersPoint(M));
}