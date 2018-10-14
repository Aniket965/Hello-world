import java.util.*;
public class DPlongestSubsequence {

	static ArrayList<String> str = new ArrayList<String>();

	public DPlongestSubsequence() {
		// TODO Auto-generated constructor stub
	}


	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the first String : ");
		String s1 = s.next();
		char ch1[] = s1.toCharArray();
		
		System.out.println("Enter the second String : ");
		String s2 = s.next();
		char ch2[] = s2.toCharArray();
		
		int DPgrid[][] = new int[ch1.length+1][ch2.length+1];
		
		for(int i = 0 ; i <= ch2.length ; i++)
		{
				DPgrid[0][i] = 0;
		}
		
		for(int i = 0 ; i <= ch1.length ; i++)
		{
				DPgrid[i][0] = 0;
		}
		
		for(int i = 1 ; i < DPgrid.length ; i++)
		{
			for(int j = 1; j < DPgrid[0].length ; j++)
			{
				if(ch1[i-1] == ch2[j-1])
				{
					DPgrid[i][j] = 1 + DPgrid[i-1][j-1];
				}
				else {
					DPgrid[i][j] = DPgrid[i-1][j];
					
					if(DPgrid[i][j] < DPgrid[i][j-1])
					{
						DPgrid[i][j] = DPgrid[i][j-1];
					}
				}
			}
		}
	

	for(int i = 0 ; i <= ch1.length ; i++)
	{
		System.out.println();
		for(int j = 0 ; j <= ch2.length ; j++)
		{
			System.out.print(DPgrid[i][j] + "\t");
		}
	}
	System.out.println();
	System.out.println("The maximum profit = " + DPgrid[ch1.length][ch2.length]);
	
	backTrack(DPgrid, ch1 , ch2 , ch1.length ,  ch2.length , "");
	
		for(String i : str)
		{
			if(i.length() == DPgrid[ch1.length][ch2.length])
			System.out.println(i);
		}
	}


	private static void backTrack(int[][] dPgrid, char[] ch1, char[] ch2, int n, int m, String s) {

		// ArrayList<ArrayList<String>> mystr = new ArrayList<ArrayList<String>>();

		if (dPgrid[n][m] != 0) {

			if ((dPgrid[n][m] == dPgrid[n - 1][m]) && (dPgrid[n][m] == dPgrid[n][m - 1])) {
				backTrack(dPgrid, ch1, ch2, n - 1, m, s);
				backTrack(dPgrid, ch1, ch2, n, m - 1, s);
			}
			else if (dPgrid[n][m] == dPgrid[n - 1][m]) {
				backTrack(dPgrid, ch1, ch2, n - 1, m, s);
			} 
			else if (dPgrid[n][m] == dPgrid[n][m - 1]) {
				backTrack(dPgrid, ch1, ch2, n, m - 1, s);
			} 
			else {
				s = ch1[n - 1] + s;
				backTrack(dPgrid, ch1, ch2, n - 1, m - 1, s);
			}
		}
		if(!str.contains(s))
			str.add(s);
	}
}
