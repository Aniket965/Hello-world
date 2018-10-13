public class RecursiveMethods {
    
    // Calculates Factorial
    public static int factorial (int n){

        if (n == 0 || n == 1){ // Base case

            return 1;

        } else {

            int result = n * factorial(n-1); // recursive step
            return result;
        }
    }
    
    
    // returns the Fibonacci number in the series, starting at index 0
    public static int Fibonacci (int n){

        if (n == 0 || n == 1){
            return 1;
        } else {
            return Fibonacci(n-1) + Fibonacci(n-2);
        }

    }
    
    // Prints String x, n times in a line separated by spaces
    public static void repeatedPrint(String x, int n){

        if (n == 0){

            return;

        } else {

            System.out.print(x + " ");
            repeatedPrint(x, n-1);
        }
    }
