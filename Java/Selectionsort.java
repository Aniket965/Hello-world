import java.util.Scanner;
class co
{
    static void selection_sort(int m[])
    {   int a=m.length;
        for(int i=0;i<a-1;i++)
        {  int min=i;
            for(int j=i+1;j<a;j++)
            { if(m[j]<m[min])
                min=j;
            }
            int aa=m[min];
            m[min]=m[i];
            m[i]=aa;
        }
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner (System.in);
        System.out.println("enter no. of elements in an array");
        int a=sc.nextInt();
        int arr[]=new int [a];
        for (int i=0;i<a;i++)
        arr[i]=sc.nextInt();
        selection_sort(arr);
        for(int mi:arr)
         System.out.print(mi+" ");
    }}
    
        