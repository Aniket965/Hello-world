/* https://projecteuler.net/problem=1
Multiples of 3 and 5
Problem 1 
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
 */
public class P0001 {

	public static int sum(int limit) {
		int result = 0;
		for (int i=1; i<limit; i++) {
			if (i%3 == 0 || i%5 == 0) {
				result += i;
			}
		}
		return result;
	}
	
	public static void main(String[] args) {
		System.out.println(sum(10));
		System.out.println(sum(1000));
	}

}
