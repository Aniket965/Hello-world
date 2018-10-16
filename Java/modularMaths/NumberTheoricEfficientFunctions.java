package modularMaths;

import java.math.BigInteger;
import java.util.ArrayList;

public class NumberTheoricEfficientFunctions {

    public long longModEvaluation(long a, long b, long n) {
        BigInteger aPowb = efficientPowerEvaluation(new BigInteger(a + "") , b);
        return aPowb.mod(BigInteger.valueOf(n)).longValue();
    }

    public BigInteger efficientPowerEvaluation(BigInteger a, long b) {
        return efficientPowerEvaluation(a, a, b);
    }


    private BigInteger efficientPowerEvaluation(BigInteger original, BigInteger a, long b) {
        if (b > 1) {
            a = efficientPowerEvaluation(original, a, b / 2);
            a = a.multiply(a);
        } else if (b == 0) {
            return BigInteger.ONE;
        }

        if (b % 2 == 0 || b == 1) {

            return a;

        } else {

            return a.multiply(original);
        }

    }


    public int totientFunction(long number) {
        int totient = 0;
        for (int i = 1; i < number; i++) {
            if (calculateGCD(number, i) == 1) {
                totient++;
            }
        }
        return totient;
    }


    public long calculateGCD(long num1, long num2) {
        if (num2 != 0)
            return calculateGCD(num2, num1 % num2);
        return num1;
    }

    public Long[] factorsOf(long val) {
        ArrayList<Long> factors = new ArrayList<>();
        for (long i = 2; i <= val; i++) {
            if (val % i == 0) {
                factors.add(i);
                val /= i;
            }
        }
        return factors.toArray(new Long[factors.size()]);
    }
}
