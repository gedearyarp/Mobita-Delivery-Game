#include "../ADT/boolean.h"
#include "../ADT/wordmachine/wordmachine.h"
#include "../ADT/wordmachine/charmachine.h"
#include "../pesanan/pesanan.h"
#include "../ADT/point/point.h"
#include "map.h"
#include "../konfigurasi/konfigurasi.h"
#include "../pcolor/pcolor.h"
#include <stdio.h>


void mapCommand(MAP m,POINT p,int waktu,char dropOff,List to_do_list){
	//fungsi untuk menampilkan peta
	int i=0,j=0,a,b,idxP,idxD;
	char pickUp[nOrder(m)];
	boolean found = false;
	if(!isEmptyList(to_do_list)){
		Address temp =FIRST(to_do_list);
		a=0;
		while(temp!=NULL){
			pickUp[a] = Label(PICK_P(INFO(temp)));
			a++;
			temp = NEXT(temp); 
		}
	}
	for(b=0;b<=nEff(m);b++){
		if(Label(p)==NAMA(m,b))idxP = b;
	}
	for(i=0;i<=PETA_Y(m)+1;i++){
		for(j=0;j<=PETA_X(m)+1;j++){
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
			while(b<=nEff(m)){
				if(PETA(m,i,j)==NAMA(m,b))idxD=b;
				b++;
			}
			if(p.label == PETA(m,i,j)){
				print_yellow(PETA(m,i,j));
			}
			else if(PETA(m,i,j)==dropOff){
				print_blue(dropOff);
			}
			else if(found){
				print_red(PETA(m,i,j));
			}
			else if(idxP<=nEff(m)&&idxD<=nEff(m)&&ELMT_M(m, idxP, idxD) == 1 && PETA(m,i,j)!='*'){
				print_green(PETA(m,i,j));
			}
			else{
				printf("%c",PETA(m,i,j));
			}
		}
		printf("\n");
	}
}
	
