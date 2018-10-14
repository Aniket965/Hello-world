
import java.util.*;
public class LongestCommonSubstring {

	public LongestCommonSubstring() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the first String : ");
		String s1 = s.nextLine();
		char A[] = s1.toCharArray();
		
		System.out.println("Enter the second String : ");
		String s2 = s.nextLine();
		char B[] = s2.toCharArray();
		
		int DPgrid [][] = new int[A.length][B.length];
		
		if(A[0] == B[0])
			DPgrid[0][0] = 1;
		
		for(int i = 1 ; i < A.length ; i++)
		{
			if(A[i] == B[0])
				DPgrid[i][0] = 1;
		}
		
		for(int j = 1 ; j < B.length ; j++)
		{
			if(A[0] == B[j])
				DPgrid[0][j] = 1;
		}
		
		for(int i = 1 ; i < A.length ; i++)
		{
			for(int j = 1 ; j < B.length ; j++)
			{
				if(A[i] == B[j])
					DPgrid[i][j] = DPgrid[i-1][j-1] + 1;
				else 
					DPgrid[i][j] = 0;
			}
		}
		

		int max = 0;
		
		for(int i = 0 ; i < A.length ; i++)
		{
			for(int j = 0 ; j < B.length ; j++)
			{
				if(max < DPgrid[i][j])
					max = DPgrid[i][j];
			}
		}
		
		System.out.print("The length of maximum common substring  = " + max);
		
		for(int i = 0 ; i < A.length ; i++)
		{
			System.out.println();
			for(int j = 0 ; j < B.length ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
		
	}

}
