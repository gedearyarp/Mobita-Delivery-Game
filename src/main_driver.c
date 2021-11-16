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
#include "ADT/matrix_char/matrix_c.h"
#include "ADT/wordmachine/wordmachine.h"
#include "ADT/wordmachine/charmachine.h"
#include "ADT/boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int money=5000,waktu=0,cap_incr,uncompleted,speedBoostTime=0;
	float time_incr;
	Queue queue_pesanan;
	List to_do_list,in_progress_list;
	char item='0';
	int command;
	boolean Finish;
	MAP m;
	Inventory ivtr;
	Tas tas;
	readFile(&m);
	boolean speedBoostActive = false;
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
	CreateQueue(&queue_pesanan);
	QueuePesanan(m, &queue_pesanan);
	uncompleted = 0;
	POINT lokasi = getUsersPoint(m);
	CreateTas(&tas);
	CreateList(&to_do_list);
	CreateList(&in_progress_list);
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
		command =ConvertInt(currentWord.contents,currentWord.length);
		if (command == 1){
			int prewaktu= waktu;
			moveCommand(m, &waktu, tas, &lokasi, &speedBoostActive, &speedBoostTime);
			if(prewaktu != waktu){
				insertToDo(&to_do_list, &queue_pesanan, waktu);
				deletePerishable(&in_progress_list, waktu, &uncompleted);
			}
		}
		else if (command== 2){
			pickUpCommand(&tas, lokasi, &to_do_list, &in_progress_list, &waktu);
		}
		else if(command == 3){
			drop_OffCommand(&tas, &in_progress_list, lokasi, &money, waktu, &speedBoostTime, &speedBoostActive);
		}
		else if(command == 4){
			mapCommand(m, lokasi, waktu, Label(DROP_P(TOP_TAS(tas))), to_do_list);
		}
		else if(command == 5){
			to_doCommand(to_do_list, waktu);
		}
		else if(command == 6){
			in_progressCommand(in_progress_list, waktu);
		}
		else if(command == 7){
			buyCommand(&money,&ivtr, m, lokasi);
		}
		else if (command == 8){
			inventoryCommand(&ivtr, &waktu, &tas, &in_progress_list, m, &lokasi);
		}
		else if (command ==9){
			helpCommand();
		}
	}
    
}
