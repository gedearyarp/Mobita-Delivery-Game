#ifndef PICKUP_H
#define PICKUP_H

#include "../tas/tas.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include "to_do.h"
#include "../ADT/point/point.h"
#include "in_progress.h"
#include <stdio.h>

void pickUpCommand(Tas *Tas, POINT P, List *to_do_list, List *in_progress_list, int *currTime);

#endif
