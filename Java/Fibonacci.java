public class Fibonacci {
  public static void main(String[] args) {
    int a = 0;
    int b = 1;
    while(b < 100) {
      int n = a + b;
      a = b;
      b = n;
      System.out.println(n);
    }
  }
}
