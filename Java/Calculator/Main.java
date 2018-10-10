package com.company;

public class Main {

    public static void main(String[] args) {

        // Erzeugung des Taschenrechners mit dem Standard-Konstruktor
        Calculator calc = new Calculator();
        // Addition
        calc.addition(10, 5);
        System.out.println(calc.getResult());
        // Subtraktion
        calc.subtraction(10, 5);
        System.out.println(calc.getResult());
        // Multiplikation
        System.out.println(calc.multiplication(10, 5));
        // Division | Nicht durch null teilen, abfangen durch ==0, abfangen durch Exception wäre Zielführend
        System.out.println(calc.division(10, 3));
    }

}
