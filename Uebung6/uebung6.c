#include <stdio.h>

#define TRUE 1
#define FALSE 0

unsigned int zahl_einlesen(void);
int quersumme(int);
void pythagoras(int);
int teilbarkeit(int);
unsigned int menue(void);
void kontrollstruktur()

int main(void){
	int repeat = TRUE;
	do{

	} while (repeat == TRUE);
	printf("Programm Beendet!\n");
	return 0;
}

unsigned int menue(void){
	printf("Bitte waehlen Sie :\n 1 – Berechnung der Quersumme\n 2 – Berechnung Pythagoras\n 3 – Zahl n durch t teilbar\n 4 – Sonst was\n 0 – Ende)\n");
	
}