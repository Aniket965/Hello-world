
#include <stdio.h> 
int main() 
{ 
    int a = 1; 
    char b ='G'; 
    double c = 3.14; 
    printf("Hello World!\n"); 
    printf("Hello! I am a character. My value is %c and "
           "my size is %lu byte.\n", b,sizeof(char));   
    printf("Hello! I am an integer. My value is %d and "
           "my size is %lu  bytes.\n", a,sizeof(int)); 
    printf("Hello! I am a double floating point variable."
           " My value is %lf and my size is %lu bytes.\n",c,sizeof(double)); 
    printf("Bye! See you soon. :)\n"); 
    return 0; 
} 
