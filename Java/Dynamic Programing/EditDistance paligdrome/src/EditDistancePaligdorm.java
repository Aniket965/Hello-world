import java.util.Scanner;

public class EditDistancePaligdorm {
    static String seq;


    static int longestPalindrome(int ii,int dd,int rr) {
        int m = seq.length();

        int[][] table = new int[m][m];

        for (int i = 0; i < m; i++) {
            table[i][i] = 0;
        }
        for (int i = 0; i < m - 1; i++) {
            if (seq.charAt(i) == seq.charAt(i + 1)) table[i][i + 1] = 0;
            else
            {
                table[i][i+1] = Math.min(Math.min(ii, dd), rr);
            }
    }

        for (int d = 2; d < m; d++) {
            for (int i = 0; i <= m - 1 - d; i++) {
                int j = i + d;
                if (seq.charAt(i) == seq.charAt(j)) table[i][j] = table[i + 1][j - 1];
                else {
                    int Icost = Math.min(table[i + 1][j] + ii, table[i][j - 1]+ii);
                    int Dcost = Math.min(table[i + 1][j] + dd, table[i][j - 1] + dd);
                    int Recost = table[i + 1][j - 1] + rr;
                    table[i][j] = Math.min(Math.min(Icost, Dcost), Recost);
                }
            }
        }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print(table[i][j] + "  ");
                }
                System.out.println();
            }
            return table[0][m - 1];
        }

    public static void main(String []args){
        Scanner sc = new Scanner(System.in);
        System.out.println("enter sequence");
        seq = sc.next();

        int ii = sc.nextInt();
        int dd = sc.nextInt();
        int rr = sc.nextInt();
        System.out.println(" Cost to make palindrome is:"+ longestPalindrome(ii,dd,rr));
    }

}