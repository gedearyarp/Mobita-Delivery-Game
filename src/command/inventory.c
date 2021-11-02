#include <stdio.h>
#include "../boolean.h"
#include "../inventory/inventory.h"

/*
kain pembungkus waktu: perlu ADT tas
senter pembesar: perlu ADT tas
pintu kemana saja: perlu ADT map
mesin waktu: gampang (done)
*/
void inventoryCommand(Inventory *I, int *waktu){
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

    removeGadget(I, numInv, &gadget);

}