import java.util.*;

public class JobScheduler {

	public JobScheduler() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of jobs you have : ");
		int jobs = s.nextInt();
		
		int startendTime[][] = new int[2][jobs];
		
		for(int i = 0 ; i < jobs ; i++)
		{
			System.out.println("Enter Start time : ");
				startendTime[0][i] = s.nextInt();
			System.out.println("Enter End time : ");
				startendTime[1][i] = s.nextInt();
		}
		
		int tempstart = 0 , tempend = 0;
		for(int i = 0 ; i < startendTime[1].length ; i++)
		{
			for(int j = i+1 ; j < startendTime[1].length ; j++)
			{
				if(startendTime[1][i] > startendTime[1][j])
				{
					tempstart = startendTime[1][i];
					tempend = startendTime[0][i];
					startendTime[1][i] = startendTime[1][j];
					startendTime[0][i] = startendTime[0][j];
					startendTime[1][j] = tempstart;
					startendTime[0][j] = tempend;
				}
			}
		}
		
		int firstStart = startendTime[0][0];
		int firstEnd = startendTime[1][0];
		
			for(int j = 1 ; j < jobs ; j++)
			{
				if(startendTime[1][j] != 0)
				{
					if((firstEnd > startendTime[0][j]) && (startendTime[1][j] > firstStart)) 
					{
						startendTime[1][j] = 0;
						startendTime[0][j] = 0;
					}
					else {
						firstStart = startendTime[0][j];
						firstEnd = startendTime[1][j];
					}
					/*if((startendTime[0][i] < startendTime[1][j]) && (startendTime[1][i] > startendTime[0][j]))
					{
						startendTime[1][j] = 0;
						startendTime[0][j] = 0;
					}*/
				}
			}
		
		
		int count = 0;
		for(int i = 0 ; i < jobs ; i++)
		{
			if(startendTime[1][i] != 0 && startendTime[0][i] != 0)
			{
				count++;
				System.out.println("The start time = " + startendTime[0][i]);
				System.out.println("The end time = " + startendTime[1][i]);
			}
		}
		
		System.out.println("The number of jobs are : " + count);
	}
}
