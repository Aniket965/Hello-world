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
System.out.println("Player Details: ");

System.out.println("Name: "+name);

System.out.println("Age: "+age);

System.out.println("Country: "+country);





}







}


class Main4
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
sc.close();


}


}