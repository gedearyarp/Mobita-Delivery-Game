#include <stdio.h>
#include <stdlib.h>
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
	int money,waktu,curr_time;
	float time_incr;
	List to_do_list,in_progress_list;
	char item;
	MAP m;
	POINT lokasi;
	Inventory ivtr;
	Tas bag;
	
	
	while(input command ){
		if (command == "MOVE"){
			moveCommand(m, &lokasi);
		}
		else if (command== "PICK_UP"){
			pick_upCommand(&bag, lokasi, &to_do_list, &in_progress_list,curr_time,&time_incr, int *cap_incr, int *uncompleted);
		}
		else if(command == "DROP_OFF"){
			drop_offCommand(&bag, lokasi, &money);
		}
		else if(command == "MAP"){
			mapCommand(m,lokasi,waktu,item)
		}
		else if(command == "TO_DO"){
			to_doCommand();
		}
		else if(command == "IN_PROGRESS"){
			in_progressCommand();
		}
		else if(command == "BUY"){
			buyCommand(&money,&ivtr);
		}
		else if (command == "INVENTORY"){
			inventoryCommand();
		}
		else if (command == "HELP"){
			helpCommand();
		}
	}
    
}
