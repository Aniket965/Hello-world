import java.util.Scanner;

class Prime
{
public static void main(String str[])
{
Scanner S=new Scanner(System.in);
int a=S.nextInt();
int flag=0;
for(int i=2;i<=a-1;i++)
{
if(a%i==0)
{
System.out.println("NOT PRIME");
flag=1;
}


}
if(flag==0)
{
System.out.println("PRIME");
}

}


};