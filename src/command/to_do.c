/* File: to_do.h */
/* Realisasi Fungsi/Prosedur untuk To Do List */

#include <stdio.h>
#include "to_do.h"
#include "../ADT/boolean.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/queue/queue.h"

void to_doCommand(List to_do_list, int curr_time) {
/* Mencetak to do list.
   Fungsi ini dipanggil setiap ada command TO_DO. */
    /* KAMUS LOKAL */
    int i;
    char pickLoc, dropLoc;  // nama tempat pick up dan drop off
    Address p;
    /* ALGORITMA */
    printf("Pesanan pada To Do List:\n");
    i = 0;
    p = FIRST(to_do_list);
    if (p == NULL) printf("-Tidak ada pesanan-");
    while (p != NULL) {   
        pickLoc = Label(PICK_P(INFO(p)));
        dropLoc = Label(DROP_P(INFO(p)));
        printf("%d. %c -> %c ", i+1, pickLoc, dropLoc);     // print lokasi
        // print jenis item
        if (TYPE(INFO(p)) == 'N'){               
            printf("(Normal Item)");
        } else if (TYPE(INFO(p)) == 'H'){
            printf("(Heavy Item)");
        } else if (TYPE(INFO(p)) == 'P'){
            printf("(Perishable Item, sisa waktu %d)", T_PERISH(INFO(p)));
        } else if (TYPE(INFO(p)) == 'V'){
            printf("(VIP Item)");
        }
        printf("\n");
        i++;
        p = NEXT(p);
    }
}

void insertToDo (List *to_do_list, Queue *queue_pesanan, int curr_time) {
/* Menghapus pesanan dari queue_pesanan dan menambahkan pesanan itu ke to_do_list. 
   Fungsi ini dipanggil setiap satuan waktu.
   Prekondisi: variabel to_do_list dan queue_pesanan sudah dideklarasikan sebelum pemanggilan fungsi. */
    /* KAMUS LOKAL */
    ElType val;
    boolean flag = true;
    /* ALGORITMA */
    while (!isEmptyQ(*queue_pesanan) && flag) {
        // insert pesanan ke to do list kalau current_time >= waktu masuk pesanan
        if (curr_time >= T_MASUK(HEAD(*queue_pesanan))) {
            dequeue(queue_pesanan, &val);
            //displayPesanan(val); printf("\n");
            //displayQueue(*queue_pesanan); printf("\n");
            //printf("%d %d", IDX_HEAD(*queue_pesanan), IDX_TAIL(*queue_pesanan));
            insertLast(to_do_list, val);
        } else {
            flag = false;
        }
    }
}

void deleteToDo (List *to_do_list, int idx, ElType *val) {
/* Menghapus val (pesanan) dari to_do_list ketika pesanan masuk in_progress. 
   Fungsi ini dipanggil setiap pesanan masuk in_progress.
   Prekondisi: variabel to_do_list sudah dideklarasikan sebelum pemanggilan fungsi. */
    /* KAMUS LOKAL */
    /* ALGORITMA */
    deleteAt(to_do_list, idx, val);
}
