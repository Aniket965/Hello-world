import java.util.Scanner;
public class AreaOfShapes
{
   public static void main(String[] args)
   {
       //print list of shapes
      System.out.println("Pick your shape: \n1. Square\n2. Rectangle\n3. Circle\n4. Triangle\n5. Kite\n6. Parallelogram\n7. Rhombus\n8. Trapezoid");
      
      //get user's shape until they give an int between 1 and 8
      int shape;
      Scanner scan = new Scanner(System.in);
      boolean good = false;
      do
      {
         System.out.print("Enter a number between 1 and 8: ");
         shape = scan.nextInt();
         if (shape > 0 && shape < 9)
         {
            good = true;
         }
      }
      while (!good);
      
      //declare variables for each area equation
      double length, width, di1, di2, base, radius, height, biggerBase, smallerBase;
      
      //switch and case for each shape
      switch (shape)
      {
         case 1:
         //Square
            System.out.print("Enter the length of one side: ");
            length = scan.nextDouble();
            System.out.println("Area: " + (length * length));
            break;
         case 2:
         //Rectangle
            System.out.print("Enter the length: ");
            length = scan.nextDouble();
            System.out.print("Enter the width: ");
            width = scan.nextDouble();
            System.out.println("Area: " + (length * width));
            break;
         case 3:
         //Circle
            System.out.print("Enter the radius: ");
            radius = scan.nextDouble();
            System.out.println("Area: " + ((radius * radius) * Math.PI));
            break;
         case 4:
         //Triangle
            System.out.print("Enter the base: ");
            base = scan.nextDouble();
            System.out.print("Enter the height: ");
            height = scan.nextDouble();
            System.out.println((base * height) / 2);
         case 5:
         //Kite
            System.out.print("Enter the length of the first diagonal: ");
            di1 = scan.nextDouble();
            System.out.print("Enther the length of the second diagonal: ");
            di2 = scan.nextDouble();
            System.out.println((di1 * di2) / 2);
         case 6:
         //Parallelogram
            System.out.print("Enter the base: ");
            base = scan.nextDouble();
            System.out.print("Enther the height: ");
            height = scan.nextDouble();
            System.out.println(base * height);
         case 7:
         //Rhombus
            System.out.print("Enter the length of the first diagonal: ");
            di1 = scan.nextDouble();
            System.out.print("Enther the length of the second diagonal: ");
            di2 = scan.nextDouble();
            System.out.println((di1 * di2) / 2);
         case 8:
         //Trapezoid
            System.out.print("Enter the length of the bigger base: ");
            biggerBase = scan.nextDouble();
            System.out.print("Enter the length of the smaller bse: ");
            smallerBase = scan.nextDouble();
            System.out.print("Enter the height: ");
            height = scan.nextDouble();
            System.out.println(((biggerBase * smallerBase) * height) / 2);
      }
   }
}