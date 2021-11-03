/* File: move.c */

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../point/point.h"
#include "../konfigurasi/konfigurasi.h"

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

void move(MAP m, POINT *user){
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
    for (j = 0; j < LengthMAP(m); j++){
        if (ELMT_M(m, i, j) == 1){
            movablePoint[k] = j;
            k++;
        }
    }
    // mencetak
    printf("Posisi yang dapat dicapai:\n");
    k = 0;
    while (movablePoint[k] != 0){
        j = movablePoint[k];
        printf("%d. %c (%d,%d)\n", k + 1, NAMA(m, j), ABSIS(m, j), ORDINAT(m, j));
    }
    printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)");
    printf("\n");
    printf("ENTER COMMAND: ");
    scanf("%d", &k);
    printf("\n");
    // ubah posisi user
    *user = m.loc[movablePoint[k - 1]];
    printf("Mobita sekarang berada di titik %c (%d,%d)!", Label(*user), Absis(*user), Ordinat(*user));
}

/* ***
