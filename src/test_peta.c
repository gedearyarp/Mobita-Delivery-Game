#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "konfigurasi.h"
#include "point/point.h"
#include "pesanan/pesanan.h"
#include "pcolor/pcolor.h"
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
	int waktu = 5;
	char item = 'A';
	showPeta(M,p,waktu,item);
}
