#include <stdio.h>
#define MAX_LENGTH_ZAHLEN 10 //Länge des datenarrays muss durch wiederholungsrate teilbar sein
#define WIEDERHLUNGSRATE 5 //Gibt an wieviele werte nacheinander eingelesen werden sollen

int read_usr_int(void); //Funktion zum werte einlesen
void flush(void); //Funktion zum löschen des inputbuffer
int bubble_sort(int *array, int size); //Funktion zum sortieren des arrays
void bswap(int *array, int index); //Funktion zum tauschen zweier array elemente (wird nur vom bubblesort benutzt)

int main(void){
	int i = 0; //counter variable wird mehrfach verwendet
	int repeat_flag = 1; //variable zum steuern de while scleifen 1 = weiter 0 = abbruch
	int startpunkt = 0; //variable zum bestimmen des startpunktes ab dem die 5 zahlen ins array geschrieben werden
	int buffer = 0; //buffer zum berechnen des mittelwertes
	char check_if_n = ' '; //buffer zur überprüfung des abbruchcharachters für die nutzereingabe
	int endpunkt = 0; //gibt das letzte feld im array an das beschrieben wurde nach dem beenden der eingabe = startpunkt - 1
	int position = 0; //array stelle des minimalwertes
	float mittelwert = 0.0f; // mittelwert
	
	//array für nutzereingabe anlegen und mit 0 beschreiben
	int userzahlen[MAX_LENGTH_ZAHLEN];
	for(i = 0; i < MAX_LENGTH_ZAHLEN; i++){
		userzahlen[i] = 0;
	}
	//array für sortierte nutzereingabe anlegen und mit 0 beschreiben
	int userzahlen_sortiert[MAX_LENGTH_ZAHLEN];
	for(i = 0; i < MAX_LENGTH_ZAHLEN; i++){
		userzahlen_sortiert[i] = 0;
	}

	//Einlesen der Werte läuft solange durch bis das array voll ist oder durch den nutzer beendet wird
	do{
		printf("Bitte %i Werte eingeben : \n", WIEDERHLUNGSRATE);		
		for(i = 0; i < WIEDERHLUNGSRATE; i++){
			userzahlen[startpunkt + i] = read_usr_int();
		}
		
		//startpunkt um 5 nach rechts schieben
		startpunkt = startpunkt + 5;
		
		//abbruch falls startpunkt das ende des arrays erreicht 
		if(startpunkt <= MAX_LENGTH_ZAHLEN - 5){
			printf("Weiter? nein=n, sonst beliebiges Zeichen eingeben : ");
			flush();
			scanf("%c", & check_if_n);
			if(check_if_n == 'n'){
				repeat_flag = 0;
			}
		}else{
			printf("Maximalanzahl erreicht!\n");
			repeat_flag = 0;
		}
	}while(repeat_flag != 0);
	
	//endpunkt berechnen
	endpunkt = startpunkt - 1; 
	
	//array kopieren
	for(i = 0; i <= endpunkt; i++){
		userzahlen_sortiert[i] = userzahlen[i];
	}
	
	//kopie des array sortieren
	bubble_sort(userzahlen_sortiert,endpunkt);
	
	//Minimalwert suchen 
	repeat_flag = 1;
	i = 0;
	do{
		if(userzahlen[i] == userzahlen_sortiert[0]){
			//zahl gefunden -> while schleife abbrechen und position beschreiben
			repeat_flag = 0;
			position = i;
		}else{
			//kein treffer -> zur nächsten zahl weiter gehn
			i++;
		}
	}while(repeat_flag != 0);
	
	//Mittelwert berechnen 
	for(i = 0; i <= endpunkt; i++){
		buffer = buffer + userzahlen_sortiert[i];
	}
	mittelwert = (float)buffer / (float)(endpunkt+1) ; 
	
	//Werte ausgeben
	printf("Ausgabe Werte :\n");
	for(i = 0; i <= endpunkt; i += 5){
		printf("%i %i %i %i %i\n",userzahlen_sortiert[i],userzahlen_sortiert[i+1],userzahlen_sortiert[i+2],userzahlen_sortiert[i+3],userzahlen_sortiert[i+4]);
	}
	printf("Min Wert : %i kommt erstmalig vor an position %i\n",userzahlen_sortiert[0],position);
	printf("Mittelwert : %f\n",mittelwert);
	return 0;
}

int bubble_sort(int *array, int size){
	int iterations = size;
	int count = 0;
	int in_order = 0;
	if(0){
		return 0;
	}else{
		do{
			in_order = 0;
			for(count = 0; count < iterations; count++){
				if(array[count] > array[count + 1]){
					bswap(array,count);
				}else{
					in_order++;
				}
			}
			iterations--;
		}while((iterations > 0)&&(in_order < (size -1)));
		return 1;
	}
}

void bswap(int *array, int index){
	int array_buffer;
	array_buffer = array[index];
	array[index] = array[index + 1];
	array[index + 1] = array_buffer;
}

int read_usr_int(void){
	int eingabe = 0;
	int check_if_err = scanf("%i", &eingabe);
	while(check_if_err != 1){
		flush();
		printf("Keine ganze Zahl bitte letzten Wert erneut eingeben!\n");
		check_if_err = scanf("%i", &eingabe);
	}
	return eingabe;
}

void flush(void){
	int char_buffer = 0;
	while((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
}
