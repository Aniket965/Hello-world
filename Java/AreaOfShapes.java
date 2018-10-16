import java.util.Scanner;
import static java.lang.System;
public class AreaOfShapes
{
   static Scanner scan = new Scanner(System.in);
   public static void main(String[] args)
   {
       //print list of shapes
      out.println("Pick your shape: \n1. Square\n2. Rectangle\n3. Circle\n4. Triangle\n5. Kite\n6. Parallelogram\n7. Rhombus\n8. Trapezoid");
      
      //get user's shape until they give an int between 1 and 8
      int shape;
      boolean good = false;
      do
      {
         out.print("Enter a number between 1 and 9: ");
         shape = scan.nextInt();
         if (shape > 0 && shape < 10)
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
            out.print("Enter the length of one side: ");
            length = scan.nextDouble();
            out.println("Area: " + (length * length));
            break;
         case 2:
         //Rectangle
            out.print("Enter the length: ");
            length = scan.nextDouble();
            out.print("Enter the width: ");
            width = scan.nextDouble();
            out.println("Area: " + (length * width));
            break;
         case 3:
         //Circle
            out.print("Enter the radius: ");
            radius = scan.nextDouble();
            out.println("Area: " + ((radius * radius) * Math.PI));
            break;
         case 4:
         //Triangle
            out.print("Enter the base: ");
            base = scan.nextDouble();
            out.print("Enter the height: ");
            height = scan.nextDouble();
            out.println((base * height) / 2);
            break;
         case 5:
         //Kite
            out.print("Enter the length of the first diagonal: ");
            di1 = scan.nextDouble();
            out.print("Enther the length of the second diagonal: ");
            di2 = scan.nextDouble();
            out.println((di1 * di2) / 2);
            break;
         case 6:
         //Parallelogram
            out.print("Enter the base: ");
            base = scan.nextDouble();
            out.print("Enther the height: ");
            height = scan.nextDouble();
            out.println(base * height);
            break;
         case 7:
         //Rhombus
            out.print("Enter the length of the first diagonal: ");
            di1 = scan.nextDouble();
            out.print("Enther the length of the second diagonal: ");
            di2 = scan.nextDouble();
            out.println((di1 * di2) / 2);
            break;
         case 8:
         //Trapezoid
            out.print("Enter the length of the bigger base: ");
            biggerBase = scan.nextDouble();
            out.print("Enter the length of the smaller bse: ");
            smallerBase = scan.nextDouble();
            out.print("Enter the height: ");
            height = scan.nextDouble();
            out.println(((biggerBase * smallerBase) * height) / 2);
            break;
         case 9:
            //Cube
            out.print("Enter the length of one side: ");
            length = scan.nextDouble();
            out.println("Surface Area: " + 6(length * length));
            break;
      }
   }
}
