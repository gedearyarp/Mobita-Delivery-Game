/* File: pesanan_driver.c */
/* *** Driver ABSTRACT DATA TYPE Pesanan *** */

/* Note:
    Compile:    gcc pesanan.c pesanan_driver.c ../point/point.c -o pesanan_d
*/

#include <stdio.h>
#include "pesanan.h"

int main () {
    /* KAMUS */
    Pesanan p1, p2, p3;

    /* ALGORITMA */
    p1 = createPesanan(1, 3, 8, 'G', 8, 6, 'N', 'N', T_UNDEF, T_UNDEF);      // t=1, G(3,8)->N(8,6), Normal
    p2 = createPesanan(10, 9, 13, 'P', 10, 3, 'Q', 'P', 20, T_UNDEF);        // t=10, P(9,13)->Q(10,3), Perishable(20)
    p3 = p1;

    displayPesanan(p1); printf("\n");
    
    if (isPesananEqual(p1, p2)) printf("Pesanan 1 = Pesanan 2\n");
    else printf("Pesanan 1 != Pesanan 2\n");

    return 0;
}