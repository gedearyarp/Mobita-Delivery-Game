/* Fungsi/Prosedur untuk In Progress List */

#include <stdio.h>
#include "../ADT/boolean.h"
#include "../ADT/list_linked/list_linked.h"
#include "../tas/tas.h"

void in_progressCommand(List in_progress_list, int curr_time) {
/* Fungsi untuk mencetak in progress list.
   Fungsi ini dipanggil setiap ada command IN_PROGRESS. */
    /* KAMUS LOKAL */
    int i;
    int tSisa;      // waktu sisa perishable item
    char dropLoc;   // nama tempat drop off
    Address p;
    /* ALGORITMA */
    printf("Pesanan pada To Do List:\n");
    i = 0;
    p = in_progress_list;
    while (p != NULL) {
        dropLoc = Label(DROP_P(INFO(p)));
        printf("%d. ", i+1);
        // print jenis item
        if (TYPE(INFO(p)) == 'N'){               
            printf("Normal Item");
        } else if (TYPE(INFO(p)) == 'H'){
            printf("Heavy Item");
        } else if (TYPE(INFO(p)) == 'P'){
            tSisa = curr_time - (T_PICK(INFO(p)) + T_PERISH(INFO(p)));
            printf("Perishable Item, sisa waktu %d", tSisa);
        } else if (TYPE(INFO(p)) == 'V'){
            printf("VIP Item");
        }
        printf("(Tujuan: %c)\n", dropLoc);
        i++;
        p = NEXT(p);
    }
}

void updateInProgress (List *in_progress_list, Tas tas, int option, int curr_time, float *time_incr, int *cap_incr, int *uncompleted) {
/* Fungsi untuk mengupdate in progress list */
/* Fungsi ini dipanggil setiap pick_up barang (option 1), drop_off barang (option 2), dan tiap satuan waktu (option 3) */
/* Note: sebelum pemanggilan fungsi ini, deklarasikan dulu variabel in_progress_list, time_incr, dan cap_incr */ 
    /* KAMUS LOKAL */
    ElType deleted;    // menyimpan value hasil delete
    Address loc;    
    int idx;
    /* ALGORITMA */
    // option 1: pickup
    if (option == 0) {
        insertFirst(in_progress_list, TOP(tas));
        if (TYPE(TOP(tas)) == 'H') {
            *time_incr++;           // Heavy Item effect
        }
    }
    // option2: drop off 
    else if (option == 1) {
        deleteFirst(in_progress_list, &deleted);
        if (TYPE(deleted) == 'H' && (heavyItemCount(in_progress_list) == 0)) {
            *time_incr *= 0.5;        // Abillity: Speed Boost
        } else if (TYPE(deleted) == 'P') {
            *cap_incr++;             // Abillity: Increase Capacity
        }
    }
    // option3: hangus atau return
    else if (option == 2) {
        loc = FIRST(in_progress_list);
        while (loc != NULL) {
            if ((TYPE(INFO(loc)) == 'P') && (curr_time >= T_PICK(INFO(loc)) + T_PERISH(INFO(loc)))) {
                idx = indexOfList(in_progress_list, INFO(loc));
                deleteAt(in_progress_list, idx, &deleted);
                *uncompleted += 1;
            }
            loc = NEXT(loc);
        }
    }
}

int heavyItemCount(List in_progress_list) {
/* Fungsi antara untuk menghitung jumlah heavy item di tas / in_progress_list */
    /* KAMUS LOKAL */
    int ctr;
    Address p;
    /* ALGORITMA */
    ctr = 0;
    p = in_progress_list;
    while (p != NULL) {
        if (TYPE(INFO(p)) == 'H') {
            ctr++;
        }
        p = NEXT(p);
    }
    return ctr;
}