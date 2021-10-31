/* 
NIM             : Hansel Valentino Tanoto
Nama            : 13520046
Tanggal         : 28 Oktober 2021
Topik praktikum : ADT Linked List
Deskripsi       : Implementasi fungsi/prosedur primitif ADT Linked List
                  yang sudah didefinisikan di file header (list_linked.h)
*/

#include <stdio.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyList(List l) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (FIRST(l) ==  NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmtList(List l, int idx) {
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    return (INFO(p));
}

void setElmtList(List *l, int idx, ElType val) {
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = *l;
    while (ctr < idx) {
        ctr++;
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOfList(List l, ElType val) {
    /* KAMUS LOKAL */
    int idx;
    boolean found;
    Address p;
    /* ALGORITMA */
    idx = 0;
    found = false;
    p = l;
    while ((p != NULL) && (!found)) {
        if (isPesananEqual(INFO(p), val)){
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }
    if (found) {
        return idx;
    } else {
        return IDX_UNDEF;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val) {
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    /* KAMUS LOKAL */
    Address p, last;
    /* ALGORITMA */
    if (isEmptyList(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    /* KAMUS LOKAL */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = *l;
            while (ctr < idx-1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}
void deleteLast(List *l, ElType *val) {
    /* KAMUS LOKAL */
    Address p, loc;
    /* ALGORITMA */
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        *l = NULL; 
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p); 
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    /* KAMUS LOKAL */
    Address p, loc;
    int ctr;
    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        ctr =0;
        loc = *l;
        while (ctr < idx-1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l) {
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = l;
    printf("[");
    while (p != NULL) {
        displayPesanan(INFO(p));
        if (NEXT(p) != NULL) {
            printf(",");
        }
        p = NEXT(p);
    }
    printf("]");
}

int lengthList(List l) {
    /* KAMUS LOKAL */
    Address p;
    int ctr;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P) {
    /* KAMUS LOKAL */
    Address loc;
    boolean found;
    /* ALGORITMA */
    found = false;
    loc = FIRST(L);
    while (loc != NULL) {
        if (P == loc) {
            found = true;
        }
        loc = NEXT(loc);
    }
    return found;
}
Address searchPrec(List L, ElType X) {
    /* KAMUS LOKAL */
    int idxX, i;
    Address loc, result;
    ElType prev;
    /* ALGORITMA */
    idxX = indexOfList(L, X);
    result == NULL;
    if (idxX != IDX_UNDEF && idxX != 0) {
        loc = FIRST(L);
        i = 0;
        while (i < idxX-1) {
            i++;
            loc = NEXT(loc);
        }
        result = loc;
    }
    return result;
}

/****************** PROSES TERHADAP LIST ******************/
List concatList(List l1, List l2) {
    /* KAMUS LOKAL */
    List l3;
    Address p;
    /* ALGORITMA */
    CreateList(&l3);
    p = l1;
    while (p != NULL) {
        insertLast(&l3, p->info);
        p = p->next;
    }
    p = l2;
    while (p !=  NULL) {
        insertLast(&l3, p->info);
        p = p->next;
    }
    return l3;
}

void delAll(List *l) {
    /* KAMUS LOKAL */
    Address loc;
    ElType p;
    /* ALGORITMA */
    loc = FIRST(*l);
    while (loc != NULL) {
        deleteFirst(l, &p);
        loc = NEXT(loc);
    }
    FIRST(*l) = NULL;
}

void inverseList(List *l) {
    /* KAMUS LOKAL */
    Address loc, last, prev;
    /* ALGORITMA */
    if (!isEmptyList(*l)) {
        loc = FIRST(*l);
        while (NEXT(loc) != NULL) {
            loc = NEXT(loc);
        }
        last = loc;
        while (loc != FIRST(*l)) {
            prev = FIRST(*l);
            while (NEXT(prev) != loc) {
                prev = NEXT(prev);
            }
            NEXT(loc) = prev;
            loc = NEXT(loc);
        }
        NEXT(loc) = NULL;
        FIRST(*l) = last;
    }
}

List fInverseList(List l) {
    /* KAMUS LOKAL */
    List l2;
    /* ALGORITMA */
    l2 = fCopyList(l);
    inverseList(&l2);
    return l2;
}

void copyList(List *l1, List *l2) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    FIRST(*l2) = FIRST(*l1);
}

List fCopyList(List l) {
    /* KAMUS LOKAL */
    List l2;
    Address loc, p;
    /* ALGORITMA */
    CreateList(&l2);
    boolean success = true;
    loc = FIRST(l);
    while (success && loc != NULL){
        p = newNode(INFO(loc));
        if (p == NULL){
            success = false;
        } else {
            insertLast(&l2, INFO(p));
        }
        loc = NEXT(loc);
    }
    if (!success){
        delAll(&l2);
    }
    return l2;
}

void cpAllocList(List lIn, List *lOut) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    *lOut = fCopyList(lIn);
}

void splitList(List *l1, List *l2, List l) {
    /* KAMUS LOKAL */
    int len, ctr;
    Address loc, p;
    /* ALGORITMA */
    CreateList(l1);
    CreateList(l2);
    len = lengthList(l)/2;
    ctr = 0;
    loc = FIRST(l);
    while (loc != NULL) {
        ctr++;
        p = newNode(INFO(loc));
        if (p != NULL) {
            if (ctr <= len) {
                insertLast(l1, INFO(p));
            } else {
                insertLast(l2, INFO(p));
            }
        }
        loc = NEXT(loc);
    }
}