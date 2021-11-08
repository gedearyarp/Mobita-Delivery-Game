#include <stdio.h>
#include "help.h"

void helpCommand() {
    printf("NEW GAME -> Memulai permainan\n");
    printf("EXIT -> Menutup program\n");
    printf("MOVE -> Berpindah sesuai posisi yang dapat dicapai\n");
    printf("PICK_UP -> Mengambil item jika ada pesanan yang harus diambil pada lokasi\n");
    printf("DROP_OFF -> Mengantarkan item ke lokasi jika item di tumpukan teratas sesuai dengan pesanan\n");
    printf("MAP -> Memunculkan peta\n");
    printf("TO_DO -> Menampilkan pesanan yang masuk ke To Do List\n");
    printf("IN_PROGRESS -> Menampilkan pesanan yang sedang dikerjakan\n");
    printf("BUY -> Menampilkan gadget yang dapat dibeli lalu membelinya\n");
    printf("INVENTORY -> Menampilkan list isi inventory\n");
    printf("HELP -> Menampilkan seluruh command yang dapat dimasukkan beserta deskripsinya\n");
}