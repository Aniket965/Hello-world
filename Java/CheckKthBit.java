import java.util.Scanner;

public class CheckKthBit {
	public static void main(String args[]) {

		Scanner s = new Scanner(System.in);
		System.out.println("Enter number to check for bit manipulation!);");

		int num = s.nextInt();
		System.out.println("Enter bit to be checked! );");
		int k = s.nextInt();
		int bm = 1 << k;
				
		// Check if 5th bit is set or not?

		System.out.println("Original number " + Integer.toBinaryString(num));
	
		// turn the bit off
		num = num & (~bm);
		System.out.println("Turning bit off " + Integer.toBinaryString(num));

		// turn the bit on
		num = num | (bm);
		System.out.println("Turning bit on " + Integer.toBinaryString(num));
		
		//toggle
		
		System.out.println("Toggling " + k + "th bit! " + Integer.toBinaryString(num^k));
		
	}
}
