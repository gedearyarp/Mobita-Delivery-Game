#include "boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "konfigurasi.h"
#include "../command/map.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include <stdio.h>


int main(){
	MAP M;
	readFile(&M);
	POINT p = MakePOINT(5,4,'I');
	int waktu = 1;
	char item = 'M';
	mapCommand(M,p,waktu,item);
	
}
