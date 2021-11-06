#include <stdio.h>
#include "../ADT/boolean.h"
#include "../inventory/inventory.h"
#include "../tas/tas.h"

/*
kain pembungkus waktu: perlu ADT tas
senter pembesar: perlu ADT tas
pintu kemana saja: perlu ADT map
mesin waktu: gampang (done)
*/

void inventoryCommand(Inventory *I, int *waktu, Stack *tas){
    printInventory(*I);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    
    int numInv, gadget;
    while(true){
        printf("ENTER COMMAND: ");
        scanf("%d", &numInv);
        if(numInv >= 0 && numInv <= 5){
            break;
        } 
        printf("Pilihan hanya 0 sampai 5!\n");
    }
    if (numInv == 0) return;

    if(INV(*I, numInv) == 0){
        printf("Tidak ada Gadget yang dapat digunakan!");
        return;
    }
    else if(INV(*I, numInv) == 1){
        printf("Kain Pembungkus Waktu berhasil digunakan!");
    }
    else if(INV(*I, numInv) == 2){
        if(currCAPACITY(*tas) > 50) currCAPACITY(*tas) = 100;
        else currCAPACITY(*tas) *= 2;
        printf("Senter Pembesar berhasil digunakan!");
    }
    else if(INV(*I, numInv) == 3){
        printf("Pintu Kemana Saja berhasil digunakan!");
    }
    else if(INV(*I, numInv) == 4){
        if(*waktu >= 50) *waktu -= 50;
        else *waktu = 0;
        printf("Mesin Waktu digunakan!");
    }
    else{
        printf("error detected.");
    }
    INV(*I, numInv) = 0;
    removeGadget(I, numInv, &gadget);

}