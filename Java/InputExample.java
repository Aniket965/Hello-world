import java.util.Scanner;   //needed for scanner class

public class InputExample
{
	public static void main (String [] args)
	
	{
		String name;
		int age;
		double salary;
		
		//create a scanner object to read input
		Scanner keyboard = new Scanner(System.in);
		
		
		//get user's name
		System.out.print("What is your name? ");
		name = keyboard.nextLine();
		System.out.println("Hello, " + name + ".");
		
		
		//get the user's age
		System.out.print("What is your age? ");
		age = keyboard.nextInt();
		System.out.println("I see that you are " + age + " years old.");
		
		//get the user's salary
		System.out.print("What is your annual salary?");
		salary = keyboard.nextDouble();
		System.out.println(name + ", " + age + " years old, earns " +salary + " dollars per year.");
	
	}
}
