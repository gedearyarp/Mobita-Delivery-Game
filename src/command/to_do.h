/* File: to_do.h */
/* *** Definisi COMMAND TO_DO *** */

#ifndef TO_DO_H
#define TO_DO_H

#include "../ADT/boolean.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/queue/queue.h"

void to_doCommand(List to_do_list, int curr_time);
/* Mencetak to do list.
   Fungsi ini dipanggil setiap ada command TO_DO. */

void insertToDo (List *to_do_list, Queue *queue_pesanan, int curr_time);
/* Menghapus pesanan dari queue_pesanan dan menambahkan pesanan itu ke to_do_list. 
   Fungsi ini dipanggil setiap satuan waktu.
   Prekondisi: variabel to_do_list dan queue_pesanan sudah dideklarasikan sebelum pemanggilan fungsi. */

void deleteToDo (List *to_do_list, ElType val);
/* Menghapus val (pesanan) dari to_do_list ketika pesanan masuk in_progress. 
   Fungsi ini dipanggil setiap pesanan masuk in_progress.
   Prekondisi: variabel to_do_list sudah dideklarasikan sebelum pemanggilan fungsi. */

#endif