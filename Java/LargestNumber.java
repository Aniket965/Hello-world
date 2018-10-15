
import java.util.Scanner;

public class LargestNumber {

	public static void main(String[] args) {

    int[] nums;

		boolean exit = false;

		do {

			Scanner scanner = new Scanner(System.in);

      System.out.println("Enter the amount of numbers you want to compare: ");

      nums = new int[n];

			for (int i = 0; i < n; i ++) {
				System.out.println("Enter a number: ");
				if (scanner.hasNextInt()) {
					nums[i] = scanner.nextInt();
				} else {
					exit = true;
					break;
				}
			}

			if(exit) {
				System.out.println("Invalid input. Program terminated.");
				break;
			}

      int m = nums[0];

      for (int u = 1; u < n; u++){
        if (m < nums[u]){
            m = nums[u];
        }
      }

      System.out.println("The largest number is: " + m);

		} while(!exit);

	}

}
