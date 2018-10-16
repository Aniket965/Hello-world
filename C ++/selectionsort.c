// name-Gyantosh kumar      experiment - selection sort programming
#include<stdio.h>
 int main()
 {

     int a[10],n,i,j,temp,pos,min;
     printf("enter the element of array:\n");
     scanf("%d",&n);
     printf("enter the array:\n");
     for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       for(i=0;i<n-1;i++)
       {  min=a[i];
           pos=i;
           for(j=i+1;j<n;j++)
           {
               if(min>a[j])
               {
                min=a[j];
                pos=j;
               }
           }
           temp=a[i];
           a[i]=a[pos];
           a[pos]=temp;




       }
       for(i=0;i<n;i++)
       {
           printf("%d ",a[i]);

       }


return 0;

 }
 /*enter the element of array:
7
enter the array:
231
314
458
234
233
567
789
231 233 234 314 458 567 789
Process returned 0 (0x0)   execution time : 23.893 s
Press any key to continue.


*/
