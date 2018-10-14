import java.util.Scanner;
class Ques2
{
public static void main(String str[])
{
Scanner S=new Scanner(System.in);
int a=S.nextInt();
int sum=0;
int rem;
int onum=a;
while(a>0)
{
rem=a%10;
sum=sum*10+rem;
a=a/10;
}
if(sum==onum)
{
System.out.println("No is palidrome");
}
else
{
System.out.println("No is not Palidrome");
}

}

};
