#include <stdio.h>
#include <stdlib.h>

int main (int argc,char **argv)
{
	char s[20];

	printf("write your name\n");

	scanf("%s",s);

	printf("your name is %s\n",&s);

	return 0;
}