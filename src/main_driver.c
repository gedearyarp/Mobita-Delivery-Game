#include <stdio.h>
#include <stdlib.h>
#include "../command/buy.h"
#include "../command/map.h"
#include "../command/drop_off.h"
#include "../command/help.h"
#include "../command/in_progress.h"
#include "../command/move.h"
#include "../command/pick_up.h"
#include "../command/to_do.h"
#include "../command/inventory.h"
#include "../konfigurasi/konfigurasi.h"
#include "../ability/ability.h"
#include "../pcolor/pcolor.h"
#include "../pesanan/pesanan.h"
#include "../tas/tas.h"
#include "../ADT/point/point.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/stack/stack.h"
#include "../ADT/queue/queue.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../ADT/boolean.h"


int main(){
	int money,waktu,curr_time,cap_incr,uncompleted;
	float time_incr;
	List to_do_list,in_progress_list;
	char item;
	int command;
	boolean Finish;
	MAP m;
	POINT lokasi;
	Inventory ivtr;
	Tas tas;
	readFile(&m);
	
	printf("Main Menu: \n");
	printf("1. NEW GAME");
	printf("2. EXIT");
	printf("Masukkan angka sesuai pilihan diatas");
	scanf("%d",&command);
	if(command == "NEW GAME"){
		Finish = false;
	}
	else if(command == "EXIT"){
		Finish = true;
	}
	while(!Finish ){
		printf("\nMobita berada di posisi %c (%d,%d)\n",lokasi.label,lokasi.X,lokasi.Y);
		printf("Waktu: %d\n",waktu);
		printf("Uang yang dimiliki: %d Yen\n",money);
		printf("Pilihan Command: ");
		printf("1. MOVE");
		printf("2. PICK_UP");
		printf("3. DROP_OFF");
		printf("4. MAP");
		printf("5. TO_DO");
		printf("6. IN_PROGRESS");
		printf("7. BUY");
		printf("8. INVENTORY");
		printf("9. HELP");
		printf("ENTER COMMAND: ")
		gets(command);
		if (command == 1){
			moveCommand(m, &lokasi);
		}
		else if (command== 2){
			pick_upCommand(&tas, lokasi, &to_do_list, &in_progress_list,curr_time,&time_incr, &cap_incr, &uncompleted);
		}
		else if(command == 3){
			drop_offCommand(&tas, lokasi, &money);
		}
		else if(command == 4){
			mapCommand(m,lokasi,waktu,item)
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
		else if (command == 8{
			inventoryCommand(&Ivtr, &waktu, &tas, &in_progress_list);
		}
		else if (command ==9){
			helpCommand();
		}
		advWord();
	}
    
}
