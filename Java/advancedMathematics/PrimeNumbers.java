package advancedMathematics;

public class PrimeNumbers {

    private long generatePrime(int num) {
        if (num > 1) {
            for (int i = num; i > 1; i--) {
                if (isPrimeNumber(i)) {
                    return i;
                }
            }
            return num;
        }
        return generatePrime();
    }

    public long generatePrime() {
        int num = (int) (10 * Math.pow(10 * Math.random(), 10 * Math.random()));
        return generatePrime(num);
    }

    public boolean isPrimeNumber(long n) {

        for (long i = 2; i <= (int) Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return n != 2;
    }

}
