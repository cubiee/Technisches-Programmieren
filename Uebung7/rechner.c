#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void menue(void);
int validate_input(char *input[], int buffer[]);
void kuerzen(int data_input[]);

void addition(int data_input[], int data_output[]);
void subtraktion(int data_input[], int data_output[]);
void multiplikation(int data_input[], int data_output[]);
void division(int data_input[], int data_output[]);

int main(int argc, char *argv[]){
	if (argc < 6 || argc > 6){
		menue();
		return 0;
	}

	int userinput[4] = { 0 };

	if (validate_input(argv, userinput) == FALSE){
		printf("Ungueltige Zahlenwerte! Kein Integer oder Nenner 1 oder 2 = 0\n");
		menue();
		return 0;
	}

	int ergebnis[4] = { 0 };

	if (strcmp(argv[3], "a") == 0){
		addition(userinput, ergebnis);
	}else if (strcmp(argv[3], "s") == 0){
		subtraktion(userinput, ergebnis);
	}else if (strcmp(argv[3], "m") == 0){
		multiplikation(userinput, ergebnis);
	}else if (strcmp(argv[3], "d") == 0){
		division(userinput, ergebnis);
	}else{
		printf("Ungueltiger Operator!\n");
		menue();
	}
	
	printf("Ungekuerzt: %d/%d\nGekuerzt: %d/%d\n", ergebnis[0], ergebnis[1], ergebnis[2], ergebnis[3]);
	return 0;
}

void menue(void){
	printf("Aufruf durch:\n     ./rechner zahler1 nenner1 op zaehler2 nenner2\n");
	printf("op:\n     a = Addition\n     s = Subtraktion\n     m = Multiplikation\n     d = Division\n");
	return;
}

int validate_input(char *input[], int buffer[]){
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

	buffer[0] = atoi(input[1]);
	buffer[1] = atoi(input[2]);
	buffer[2] = atoi(input[4]);
	buffer[3] = atoi(input[5]);

	return TRUE;
}

void kuerzen(int data_input[]){
	if (data_input[0] % data_input[1] == 0){
		data_input[2] = data_input[0] / data_input[1];
		data_input[3] = 1;
	}else{
		int rest;
		int zahl = data_input[0];
		int teiler = data_input[1];
		do{
			rest = zahl % teiler;
			zahl = teiler;
			teiler = rest;
		} while (rest != 0);
		data_input[2] = data_input[0] / zahl;
		data_input[3] = data_input[1] / zahl;
	}
	return;
}

void addition(int data_input[], int data_output[]){
	if (data_input[1] == data_input[3]){
		data_output[1] = data_input[1];
		data_output[0] = data_input[0] + data_input[2];
	}else{
		data_output[0] = (data_input[0] * data_input[3]) + (data_input[2] * data_input[1]);
		data_output[1] = data_input[1] * data_input[3];
	}
	kuerzen(data_output);
	return;
}

void subtraktion(int data_input[], int data_output[]){
	if (data_input[1] == data_input[3]){
		data_output[1] = data_input[1];
		data_output[0] = data_input[0] - data_input[2];
	}
	else{
		data_output[0] = (data_input[0] * data_input[3]) - (data_input[2] * data_input[1]);
		data_output[1] = data_input[1] * data_input[3];
	}
	kuerzen(data_output);
	return;
}

void multiplikation(int data_input[], int data_output[]){
	data_output[0] = data_input[0] * data_input[2];
	data_output[1] = data_input[1] * data_input[3];

	kuerzen(data_output);
	return;
}

void division(int data_input[], int data_output[]){
	data_output[0] = data_input[0] * data_input[3];
	data_output[1] = data_input[1] * data_input[2];
	kuerzen(data_output);
	return;
}