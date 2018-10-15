package com.company;

public class Main {

    public static void main(String[] args) {
        School student=new School();
        while(student.exitCode!=-1) {
            student.choice();
        }
        System.out.println("GoodBye");
    }
}
