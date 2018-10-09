public class determinant {
        public static int  det(int N, int[][] a) {
        int[][] T = new int[N - 1][N - 1];
        int k = 0, l = 0, D = 0;
        switch (N) {
            case 1: {
                D = a[0][0];
                break;
            }
            case 2:
                D = a[0][0] * a[1][1] - a[0][1] * a[1][0];
                break;
            default:
                for (int z = 0; z < N; z++) {
                    for (int s = 0; s < N; s++) {

                        if (s != z) {

                            for (int t = 1; t < N; t++) {
                                T[k][l] = a[t][s];
                                k++;
                            }
                            l++;
                        }
                        k = 0;

                    }
                    l = 0;


                    int M = det(N - 1, T);
                    D += Math.pow(-1, z) * a[0][z] * M;
                }
        }
        return D;
    }
        public static void main(String[] args) {
        int [][] mat = new int[3][3];
        mat[0][0]=-1;mat[1][0]=2;mat[2][0]=5;
        mat[0][1]=1;mat[1][1]=2;mat[2][1]=3;
        mat[0][2]=-2;mat[1][2]=8;mat[2][2]=10;
            System.out.println(det(mat.length, mat));
    }
}
