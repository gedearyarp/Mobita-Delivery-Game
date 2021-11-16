#include "move.h"

int main(){
    /* KAMUS LOKAL */
    Tas tas;
    int time, speedBoostTime, i, j, command;
    boolean speedBoostActive, finish;
    MAP m;
    POINT user;
    Pesanan p;
    
    /* ALGORITMA */
////// buat setting
    // buat map
    readFile(&m);
    // deklarasi
    speedBoostTime = 0;
    speedBoostActive = false;
    CreateTas(&tas);
    time = 0;
    user = getUsersPoint(m);
    finish = false;
    startWord();
    while (!finish){
        printf("\nWaktu: %d\n", time);
        printf("Lokasi: (%d,%d)\n", Absis(user), Ordinat(user));
        printf("1. MOVE\n");
        printf("2. FINISH\n");
        printf("3. TELEPORT\n");
        printf("4. ISI HEAVY\n");
        if (!TasIsEmpty(tas)){
            printf("5. BUANG HEAVY\n");
        }
        advWord();
        command = ConvertInt(currentWord.contents, currentWord.length);
        if (command == 1){
            moveCommand(m, &time, tas, &user, &speedBoostActive, &speedBoostTime);
        }
        else if (command == 2){
            finish = true;
        }
        else if (command == 3){
            moveInv(m, &user, &i);
        }
        else if (command == 4){
            p = createPesanan(time, 1, 1, 'a', 2, 2, 'b', 'H', 1, 1);
            pushTas(&tas, p);
        }
        else if (command == 5){
            popTas(&tas, &p);
        }
    }   
}