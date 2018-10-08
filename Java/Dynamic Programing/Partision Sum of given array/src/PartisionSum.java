import java.util.Scanner;

public class PartisionSum {

	public PartisionSum() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		int sum = 0;
		System.out.println("Enter the number of item you have : ");
		int items = s.nextInt();

		int maxval = 0;
		System.out.println("Enter the items :");
		int item[] = new int[items + 1];

		for (int i = 0; i <= items; i++) {
			if (i == 0)
				item[i] = 0;
			else
				item[i] = s.nextInt();

			sum = sum + item[i];
		}
		

		if ((sum % 2) == 0) {
			
			sum = sum/2;
			boolean DPgrid[][] = new boolean[items + 1][sum + 1];

			for (int i = 0; i <= sum; i++) {
				DPgrid[0][i] = false;
			}

			for (int i = 0; i <= items; i++) {
				DPgrid[i][0] = true;
			}

			for (int i = 1; i <= items; i++) {
				for (int j = 1; j <= sum; j++) {
					DPgrid[i][j] = (DPgrid[i - 1][j]);

					if (item[i] <= j) {
						if (DPgrid[i][j] == false)
							DPgrid[i][j] = (DPgrid[i - 1][j - item[i]]);
					}
				}
			}

			for (int i = 0; i <= items; i++) {
				System.out.println();
				for (int j = 0; j <= sum; j++) {
					System.out.print(DPgrid[i][j] + "\t");
				}
			}

			if (DPgrid[items][sum] == true)
				System.out.println("The subset sum of given number is possible!");
			else
				System.out.println("The subset sum of given number is not possible!");
		}
		
		else 
			System.out.println("The subset sum of given number is not possible !");

	}

}
