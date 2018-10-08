import java.util.Scanner;

public class n3 {

    static int min;
    static int result;
    static int X;
    int go = 0;

    public static void main(String args[]) throws Exception {
        {
            Scanner sc = new Scanner(System.in);
            // sc = new Scanner(new FileInputStream("input.txt"));

            int T = sc.nextInt();
            for (int tc = 0; tc < T; tc++) {



                int N = sc.nextInt();
                min = sc.nextInt();

                result = Integer.MAX_VALUE;

                int m[][] = new int[N][N];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < 3; j++) {
                        m[i][j] = sc.nextInt();
                    }
                }

                n3 game = new n3();
                game.start(m, N);
                System.out.println(result);

            }
        }
    }

    private void start(int[][] m, int N) {

        int x = min;
        compute(m, -1, 0, 0, N);
        // compute(m, -1, 0, -x, N);
        compute(m, -1, 1, 0, N);
        compute(m, -1, 2, 0, N);

    }

    private boolean isSafe(int[][] m, int row, int col, int N) {

        if (row >= 0 && col >= 0 && row < N && col < 3) {
            return true;
        }

        return false;
    }

    private void compute(int[][] m, int x, int y, int value, int N) {
        // System.out.println(value + " " + x + " " + y);

        if (go == 1) {
            return;
        }

        if (x == N - 1 && value >= min) {
            if (value < result) {
                result = value;
            }

            if (value == min) {
                result = min;
                go = 1;
            }
            return;
        }

        if (isSafe(m, x + 1, y - 1, N)) {
            compute(m, x + 1, y - 1, value + m[x + 1][y - 1], N);
            compute(m, x + 1, y - 1, value - m[x + 1][y - 1], N);
        }

        if (isSafe(m, x + 1, y, N)) {
            compute(m, x + 1, y, value + m[x + 1][y], N);
            compute(m, x + 1, y, value - m[x + 1][y], N);
        }

        if (isSafe(m, x + 1, y + 1, N)) {
            compute(m, x + 1, y + 1, value + m[x + 1][y + 1], N);
            compute(m, x + 1, y + 1, value - m[x + 1][y + 1], N);
        }

    }
}