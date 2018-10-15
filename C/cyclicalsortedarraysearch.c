/*Rahul ghosh
This program is for cyclically sorting an array from a given a particular  number as a peak point.
example of cyclically sorted array:  3 4 5 1 2 (here 5 is the peak point)
after this seraching a number from that cyclically sorted array can be done in O(logn) time using this code



*/

#include <stdio.h>
#include<stdlib.h>
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);

        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}
int main()
{
  int n,u,l,i,j,f,temp,k,value,search,result;
  printf("Enter the size of array: ");
  scanf("%d",&n);
  printf("Enter Lower limit: \n");
  scanf("%d",&l);
  printf("Enter Upper limit: \n");
  scanf("%d",&u);
  int arr[n];
  for(i=0;i<n;i++)
      {
        while(1)
        {
          arr[i] = rand() % (u - l + 1) + l;
          f=0;
          for(j=0;j<i;j++)
          {
            if(arr[i]==arr[j])
            {
              f=1;
              break;
            }
          }
          if(f==0)
          break;
        }
      }
      for(i=0;i<n;i++)
      {
        //printf("%d\n",arr[i]);
      }
      printf("The elements in the array are: \n");
      for(i=0;i<n;i++)
      {
      printf("%d \n",arr[i]);
      }
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
           if(arr[i]>arr[j])
            {
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
            }
          }
      }
      printf("The elements in the random sorted array are:\n");
      for(i=0;i<n;i++)
      {
         printf("%d \n",arr[i]);
      }
      printf("Enter the index from which you want to sort it cyclically:\n");
      scanf("%d",&k);
      value=k;
      i=0;
      while (value<n) {
        temp=arr[i];
        arr[i++]=arr[value];
        arr[value++]=temp;
      }
      for(i=n-k;i<n;i++)
      {
      for(j=i+1;j<n;j++)
      {
      if(arr[i]>arr[j])
      {
      temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
      }
      }
      }

      printf("The elements of cyclically Sorted Array are :\n");
      for(i=0;i<n;i++)
      {
      printf("%d \n",arr[i]);
      }
      printf("Enter an Element to search: ");
      scanf("%d",&search );
      if(search==arr[0])
      printf("Element present at Index: 0\n");
      else if(search<arr[0])
      {
      result=binarySearch(arr,n-k,n-1,search);
      if (result==-1)
        printf("Element is  not Present.\n");
      else
        printf("Element Present in Index: %d\n",result);
      }
      else if(search>arr[0])
      {
        result=binarySearch(arr,0,n-k-1,search);
        if (result==-1)
          printf("Element not Present.\n");
        else
          printf("Element Present in Index: %d\n",result);
      }



return 0;
}

