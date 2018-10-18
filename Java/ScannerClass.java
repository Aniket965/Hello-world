import java.util.Scanner;


public class ScannerClass{

   public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter a String");
    String name = scanner.nextLine();
    
    System.out.println("Enter a Integer value");
    int i = scanner.nextInt();

    System.out.println("Enter a double decimal value");
    double d = scanner.nextDouble();

    System.out.println("Enter a float value");
    float f = scanner.nextFloat();

    System.out.println("Enter a Boolean value");
    boolean boo = scanner.nextBoolean();

    System.out.println("Enter a Byte value");
    byte by = scanner.nextByte();

    System.out.println("Enter a Short value");
    short sh = scanner.nextShort();

    System.out.println("Enter a Long value");
    long lo = scanner.nextLong();

    System.out.println("\n***********************");

    System.out.println("String is : "+name);
    System.out.println("Integer is : "+i);
    System.out.println("Double is : "+d);
    System.out.println("Float is : "+f);
    System.out.println("Boolean is : "+boo);
    System.out.println("Byte is : "+by);
    System.out.println("Short is : "+sh);
    System.out.println("Long is : "+lo);

    }


}