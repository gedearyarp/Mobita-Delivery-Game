/* File: inventory.h */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef INVENTORYCMD_H
#define INVENTORYCMD_H

#include "../ADT/boolean.h"
#include "../list_linked/list_linked.h"
#include "../inventory/inventory.h"
#include "../tas/tas.h"
#include "../pesanan/pesanan.h"

void inventoryCommand(Inventory *I, int *waktu, Tas *tas, List *in_progress_list);

#endif


