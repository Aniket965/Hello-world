import java.util.Scanner;



public class ConditionalOperator{

    public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        int a,b,max=0;
        a = scan.nextInt();
        b = scan.nextInt();
        max = a>b?a:b;
        System.out.println("Max is : "+max);

    }

}