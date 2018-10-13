package Mathematics;

import static Mathematics.EuclidGCD.gcd;

/**
 * Calculates lowest common multiple for given integer numbers
 */
public class LCM {
    public static void main(String[] args) {
        System.out.println(lcm(2, 5));
        System.out.println(lcm(15, 3));
        System.out.println(lcm(75, 10));
    }

    public static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

}
