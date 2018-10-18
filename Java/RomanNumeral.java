import java.util.Scanner;  // Needed for Scanner

public class RomanNumeral
{
   public static void main(String[] args)
   {
	Scanner keyboard = new Scanner(System.in);
	
	int number;
	System.out.println("Enter a number between 1-10.");
	number = keyboard.nextInt();
	   
	if (number < 1 || number > 10)
	{
		System.out.println("Your input is invalid.");
	}
	else 
		{
			if (number==1)
			System.out.println("I");
			
			if (number==2)
			System.out.println("II");
			
			if (number==3)
			System.out.println("III");
			
			if (number==4)
			System.out.println("IV");
			
			if (number==5)
			System.out.println("V");
			
			if (number==6)
			System.out.println("VI");
			
			if (number==7)
			System.out.println("VII");
			
			if (number==8)
			System.out.println("VIII");
			
			if (number==9)
			System.out.println("IX");
			
			if (number==10)
			System.out.println("X");
		}
		
   }
}
	
