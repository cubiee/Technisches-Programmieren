#include <stdio.h>

#define TRUE 1
#define FALSE 0

unsigned int zahl_einlesen(void);
int menue(void);
void controll(void);




int main(void){
	controll();
	return 0;
}


void controll(void){
	int repeat = TRUE;
	int auswahl = 0;
	do{
		auswahl = menue();
		switch (auswahl){
			case 0: 
				printf("Abbruch\n"); 
				repeat = FALSE;
				break;
			case 1: 
				printf("Nummer 1\n");
				break;
			case 2:
				printf("Nummer 2\n");
				break;
			case 3:
				printf("Nummer 3\n");
				break;
			case 4:
				printf("Nummer 4\n");
				break;
		}
	} while (repeat != FALSE);
}




int menue(void){
	printf("Bitte waehlen Sie :\n");
	printf("1 – Berechnung der Quersumme\n");
	printf("2 – Berechnung Pythagoras\n");
	printf("3 – Zahl n durch t teilbar\n");
	printf("4 – Sonst was\n");
	printf("0 – Ende\n");
	
	int user_value = 0;
	int char_buffer = 0;
	int pruefe = scanf("%i", &user_value);
	while ((pruefe != 1) || (user_value < 0) || (user_value > 4)){
		while ((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
		printf("Ungueltige eingabe!\n");
		pruefe = scanf("%i", &user_value);
	}
	return user_value;
}

