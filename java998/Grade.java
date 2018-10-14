import java.util.Scanner;

class Grade
{
public static void main(String arg[])
{
Scanner s=new Scanner(System.in);
int a=s.nextInt();

if(a<50)

{
System.out.println("FAIL");

}

else if(a>=50 && a<60)
{
System.out.println("D");
}
else if(a>=60 && a<70)
{
System.out.println("c");
}
else if(a>=70 && a<80)
{
System.out.println("B");
}
else if(a>=80 && a<90)
{
System.out.println("A");
}

else
{
System.out.println("O");
}
}


};