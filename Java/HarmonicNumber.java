import java.util.Scanner;


public class HarmonicNumber {
	public static void main(String args[]) {
		double harmonic = 0;
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the nth number for the harmonic number: ");
		int n = input.nextInt();
		System.out.println("The Harmonic number is " + harmonic(n));
	}

	public static double harmonic(int n) {
		if (n > 1) {
			return (1.0 / n) + harmonic(n - 1);
		} else {
			return 1.0;
		}
	}
}
