/* File: drop_off.h */
/* *** Definisi COMMAND IN_PROGRESS *** */

#ifndef DROP_OFF_H
#define DROP_OFF_H

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../tas/tas.h"
#include "../ADT/point/point.h"
#include "../ability/ability.h"
#include "../ADT/list_linked/node.h"
#include "../ADT/list_linked/list_linked.h"

void drop_OffCommand(Tas *Tas, List *in_progress_list, POINT p, int *uang, int currTime, int *speedBoostTime, boolean *speedBoostActive);/* Prosedur untuk drop off jika drop location barang paling atas di tas sama dengan lokasi user. 
    Jika tidak sama, tidak akan di drop off */

#endif
