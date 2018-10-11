package com.company;

import java.time.*;
import java.util.Calendar;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello Funny World!");
        System.out.println("Salom Kulgili Dunyo!");
        System.out.println("Привет Смешной Мир");
        System.out.println("Merhaba Komik Dunya");

        System.out.println("This is my second pull request");

        System.out.println("Things I learned today: ");
        // this is the first time I used java.time.* library. I liked it very much... 
        LocalTime time = LocalTime.now();
        System.out.println(time);

        // this is the the same thing with java.util.Calendar
        Calendar calendar = Calendar.getInstance();
        System.out.println(calendar.toString()); // but it produces whoppingly big output

        System.out.println("Then I learned about AndroidX, Gradle, Jake Wharton");
        System.out.println("Also, I asked two questions on StackOverflow and found a solution to one of my problems.");
        System.out.println("Currently, I have 22 reputation on SO.");
        System.out.println("Bugun yana shuni bildimki, mani o'rganadigan narsam rossa ko'p ekan.");
        System.out.println("Xudo xohlasa programma qilishda naziri yo'q bo'laman.");
    }
}
