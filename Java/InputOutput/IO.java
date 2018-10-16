package Assignment3.InputOutput;
import java.util.Scanner;

public class IO { //Using this we don't have to print or read in the code.


    Scanner input = new Scanner(System.in);

    public int readInt(){
        int number = input.nextInt();
        input.nextLine();
        return number;
    }

    public double readDouble(){
        double number = input.nextDouble();
        input.nextLine();
        return number;
    }

    public String readString(){
        String word = input.nextLine();
        return word;
    }

    public void printSomething(String thing){

        System.out.println(thing);
    }

}
