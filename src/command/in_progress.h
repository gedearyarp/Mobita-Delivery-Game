/* File: in_progress.h */
/* *** Definisi COMMAND IN_PROGRESS *** */

#ifndef IN_PROGRESS_H
#define IN_PROGRESS_H

#include "../ADT/boolean.h"
#include "../ADT/list_linked/node.h"
#include "../ADT/list_linked/list_linked.h"
#include "../tas/tas.h"

void in_progressCommand(List in_progress_list, int curr_time);
/* Fungsi untuk mencetak in progress list.
   Fungsi ini dipanggil setiap ada command IN_PROGRESS. */

void updateInProgress (List *in_progress_list, Tas tas, int option);
/* Fungsi untuk mengupdate in progress list */
/* Fungsi ini dipanggil setiap pick_up barang (option 1) dan drop_off barang (option 2) */
/* Note: sebelum pemanggilan fungsi ini, deklarasikan dulu variabel in_progress_list */ 

void deletePerishable(List *in_progress_list, int curr_time, int *uncompleted);
/* Menghapus Perishable item jika sudah lewat batas waktu */
/* Fungsi ini dipanggil setiap satuan waktu */
/* Note: sebelum pemanggilan fungsi ini, deklarasikan dulu variabel in_progress_list dan uncompleted (gagal diantar) */ 

#endif


