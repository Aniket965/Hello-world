import java.util.Scanner;

class Switch

{
public static void main(String arg[])

{
Scanner s=new Scanner(System.in);
int ch=s.nextInt();
String str=s.nextLine();
switch(ch)
{
case 1:str="january";
break;

case 2:
str="feb";
break;

case 3:
str="march";
break;


case 4:
str="april";
break;


case 5:
str="may";
break;

case 6:
str="june";
break;


case 7:
str="july";
break;


case 8:
str="august";
break;


case 9:
str="september";
break;


case 10:
str="october";
break;


case 11:
str="nov";
break;

case 12:
str="dec";
break;

default:
System.out.println("INVALID MONTH");

}

System.out.println(str);

}





};