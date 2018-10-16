package com.basic;

import java.util.Scanner;

/*
* Tính S(n) = 1^2 + 2^2 + 3^2 + … + n^2;
*   sum = (n * (n + 1) * (2 * n + 1 )) / 6;
* */
public class BaiTap2 {

    public static void main(String[] args) {
        System.out.print("Nhap n:");
        int n =new Scanner(System.in).nextInt();
        System.out.println("Sum = " + (n*(n+1)*(2*n+1))/6);
    }
}
