#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 10000

int main(int argc, char *argv[]){
    if(argc < 3){
        menue();
    }else{
        FILE *klartext;
        FILE *verschluesselt;
        if(NULL == (klartext = fopen(argv[1], "r"))){
            printf("Konnte datei nicht öffnen\n");
        }else if(NULL == (verschluesselt = fopen("verschluesselt.txt", "r"))){
            printf("Konnte datei nicht öffnen\n");
        }else{
            char dateipuffer[BUFFERSIZE] = { 0 };
            char zeilenpuffer[BUFFERSIZE] = { 0 };
            int startpoint = 0;
            while(NULL == (fgets(zeilenpuffer, BUFFERSIZE, klartext))){
                for(int i = startpoint; i < (startpoint + strlen(zeilenpuffer); i++)){
                    dateipuffer[i] = zeilenpuffer[i - startpoint]; 
                }
                startpoint += strlen(zeilenpuffer);
            }
            printf("%s", )
        }
    }
    return 0;
}
