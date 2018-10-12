import java.util.Scanner;
class Reverse
{

public static void main(String arg[])
{

  
  Scanner sc=new Scanner(System.in);

    int arr[]=new int[arg.length];
    System.out.println("ENTER ELEMENTS");
    for(int i=0;i<arg.length;i++)
    {
	int item=sc.nextInt();
        arr[i]=item;
    }
int n=arg.length();
for(int i=0;i<arg.length/2;i++)
{

 int temp=arr[i];
 arr[i]=arr[n-1];
 arr[n-1]=temp;
 n--;
}

System.out.println();
System.out.println("REVERSED ARRAY");
for(int i=0;i<=arg.length-1;i++)
{

System.out.println(arr[i]+" ");
}

}


}