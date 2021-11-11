#include <stdio.h>
#include <stdlib.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"

Word currentWord;
boolean endWord;
void ignoreBlank(){
	/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
   while(currentChar == BLANK || currentChar =='\n'&& currentChar != EOF ){
   		adv();
   }
}


void startWord(){
	/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    start();
    ignoreBlank();
    if(currentChar == EOF){
    	endWord = true;
	}
	else {
		endWord = false;
		copyWord();
	}
}
void advWord(){
	/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
	ignoreBlank();
	if(currentChar == EOF){
		endWord= true;
	}
	else{
		copyWord();
	}
}


void copyWord(){
	/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
	int x;
	x = 0;
	while ((currentChar != EOF) && (currentChar != BLANK) && (currentChar !='\n')){
		if (x<CAPACITY){
			currentWord.contents[x] = currentChar;
		}
		adv();
		x++;
	}
	if(x<CAPACITY) currentWord.length = x;
	else currentWord.length = CAPACITY;
}

