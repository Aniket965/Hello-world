import java.util.*;

class Job{
	int start;
	int end;
	int profit;
	
	public Job(int s , int e , int p)
	{
		start = s;
		end = e;
		profit = p;
	}
	
}

public class JobScheduling{
	public static void main(String args[])
	{
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the number of jobs ");
		int n = s.nextInt();
		
		Job jobs[] = new Job[n];
		//assumption is we are taking the jobs in sorted order of start time
		for(int i = 0 ; i < n ; i++)
		{
			System.out.println("Enter start time, end time and Profit");
			jobs[i] = new Job(s.nextInt() , s.nextInt() , s.nextInt());
		}
		
		int T[] = new int[n];
		for(int i = 0 ; i < n; i++)
		{
			T[i] = jobs[i].profit;
		}
		
		int Maxval = Integer.MIN_VALUE;
		for(int i = 1;  i < n ; i++)
		{
			for(int j = 0 ; j < i ; j++)
			{
				if(jobs[j].end <= jobs[i].start)
				{
					T[i] = Math.max(T[i] , T[j] + jobs[i].profit);
					Maxval = Math.max(Maxval , T[i]);
				}
			}
		}
		
		/*for(int i = 0 ; i < n ; i++)
		{
			System.out.print(T[i] + "\t");
		}*/
		
		System.out.println("The highest profit = " + Maxval);
		
	}
}