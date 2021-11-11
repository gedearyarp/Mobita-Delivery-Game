/* File: move.h */

#ifndef MOVE_H
#define MOVE_H

#include <stdio.h>
#include <stdlib.h>
#include "../ADT/boolean.h"
#include "../ADT/point/point.h"
#include "../konfigurasi/konfigurasi.h"
#include "../tas/tas.h"

int idxPOINT(MAP m, POINT p);
/* mengembalikan indeks point pada map dari point */

POINT pointIdx(MAP m, int i);
/* mengembalikan point dari sebuah indeks */

int duration(Tas tas);
/* mengembalikan waktu yang diperlukan untuk move
   bertambah 1 untuk tiap heavy item di tas */

void moveCommand(MAP m, int *waktu, Tas tas, POINT *user, boolean *speedBoostActive, int *speedBoostTime);
/* menyajikan titik mana saja yang dapat disinggahi dari posisi user,
   kemudian user memilih salah satu titik, lokasi user sekarang
   berpindah ke titik tersebut */

void moveInv(MAP m, POINT *user);
/* memindahkan user ke mana saja tanpa menambah waktu */

#endif // MOVE_H
