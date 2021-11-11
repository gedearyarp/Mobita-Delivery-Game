/* File: charmachine.c */
/* Implementasi Character Engine */

#include "charmachine.h"
#include <stdio.h>
#include <stdlib.h>

char currentChar;
boolean eot;

static FILE * tape;
static int retval;

void startFile() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	char ch, file_name[25];
	printf("Masukkan nama file : ");
	gets(file_name);
	tape = fopen(file_name, "r");
	if (tape == NULL)
	{
		perror("Error ketika membuka file\n");
		exit(EXIT_FAILURE);
		return;
   	}
	adv();
}
void start() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
	tape = stdin;
	adv();
}

void adv() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama, 
          currentChar mungkin = MARK
		      Jika  currentChar = MARK maka EOP akan menyala (true) */

	/* Algoritma */
//	retval = fscanf(tape,"%c",&currentChar);
	currentChar = fgetc(tape);
	eot = (currentChar == EOF);
	if (eot) {
       fclose(tape);
 	}
}
