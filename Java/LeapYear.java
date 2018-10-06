import java.util.Scanner;

public class LeapYear{

  public static void main(String[] args) {
        
    Scanner scan = new Scanner(System.in);
    System.out.print("Enter a Year : ");
    int year = scan.nextInt();

    if (year % 4 == 0 && year % 100 != 0) {
      System.out.println("A leap year");
    } else if (year % 400 == 0) {
      System.out.println("A leap year");
    } else {
      System.out.println("Not a leap year");
    }
  }
}
