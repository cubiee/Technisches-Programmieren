#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

void menue(void);
int load_file(char *filename, char **buffer);
int write_file(char *filename, char *data);

char verschluesseln(char character, int n);

int main(int argc, char *argv[]){
    if(argc < 4){
        menue();
    }else{
		char *datei_inhalt;
		int characters_loaded = 0;
		if ((characters_loaded = load_file(argv[2], &datei_inhalt)) < 0){
			printf("Eingabedatei konnte nicht geöffnet werden!\n");
			menue();
		}
		else{
			for (int i = 0; i < characters_loaded; i++){
				datei_inhalt[i] = verschluesseln(datei_inhalt[i], atoi(argv[1]));
			}
			write_file(argv[3], datei_inhalt);
		}
    }
    return 0;
}


void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./geheim <schluessel> <eingabedatei> <ausgabedatei>\n");
}

int load_file(char *filename, char **buffer){
	FILE *datei;
	if (NULL == (datei = fopen(filename, "r"))){
		return -1;
	}
	else
	{
		fseek(datei, 0, SEEK_END);
		long anzahl_zeichen = ftell(datei);
		*buffer = malloc((anzahl_zeichen + 1)*sizeof(char));
		rewind(datei);
		for (int i = 0; i < anzahl_zeichen; i++){
			(*buffer)[i] = fgetc(datei);
		}
		fclose(datei);
		(*buffer)[anzahl_zeichen] = '\0';
		return anzahl_zeichen;
	}
}

int write_file(char *filename, char *data){
	FILE *datei;
	if (NULL == (datei = fopen(filename, "w"))){
		return FALSE;
	}
	else
	{
		fputs(data, datei);
		fclose(datei);
		return TRUE;
	}
}

char verschluesseln(char character, int key){
	key = key % 26;
	if (character >= 'a' && character <= 'z'){
		return ((character - 'a' + key) % 26) + 'a';
	}
	if (character >= 'A' && character <= 'Z'){
		return ((character - 'A' + key) % 26) + 'A';
	}
	else
	{
		return character;
	}
}