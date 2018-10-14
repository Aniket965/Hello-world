import java.util.Scanner;
public class MyOperators{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int sum,sub,mul,div,mod,max=0;

        System.out.println("Enter two values");
        int a = scan.nextInt();
        int b = scan.nextInt();

        System.out.println("\nThere Arithmetic Operations are\n===========================");
        
        sum = a+b;
        sub = a-b;
        mul = a*b;
        div = a/b;
        mod = a%b;
        max = a>b?a:b;
        
        System.out.println("Addition is : "+sum);
        System.out.println("Subtraction is : "+sub);
        System.out.println("Multiplication is : "+mul);
        System.out.println("Division is : "+div);
        System.out.println("Modulas is : "+mod);
        
        System.out.println("\nRelational Operations are\n==================================");

        System.out.println("A is greater then b : "+(a>b));
        System.out.println("A is smaller then b : "+(a<b));
        System.out.println("A is greater or equal to b : "+(a>=b));
        System.out.println("A is smaller or equal to b : "+(a<=b));
        System.out.println("A is equal to b : "+(a==b));
        System.out.println("A is not equal to b : "+(a!=b));

        System.out.println("\nLogical Operators are\n======================================");

        System.out.println("A is larger then b and b is smaller then A : "+(a>b && b<a));
        System.out.println("A is larger then b or b is smaller then A : "+(a>b || b<a));
        System.out.println("A is not smaller then b : "+(!(a<b)));

        System.out.println("\nIncrement and decrement operators are\n==========================================");
        System.out.println("Increment of A results to : "+(++a));
        System.out.println("Decrement of B results to : "+(--b));

        System.out.println("\nTypeCasting the Operators\n================================");

         float fa = a;
         double db = b;
         System.out.println("Float value of a is : "+fa);
         System.out.println("Double value of b is : "+db);

         System.out.println("\nConditional Operators\n================================");
         System.out.println("Max value of A or B is : "+max);
       



    }
}