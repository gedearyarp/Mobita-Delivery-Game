#include "inventory.h"
#include "inventory.c"
#include <stdio.h>

/*
INDEX GADGET :
1 = Kain Pembungkus Waktu
2 = Senter Pembesar
3 = Pintu Kemana Saja
4 = Mesin Waktu
*/ 

int main(){
	Inventory inv = createInventory();
    int gdt;
    addGadget(&inv, 1);
    addGadget(&inv, 4);
    addGadget(&inv, 5);
    addGadget(&inv, 2);
    addGadget(&inv, 4);
    addGadget(&inv, 8);
    addGadget(&inv, 1);
    addGadget(&inv, 1);
    addGadget(&inv, 1);
    removeGadget(&inv, 2, &gdt);
    removeGadget(&inv, 4, &gdt);
    removeGadget(&inv, 2, &gdt);
    printInventory(inv);
}
