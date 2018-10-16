package modularMaths;

import java.math.BigInteger;

public class ModularOperations {


    BigInteger original;
    private int MAX = 1000;

    // calculates (a^b) % n efficiently
    public long modifiedModEvaluation(long a, long b, long n) {

        long result = 1;
        for (long i = 1; i <= b; i++) {
            result = (result * a) % n;
        }
        return result;
    }

    // calculates (a^b) % n efficiently
    public long efficientEvaluation(long a, long b, long n) {

        String moduloBinary = Long.toBinaryString(b);
        long result = a % n;
        long power = (long) Math.pow(2 * Long.parseLong(moduloBinary.substring(0,
                1)), moduloBinary.length() - 1);
        long incrementalLimit = (long) (Math.log(power) / Math.log(2));

        BigInteger finalResult = BigInteger.ONE;

        for (int i = 1; i <= incrementalLimit; i++) {
            result *= result;
            result = result % n;

            finalResult = finalResult.multiply(BigInteger.valueOf(result)).mod(BigInteger.valueOf(n));
        }
        return finalResult.longValue();

    }

    public BigInteger efficientEvaluation(BigInteger a, long b, long n) {
        this.original = a;
        if (b > 1) {
            a = efficientEvaluation(a, b / 2, n);
            a = a.multiply(a);
            a = a.mod(BigInteger.valueOf(n));
        } else if (b == 0) {
            return BigInteger.ONE;
        }

        if (b % 2 == 0 || b == 1) {
            return a.mod(BigInteger.valueOf(n));

        } else {
            return a.multiply(this.original).mod(BigInteger.valueOf(n));
        }

    }


    public long nieveMultiplicativeInverse(long generator, long modulo) {
        if (calculateGCD(generator, modulo) == 1) {
            long workOn;
            long eliminate;
            for (long i = 1; i < MAX; i++) {
                for (long j = 1; j < MAX; j++) {
                    workOn = j * generator;
                    eliminate = i * modulo;
                    long checkEqualToOne = workOn - eliminate;
                    if (checkEqualToOne == 1) {
                        return j;
                    }
                }
            }
        }
        throw new RuntimeException();
    }

    public long multiplicativeInverse(long a, long n) {
        long retainOriginalModulo = n;
        long xRetainPastY;
        long quotientFloor;
        long multiplicativeInverse = 1;
        long y = 0;
        long RetainPastModulo;

        if (calculateGCD(a, n) == 1)
            while (a > 1) {
                quotientFloor = a / n;
                RetainPastModulo = n;
                n = a % n;
                a = RetainPastModulo;
                xRetainPastY = y;
                y = multiplicativeInverse - quotientFloor * xRetainPastY;
                multiplicativeInverse = xRetainPastY;
            }
        if (multiplicativeInverse < 0)
            multiplicativeInverse += retainOriginalModulo;

        return multiplicativeInverse;
    }


    public long calculateGCD(long num1, long num2) {
        if (num2 != 0)
            return calculateGCD(num2, num1 % num2);
        return num1;
    }

}

