package com.github.draylar;

import java.util.Random;

public class BruteForceHelloWorld {

    private static String possibleChars = "abcdefghijklmnopqrstuvwxyz ,!";
    private static Random random = new Random();

    public static void main(String[] args) {
        String helloWorld = "hello, world!";
        int totalAttemptCount = 0;

        // iterate over each character of hello world
        for(int i = 0; i < helloWorld.length(); i++) {
            do {
                totalAttemptCount++;
            } while (helloWorld.charAt(i) != getRandomCharacter());
        }

        logGuessCount(totalAttemptCount);
    }


    public static char getRandomCharacter() {
        return possibleChars.charAt(random.nextInt(29));
    }


    public static void logGuessCount(int totalAttemptCounts) {
        System.out.println("Total character guesses: " + totalAttemptCounts);
    }
}
