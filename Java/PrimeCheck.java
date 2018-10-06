import java.util.Scanner;

public class PrimeCheck{

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        int value = scan.nextInt();
        boolean flag=true;

        for(int i = 2;i<value;i++)
            {
                if(value%i==0)
                    {
                        flag = false;
                    }
            }
        
            if(flag == true)
                {
                    System.out.println("Yes it is a Prime Number");
                }
            else
                {
                    System.out.println("No it is not a Prime Number");
                }

    }
}