
/*A car factory has two assembly lines, each with n stations. 
 * A station is denoted by Si,j where i is either 1 or 2 and indicates the assembly line the station is on, 
 * and j indicates the number of the station. The time taken per station is denoted by ai,j. 
 * Each station is dedicated to some sort of work like engine fitting, body fitting, painting and so on. 
 * So, a car chassis must pass through each of the n stations in order before exiting the factory. 
 * The parallel stations of the two assembly lines perform the same task. After it passes through station Si,j, 
 * it will continue to station Si,j+1 unless it decides to transfer to the other line. 
 * Continuing on the same line incurs no extra cost, but transferring from line i at station j – 1 
 * to station j on the other line takes time ti,j. Each assembly line takes an entry time ei and exit time xi 
 * which may be different for the two lines. Give an algorithm for computing the minimum time it will take to build a car chassis.*/

import java.util.*;

public class AssemblyLineScheduling {

	public AssemblyLineScheduling() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);

		System.out.println("Enter the number of stations in each assembly : ");
		int n = s.nextInt();

		int a[][] = new int[2][n]; // time to service a car in same assembly line
		int t[][] = new int[2][n]; // time to change the station form assembly line A to B or vice versa
		int T1[] = new int[n];
		int T2[] = new int[n];
		
		System.out.println("Enter the entry time for assembly 1 and 2 :");
		int entry1 = s.nextInt();
		int entry2 = s.nextInt();

		System.out.println("Enter the exit time for assembly 1 and 2 :");
		int exit1 = s.nextInt();
		int exit2 = s.nextInt();

		int minsum = Integer.MAX_VALUE;

		System.out.println("Enter the service time for both the assemblies, A then B : ");

		for (int j = 0; j < a[0].length; j++) {
			for (int i = 0; i < 2; i++) {
				a[i][j] = s.nextInt();
			}
		}
		
		System.out.println("Enter the swap time for both the assemblies, A then B : ");

		for (int j = 0; j < t[0].length; j++) {
			for (int i = 0; i < 2; i++) {
				t[i][j] = s.nextInt();
			}
		}
		
		
		T1[0] = entry1 + a[0][0]+t[0][0];
		T2[0] = entry2 + a[1][0]+t[1][0];
		
		for(int i = 1 ; i < n ; i++)
		{
			T1[i] = Math.min((a[0][i] + T1[i-1]) , (t[1][i] + T2[i-1] + a[0][i]));
			T2[i] = Math.min((a[1][i] + T2[i-1]) , (t[0][i] + T1[i-1] + a[1][i]));
		}
		
		System.out.println("Minimum value = " + Math.min(T1[T1.length-1]+exit1 , T2[T2.length-1]+exit2));
		
	}

}
