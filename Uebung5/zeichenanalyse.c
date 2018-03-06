#include <stdio.h>
#define MAX_LENGTH_ZEICHEN 1000

int character_check(int data_length, int char_length, unsigned char *data_array ,unsigned  char character_array[2][char_length]);

int main(void){
	unsigned char user_data[] = {"AA-BCDEFGHIJKLMNOPQRSTUVWXYZ*"};
	unsigned char compare_character[][27] = {
		{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','*'},
		{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
	};
	int user_data_size = sizeof(user_data)/sizeof(unsigned char);
	int compare_character_size = (sizeof(compare_character)/sizeof(unsigned char))/2;
	
	int check = character_check(user_data_size -1, compare_character_size, user_data, compare_character);
	
	int count = 0;
	for(count = 0 ; count < compare_character_size; count++){
		printf(" %c ",(char)compare_character[0][count]);
	}
	printf("\n");
	
	for(count = 0 ; count < compare_character_size; count++){
		printf(" %i ",compare_character[1][count]);
	}
	printf("\n");	
	
	
	printf("User array size %i\n",user_data_size);
	printf("Compare array size %i\n", compare_character_size);
	
	
	return 0;
}

int character_check(int data_length, int char_length, unsigned char *data_array ,unsigned char character_array[2][char_length]){
	int i,j,success = 0;
	for(i = 0; i < char_length; i++){
		for(j = 0; j < data_length; j++){
			if(character_array[0][i] == '*'){
				if(((data_array[j] >= 65)&&(data_array[j] <= 90))||((data_array[j] >=97)&&(data_array[j] <= 122))){

				}else{
					character_array[1][i]++;
				}
			}else{
				if((data_array[j] == character_array[0][i])||(data_array[j] == (character_array[0][i] + 32))){
					character_array[1][i]++;
				}
			}
		}
	}	
	return success;
}
