#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void menue(void);
int check_if_valid_input(char *input[]);
void kuerzen(int zaehler, int nenner);

void addition(int zaehler1, int nenner1, int zaehler2, int nenner2);
void subtraktion(int zaehler1, int nenner1, int zaehler2, int nenner2);
void multiplikation(int zaehler1, int nenner1, int zaehler2, int nenner2);
void division(int zaehler1, int nenner1, int zaehler2, int nenner2);

int main(int argc, char *argv[]){
	if (argc < 6 || argc > 6){
		menue();
		return 0;
	}

	if (check_if_valid_input(argv) == FALSE){
		printf("Ungueltige Zahlenwerte! Kein Integer oder Nenner 1 oder 2 = 0\n");
		menue();
		return 0;
	}

	if (strcmp(argv[3], "a") == 0){
		addition(atoi(argv[1]), atoi(argv[2]), atoi(argv[4]), atoi(argv[5]));
	}else if (strcmp(argv[3], "s") == 0){
		subtraktion(atoi(argv[1]), atoi(argv[2]), atoi(argv[4]), atoi(argv[5]));
	}else if (strcmp(argv[3], "m") == 0){
		multiplikation(atoi(argv[1]), atoi(argv[2]), atoi(argv[4]), atoi(argv[5]));
	}else if (strcmp(argv[3], "d") == 0){
		division(atoi(argv[1]), atoi(argv[2]), atoi(argv[4]), atoi(argv[5]));
	}else{
		printf("Ungueltiger Operator!\n");
		menue();
	}

	return 0;
}

void menue(void){
	printf("Aufruf durch:\n     ./rechner zahler1 nenner1 op zaehler2 nenner2\n");
	printf("op:\n     a = Addition\n     s = Subtraktion\n     m = Multiplikation\n     d = Division\n");
	return;
}

int check_if_valid_input(char *input[]){
	char suchstring[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+,.";
	//zaehler 1
	if (strpbrk(input[1], suchstring) != NULL){
		return FALSE;
	}
	//nenner 1
	if ((strpbrk(input[2], suchstring) != NULL) || (atoi(input[2]) == 0)){
		return FALSE;
	}
	//zaehler 2
	if (strpbrk(input[4], suchstring) != NULL){
		return FALSE;
	}
	//nenner 2
	if ((strpbrk(input[5], suchstring) != NULL) || (atoi(input[5]) == 0)){
		return FALSE;
	}
	return TRUE;
}

void kuerzen(int zaehler, int nenner){
	if (zaehler % nenner == 0){
		printf("Gekuerzt  : %i\n", zaehler / nenner);
	}else{
		int rest;
		int zahl = zaehler;
		int teiler = nenner;
		do{
			rest = zahl % teiler;
			zahl = teiler;
			teiler = rest;
		} while (rest != 0);
		printf("Gekuerzt  : %i/%i\n", zaehler / zahl, nenner / zahl);
	}
	return;
}

void addition(int zaehler1, int nenner1, int zaehler2, int nenner2){
	int zaehlerergebnis;
	int nennergebnis;
	if (nenner1 == nenner2){
		nennergebnis = nenner1;
		zaehlerergebnis = zaehler1 + zaehler2;
	}else{
		zaehlerergebnis = (zaehler1 * nenner2) + (zaehler2 * nenner1);
		nennergebnis = nenner1 * nenner2;
	}
	printf("Ungekuerzt: %i/%i\n", zaehlerergebnis, nennergebnis);
	kuerzen(zaehlerergebnis, nennergebnis);
	return;
}

void subtraktion(int zaehler1, int nenner1, int zaehler2, int nenner2){
	int zaehlerergebnis;
	int nennergebnis;
	if (nenner1 == nenner2){
		nennergebnis = nenner1;
		zaehlerergebnis = zaehler1 - zaehler2;
	}
	else{
		zaehlerergebnis = (zaehler1 * nenner2) - (zaehler2 * nenner1);
		nennergebnis = nenner1 * nenner2;
	}
	printf("Ungekuerzt: %i/%i\n", zaehlerergebnis, nennergebnis);
	kuerzen(zaehlerergebnis, nennergebnis);
	return;
}

void multiplikation(int zaehler1, int nenner1, int zaehler2, int nenner2){
	int zaehlerergebnis = zaehler1 * zaehler2;
	int nennergebnis = nenner1 * nenner2;
	printf("Ungekuerzt: %i/%i\n", zaehlerergebnis, nennergebnis);
	kuerzen(zaehlerergebnis, nennergebnis);
	return;
}

void division(int zaehler1, int nenner1, int zaehler2, int nenner2){
	int zaehlerergebnis = zaehler1 * nenner2;
	int nennergebnis = nenner1 * zaehler2;
	printf("Ungekuerzt: %i/%i\n", zaehlerergebnis, nennergebnis);
	kuerzen(zaehlerergebnis, nennergebnis);
	return;
}