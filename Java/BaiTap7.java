package com.basic;

import java.util.Scanner;

/*
* Tính S(n) = 1/2 + 2/3 + 3/4 + .... + n / n + 1;
* */
public class BaiTap7 {
    public static void main(String[] args) {
        System.out.print("Nhap n: ");
        int n = new Scanner(System.in).nextInt();
        float sum = 0;
        for (int i = 1; i <=n ; i++) {
            sum += (i*1.0)/(i+1);
        }
        System.out.println("Sum : " + sum);
    }
}
