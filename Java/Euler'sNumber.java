import java.util.*;
public class Eca {
	public Eca() {
		
	}
	public static double factorial(double n) {
		if (n == 0) {
			return 1;
		}
		else {
			return n* Eca.factorial(n-1);
		}
	}
	public static void napierConstant() {
		double e = 0;
		for (int count = 0; count < 11; count++) {
			e += (2*count+2)/Eca.factorial(2*count+1);
		}
		System.out.println("The Napier Constant is " + Math.round(e*1000000000000000.0)/1000000000000000.0);
	}
	public static void main(String[] args) {
		Eca.napierConstant();
		Scanner sc = new Scanner(System.in);
		boolean check = true;
		while (check) {
			
			if (sc.nextLine().trim().equalsIgnoreCase("exit")) {
				check = false;
				
			}
			Eca.napierConstant();
		}

	}

}
