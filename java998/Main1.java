import java.util.Scanner;

class Player
{
String name;
int age;
String country;

void setName(String n)
{
name=n;
}
void setAge(int r)
{
age=r;
}
void setCountry(String c)
{
country=c;
}

void display()
{
System.out.println("Player Details:");
System.out.println("Name is "+name);
System.out.println("Age is "+age);
System.out.println("Country is "+country);

}

}
class Main1
{
public static void main(String arg[])
{

Player p=new Player();
Scanner s=new Scanner(System.in);
System.out.println("Enter Name:");
String n=s.nextLine();
p.setName(n);
System.out.println("Enter Age:");
int r=s.nextInt();
p.setAge(r);
System.out.println("Enter Country:");
s.nextLine();
String c=s.nextLine();
p.setCountry(c);
p.display();
}

}