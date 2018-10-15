
/*
finding the minimum and maximum with
less than twice the cost

Walk through elements by pairs

Compare each element in pair to the other

Compare the largest to maximum, smallest to minimum

Total cost: 3 comparisons per 2 elements = 3n/2

*/
#include <stdio.h>
#include <limits.h>


int main()
{
    int N,i;
    printf("Enter the size of the array\n");
    scanf("%d",&N);
    int a[N];
    printf("Enter the elements\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
   
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<N;i+=2)
    {
        if(i+1==N)//checking for odd sized array
        {
            if(a[i]>max)
                max=a[i];
            else if(a[i]<min)
                min=a[i];
        }
        else// for all other even sized array
        {
            if(a[i]>a[i+1])
            {
                if(a[i]>max)
                    max=a[i];
                if(a[i+1]<min)
                    min=a[i+1];
            }
            else
            {
                if(a[i+1]>max)
                    max=a[i+1];
                if(a[i]<min)
                    min=a[i];
            }
        }
    }
    printf("The maximum is %d\n",max);
    printf("The minimum is %d",min);
    return 0;
}