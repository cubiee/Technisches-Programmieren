/*teilnehmer.c
<PROGRAMMBESCHREIBUNG>
Datum: May  3 2018
Autor: <NAME> <VORNAME>
Mat.Nr.: <MATRIKELNUMMER>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define BUFFERSIZE 40
#define MAXTEILNEHMER 100

typedef struct teilnehmer_s{
	char name[BUFFERSIZE];
	char firma[BUFFERSIZE];
	float teilnahmebeitrag;
} TEILNEHMER;

TEILNEHMER new_teilnehmer(void);
TEILNEHMER *generate_data_set(void);
int save_data(TEILNEHMER *dataset, int teilnehmeranzahl, char *speicherort);

int main(void){
	TEILNEHMER *data = generate_data_set();
	for(int i = 0; i < MAXTEILNEHMER; i++){
		strcpy(data[i].name, "HALLO");
		strcpy(data[i].firma, "WELT");
		data[i].teilnahmebeitrag = (100.0f + i);
	}

	if(save_data(data, MAXTEILNEHMER, "save.dat") == FALSE){
		printf("FEHLER!\n");
	}

	return 0;
}

TEILNEHMER new_teilnehmer(void){
	TEILNEHMER new;
	strcpy(new.name, "");
	strcpy(new.firma, "");
	new.teilnahmebeitrag = 0.0f;
	return new;
}

TEILNEHMER *generate_data_set(){
	TEILNEHMER *dataset = malloc(MAXTEILNEHMER * sizeof(TEILNEHMER));
	for(int i = 0; i < MAXTEILNEHMER; i++){
		dataset[i] = new_teilnehmer();
	}
	return dataset;
}

int save_data(TEILNEHMER *dataset, int teilnehmeranzahl, char *speicherort){
	FILE *save_file;
	int status = TRUE;
	if(NULL == (save_file = fopen(speicherort, "w"))){
		status = FALSE;
		printf("Speicherdatei konnte nicht geöffnet werden!\n");
	}
	else{
		for(int i = 0; i < teilnehmeranzahl; i++){
			fprintf(save_file,"Name: %s \t Firma: %s \t Beitrag: %f\n",dataset[i].name, dataset[i].firma, dataset[i].teilnahmebeitrag);
		}
		fclose(save_file);
	}
	return status;
}
