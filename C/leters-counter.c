#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
int main(void)
{
	char n1[50];
	int c=0;
	printf("Norman Daniel Vicente Orellana\n\n");
	printf("Enter word: ");
	scanf("%s", &n1);
	c=strlen(n1);
	printf("\nNumber of digits : %d\n", c);
	system("pause");	
	return 0;
}
