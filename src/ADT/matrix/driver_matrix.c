#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix m;
    int bar,kol,maks,mins;
    scanf("%d", &bar);
    scanf("%d", &kol);
    CreateMatrix(bar, kol, &m);
    readMatrix(&m, bar, kol);
    int k=1;
    printf("%d\n", isIdxValid(100,100));
    printf("lastRow: %d lastCol: %d\n", getLastIdxRow(m), getLastIdxCol(m));
    printf("%d\n", isIdxEff(m, 2,4));
    transpose(&m);
    displayMatrix(m);
    printf("det: %d\n", determinant(m));
    pInverse1(&m);
    displayMatrix(m);
}