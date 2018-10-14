import java.util.Scanner;

public class PascalTriangle {

    public static void  main(String[] args){


        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter number");
        int n=scanner.nextInt();

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                System.out.print(get_number(i,j)+" ");
            }

            System.out.println();
        }



    }

    private static int get_number(int i, int j) {

//          n                  n!
//           C     =     _____________
//             r          (n-r)! * r!
//
        return  factorial(i)/(factorial(i-j)* factorial(j));
    }

    private static int factorial(int n) {

        if(n==0) return 1;
        if(n==1) return 1;
        else return n* factorial(n-1);



    }
}
