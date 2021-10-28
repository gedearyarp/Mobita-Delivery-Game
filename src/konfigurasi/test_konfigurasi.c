#include "boolean.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "konfigurasi.h"
#include "../point/point.h"
#include "../pesanan/pesanan.h"
#include <stdio.h>


int main(){
	MAP M;
	CreateMap (&M);
	BacaKoordinat(&M);
	BacaAdjMatrix(&M);
	BacaPesanan(&M);
	
}
