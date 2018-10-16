#include <stdio.h>

void main(){
	printf("\n*****Check wether a year is a leap year or not*****\n\n\n");
	
	int year;
	
	printf("Enter a year\n");
	scanf("%d", &year);

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("--->This year is a leap year");
	else
		printf("--->This year is not a leap year");
}
