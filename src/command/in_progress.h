/* File: in_progress.h */
/* *** Definisi COMMAND IN_PROGRESS *** */

#ifndef IN_PROGRESS_H
#define IN_PROGRESS_H

#include "../ADT/boolean.h"
#include "../ADT/list_linked/list_linked.h"
#include "../tas/tas.h"

void in_progressCommand(List in_progress_list, int curr_time);
/* Fungsi untuk mencetak in progress list.
   Fungsi ini dipanggil setiap ada command IN_PROGRESS. */

void updateInProgress (List *in_progress_list, Tas tas, int option, int curr_time, float *time_incr, int *cap_incr, int *uncompleted);
/* Fungsi untuk mengupdate in progress list */
/* Fungsi ini dipanggil setiap pick_up barang (option 1), drop_off barang (option 2), dan tiap satuan waktu (option 3) */
/* Note: sebelum pemanggilan fungsi ini, deklarasikan dulu variabel in_progress_list, time_incr, dan cap_incr */ 

int heavyItemCount(List in_progress_list);
/* Fungsi antara untuk menghitung jumlah heavy item di tas / in_progress_list */

#endif


