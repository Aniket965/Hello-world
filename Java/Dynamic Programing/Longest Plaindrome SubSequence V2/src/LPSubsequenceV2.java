
//Solution : Reverse the string and find the longest common subsequence, you will get the Longest Palindrome SubSequence

import java.util.*;

public class LPSubsequenceV2 {

	public LPSubsequenceV2() {
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.println("Enter the String : ");
		String s1 = s.nextLine();
		char ch1[] = s1.toCharArray();

		StringBuilder s2 = new StringBuilder();
		s2.append(s1);
		s2 = s2.reverse();
		System.out.println("Input String : " + s1);
		System.out.println("String after reverse : " + s2);

		char ch2[] = s2.toString().toCharArray();

		int DPgrid[][] = new int[ch1.length + 1][ch2.length + 1];

		for (int i = 0; i < ch1.length; i++) {
			DPgrid[0][i] = 0;
		}

		for (int i = 0; i < ch2.length; i++) {
			DPgrid[i][0] = 0;
		}

		for (int i = 1; i < DPgrid.length; i++) {
			for (int j = 1; j < DPgrid[0].length; j++) {
				if (ch1[j - 1] == ch2[i - 1]) {
					DPgrid[i][j] = 1 + DPgrid[i - 1][j - 1];
				} else {
					DPgrid[i][j] = DPgrid[i - 1][j];

					if (DPgrid[i][j] < DPgrid[i][j - 1]) {
						DPgrid[i][j] = DPgrid[i][j - 1];
					}
				}
			}
		}

		for (int i = 0; i <= ch1.length; i++) {
			System.out.println();
			for (int j = 0; j <= ch2.length; j++) {
				System.out.print(DPgrid[i][j] + "\t");
			}
		}
	}
}
