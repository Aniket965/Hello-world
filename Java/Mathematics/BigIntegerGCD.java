import java.util.Scanner;
import java.math.BigInteger;

public class GCD {
  public static void main(String args[]) {
      Scanner in=new Scanner(System.in);
      String num1=in.next();
      String num2=in.next();
      System.out.println((new BigInteger(num1)).gcd(new BigInteger(num2)));
  }
}  
