import java.util.Scanner;

class One
{
public static void main(String arg[])
{

Scanner S=new Scanner(System.in);
String name=S.nextLine();
long roll=S.nextLong();
float m1=S.nextFloat();
float m2=S.nextFloat();
float m3=S.nextFloat();
float m4=S.nextFloat();
float m5=S.nextFloat();
System.out.println(name);
System.out.println(roll);
System.out.println(m1);
System.out.println(m2);
System.out.println(m3);
System.out.println(m4);
System.out.println(m5);
float sum=m1+m2+m3+m4+m5;
System.out.println(sum/500*100);

}


};