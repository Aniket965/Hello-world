/*
Create a C program that displays the perimeter and area of a rectangle.
*/

#include <stdlib.h>
#include <stdio.h>

void retangulo(); //Declaring the functiong

int main()
{
    retangulo(); //Calling the function
    return 0;
}

//Creating the function
void retangulo()
{
	float h, w, perimeter, area;
	
	printf("Tell me the width of the rectangle in cm: \n");
	scanf("%f", &w);
	printf("Tell me the height of the rectangle in cm: \n");
	scanf("%f", &h);
	
	area =  (h*w);
	perimeter = 2*(h+w);
	
	printf("The perimeter is: %.2f\n", perimeter);
	printf("The area is: %.2f\n", area);
		
}
