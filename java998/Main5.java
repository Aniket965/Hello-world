import java.util.Scanner;
class Player3
{
private String name;
private int age;
private String country;
public Player3()
{
age=0;
name=" ";
country=" ";

}

public Player3(String name,int age,String country)
{
this.name=name;
this.age=age;
this.country=country;

}

public String toString()
{

return "Name:"+this.name+" Age: "+this.age+" Country: "+this.country;

}


}


class Main5
{
public static void main(String arg[])
{

Scanner sc=new Scanner(System.in);
System.out.println("Enter name:");
String name=sc.nextLine();
System.out.println("Enter Age:");
int age=sc.nextInt();

System.out.println("Enter country:");
sc.nextLine();
String country=sc.nextLine();
Player3 obj=new Player3(name,age,country);
System.out.println(obj.toString());
sc.close();


}


}