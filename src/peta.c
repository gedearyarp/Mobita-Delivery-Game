#include "boolean.h"
#include "matrix.h"
#include "wordmachine.h"
#include "charmachine.h"
#include "pesanan/pesanan.h"
#include "point/point.h"
#include "konfigurasi.h"
#include "pcolor/pcolor.h"
#include <stdio.h>

void showPeta(MAP m,POINT p,int waktu,char item){
	//fungsi untuk menampilkan peta
	int i=0,j=0,a,b,idxP,idxD;
	char dropOff;
	char pickUp[nOrder(m)];
	boolean found = false;
	for(a=0;a<nOrder(m);a++){
		if(O_PICK_LABEL(m,a) == item)dropOff = O_DROP_LABEL(m,a);
		if(O_MASUK(m,a)>=waktu)pickUp[a] = O_PICK_LABEL(m,a);
	}
	for(b=0;b<nEff(m);b++){
		if(Label(p)==NAMA(m,b))idxP = b;
	}
	while(PETA(m,i,j)!= '/'){
		j = 0;
		while(PETA(m,i,j)!='/'){
			if(PETA(m,i,j)==' ') {
				printf("%c",PETA(m,i,j));
				continue;
			}
			found = false;
			a=0;
			while(a<nOrder(m)){
				if(pickUp[a] == PETA(m,i,j))found = true;
				a++;
			}
			b=0;
			while(b<nEff(m)){
				if(PETA(m,i,j)==NAMA(m,b))idxD=b;
				b++;
			}
			if(i == Ordinat(p) && j==Ordinat(p)){
				print_yellow(PETA(m,i,j));
			}
			else if(PETA(m,i,j)==dropOff){
				print_blue(dropOff);
			}
			else if(found){
				print_red(PETA(m,i,j));
			}
			else if(ELMT_M(m, idxP, idxD) == 1){
				print_green(PETA(m,i,j));
			}
			else{
				printf("%c",PETA(m,i,j));
			}
			j++;
		}
		i++;
	}
}
	
