import java.util.Scanner;

class Prime {
  public static void main(String[] args) {
    // prompt user and get the integer
    System.out.print("Enter the integer to validate if it is a prime"); 
    Scanner scanner = new Scanner(System.in);
    int integer = scanner.nextInt();

    if (isPrime(integer)) {
      System.out.println("Prime");
    } else {
      System.out.println("Not prime");
    }
  }

  /**
   * Returns true if argument is a prime number.
   */
  public static boolean isPrime(int integer) {
    // guard code: anything that is a multiple of 2 is not a prime number
    if (integer % 2 == 0) {
      return false;
    }

    for (int index = 3; index * index < integer; index += 2) {
      if (integer % index == 0) {
        return false;
      }
    }

    return true;
  }
}
