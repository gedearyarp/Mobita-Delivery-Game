#include <stdio.h>
#include "boolean.h"
#include "inventory.h"

Inventory createInventory(){
    Inventory I;
    int i;
    for(i=0; i<6; i++){
        INV(I, i) = 0;
    }
    TOT_INV(I) = 0;
    return I;
}
/*
INDEX GADGET :
1 = Kain Pembungkus Waktu
2 = Senter Pembesar
3 = Pintu Kemana Saja
4 = Mesin Waktu
*/ 

void printInventory(Inventory I){
    int i;
    for(i=1; i<=5; i++){
        if(INV(I, i) == 0) printf("%d. -\n", i);
        else if (INV(I, i) == 1) printf("%d. Kain Pembungkus Waktu\n", i);
        else if (INV(I, i) == 2) printf("%d. Senter Pembesar\n", i);
        else if (INV(I, i) == 3) printf("%d. Pintu Kemana Saja\n", i);
        else if (INV(I, i) == 4) printf("%d. Mesin Waktu\n", i);
    }
}

void addGadget(Inventory *I, int idxGadget){
    if(idxGadget>4 || idxGadget<1){
        printf("Idx Gadget hanya 1 sampai 4.\n");
        return;
    }
    if(TOT_INV(*I) == 5){
        printf("Inventory penuh!\n");
        return;
    }
    TOT_INV(*I) ++;
    int i;
    for(i=1; i<=5; i++){
        if(INV(*I, i) == 0){
            INV(*I, i) = idxGadget;
            break;
        }
    }
}

void removeGadget(Inventory *I, int numInv, int *gadget){
    TOT_INV(*I) --;
    *gadget = INV(*I, numInv);
    INV(*I, numInv) = 0;
}
