import java.util.*;
class  MagicSquare {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Welcome to Magic Square !");
		System.out.println("Enter size. (size is odd number only.)");
		int n = scan.nextInt();
		int[][] m = new int[n+1][n+1];
		int r = 1;
		int c = n / 2 + 1;
		m[r][c] = 1;
		int n2 = n * n ;
		for (int k = 2; k <= n2; k++) {
			if (r == 1 && c == n) {
				r = 2;
			} else if (r ==1) {
				r = n;
				c++;
			} else if (c == n) {
				r--;
				c = 1;
			} else if (m[r-1][c+1] > 0) {
				r++;
			} else {
				r--;
				c++;
			}
			m[r][c] = k;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				System.out.print(m[i][j] + "  ");
			}
			System.out.println(" ");
		}
		System.out.println("========== Program Terminated ==========");
	}
}
