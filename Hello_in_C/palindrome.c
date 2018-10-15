#include <stdio.h>
int main()
{
    int n, revInt = 0, rem, origInt;

    printf("Enter an integer: ");
    scanf("%d", &n);

    origInt = n;

    while( n!=0 )
    {
        rem = n%10;
        revInt = revInt*10 + rem;
        n /= 10;
    }

    // palindrome if orignalInteger and reversedInteger are equal
    if (origInt == revInt)
        printf("%d is a palindrome.", origInt);
    else
        printf("%d is not a palindrome.", origInt);
    
    return 0;
}