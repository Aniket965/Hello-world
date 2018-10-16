import java.util.Scanner;
public class Hello{
 public static void main(String args[]){
  System.out.print("Enter your name: ");
  Scanner keyboard=new Scanner(System.in);
  String Name = keyboard.nextLine(); 
  System.out.print("Hello world");
  System.out.println(", I am "+Name);
  
 }
}
