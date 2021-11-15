#include "ability.h"
#include "../ADT/boolean.h"
#include <stdio.h>

void speedBoost(int *waktu, int *speedBoostTime, boolean *speedBoostActive){
    if (*speedBoostActive){
        *speedBoostTime=*speedBoostTime+1;
        if (*speedBoostTime <=10){
            if ((*speedBoostTime%2) == 0){
                *waktu=*waktu+1;
            }
        }
        else{
            *speedBoostActive=false;
            *speedBoostTime=0;
            *waktu=*waktu+1;
        }
    }
    else{
        *waktu = *waktu+1;
    }
}

void increaseCapacity(Tas *tas){
    if (currMaxCapaxity(*tas)<MAXCAPACITY-1){
        currMaxCapaxity(*tas)=currMaxCapaxity(*tas)+1;
    }
}
