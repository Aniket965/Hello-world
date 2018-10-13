import java.util.Scanner;

package com.company;

public class Main {

    public static void main(String[] args) {
        
        int a,b;
		Scanner in = new Scanner(System.in);
        
        System.out.println("Enter First digit");
        a = in.nextInt();
        System.out.println("Enter Second digt");
        b = in.nextInt();
        System.out.println("You entered integer " + a+" and "+ b);

        // Erzeugung des Taschenrechners mit dem Standard-Konstruktor
        Calculator calc = new Calculator();
        // Addition
        calc.addition(a,b);
	    System.out.println("Addition : "+calc.getResult());
        // Subtraction
        calc.subtraction(a,b);
	    System.out.println("Subtraction : "+calc.getResult());
        // Multiplication
        System.out.println("Multiplication : "+calc.multiplication(a,b));
        // Division | Nicht durch null teilen, abfangen durch ==0, abfangen durch Exception wäre Zielführend
        System.out.println("Division : "+calc.division(a,b));
    }

}
