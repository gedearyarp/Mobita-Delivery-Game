#include "boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "konfigurasi.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include <stdio.h>


int main(){
	MAP M;
	CreateMap (&M);
	BacaKoordinat(&M);
	BacaAdjMatrix(&M);
	BacaPesanan(&M);
	
}
