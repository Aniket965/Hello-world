/*Algorithm:

Input: A set of activities S = {a1,…, an}

Each activity has start time and a finish time

ai=(si, fi)

Two activities are compatible if and only if
their interval does not overlap

Output: a maximum-size subset of
mutually compatible activities

*/

#include<stdio.h>
int main()
{
    int n,i,j,k,m;
    printf("enter the number of activity\n");
    scanf("%d",&n);
    int a[2][n];
    printf("give the input according to a sorted sequence of earliest finish time");
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0)
            {
                printf("\nenter the start time of activity %d ",j);
                scanf("%d",&a[0][j]);
            }
            if(i==1)
            {
                printf("\nenter the finish time of the activity %d ",j);
                scanf("%d",&a[1][j]);
            }
        }
    }
    
    printf("The larger activity set and the activities that can be performed are(activity set must not be unique): ");
    printf("activity 0\n");
    k = 0;
    for(m=1;m<n;m++)
    {
        if(a[0][m] >= a[1][k])
        {
            printf("activity %d\n",m);
            k=m;
         
        }
    }
    
    
    return 0;
}