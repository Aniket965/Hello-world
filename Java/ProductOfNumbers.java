import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for(int x=1; x<11; x++){
            int productOfNumbers = x*n;
            System.out.println(""+n+" x "+x+" = "+productOfNumbers);
        }
    }
