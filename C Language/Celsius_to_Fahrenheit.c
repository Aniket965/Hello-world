#include <stdio.h>

void main(){
	printf("\n**Covert the temperature from degree Celsius to degree Fahrenheit**\n");
	
	float oC,F;
	
	printf("Enter degrees Celsius:");
	scanf("%f",&oC);
         F=oC*1.8+32;
	printf("fahrenhiet value is :%f",F);
}
