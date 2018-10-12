
class Student1
{
private int rollNo;
private String name;
private String collegeName;

void setRollNo(int rollNo)
{
this.rollNo=rollNo;

}
int getRollNo()
{
return rollNo;

}
void setName(String name)
{

this.name=name;
}

String getName()
{

return name;
}
void setCollegeName(String collegeName)
{
this.collegeName=collegeName;
}
String getCollegeName()
{
return collegeName;
}
}




class Csestudents extends Student1
{
float javaMarks;

void setJavaMarks(float javaMarks)
{
this.javaMarks=javaMarks;
}
float getJavaMarks()
{
return javaMarks;
}
}



class Test1
{
public static void main(String arg[])
{

Csestudents obj=new Csestudents();
obj.setRollNo(10);
obj.setName("ishani");
obj.setCollegeName("cu");
obj.setJavaMarks((float)45.6);
int r=obj.getRollNo();
float m=obj.getJavaMarks();
String s=obj.getName();
String s1=obj.getCollegeName(); 
System.out.println("Name"+s);
System.out.println("Rollno"+r);
System.out.println("clgname"+s1);
System.out.println("java marks"+m);

}
}



