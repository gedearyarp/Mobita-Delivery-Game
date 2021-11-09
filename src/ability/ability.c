#include "ability.h"
#include "../ADT/boolean.h"
#include <stdio.h>

void speedBoost(int *waktu, int *speedBoostTime, boolean *speedBoostActive){
    if (speedBoostActive){
        speedBoostTime++;
        if (*speedBoostTime <=10){
            if ((*speedBoostTime % 2) == 0){
                waktu++;
            }
        }
        else{
            *speedBoostActive=false;
            *speedBoostTime=-1;
        }
    }
    else{
        waktu++;
    }
}
