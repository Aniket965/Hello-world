package com.basic;

import java.util.Scanner;

/*
 * Tính S(n) = 1/2 + 1/4 + ... + 1/2n
 * */
public class BaiTap4 {
    public static void main(String[] args) {
        System.out.print("Nhap n:");
        int n = new Scanner(System.in).nextInt();
        float sum = 0;
        for (int i = 1; i <= n ; i++) {
            sum += 1.0/(2*i);
        }
        System.out.println("Sum : " + sum);
    }
}
