/*-------------------------------------------------Problem : EggDrop-------------------------------------
 * 
 * The following is a description of the instance of this famous puzzle involving n=2 eggs and a building with k=36 floors.

Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:

…..An egg that survives a fall can be used again.
…..A broken egg must be discarded.
…..The effect of a fall is the same for all eggs.
…..If an egg breaks when dropped, then it would break if dropped from a higher floor.
…..If an egg survives a fall then it would survive a shorter fall.
…..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor do not cause an egg to break.

If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. Drop the egg from the first-floor window; if it survives, drop it from the second floor window. Continue upward until it breaks. In the worst case, this method may require 36 droppings. Suppose 2 eggs are available. What is the least number of egg-droppings that is guaranteed to work in all cases?
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that total number of trials are minimized.
 * */
import java.util.*;
public class EggDroping {

	public EggDroping() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of floors in a building : ");
		int n = s.nextInt();
		int egg = 4;
		
		int DPgrid[][] = new int[egg+1][n+1];
		
		// if you have k eggs and you are on 0th floor then 0 trials and for 1st floor you need only 1 trial 
		for(int i = 1 ; i <= egg ; i++)
		{
			DPgrid[i][0] = 0;
			DPgrid[i][1] = 1;
		}
		
		// if you have only 1 egg the for every floor you required n number's of trials
		
		for(int i = 1 ; i <= n ; i++)
		{
			DPgrid[1][i] = i;
		}
		int trial = 0;
		
		for(int i = 2 ; i <= egg ; i++)
		{
			for(int j = 2 ; j <= n ; j++)
			{
				DPgrid[i][j] = Integer.MAX_VALUE;
				for(int k = 1 ; k <= j ; k++)
				{
					trial = 1 + max(DPgrid[i-1][k-1] , DPgrid[i][j-k]);
					if(DPgrid[i][j] > trial)
						DPgrid[i][j] = trial;
				}
			}
		}
		
		int printonce = 1;
		for(int i = 0 ; i <= egg ; i++)
		{
			System.out.print("\t");
			
			System.out.println();
			System.out.print(i + "\t");
			for(int j = 0 ; j <= n ; j++)
			{
				System.out.print(DPgrid[i][j] + "\t");
			}
			System.out.println();
		}
		
		System.out.println("The number of attemps to find the broken eggs = " + DPgrid[egg][n]);
		s.close();
	}

	private static int max(int i, int j) {
		return ((i>j) ? i : j);
	}

}
