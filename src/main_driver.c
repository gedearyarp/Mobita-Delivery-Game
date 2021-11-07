#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../konfigurasi/konfigurasi.h"
#include "../command/buy.c"
#include "../command/map.c"
#include "../command/drop_off.c"
#include "../command/help.c"
#include "../command/in_progress.c"
#include "../command/move.c"
#include "../command/pick_up.c"
#include "../command/to_do.c"
#include "../command/inventory.c"




int main(){
	int money,waktu,curr_time,cap_incr,uncompleted;
	float time_incr;
	List to_do_list,in_progress_list;
	char item,command[15];
	MAP m;
	POINT lokasi;
	Inventory ivtr;
	Tas tas;
	CreateMap (&M);
	BacaKoordinat(&M);
	BacaAdjMatrix(&M);
	BacaPesanan(&M);
	startWord();
	strcpy(command,currentWord.contents)
	while(command !="EXIT" ){
		if (command == "MOVE"){
			moveCommand(m, &lokasi);
		}
		else if (command== "PICK_UP"){
			pick_upCommand(&tas, lokasi, &to_do_list, &in_progress_list,curr_time,&time_incr, &cap_incr, &uncompleted);
		}
		else if(command == "DROP_OFF"){
			drop_offCommand(&tas, lokasi, &money);
		}
		else if(command == "MAP"){
			mapCommand(m,lokasi,waktu,item)
		}
		else if(command == "TO_DO"){
			to_doCommand(to_do_list, curr_time);
		}
		else if(command == "IN_PROGRESS"){
			in_progressCommand(in_progress_list, curr_time);
		}
		else if(command == "BUY"){
			buyCommand(&money,&ivtr);
		}
		else if (command == "INVENTORY"){
			inventoryCommand(&Ivtr, &waktu, &tas, &in_progress_list);
		}
		else if (command == "HELP"){
			helpCommand();
		}
		advWord();
	}
    
}
