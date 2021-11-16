#include "tas.h"
#include <stdio.h>

int main(){
    Tas tas;
    Pesanan psn1,psn2, temp;
    psn1=createPesanan(1, 1, 2, 'X', 5, 6, 'A', 'N', -1, 1);
    psn2=createPesanan(1, 1, 2, 'X', 7, 8, 'B', 'N', -1, 1);
    CreateTas(&tas);
    printf("%d", TasIsEmpty(tas));
    pushTas(&tas, psn1);
    pop(&tas, &temp);
    push(&tas, psn2);
    printf("curr cap: %d, curr max cap: %d", currCAPACITY(tas), currMaxCapacity(tas));
}