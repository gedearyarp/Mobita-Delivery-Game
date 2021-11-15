/* File: peta.h */
/* *** Definisi ABSTRACT DATA TYPE POINT *** */

#ifndef PETA_H
#define PETA_H

#define CAPACITY 50
#define VAL_UNDEF -999

#include "../ADT/boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../ADT/matrix/matrix.h"
#include "../ADT/matrix_char/matrix_c.h"
#include "../konfigurasi/konfigurasi.h"
#include "../ADT/point/point.h"
#include "../pesanan/pesanan.h"
#include "../pcolor/pcolor.h"
#include "../ADT/list_linked/list_linked.h"


void mapCommand(MAP m,POINT p,int waktu,char item,List to_do_list);
	//fungsi untuk menampilkan peta
#endif


