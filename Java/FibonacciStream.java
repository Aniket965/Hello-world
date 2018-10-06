import java.util.*;
import java.util.stream.*;
import java.math.*;

public class FibonacciStream {
  public static void main(String[] args) {
    System.out.print("Enter number of terms: ");
    Scanner scan = new Scanner(System.in);
    int limit = scan.nextInt();

    Stream.iterate(new BigInteger[] 
        { BigInteger.ONE, BigInteger.ONE },
	p -> new BigInteger[] { p[1], p[0].add(p[1]) })
      .limit(limit)
      .forEach(p->System.out.println(p[0]));
  }
}
