/*
https://projecteuler.net/problem=3
Largest prime factor
Problem 3 
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
 */
public class P0003 {

	public static boolean isPrime(int n) {
		for (int i=2; i<n; i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		for (int i=1; i<100; i++) {
			if (isPrime(i)) {
				System.out.println(i);
			}
		}

	}

}
