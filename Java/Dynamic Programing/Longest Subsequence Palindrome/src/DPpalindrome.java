import java.util.*;
public class DPpalindrome {

	public DPpalindrome() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the string : ");
		String str = s.next();
		
		char ch[] = str.toCharArray();
		
		int DPgrid[][] = new int[ch.length][ch.length];
		
		for(int i = 0 ; i < ch.length ; i++)
		{
			DPgrid[i][i] = 1;
			
			if(i != ch.length-1) 
			{
				if(ch[i] == ch[i+1])
					DPgrid[i][i+1] = 2;
				else
					DPgrid[i][i+1] = 1;
			}
		}
		
		
		for(int l = 2 ; l < DPgrid.length ; l++)
		{
			for(int i = 0 ; i < DPgrid[0].length - l ; i++)
			{
				int j = l+i;
				if(ch[i] == ch[j])
				{
					DPgrid[i][j] = 2 + DPgrid[i+1][j-1];
				}
				else
				{
					DPgrid[i][j] = DPgrid[i][j-1];
					
					if(DPgrid[i][j] < DPgrid[i+1][j])
						DPgrid[i][j] = DPgrid[i+1][j];
				}
			}
		}
		
		for(int i = 0 ; i < DPgrid.length ; i++)
		{
			System.out.println();
			for(int j = 0 ; j < DPgrid.length ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
			
		System.out.println("The maximum profit = " + DPgrid[0][DPgrid.length - 1]);
		
	}
	

}
