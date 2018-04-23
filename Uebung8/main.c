#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 10000

void menue(void);

int main(int argc, char *argv[]){
    if(argc < 3){
        menue();
    }else{

        FILE *klartext;
        FILE *verschluesselt;

        if(NULL == (klartext = fopen(argv[1], "r"))){
            printf("Konnte datei nicht öffnen\n");
        }else if(NULL == (verschluesselt = fopen("verschluesselt.txt", "w"))){
            printf("Konnte datei nicht öffnen\n");
        }else{
            char dateipuffer[BUFFERSIZE] = { 0 };
            char zeilenpuffer[1000] = { 0 };

            int startpoint = 0;
			int i = 0;
            while((NULL != (fgets(zeilenpuffer, 1000, klartext))) && (startpoint < BUFFERSIZE - 1000)){

                for(i = startpoint; i < (startpoint + strlen(zeilenpuffer)); i++){
                    dateipuffer[i] = zeilenpuffer[i - startpoint]; 
                }
                startpoint += strlen(zeilenpuffer);
            }
			for (i = 0; i < strlen(dateipuffer); i++){
				if ((dateipuffer[i] >= 'A') && (dateipuffer[i] < 'Z')){
					dateipuffer[i] += 1 ;
				}
				else if (dateipuffer[i] == 'Z'){
					dateipuffer[i] = 'A';
				}
				else if ((dateipuffer[i] >= 'a') && (dateipuffer[i] < 'z')){
					dateipuffer[i] += 1;
				}
				else if (dateipuffer[i] == 'z'){
					dateipuffer[i] = 'a';
				}
			}
			fputs(dateipuffer, verschluesselt);
        }
    }
    return 0;
}


void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./verschlüsselung <dateiname> <versatz>\n");
}