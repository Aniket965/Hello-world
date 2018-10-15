import java.util.Scanner;
class Student
{
int rollNo;
String name;
String clgName;
Student()
{
rollNo=0;
name=" ";
clgName=" ";
}
Student(int rollNo,String name,String clgName)
{
this.rollNo=rollNo;
this.name=name;
this.clgName=clgName;
}
void setRollNO(int r)
{
rollNo=r;
}

void setName(String n)
{
name=n;
}
void setClgName(String cn)
{
clgName=cn;
}

void display()
{
System.out.println("ROLL no "+rollNo);
System.out.println("Name "+name);
System.out.println("clgName "+clgName);
System.out.println("\n");

}
}

class Main
{
public static void main(String arg[])
{
Scanner sc=new Scanner(System.in);
int r;
String cn;
String n;
r=sc.nextInt();
sc.nextLine();
n=sc.nextLine();
cn=sc.nextLine();

Student ob=new Student();
Student ob1=new Student(2,"jaisleen","Chitkara");
ob.setRollNO(r);
ob.setName(n);
ob.setClgName(cn);
ob.display();
ob1.display();
}


}