/* File: list_linked.c */

#include <stdio.h>
#include "list_linked.h"

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    return (FIRST(l) ==  NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx) {
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (ctr < idx) {
        ctr++;
        p = p->next;
    }
    return (p->info);
}

void setElmt(List *l, int idx, ElType val) {
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = *l;
    while (ctr < idx) {
        ctr++;
        p = p->next;
    }
    p->info = val;
}

int indexOf(List l, ElType val) {
    /* KAMUS LOKAL */
    int idx;
    boolean found;
    Address p;
    /* ALGORITMA */
    idx = 0;
    found = false;
    p = l;
    while ((p != NULL) && (!found)) {
        if (isEqual(p->info, val)) {
            found = true;
        } else {
            idx++;
            p = p->next;
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
        p->next = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    /* KAMUS LOKAL */
    Address p, last;
    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = *l;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = p;
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
                loc = loc->next;
            }
            p->next = loc->next;
            loc->next = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val) {
    /* KAMUS LOKAL */
    Address p;
    /* ALGORITMA */
    p = *l;
    *val = p->info;
    *l = p->next;
    free(p);
}
void deleteLast(List *l, ElType *val) {
    /* KAMUS LOKAL */
    Address p, loc;
    /* ALGORITMA */
    p = *l;
    loc = NULL;
    while (p->next != NULL) {
        loc = p;
        p = p->next;
    }
    if (loc == NULL) {
        *l = NULL; 
    } else {
        loc->next = NULL;
    }
    *val = p->info; 
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
            loc = loc->next;
        }
        p = loc->next;
        *val = p->info;
        loc->next = p->next;
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
        printf("%d", p->info);
        if (p->next != NULL) {
            printf(",");
        }
        p = p->next;
    }
    printf("]");
}

int length(List l) {
    /* KAMUS LOKAL */
    Address p;
    int ctr;
    /* ALGORITMA */
    ctr = 0;
    p = l;
    while (p != NULL) {
        ctr++;
        p = p->next;
    }
    return ctr;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2) {
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