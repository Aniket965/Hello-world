/*Rod Cutting problem by murali sir
 * 
 * you have a rod of length 100. Now say you have to cut the rod at point 80 90 95 
 * such that if you cut the rod of length l then the cost of length l will get added to the whole price
 * 
 *  Example : say you have a rod of length 100 then you break the rod at point 80, then you have 2 rods of length 80 and 20.
 *  Now the price of cutting it is 100,
 *  After this there is no way to cut the rod 80
 *  now you must cut the rod of length 20 at point 90 or at point 95
 *  if you cut the rod at point 90 then cost  = cost + 20;
 *  next you have to cut the the rod at point 95 the cost = 100 + 20 + 10;
 *  if you cut the rod at point 95 then still the cost = cost + 20;
 *  next you have to cut the rod at point 90 then the cost  = 100 + 20 + 15;
 * 
 * so the minimum is 130 
 * not the 135
 * */

import java.util.*;

public class RodCutting {

	public static void main(String[] args) {
	
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the length of rod :");
		int n = s.nextInt();
		
		System.out.println("Enter the position to cut the rod :");
		int cuts = s.nextInt();
		
		int cut[] = new int[cuts];
		int max = 0;
		for(int i = 0 ; i < cuts ; i++)
		{
			cut[i] = s.nextInt();
			max = max + cut[i];
		}
		
		int DPgrid[][] = new int[cuts][cuts];
		
		for(int i = 0 ; i < cuts ; i++)
		{
			DPgrid[i][i] = 0;
		}
		
		int temp = 0;
		int min_cost = max;
		for(int i = 0 ; i < cuts ; i++)
		{	
			for(int l = 0 ; l < i ; l++)
			{
				int j = l + i;
				for(int k = i ; k < j ; k++)
				{
					min_cost = Math.min(min_cost , DPgrid[i][k] + DPgrid[k][j]);
				}
				DPgrid[i][j] = cut[j] - cut[i] + min_cost;
			}
		}
		
		
		for(int i = 0 ; i < cuts ; i++)
		{
			System.out.println();
			for(int j = 0 ; j < cuts ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
	}

	private static int min(int max, int temp) {
		// TODO Auto-generated method stub
		return (max < temp ? max : temp);
	}
}
