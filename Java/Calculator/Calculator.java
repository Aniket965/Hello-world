package com.company;

public class Calculator {
    private double number1, number2,result;

    public Calculator(double number1, double number2) {
        this.number1 = number1;
        this.number2 = number2;
    }

    public Calculator() {
    }

    // Method Addition
//    public int addition(int number1, int number2) {
//        return number1 + number2;
//    }

    public void addition(double number1, double number2) {
        this.result = number1 + number2;
    }

    // Method Subtraction
    public void subtraction(double number1, double number2) {
        this.result = number1 - number2;
    }

    // Method Multiplication
    public int multiplication(double number1, double number2) {
        return number1 * number2;
    }

    // Method Diffusion
    public double division(double number1, double number2) {
        if (number2 == 0) {
            System.out.println("Fehler, durch 0 teilen nicht möglich!");
            return 0;
        } else {
            return (double) (number1/number2);
        }
    }

    public int getNumber1() {
        return number1;
    }
// Inserting the number 1
    public void setNumber1(double number1) {
        this.number1 = number1;
    }
// getting number 2
    public int getNumber2() {
        return number2;
    }

    public void setNumber2(double number2) {
        this.number2 = number2;
    }

    public double getResult() {
        return result;
    }

    public void setResult(double result) {
        this.result = result;
    }
}
// My changes
