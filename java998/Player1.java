import java.util.Scanner;

class Player1
{
private String name;
private int age;
private String country;

public void setName(String name)
{

this.name=name;
}
public String getName()
{
return this.name;
}
public void setAge(int age)
{

this.age=age;
}
public int getAge()
{
return this.age;
}
public void setCountry(String country)
{

this.country=country;
}
public String getCountry()
{
return this.country;

}
}


class Main2
{

public static void main(String arg[])
{

Player1 obj=new Player1();
Scanner s=new Scanner(System.in);
System.out.println("Enter Name:");
String name=s.nextLine();
System.out.println("Enter Age:");
int age=s.nextInt();
s.nextLine();
System.out.println("Enter country:");
String country=s.nextLine();
obj.setName(name);
obj.setAge(age);
obj.setCountry(country);
name=obj.getName();
age=obj.getAge();
country=obj.getCountry();

System.out.println("Player Details:");

System.out.println("Name :"+name);

System.out.println("Age :"+age);

System.out.println("Country :"+country);

}

}
