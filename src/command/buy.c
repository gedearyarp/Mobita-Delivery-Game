#include <stdio.h>
#include "../ADT/boolean.h"
#include "buy.h"
#include "../inventory/inventory.h"

void buyCommand(int *uang, Inventory *I){
    printf("Uang Anda sekarang: %d Yen\n", uang);
    printf("Gadget yang tersedia\n");
    printf("1. Kain Pembungkus Waktu (800yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");

    /*
    INDEX GADGET :
    1 = Kain Pembungkus Waktu
    2 = Senter Pembesar
    3 = Pintu Kemana Saja
    4 = Mesin Waktu
    */

    int gadget, hargaGadget[5] = { 0, 800, 1200, 1500, 3000 };
    while(true){
        printf("ENTER COMMAND: ");
        scanf("%d", &gadget);
        if(gadget >= 0 && gadget <= 4){
            break;
        }
        printf("Pilihan hanya 0 sampai 4!\n");
    }

    if (gadget == 0) return;

    if(TOT_INV(*I) >= 5){
        printf("Inventory sudah penuh!");
        return;
    }

    if(*uang < hargaGadget[gadget]){
        printf("Uang tidak cukup untuk membeli gadget!\n");
        return;
    }
    *uang -= hargaGadget[gadget];
    addGadget(I, gadget);
    if (gadget == 1) printf("Kain Pembungkus Waktu berhasil dibeli!\n");
    else if (gadget == 2) printf("Senter Pembesar berhasil dibeli!\n");
    else if (gadget == 3) printf("Pintu Kemana Saja berhasil dibeli!\n");
    else if (gadget == 4){ printf("Mesin Waktu berhasil dibeli!\n");
    printf("Uang Anda sekarang: %d Yen\n", *uang);
}
