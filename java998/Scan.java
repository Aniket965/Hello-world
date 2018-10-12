
import  java.util.Scanner;
class Scan
{
public static void main(String arg[])
{
Scanner S=new Scanner(System.in);
String name=S.nextLine();
int a=S.nextInt();
float b=S.nextFloat();
char c=S.next().charAt(0);
System.out.println("value of int  "+a);
System.out.println("value of float "+b);
System.out.println(name);
System.out.println(c);


}



};