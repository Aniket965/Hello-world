// This program draws a rocket shape to any size. 

public class DrawRocket {
   public static final int SIZE = 3; // changes size
   
   // declares methods to draw the rocket
   public static void main(String[] args) {
      drawPoint();
      drawLine();
      drawUpDiamond();
      drawDownDiamond();
      drawLine();
      drawDownDiamond();
      drawUpDiamond();
      drawLine();
      drawPoint();
   }
   
   // draws the rocket cone and tail
   public static void drawPoint() {
      for (int line = 1; line <= (SIZE * 2 - 1); line++) {
         for (int space = (SIZE * 2 - 1); space >= line; space--) {
            System.out.print(" ");
         }
         for (int forSlash = 1; forSlash <= line; forSlash++) {
            System.out.print("/");
         }
         System.out.print("**");
         for (int backSlash = 1; backSlash <= line; backSlash++) {
            System.out.print("\\");
         }
         System.out.println();
      }
   }
   
   // draws the rocket borders
   public static void drawLine() {
      System.out.print("+");
      for (int line = 1; line <= (SIZE * 2); line++) {
         System.out.print("=*");
      }
      System.out.println("+");
   }
   
   // draws the half of the rocket's body
   public static void drawUpDiamond() {
      for (int line = 1; line <= SIZE; line++) {
         System.out.print("|");
         for (int half = 1; half <= 2; half++) {
            for (int dot = (SIZE - 1); dot >= line; dot--) {
               System.out.print(".");
            }
            for (int point = 1; point <= line; point++) {
               System.out.print("/\\");
            }
            for (int dot = (SIZE - 1); dot >= line; dot--) {
               System.out.print(".");
            }
         }
         System.out.println("|");
    }
   }
   
   // draws the other half of the other rocket's body
   public static void drawDownDiamond() {
      for (int line = 1; line <= SIZE; line++) {
         System.out.print("|");
         for (int half = 1; half <= 2; half++) {
            for (int dot = 1; dot <= (line - 1); dot++) {
               System.out.print(".");
            }
            for (int point = SIZE; point >= line; point--) {
               System.out.print("\\/");
            }
            for (int dot = 1; dot <= (line - 1); dot++) {
               System.out.print(".");
            }
         }
         System.out.println("|");
      }
   }
}
