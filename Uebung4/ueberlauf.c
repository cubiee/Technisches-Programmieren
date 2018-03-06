#include <stdio.h>


int main(void){
	unsigned char zahl_1 = 0;
	char zahl_2 = 0;
	int max_value_1 = 255; 
	int max_value_2 = 127;

	printf("max_value_1 %i\n",max_value_1);
	printf("max_value_2 %i\n",max_value_2);
	
	zahl_1 = (char)(max_value_1 - 5);
	zahl_2 = (char)(max_value_2 - 5);
	
	for( int counter = -5; counter < 5; counter++){
		zahl_1++;
		zahl_2++;
		printf("Zahl 1: %5i  Zahl 2: %5i\n",zahl_1 , zahl_2);
	}	
	return 0;
}

