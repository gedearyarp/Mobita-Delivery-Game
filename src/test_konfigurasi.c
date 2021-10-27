#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "konfigurasi.h"
#include "point.h"
#include "pesanan.h"
#include <stdio.h>


int main(){
	MAP M;
	CreateMap (&M);
	BacaKoordinat(&M);
	BacaAdjMatrix(&M);
	BacaPesanan(&M);
	
}
