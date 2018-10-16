package com.basic;

/*Bài tập 1: Tính S(n) = 1 + 2 + 3 + … + n.
* O(1) : ∑n=1∞n=n(n+1)/2
* */

import java.util.Scanner;

public class BaiTap1 {

    public static void main(String[] args) {
        System.out.print("Nhap n: ");
        int n = new Scanner(System.in).nextInt();
        int sum = n*(n+1)/2;
        System.out.println(sum);
    }
}
