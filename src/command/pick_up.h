#ifndef PICKUP_H
#define PICKUP_H

#include "../tas/tas.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"

void pickUpCommand(Tas *Tas, POINT P, List *to_do_list, List *in_progress_list);

#endif
