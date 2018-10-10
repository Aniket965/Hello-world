#include <stdio.h>
#include <stdlib.h>

int main (int argc,char **argv)
{
	char s[30];

	printf("please write your name\n");

	scanf("%s",s);

	printf("your name is %s\n",&s);

	return 0;
}