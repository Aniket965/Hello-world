#include<stdio.h>

void complete_waste()
{
	while(1)
		asm volatile("nop");
}

int main()
{
	complete_waste();
	return 0;
}
