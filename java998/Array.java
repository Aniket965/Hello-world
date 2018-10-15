import java.util.Scanner;
class Array
{

public static void main(String arg[])
{
Scanner sc=new Scanner(System.in);
int arr[]=new int[5];

for(int i=0;i<5;i++)
{

int f=sc.nextInt();
arr[i]=f;

}

for(int i=0;i<5;i++)
{

System.out.println(arr[i]);
}

System.out.println("\n");

int b[][]=new int[2][2];


for(int i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{
int r=sc.nextInt();
b[i][j]=r;

}
}

for(int i=0;i<2;i++)
{
for(int j=0;j<2;j++)
{

System.out.print(b[i][j]+"  ");

}
System.out.print("\n");

}






}

}