import java.util.Scanner;

public class LeapYear{

    public static void main(String[] args) {
        
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a Year : ");
        int year = scan.nextInt();

        if(year%4==0 || year%100==0)
            {
                System.out.println("Yes it is a Leap year");
            }
        else
            {
                System.out.println("No it is not a Leap year");
            }

    }

}