/* File: point_driver.c */
/* *** Driver ABSTRACT DATA TYPE POINT *** */

/* Note:
    Compile:
    gcc driver_point.c point.c -o driver_point
*/

#include <stdio.h>
#include "point.h"

int main () {
    /* KAMUS */
    POINT P1, P2;

    /* ALGORITMA */
    /* *** Konstruktor membentuk POINT *** */
    P1 = MakePOINT(1,2,'A');

    /* *** Kelompok interaksi dengan I/O device, BACA/TULIS  *** */
    printf("Point pertama (P1): ");
    TulisPOINT(P1);
    printf("\nMasukkan point kedua (P2) dengan format x<spasi>y<spasi>label: ");
    BacaPOINT(&P2);
    printf("Point kedua (P2): ");
    TulisPOINT(P2);
    
    /* *** Kelompok operasi relasional terhadap POINT *** */
    if (EQ(P1, P2)) printf("\nPoint 1 dan point 2 sama (EQ)");
    if (NEQ(P1, P2)) printf("\nPoint 1 dan point 2 berbeda (NEQ)");

    /* *** Kelompok menentukan di mana P berada *** */
    if (IsOnSbX(P2)) printf("\nPoint 2 ada di sumbu x (IsOnSbX)");
    if (IsOnSbY(P2)) printf("\nPoint 2 ada di sumbu y (IsOnSbY");
    if (IsOrigin(P2)) printf("\nPoint 2 ada di origin (IsOrigin");
    else printf("\nPoint 2 ada di kuadran %d", Kuadran(P2));

    /* *** Kelompok operasi lain terhadap POINT *** */
    printf("\nJika P1=(1,2) digeser 1 satuan ke kanan, koordinatnya menjadi: ");
    TulisPOINT(NextX(P1));
    printf("\nJika P1=(1,2) digeser 1 satuan ke atas, koordinatnya menjadi: ");
    TulisPOINT(NextY(P1));
    printf("\nJika P1=(1,2) digeser 2 satuan ke kanan dan 2 satuan ke atas, koordinatnya menjadi: ");
    TulisPOINT(PlusDelta(P1, 2, 2));
    printf("\nJika P1=(1,2) dicerminkan terhadap sumbu x, koordinatnya menjadi: ");
    TulisPOINT(MirrorOf(P1, true));
    printf("\nJika P1=(1,2) dicerminkan terhadap sumbu y, koordinatnya menjadi: ");
    TulisPOINT(MirrorOf(P1, false));
    
    printf("\nKoordinat P2 saat ini adalah ");
    TulisPOINT(P2);
    
    printf("\nJarak P2 ke origin adalah %f satuan", Jarak0(P2));
    printf("\nPanjang garis dari P1 ke P2 adalah %f satuan", Panjang(P1,P2));

    printf("\n1) P2 akan digeser ke sumbu x. Hasilnya P2=");
    GeserKeSbX(&P2); TulisPOINT(P2);
    printf("\n2) P2 akan ditranslasi sebesar (1,3). Hasilnya P2=");
    Geser(&P2,1,3); TulisPOINT(P2);
    printf("\n3) P2 akan digeser ke sumbu y. Hasilnya P2=");
    GeserKeSbY(&P2); TulisPOINT(P2);
    printf("\n4) P2 akan ditranslasi sebesar (4,2). Hasilnya P2=");
    Geser(&P2,4,2); TulisPOINT(P2);
    printf("\n5) P2 akan dicerminkan terhadap sumbu x. Hasilnya P2=");
    Mirror(&P2, true); TulisPOINT(P2);
    printf("\n6) P2 akan dicerminkan terhadap sumbu y. Hasilnya P2=");
    Mirror(&P2, false); TulisPOINT(P2);
    printf("\n7) P2 akan dirotasi 60 derajat searah arah jarum jam. Hasilnya P2=");
    Putar(&P2, 60); TulisPOINT(P2);

    return 0;
}