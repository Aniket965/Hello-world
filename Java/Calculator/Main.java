import java.util.Scanner;
import static java.lang.System;
package com.company;

public class Main {
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int a,b;
        out.println("Enter First digit");
        a = in.nextInt();
        out.println("Enter Second digt");
        b = in.nextInt();
        out.println("You entered integer " + a+" and "+ b);
        // Erzeugung des Taschenrechners mit dem Standard-Konstruktor
        Calculator calc = new Calculator();
        // Addition
        calc.addition(a,b);
	    out.println("Addition : "+calc.getResult());
        // Subtraction
        calc.subtraction(a,b);
	    out.println("Subtraction : "+calc.getResult());
        // Multiplication
        out.println("Multiplication : "+calc.multiplication(a,b));
        // Division | Nicht durch null teilen, abfangen durch ==0, abfangen durch Exception wäre Zielführend
        out.println("Division : "+calc.division(a,b));
    }
}
