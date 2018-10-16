package com.basic;


import java.util.Scanner;

/*
* Tính S(n) = 1 + 1/2 + 1/3 + ... + 1/n;
* */
public class BaiTap3 {
    public static void main(String[] args) {
        int n;
        float sum = 0;
        System.out.print("Nhap n: ");
        n = new Scanner(System.in).nextInt();

        for (int i = 1; i <= n; i++) {
            sum += 1.0/i; // if 1/i ==> int/int
        }
        System.out.println("Sum = "+ sum);
    }
}
