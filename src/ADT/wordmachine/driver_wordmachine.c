#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"
#include <stdio.h>

int main(){
	startWord();
	int geser = currentWord.length;
	if(geser >26) geser = geser - 26;
	int i =0;
	while(!endWord) {
		
		for(i=0;i<currentWord.length;i++) {
			if(currentWord.contents[i]+geser<=90)
				printf("%c",currentWord.contents[i]+geser);
			else 
				printf("%c",currentWord.contents[i]+geser-26);
		}
		if(currentChar!=MARK)printf(" ");
		advWord();
	}
	printf(".\n");
	return 0;
}
