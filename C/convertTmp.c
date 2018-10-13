#include <stdio.h>

float FahrenheitToCelsius (float temp)
{
   float fTemp = (temp*(9.0/5.0))+32.0;

   return fTemp;
}

int main()
{
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = FahrenheitToCelsius(celsius); 
    
    printf("%.02f Celsius = %.02f Fahrenheit", celsius, fahrenheit);

    return 0;
}
