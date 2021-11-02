/* File: driver_list_linked.c */
/* FILE DRIVER ADT LINKED LIST */

/* Note: 
    Compile:     gcc list_linked.c list_linked_driver.c node.c ../pesanan/pesanan.c ../point/point.c -o d_list_linked
*/

#include <stdio.h>
#include "list_linked.h"

int main () {
    /* KAMUS */
    List l1, l2, l3, l4, l5, l6;
    Pesanan p1, p2, p3, p4, temp;
    Address loc1, loc2;

    /* ALGORITMA */
    p1 = createPesanan(1, 3, 8, 'G', 8, 6, 'N', 'N', T_UNDEF, T_UNDEF);     // t=1, G(3,8)->N(8,6), Normal
    p2 = createPesanan(2, 8, 2, 'M', 1, 15, 'B', 'H', T_UNDEF, T_UNDEF);    // t=2, M(8,2)->B(1,15), Heavy
    p3 = createPesanan(9, 10, 3, 'Q', 7, 10, 'L', 'V', T_UNDEF, T_UNDEF);   // t=9, Q(10,3)->L(7,10), VIP
    p4 = createPesanan(10, 9, 13, 'P', 10, 3, 'Q', 'P', 20, T_UNDEF);       // t=10, P(9,13)->Q(10,3), Perishable(20)
    
    // PEMBUATAN LIST KOSONG
    CreateList(&l1);


    // TEST LIST KOSONG
    if (isEmptyList(l1)) printf("List kosong.\n");
    else printf("List tidak kosong.\n");


    // INSERT ELEMEN LIST
    insertFirst(&l1, p1);   displayList(l1); printf("\n");
    insertLast(&l1, p2);    displayList(l1); printf("\n");
    insertAt(&l1, p3, 1);   displayList(l1); printf("\n");


    // GETTER SETTER
    temp = getElmtList(l1, 1);  displayPesanan(temp); printf("\n");

    setElmtList(&l1, 2, p4);     displayList(l1); printf("\n");
    
    printf("Index of p3 = %d\n", indexOfList(l1, p3));


    // PROSES SEMUA ELEMEN LIST 
    displayList(l1); printf("\n");

    printf("Length = %d\n", lengthList(l1));


    // PENCARIAN ELEMEN LIST
    loc1 = NEXT(FIRST(l1));
    if (fSearch(l1, loc1)) printf("Elemen ada di list.\n");
    else printf("Elemen tidak ada di list.\n");
    
    loc1 = searchPrec(l1, p3);  // alamat elemen sebelum p3, dengan list l1 = [p1,p3,p4]
    loc2 = FIRST(l1);           // alamat elemen p1, dengan list l1 = [p1,p3,p4]
    printf("Address p1 = %p = %p = Address before p3\n", &loc2, &loc1);


    // PROSES TERHADAP LIST
    copyList(&l1, &l2);     displayList(l2); printf("\n");
    l3 = fCopyList(l1);     displayList(l3); printf("\n");
    cpAllocList(l1, &l4);   displayList(l4); printf("\n");

    inverseList(&l3);       displayList(l3); printf("\n");
    l4 = fInverseList(l4);  displayList(l4); printf("\n");

    l4 = concatList(l1,l3);     displayList(l4); printf("\n");
    splitList(&l5, &l6, l4);    displayList(l5); displayList(l6); printf("\n");


    // DELETE ELEMEN LIST
    delAll(&l5);     displayList(l5); printf("\n");
    
    deleteAt(&l1, 1, &temp);    displayList(l1); printf("\n");
    deleteFirst(&l1, &temp);    displayList(l1); printf("\n");
    deleteLast(&l1, &temp);     displayList(l1); printf("\n");
    
    return 0;
}