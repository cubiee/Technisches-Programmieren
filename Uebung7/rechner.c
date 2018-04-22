#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


typedef struct bruch_s{
	int zaehler;
	int nenner;
} BRUCH;

void menue(void);
int validate_input(char *input[], BRUCH *bruch1, BRUCH *bruch2);
void kuerzen(BRUCH ungekuerzt, BRUCH *gekuerzt);
void ausgabe(BRUCH ungekuerzt, BRUCH gekuerzt);

void addition(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis);
void subtraktion(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis);
void multiplikation(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis);
void division(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis);


int main(int argc, char *argv[]){
	BRUCH eingabeA;
	BRUCH eingabeB;
	BRUCH ergebnis_UG;
	BRUCH ergebnis_G;
	if (argc < 6 || argc > 6){
		menue();
	}else if (validate_input(argv, &eingabeA, &eingabeB) == FALSE){
		printf("Ungueltige Zahlenwerte! Kein Integer oder Nenner 1 oder 2 = 0\n");
		menue();
	}else{
		if (strcmp(argv[3], "a") == 0){
			addition(eingabeA, eingabeB, &ergebnis_UG);
			kuerzen(ergebnis_UG, &ergebnis_G);
			ausgabe(ergebnis_UG, ergebnis_G);
		}
		else if (strcmp(argv[3], "s") == 0){
			subtraktion(eingabeA, eingabeB, &ergebnis_UG);
			kuerzen(ergebnis_UG, &ergebnis_G);
			ausgabe(ergebnis_UG, ergebnis_G);
		}
		else if (strcmp(argv[3], "m") == 0){
			multiplikation(eingabeA, eingabeB, &ergebnis_UG);
			kuerzen(ergebnis_UG, &ergebnis_G);
			ausgabe(ergebnis_UG, ergebnis_G);
		}
		else if (strcmp(argv[3], "d") == 0){
			division(eingabeA, eingabeB, &ergebnis_UG);
			kuerzen(ergebnis_UG, &ergebnis_G);
			ausgabe(ergebnis_UG, ergebnis_G);
		}
		else{
			printf("Ungueltiger Operator!\n");
			menue();
		}
	}
	return 0;
}


void menue(void){
	printf("Aufruf durch:\n     ./rechner zahler1 nenner1 op zaehler2 nenner2\n");
	printf("op:\n     a = Addition\n     s = Subtraktion\n     m = Multiplikation\n     d = Division\n");
	return;
}

int validate_input(char *input[], BRUCH *bruch1, BRUCH *bruch2){
	char suchstring[] = { 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~"
	};

	if (strpbrk(input[1], suchstring) != NULL){
		return FALSE;
	}else if ((strpbrk(input[2], suchstring) != NULL) || (atoi(input[2]) == 0)){
		return FALSE;
	}else if (strpbrk(input[4], suchstring) != NULL){
		return FALSE;
	}else if ((strpbrk(input[5], suchstring) != NULL) || (atoi(input[5]) == 0)){
		return FALSE;
	}else{
		bruch1->zaehler = atoi(input[1]);
		bruch1->nenner = atoi(input[2]);
		bruch2->zaehler = atoi(input[4]);
		bruch2->nenner = atoi(input[5]);
		return TRUE;
	}
}

void kuerzen(BRUCH ungekuerzt, BRUCH *gekuerzt){
	if (ungekuerzt.zaehler % ungekuerzt.nenner == 0){
		gekuerzt->zaehler = ungekuerzt.zaehler / ungekuerzt.nenner;
		gekuerzt->nenner = 1;
	}else{
		int rest;
		int zahl = ungekuerzt.zaehler;
		int teiler = ungekuerzt.nenner;
		do{
			rest = zahl % teiler;
			zahl = teiler;
			teiler = rest;
		} while (rest != 0);
		gekuerzt->zaehler = ungekuerzt.zaehler / zahl;
		gekuerzt->nenner = ungekuerzt.nenner / zahl;
	}
	return;
}

void ausgabe(BRUCH ungekuerzt, BRUCH gekuerzt){
	printf("Ergebnis:\n");
	printf("Ungekuerzt: %i/%i\n", ungekuerzt.zaehler, ungekuerzt.nenner);
	if (gekuerzt.nenner == 1){
		printf("Gekuerzt  : %i\n", gekuerzt.zaehler);
	}else{
		printf("Gekuerzt  : %i/%i\n", gekuerzt.zaehler, gekuerzt.nenner);
	}
	return;
}


void addition(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis){
	if (bruch1.nenner == bruch2.nenner){
		ergebnis->nenner = bruch1.nenner;
		ergebnis->zaehler = bruch1.zaehler + bruch2.zaehler;
	}else{
		ergebnis->zaehler = (bruch1.zaehler * bruch2.nenner) + (bruch2.zaehler * bruch1.nenner);
		ergebnis->nenner = bruch1.nenner * bruch2.nenner;
	}
	return;
}

void subtraktion(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis){
	if (bruch1.nenner == bruch2.nenner){
		ergebnis->nenner = bruch1.nenner;
		ergebnis->zaehler = bruch1.zaehler - bruch2.zaehler;
	}
	else{
		ergebnis->zaehler = (bruch1.zaehler * bruch2.nenner) - (bruch2.zaehler * bruch1.nenner);
		ergebnis->nenner = bruch1.nenner * bruch2.nenner;
	}
	return;
}

void multiplikation(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis){
	ergebnis->zaehler = bruch1.zaehler * bruch2.zaehler;
	ergebnis->nenner = bruch1.nenner * bruch2.nenner;
	return;
}

void division(BRUCH bruch1, BRUCH bruch2, BRUCH *ergebnis){
	ergebnis->zaehler = bruch1.zaehler * bruch2.nenner;
	ergebnis->nenner = bruch1.nenner * bruch2.zaehler;
	return;
}