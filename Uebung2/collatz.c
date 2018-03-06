#include <stdio.h>

void flush(void);

int main(){
	int startwert = 0;
	
	printf("Collatz Folge:\n");
	printf("Bitte Startwert eingeben: ");
	scanf("%i", & startwert);
	while(startwert <= 0){
		flush();
		printf("Ungültiger Eingabewert bitte Startwert erneut angeben!\n");
		printf("Bitte Startwert eingeben: ");
		scanf("%i", & startwert);
	}
	printf("a0 = %i\n",startwert);
	printf("%i ",startwert);
	while(startwert != 1){
		if(startwert % 2 == 0){
			startwert = startwert / 2 ;
			printf("%i ", startwert);
		}else{
			startwert = 3 * startwert + 1;
			printf("%i ", startwert);
		}
	}
	printf("\n");
	return 0;
}


void flush(void){
	int char_buff = 0;
	while ((char_buff = getchar()) != '\n' && char_buff != EOF) { }
}