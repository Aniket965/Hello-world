import java.util.*;

public class DPKnapsack {

	static ArrayList<String> str = new ArrayList<String>();
	
	public DPKnapsack() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of item's you have : ");
		int items = s.nextInt();
		
		System.out.println("Enter the Weight of Knapsack : ");
		int W = s.nextInt();
		
		int p[] = new int[items + 1];
		int w[] = new int[items + 1];
		int DPgrid[][] = new int[items + 1][W + 1];
		
		for(int i = 0 ; i <= items ; i++)
		{
			if(i == 0)
			{
				p[i] = 0;
				w[i] = 0;
			}
			else {
				System.out.println("Enter Profit : ");
				p[i] = s.nextInt();
				System.out.println("Enter Weight : ");
				w[i] = s.nextInt();
			}
		}
		
		for(int i = 0 ; i <= items ; i++)
		{
			DPgrid[i][0] = 0;
		}
		
		for(int i = 0 ; i <= W ; i++)
		{
			DPgrid[0][i] = 0;
		}
		
		int profit = 0;
		for(int i = 1 ; i <= items ; i++)
		{
			for(int j = 1 ; j <= W ; j++)
			{
				//if i pick the item then profit will become profit = profit of w1 + profit of (i-1 , W-j)
				
				
					if(i == 1)
					{
						if(j >= w[i])
							DPgrid[i][j] = p[i];
						else
							DPgrid[i][j] = 0;
					}
					else
					{
						DPgrid[i][j] = DPgrid[i-1][j];
						
						if(w[i] <= j && (p[i] + (DPgrid[i-1][j-w[i]]) > DPgrid[i][j]))
						{
							DPgrid[i][j] = (p[i] + DPgrid[i-1][j-w[i]]);
							profit = profit + (DPgrid[i][j]);
						}
					}
				
			}
		}
		
		for(int i = 0 ; i <= items ; i++)
		{
			System.out.println();
			for(int j = 0 ; j <= W ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
			
		System.out.println("The maximum profit = " + DPgrid[items][W]);
		backTrack(DPgrid , items , w , p , W , "");
		
		for(String item : str)
		{
			System.out.println(item);
		}
		
	}

	private static void backTrack(int[][] dPgrid, int i, int[] w, int[] p, int j, String s) {
		// TODO Auto-generated method stub
		// items = i
		// weight = j

		if (dPgrid[i][j] != 0) {
			if (dPgrid[i][j] == dPgrid[i - 1][j]) {
				backTrack(dPgrid, i - 1, w, p, j, s);
			} else if (w[i] <= j && (p[i] + (dPgrid[i - 1][j - w[i]]) >= dPgrid[i][j])) {
				s = w[i] + " " + s;
				backTrack(dPgrid, i - 1, w, p, j - w[i], s);
			}
		}
		
		str.add(s);
	}
}
