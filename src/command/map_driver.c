#include "boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../konfigurasi/konfigurasi.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include "../pcolor/pcolor.h"
#include "peta.h"
#include <stdio.h>


int main(){
	MAP M;
	POINT p;
	CreateMap (&M);
	BacaKoordinat(&M);
	BacaAdjMatrix(&M);
	BacaPesanan(&M);
	p = MakePOINT(5,4,'I');
	int waktu = 1;
	char item = 'M';
	showPeta(M,p,waktu,item);
}
