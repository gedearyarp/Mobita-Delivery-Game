#include "ability.h"

speedBoost(int *waktu, int *speedBoostTime, boolean *speedBoostActive){
    if (*speedBoostActive){
        *speedBoostTime++;
        if (*speedBoostTime <=10){
            if ((*speedBoostTime mod 2) == 0){
                *waktu++;
            }
        }
        else{
            *speedBoostActive=false;
            *speedBoostTime=IDX_UNDEF;
        }
    }
    else{
        *waktu++;
    }
}