#ifndef INVENTORY_H
#define INVENTORY_H

#include "boolean.h"

typedef struct {
    int gadget[6];
    int total;
} Inventory;

#define INV(I, n) (I).gadget[n]
#define TOT_INV(I) (I).total

Inventory createInventory();

void printInvetory(Inventory I);

void addGadget(Inventory *I, int idxGadget);

void removeGadget(Inventory *I);


#endif