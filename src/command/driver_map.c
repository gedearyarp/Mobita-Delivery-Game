#include "../ADT/boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../ADT/list_linked/list_linked.h"
#include "../ADT/list_linked/Node.h"
#include "../ADT/stack/stack.h"
#include "../ADT/queue/queue.h"
#include "../konfigurasi/konfigurasi.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include "../pcolor/pcolor.h"
#include "map.h"
#include "to_do.h"
#include <stdio.h>


int main(){
	MAP m;
	readFile(&m);
	POINT p = MakePOINT(5,4,'I');
	int waktu = 1;
	char dropOff = 'N';
	List to_do_list;
	Queue queue_pesanan;
	CreateQueue(&queue_pesanan);
	QueuePesanan(m, &queue_pesanan);
	CreateList(&to_do_list);
	insertToDo(&to_do_list, &queue_pesanan, waktu);
	mapCommand(m,p,waktu,dropOff,to_do_list);
}
