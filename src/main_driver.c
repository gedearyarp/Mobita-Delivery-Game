#include "command/map.h"
#include "command/buy.h"
#include "command/drop_off.h"
#include "command/help.h"
#include "command/in_progress.h"
#include "command/move.h"
#include "command/pick_up.h"
#include "command/to_do.h"
#include "command/command_inventory.h"
#include "inventory/inventory.h"
#include "konfigurasi/konfigurasi.h"
#include "ability/ability.h"
#include "pcolor/pcolor.h"
#include "pesanan/pesanan.h"
#include "tas/tas.h"
#include "ADT/point/point.h"
#include "ADT/list_linked/list_linked.h"
#include "ADT/list_linked/Node.h"
#include "ADT/stack/stack.h"
#include "ADT/queue/queue.h"
#include "ADT/matrix/matrix.h"
#include "ADT/matrix_c/matrix_c.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/wordmachine/charmachine.h"
#include "ADT/boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int money,waktu,curr_time,cap_incr,uncompleted,speedBoostTime;
	float time_incr;
	Queue queue_pesanan;
	List to_do_list,in_progress_list;
	char item;
	int command;
	boolean Finish;
	MAP m;
	POINT lokasi;
	Inventory ivtr;
	Tas tas;
	readFile(&m);
	boolean speedBoostActive;
	printf("Main Menu: \n");
	printf("1. NEW GAME\n");
	printf("2. EXIT\n");
	printf("Masukkan angka sesuai pilihan diatas: ");
	startWord();
	if(currentWord.contents[0] == '1'){
		Finish = false;
	}
	else if(currentWord.contents[0] == '2'){
		return 0;
	}
	QueuePesanan(m, &queue_pesanan);
	curr_time = 0;
	uncompleted = 0;
	while(!Finish ){
		printf("\nMobita berada di posisi %c (%d,%d)\n",lokasi.label,lokasi.X,lokasi.Y);
		printf("Waktu: %d\n",waktu);
		printf("Uang yang dimiliki: %d Yen\n",money);
		printf("Pilihan Command: ");
		printf("\n1. MOVE");
		printf("\n2. PICK_UP");
		printf("\n3. DROP_OFF");
		printf("\n4. MAP");
		printf("\n5. TO_DO");
		printf("\n6. IN_PROGRESS");
		printf("\n7. BUY");
		printf("\n8. INVENTORY");
		printf("\n9. HELP");
		printf("\nENTER COMMAND: ");
		advWord();
		command =convertInt(currentWord.contents,currentWord.length);
		if (command == 1){
			int prewaktu= waktu;
			moveCommand(m, &waktu, tas, &lokasi, &speedBoostActive, &speedBoostTime);
			if(prewaktu){
				insertToDo(&to_do_list, &queue_pesanan, curr_time);
				deletePerishable(&in_progress_list, curr_time, &uncompleted);
			}
		}
		else if (command== 2){
			pickUpCommand(&tas, lokasi, &to_do_list, &in_progress_list);
		}
		else if(command == 3){
			drop_OffCommand(&tas,&in_progress_list, lokasi, &money, curr_time, &speedBoostTime, &speedBoostActive);
		}
		else if(command == 4){
			mapCommand(m,lokasi,waktu,item);
		}
		else if(command == 5){
			to_doCommand(to_do_list, curr_time);
		}
		else if(command == 6){
			in_progressCommand(in_progress_list, curr_time);
		}
		else if(command == 7){
			buyCommand(&money,&ivtr);
		}
		else if (command == 8){
			inventoryCommand(&ivtr, &waktu, &tas, &in_progress_list);
		}
		else if (command ==9){
			helpCommand();
		}
	}
    
}
