/* File: drop_off.h */
/* *** Definisi COMMAND IN_PROGRESS *** */

#ifndef DROP_OFF_H
#define DROP_OFF_H

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../tas/tas.h"
#include "../point/point.h"

void drop_OffCommand(Tas *Tas, POINT p, int *uang);
/* Prosedur untuk drop off jika drop location barang paling atas di tas sama dengan lokasi user. 
    Jika tidak sama, tidak akan di drop off */

#endif