#include <stdio.h>


int main(void){
	int character = 32;
	for(int count = 0; count < 24; count++){
		printf("%3i = 0x%x = %c   ",character,character,(char)character);
		printf("%3i = 0x%x = %c   ",character+1,character+1,(char)(character+1));
		printf("%3i = 0x%x = %c   ",character+2,character+2,(char)(character+2));
		printf("%3i = 0x%x = %c\n",character+3,character+3,(char)(character+3));
		character = character + 4;
	}
	return 0;
}