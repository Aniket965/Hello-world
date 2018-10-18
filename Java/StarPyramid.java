/*
*  
*  Create the following pattern:
*    
*        * 
*       * * 
*      * * * 
*     * * * * 
*    * * * * *  
*
*/

import java.util.Scanner;

public class StarPyramid {

	public static void main(String[] args) {
		int height;

		Scanner input = new Scanner(System.in);
		System.out.print("Enter the height of the pyramid: ");
		height = input.nextInt();
		input.close();

		for (int line = 1; line <= height; line++) {
			for (int sp = 1; sp <= (height - line); sp++)
				System.out.print(" ");
			for (int star = 1; star <= line; star++)
				System.out.print("* ");
			System.out.println();
		}

	}
}