/* File: in_progress.c */
/* Realisasi Fungsi/Prosedur untuk In Progress List */

#include <stdio.h>
#include "in_progress.h"
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
    printf("Pesanan pada In Progress List:\n");
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
            tSisa = (T_PICK(INFO(p)) + T_PERISH(INFO(p))) - curr_time;
            printf("Perishable Item, sisa waktu %d", tSisa);
        } else if (TYPE(INFO(p)) == 'V'){
            printf("VIP Item");
        }
        printf(" (Tujuan: %c)\n", dropLoc);
        i++;
        p = NEXT(p);
    }
}

void updateInProgress (List *in_progress_list, Tas tas, int option, int *currTime) {
/* Fungsi untuk mengupdate in progress list */
/* Fungsi ini dipanggil setiap pick_up barang (option 1) dan drop_off barang (option 2) */
/* Note: sebelum pemanggilan fungsi ini, deklarasikan dulu variabel in_progress_list */ 
    /* KAMUS LOKAL */
    ElType deleted;    // menyimpan value hasil delete
    Address loc;    
    int idx;
    /* ALGORITMA */
    // option 1: pickup
    if (option == 1) {
        insertFirst(in_progress_list, TOP_TAS(tas));
        T_PICK(INFO(FIRST(*in_progress_list)))=*currTime;
    }
    // option2: drop off 
    else if (option == 2) {
        deleteFirst(in_progress_list, &deleted);
    }
}

void deletePerishable(List *in_progress_list, int curr_time, int *uncompleted) {
/* Menghapus Perishable item jika sudah lewat batas waktu */
/* Fungsi ini dipanggil setiap satuan waktu */
/* Note: sebelum pemanggilan fungsi ini, deklarasikan dulu variabel in_progress_list dan uncompleted (gagal diantar) */ 
    /* KAMUS LOKAL */
    ElType deleted;    // menyimpan value hasil delete
    Address loc;    
    int idx;
    /* ALGORITMA */
    loc = FIRST(*in_progress_list);
    while (loc != NULL) {
        if ((TYPE(INFO(loc)) == 'P') && (curr_time >= T_PICK(INFO(loc)) + T_PERISH(INFO(loc)))) {
            idx = indexOfList(*in_progress_list, INFO(loc));
            deleteAt(in_progress_list, idx, &deleted);
            *uncompleted += 1;
        }
        loc = NEXT(loc);
    }
}
