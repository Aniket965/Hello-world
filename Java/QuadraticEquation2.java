/**
*This program will prompt you for the a, b, and c values
*for the equation ax^2 + bx + c and find the roots for you provided that
*you don't give any numbers that will result in imaginary values.
*If you do give numbers that will result in imaginary answers, the
*program will send you back to the start.
*/

import java.util.Scanner;
public class QuadraticEquation2 {
  public static void main(String[] args) {

    Scanner input = new Scanner(System.in); // Using Scanner
    double a, b, c;// Portions of the well-known Quadratic Equation
    double root1, root2; // This will be the roots of the equation
    boolean response = false;
    double determinant; // I need to add this to be able to make sure that the input is valid

    do {
      do {
        do {
          System.out.println("This is a Quadratic Equation solver.");
          System.out.println("Note: Imaginary values will not work"); // The program will spit out NaN instead of a value

          System.out.print("Please input the 'a' value:"); // ax^2, inputting 0 here will make this a non-quadratic and will therefore not work correctly
          a = input.nextDouble();

          if (a==0) {
            System.out.println("Your input of '0' is invalid. This is no longer a quadratic. Try Again!");// To stop people from making it a non-quadratic
          }
        } while (a==0);

        System.out.print("Please input the 'b' value:"); // ax^2 + bx
        b = input.nextDouble();

        System.out.print("Please input the 'c' value:"); // ax^2 + bx + c
        c = input.nextDouble();

        root1 = (-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a);
        root2 = (-b - Math.sqrt(b * b - 4 * a * c)) / (2 * a); // The actual formula
        determinant = (b * b - 4 * a * c); // Determinant Equation

        if (determinant<0) {
          System.out.println("Your inputs have yielded imaginary answers. Try Again!");
        }
      } while (determinant<0);

      System.out.printf("Your first root is %1.4f %n", root1); // Show the minimum digits required for the number before the decimal
      System.out.printf("Your second root is %1.4f %n", root2); // And go out to 4 decimal places

      System.out.println("Do you want to do another? (Answer 'true' or 'false')");// Asking to loop the formula
      response = input.nextBoolean();

    } while (response);
    System.out.println("Goodbye!");

  }
}
