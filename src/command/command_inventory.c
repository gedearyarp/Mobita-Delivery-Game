#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/list_linked/list_linked.h"
#include "command_inventory.h"
#include "../inventory/inventory.h"
#include "../tas/tas.h"
#include "../pesanan/pesanan.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../konfigurasi/konfigurasi.h"
#include "../ability/ability.h"
/*
kain pembungkus waktu: perlu ADT tas
senter pembesar: perlu ADT tas
pintu kemana saja: perlu ADT map
mesin waktu: gampang (done)
*/

void inventoryCommand(Inventory *I, int *waktu, Tas *tas, List *in_progress_list, MAP peta, POINT *user){
    printInventory(*I);
    printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
    
    int numInv, gadget;
    while(true){
        printf("ENTER COMMAND: ");
        advWord();
        numInv =ConvertInt(currentWord.contents,currentWord.length);
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
        int ada = 0, psnPerish = -1;
        for(int psn=currCAPACITY(*tas)-1; psn>=0; psn--){
            if(TYPE((*tas).buffer[psn]) == 'P'){
                psnPerish = psn;
                ada = 1;
                break;
            }
        }
        if(!ada){
            printf("Tidak ada Kain Pembungkus Waktu dalam tas!");
            return;
        }
        (*tas).buffer[psnPerish].tPick = *waktu;
        int now = 0;
        Address perish = FIRST(*in_progress_list);
        while(now != currCAPACITY(*tas)-psnPerish-1){
            perish = NEXT(perish);
            now ++;
        }
        INFO(perish).tPick = *waktu;
        printf("Kain Pembungkus Waktu berhasil digunakan!");
    }
    else if(INV(*I, numInv) == 2){
        if(currMaxCapacity(*tas) > 50) currMaxCapacity(*tas) = 100;
        else currMaxCapacity(*tas) *= 2;
        printf("Senter Pembesar berhasil digunakan!");
    }
    else if(INV(*I, numInv) == 3){
        int berhasil = 0;
        moveInv(peta, user, &berhasil);
        if(!berhasil) return;
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
