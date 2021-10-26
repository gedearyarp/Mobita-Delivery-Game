/* fungsi-fungsi untuk command TO_DO */

#include <stdio.h>
#include "pesanan.h"
#include "list_linked.h"
#include "boolean.h"

void printToDo(List to_do_list, int curr_time) {
/* Mencetak daftar to do list */
    /* KAMUS LOKAL */
    int i;                  // pencacah
    int tSisa;              // waktu sisa perishable item
    char pickLoc, dropLoc;  // nama tempat pick up dan drop off
    /* ALGORITMA */
    printf("Pesanan pada To Do List:\n");
    for (i = 0; i < length(to_do_list); i++) {
        pickLoc = Label(PICK_P(INFO(to_do_list)));
        dropLoc = Label(DROP_P(INFO(to_do_list)));
        printf("%d. %c -> %c ", i+1, pickLoc, dropLoc);     // print lokasi
        // print jenis item
        if (TYPE(INFO(to_do_list)) == 'N'){               
            printf("(Normal Item)");
        } else if (TYPE(INFO(to_do_list)) == 'H'){
            printf("(Heavy Item)");
        } else if (TYPE(INFO(to_do_list)) == 'P'){
            tSisa = T_PERISH(INFO(to_do_list)) - curr_time;
            printf("(Perishable Item, sisa waktu %d)", tSisa);
        } else if (TYPE(INFO(to_do_list)) == 'V'){
            printf("(VIP Item)");
        }
        printf("\n");
    }
}

void updateToDo (List *to_do_list, List list_pesanan, int curr_time, int *uncompleted) {
/* Mengupdate to do list. Note: Deklarasikan variabel to_do_list dan uncompleted */
    /* KAMUS LOKAL */
    int i;
    Address p;
    ElType val;
    /* ALGORITMA */
    // insert item ke to do list sesuai waktu masuknya
    i = 0;
    p = list_pesanan;
    while (i < length(list_pesanan)) {
        if (curr_time == T_MASUK(INFO(p))) {
            insertLast(to_do_list, INFO(p));
        }
        i++;
        p = NEXT(p);
    }
}