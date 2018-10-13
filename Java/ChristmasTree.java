import java.util.Scanner;

public class ChristmasTree {

    public static void main(String[] args) {

        // Scanner für Eingabe und Zuweisung Größenvariable
        Scanner input = new Scanner(System.in);
        System.out.println("Wie groß soll dein Baum sein?");
        int christmasTreeSize = input.nextInt();
        // Schleife für Zeilenwechsel (Höhe) des Baums, Stamm kommt später
        for (int i = 1; i <= christmasTreeSize; i++) {
            // "degenerierende" Schleife für Leerzeichen zu Beginn
            for (int a = (christmasTreeSize - i) - 1; a >= 0; a--) {
                System.out.print(' ');
            }
            // Schleife für Sterne
            for (int b = 1; b < (2 * i); b++) {
                System.out.print('*');
            }
            System.out.println();
        }
        // Schleife für Leerzeichen vor Stamm und sysout Stamm
        for (int c = 1; c < christmasTreeSize; c++) {
            System.out.print(' ');
        }
        System.out.println('I');
    }

}

