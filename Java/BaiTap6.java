package com.basic;

import java.util.Scanner;

/*
* Tính S(n) = 1/1x2 + 1/2x3 +...+ 1/n x (n + 1);
* */
public class BaiTap6 {
    public static void main(String[] args) {
        System.out.print("Nhap n: ");
        int n = new Scanner(System.in).nextInt();
        float sum = 0;
        for (int i = 1; i <=n ; i++) {
            sum += 1.0/(i*(i+1));
        }
        System.out.println("Sum : " + sum);
    }
}
