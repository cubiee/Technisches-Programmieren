#include <stdio.h>

void flush(void);

int main(void){
	int endwert = 0;
	int buffer_a = 0;
	int buffer_b = 0;
	
	printf("Pythagoräische Zahlen\n");
	printf("Bitte Endwert eingeben: ");
	scanf("%i", & endwert);
	while(endwert <= 0){
		flush();
		printf("Ungültiger Eingabewert bitte Endwert erneut angeben!\n");
		printf("Bitte Endwert eingeben: ");
		scanf("%i", & endwert);
	}
		
	for(int zahl_c = 1; zahl_c <= endwert; zahl_c++){
		for(int zahl_a = 1; zahl_a <= endwert; zahl_a++){
			for(int zahl_b = 1; zahl_b <= endwert; zahl_b++){
				if((zahl_a*zahl_a + zahl_b*zahl_b == zahl_c*zahl_c)&&(buffer_a != zahl_a)&&(buffer_b != zahl_b)){
					buffer_a = zahl_b;
					buffer_b = zahl_a;
					printf("Fuer a = %4i, b = %4i, c = %4i: %4i + %4i = %4i\n", zahl_a, zahl_b, zahl_c, zahl_a*zahl_a, zahl_b*zahl_b, zahl_c*zahl_c);
				}
			}
		}
	}
	return 0;
}


void flush(void){
	int char_buff = 0;
	while ((char_buff = getchar()) != '\n' && char_buff != EOF) { }
}