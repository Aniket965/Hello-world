package com.company;

public class Calculator {
    private int number1, number2;
    private double result;

    public Calculator(int number1, int number2) {
        this.number1 = number1;
        this.number2 = number2;
    }

    public Calculator() {
    }

    // Methode Addition
//    public int addition(int number1, int number2) {
//        return number1 + number2;
//    }

    public void addition(int number1, int number2) {
        this.result = number1 + number2;
    }

    // Methode Subtraktion
    public void subtraction(int number1, int number2) {
        this.result = number1 - number2;
    }

    // Methode Multiplikation
    public int multiplication(int number1, int number2) {
        return number1 * number2;
    }

    // Methode Diffusion
    public double division(int number1, int number2) {
        if (number2 == 0) {
            System.out.println("Fehler, durch 0 teilen nicht möglich!");
            return 0;
        } else {
            return (double) number1 / (double) number2;
        }
    }

    public int getNumber1() {
        return number1;
    }

    public void setNumber1(int number1) {
        this.number1 = number1;
    }

    public int getNumber2() {
        return number2;
    }

    public void setNumber2(int number2) {
        this.number2 = number2;
    }

    public double getResult() {
        return result;
    }

    public void setResult(double result) {
        this.result = result;
    }
}
