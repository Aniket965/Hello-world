import java.util.*;
public class CatalanNumber {

	public CatalanNumber() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the index for catalan's number : ");
		int n = s.nextInt();
		
		System.out.println("the ith catalan's number = " + catalanNumber(n));
		
	}

	private static int catalanNumber(int n) {
		// TODO Auto-generated method stub
		int count = 0;
		if(n == 0 || n == 1)
			return 1;
		
			for(int i = 1 ; i <= n ; i++)
			{
				count = count + (catalanNumber(i-1) * catalanNumber(n-i));
			}
		
		
		return count;
	}
	
}
