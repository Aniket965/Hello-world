#include <stdio.h>

void main(){
	printf("\n*****Covert the temperature from degree Celsius to degree Fahrenheit*****\n\n\n");
	
	float oC;
	
	printf("Enter degrees Celsius: ");
	scanf("%f", &oC);

	printf("--->Degrees Fahrenheit is: %.1f", oC * 1.8 + 32);
}
