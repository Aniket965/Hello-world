import java.util.*;

public class BellsNumber {

	public BellsNumber() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the nth bell number you need : ");
		int n = s.nextInt();
		
		int DPgrid[][] = new int[n][n];
		
		
		int bellnumber = bellNumber(DPgrid , n);
		System.out.println("The nth bell's number = " + bellnumber);
		
		
	}

	private static int bellNumber(int[][] dPgrid, int n) {
		// TODO Auto-generated method stub
		
		dPgrid[0][0] = 1;
		for(int i = 1 ; i < n ; i++)
		{
			dPgrid[i][0] = dPgrid[i-1][i-1];
			for(int j = 1 ; j <= i ; j++)
			{
				dPgrid[i][j] = dPgrid[i-1][j-1] + dPgrid[i][j-1];
			}
		}
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				System.out.print(dPgrid[i][j] + "\t");
			}
			System.out.println();
		}
		
		return dPgrid[n-1][n-1];
	}

}
