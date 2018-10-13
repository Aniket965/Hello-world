/* Problem Statement: Program to print armstrong number and check whether armstrong number or not */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ArmstrongNumber
{
	static void printArmstrong(int user_input)
	{
		int temp = user_input;
		int num, rem, qub, sum;
		System.out.println("First "+ temp +" armstrong numbers are - ");
		
		for(int i = 1; i <= temp; i++)
		{
			num = i;
			sum = 0;
			
			while(num > 0)
			{
				rem = num % 10;
				qub = rem * rem * rem;
				sum = sum + qub;
				num = num / 10;
			}
			
			if(sum == i)
			{
				System.out.print(" "+sum);
			}
		}
		System.out.println();
	}
	
	static void checkArmstrong(int user_input)
	{
		int temp = user_input;
		int sum = 0, rem;
		
		while( temp != 0 )
		{
			rem = temp % 10;
			sum = sum + rem * rem * rem;
			temp = temp / 10;
		}

		if(user_input == sum)
			System.out.println(user_input +" is an Armstrong Number.");
		else
			System.out.println(user_input +" is not an Armstrong Number.");
	}
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int choice;
		String ans;
		do
		{
			System.out.println("Armstrong Numbers!");
			System.out.println("Press 1: Print Armstrong Numbers");
			System.out.println("Press 2: Check Armstrong Number");
			System.out.println("Press 3: Quit");
			System.out.print(": ");
			choice = Integer.parseInt(br.readLine());
			
			switch(choice)
			{
			case 1:
				System.out.println("How many armstrong numbers you want?");
				int num = Integer.parseInt(br.readLine());
				printArmstrong(num);
				break;
		
			case 2:
				System.out.print("Enter number for armstrong check: ");
				int check = Integer.parseInt(br.readLine());
				checkArmstrong(check);
				break;
			
			case 3:
				System.exit(0);
				break;
				
			default:
				System.out.println("Wrong choice entered!! Please try again..");
				break;
			}
			
			System.out.println("Do you want to continue?");
			System.out.print("(Y/N): ");
			ans = br.readLine();			
		}
		while(ans.toLowerCase().equals("y"));
	}

}
