import java.util.Scanner;
class Student
{
int roll;
String name;

Student()
{
System.out.println("Base class defualt constructor");

}

Student(int roll)
{
this.roll=roll;
System.out.println("Base class parametrized constructor");

}

}


class extends Csestudent
{
float marks;


Csestudent()
{
System.out.println("Derived class defualt constructor");

}

Csestudent(int roll)
{
super(100);
this.roll=roll;
System.out.println("Derived class parametrized constructor");

}

class Csestudent extends Student
{
float marks;


Csestudent()
{
System.out.println("Derived class defualt constructor");

}

Csestudent(int roll)
{
super(100);
this.roll=roll;
System.out.println("Derived class parametrized constructor");

}


}

class Testclass

{
public static void main(String arg[])
{
int roll;
Scanner sc=new Scanner(System.in);
roll=sc.nextInt();

Csestudent cse=new Csestudent(roll);

}

} 
