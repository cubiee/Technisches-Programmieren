#include <stdio.h>

long long exponetiate(long long base ,long long exponent);

int main(void){
	int var_1 ;
	// int var_2 ;
	
	long long max_value_var_1 = (exponetiate(2,sizeof(var_1)*8)/2)-1;
	// long long max_value_var_2 = (exponetiate(2,sizeof(var_2)*8))-1;
	
	printf("Speicherbreite : %lu Maximalwert : %lli\n",sizeof(var_1)*8,max_value_var_1);
	
	
	return 0;
}

long long exponetiate(long long base ,long long exponent){
	long long result = 1;
	for(int exponent_counter = 1; exponent_counter <= exponent; exponent_counter++){
		result = result * base;
	}
	return result;
}