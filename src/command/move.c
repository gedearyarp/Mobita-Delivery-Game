/* File: move.c */

#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "../ability/ability.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../konfigurasi/konfigurasi.h"

POINT getUsersPoint(MAP m){
/* mengembalikan point lokasi Mobita di awal
   yaitu headquarter/point pertama di map */
    /* KAMUS LOKAL */
    
    /* ALGORITMA */
    return m.loc[0];
}

int idxPOINT(MAP m, POINT p){
/* mengembalikan indeks point pada map dari point */
    /* KAMUS LOKAL */
    int i;
    boolean diff;
    /* ALGORITMA */
    diff = true;
    i = 0;
    // mencari indeks ke berapa p
    while (diff && (i < LengthMAP(m))){
        if (Label(p) == NAMA(m, i)){
            diff = false;
        }
        else{
            i++;
        }
    }
    // mengembalikan indeks, yaitu i
    return i;
}

POINT pointIdx(MAP m, int i){
/* mengembalikan point dari sebuah indeks */
    /* KAMUS LOKAL */

    /* ALGORITMA */
    return m.loc[i];
}

int duration(Tas tas){
/* mengembalikan waktu yang diperlukan untuk move
   bertambah 1 untuk tiap heavy item di tas */
    /* KAMUS LOKAL */
    int i, t;
    /* ALGORITMA */
    t = 1;
    if (TasIsEmpty(tas)){
        return t;
    }
    else{
        for (i = 0; i <= IDX_TAS(tas); i++){
            if (TYPE(tas.buffer[i]) == 'H'){
                t++;
            }
        }
        return t;
    }
}

void moveCommand(MAP m, int *waktu, Tas tas, POINT *user, boolean *speedBoostActive, int *speedBoostTime){
/* menyajikan titik mana saja yang dapat disinggahi dari posisi user,
   kemudian user memilih salah satu titik, lokasi user sekarang
   berpindah ke titik tersebut */
    /* KAMUS LOKAL */
    int i, j, k;
    int movablePoint[50];
    POINT p;
    /* ALGORITMA */
    // mencari indeks dari point user pada map
    i = idxPOINT(m, *user);
    // memasukkan semua indeks titik yang memiliki nilai 1 pada hub dengan indeks ke-i
    k = 0;
    for (j = 0; j <=LengthMAP(m); j++){
    	movablePoint[j] = -1;
        if (ELMT_M(m, i, j) == 1){
            movablePoint[k] = j;
            k++;
        }
    }
    // mencetak
    printf("Posisi yang dapat dicapai:\n");
    k = 0;
    while (movablePoint[k] != -1){
        j = movablePoint[k];
        if (j<=nEff(m))printf("%d. %c (%d,%d)\n", k + 1, NAMA(m, j), ABSIS(m, j), ORDINAT(m, j));
        k++;
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)");
    printf("\n");
    printf("ENTER COMMAND: ");
    advWord();
    k =ConvertInt(currentWord.contents,currentWord.length);
    printf("\n");
    // apabila posisi yang dipilih bukan 0, maka move akan dieksekusi
    if (k != 0){
        // ubah posisi user
        *user = m.loc[movablePoint[k - 1]];
        // ubah waktu
        if (duration(tas)!=1) {         // ada heavy item
            *speedBoostActive=false;
            *waktu += duration(tas);
        }
       else{
            speedBoost(waktu, speedBoostTime, speedBoostActive);    
        }
        // display
        printf("Mobita sekarang berada di titik %c (%d,%d)!", Label(*user), Absis(*user), Ordinat(*user));
    }
}

void moveInv(MAP m, POINT *user){
/* memindahkan user ke mana saja tanpa menambah waktu */
    /* KAMUS LOKAL */
    int i, n;
    int points[50];
    /* ALGORITMA */
    // mencetak tiap lokasi yang bisa disinggahi
    n = 0;
    for (i = 0; i < LengthMAP(m); i++){
        if (Label(*user) != NAMA(m, i)){
            points[n] = i;
            printf("%d. %c (%d,%d)\n", n + 1, NAMA(m, i), ABSIS(m, i), ORDINAT(m, i));
            n++;
        }
    }
    // input posisi yang ingin dipilih
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)");
    printf("\n");
    printf("ENTER COMMAND: ");
    advWord();
    n = ConvertInt(currentWord.contents, currentWord.length);
    printf("\n");
    // pindahkan user ke titik yang dipilih
    if (k != 0){
        *user = pointIdx(m, points[n - 1]);
        printf("Mobita sekarang berada di titik %c (%d,%d)!\n", Label(*user), Absis(*user), Ordinat(*user));
        printf("Pintu Kemana Saja berhasil digunakan!");
    }
}
