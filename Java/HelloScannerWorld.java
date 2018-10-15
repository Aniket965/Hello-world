import java.util.Scanner;
public class HelloScannerWorld
{
  public static void main(String[] args)
  {
    Scanner kb = new Scanner("Hello World");
    String HelloWorld = kb.nextLine();
    System.out.println(HelloWorld);
  }

}
