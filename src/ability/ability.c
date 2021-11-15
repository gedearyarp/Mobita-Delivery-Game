#include "ability.h"
#include "../ADT/boolean.h"
#include <stdio.h>

void speedBoost(int *waktu, int *speedBoostTime, boolean *speedBoostActive){
    if (*speedBoostActive==true){
        *speedBoostTime++;
        if (*speedBoostTime <=10){
            if ((*speedBoostTime%2) == 0){
                *waktu++;
            }
        }
        else{
            *speedBoostActive=false;
            *speedBoostTime=0;
        }
    }
    else{
        *waktu = *waktu+1;
    }
}

void increaseCapacity(Tas *tas){
    if (currCAPACITY(*tas)<MAXCAPACITY-1){
        currCAPACITY(*tas)++;
    }
}
