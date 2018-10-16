package com.basic;

import java.util.Scanner;

/*
* Tính S(n) = 1 + 1/3 + 1/5 + ... + 1/(2n + 1);
* */
public class BaiTap5 {
    public static void main(String[] args) {
        System.out.print("Nhap n: ");
        int n = new Scanner(System.in).nextInt();
        float sum = (float)1.0;
        for (int i = 1; i <=n; i++) {
            sum += 1.0/(2*i+1);
        }
        System.out.println("Sum : " + sum);
    }
}
