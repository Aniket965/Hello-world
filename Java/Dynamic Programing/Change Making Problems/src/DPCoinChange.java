import java.util.*;

public class DPCoinChange {

	static ArrayList<String> str = new ArrayList<String>();
	
	public DPCoinChange() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		
		System.out.println("Enter the Amount to have a change : ");
		int amount = s.nextInt();
		System.out.println("Enter the number of denominations required : ");
		int items = s.nextInt();
		
		int deno[] = new int[items+1];
		
		System.out.println("Enter the denominaitons : ");
		deno[0] = 0;
		for(int i = 1 ; i <= items ; i++)
		{
			deno[i] = s.nextInt();
		}
		
		// now the table for DP approach have rows = Amount and Columns = items(denominations)
		
		int DPchange[][] = new int[amount+1][items+1]; 
		
		for(int i = 0 ; i <= amount ; i++)
		{
			for(int j = 1 ; j <= items ; j++)
			{
				if(i == 0)
					DPchange[i][j] = 0;
				else if(deno[j] == 1)
					DPchange[i][j] = i;
				else 
				{
					DPchange[i][j] = DPchange[i][j-1];
					if(i >= deno[j] && DPchange[i][j] > (1+DPchange[i-deno[j]][j]))
						DPchange[i][j] = (1+DPchange[i-deno[j]][j]);
				} 
			}
		}
		
		int printonce = 1;
		for(int i = 0 ; i <= amount ; i++)
		{
			System.out.print("\t");
			if(printonce == 1) {
				for(int j = 0 ; j <= items ; j++)
				{
					System.out.print(deno[j] + "\t");
				}
				printonce = 0;	
			}
			System.out.println();
			System.out.print(i + "\t");
			for(int j = 0 ; j <= items ; j++)
			{
				System.out.print(DPchange[i][j] + "\t");
			}
			System.out.println();
		}
		
		System.out.println("The numbers of coins required = " + DPchange[amount][items]);
		
		backTrack(DPchange, amount, deno , deno.length-1 , "");
		
		for(String backtrack : str)
		{
				System.out.println(backtrack);
		}

	}

	

	private static void backTrack(int[][] dPchange, int i, int[] deno , int j , String s) {
		// TODO Auto-generated method stub
		// amount = i;
		// coins = j

		if (dPchange[i][j] != 0) {
			if (dPchange[i][j] == dPchange[i][j - 1]) {
				backTrack(dPchange, i, deno, j - 1, s);
			} else if (i >= deno[j] && dPchange[i][j] >= (1 + dPchange[i - deno[j]][j])) {
				s = deno[j] + " " + s;
				backTrack(dPchange, i - deno[j], deno, j, s);
			}
		}
		
			str.add(s);
	}
}
