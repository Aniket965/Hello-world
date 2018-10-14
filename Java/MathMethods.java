import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class MathMethods {

    static int binaryStringToInteger(String binary) {
        int decimal = 0;
        for (int i = binary.length() - 1; i >= 0; i--) {
            decimal += Character.getNumericValue(binary.charAt(i)) * Math.pow(2, binary.length() - i);
        }

        return decimal;
    }

    static boolean isPentagonal(long number) {

        for (long i = 1; i < number / 2; i++) {
            if (i * (3 * i - 1) == 2 * number) {
                return true;
            }
        }

        return false;
    }

    static String intToBinary(int number) {
        StringBuilder binaryBuilder = new StringBuilder();
        String binaryString;
        int newRemainder;

        while (number != 0) {
            newRemainder = number % 2;
            number = number / 2;
            binaryBuilder.insert(0, String.valueOf(newRemainder));
        }

        binaryString = binaryBuilder.toString();

        return binaryString;
    }

    static boolean stringIsPalindrome(String string) {
        boolean isPalindrome = true;

        /*if (string.length() % 2 == 0) {*/
        for (int i = 0; i < string.length() / 2; i++) {
            if (string.charAt(i) != string.charAt(string.length() - 1 - i)) {
                isPalindrome = false;
                break;
            }
        }
        /*} else {

        }*/

        return isPalindrome;
    }

    static boolean isPrimeWithEven(long numberPrime) {
        boolean prime = true;
        long i = 1;

        if (numberPrime == 1) {
            prime = false;
        } else {
            while (prime && i < (int) Math.sqrt(numberPrime)) {
                i++;
                if (numberPrime % i == 0)
                    prime = false;
            }
        }

        return prime;
    }

    static boolean isPrime(long numberPrime) {
        boolean prime = true;
        long i = 1;

        while (prime && i < (int) Math.sqrt(numberPrime)) {
            i += 2;
            if (numberPrime % i == 0)
                prime = false;
        }

        return prime;
    }

    static long isDivisor(long number) {
        long i = 1;
        boolean prime = false;

        while (i < number / 2 && !prime) {
            i = i + 2;
            if (number % i == 0) {
                System.out.println("I check if " + i + " is prime");
                prime = isPrime(i);
            }
        }

        return i;
    }

    static boolean isPandigitalNoZero(int numberPan) {
        String stringPan = String.valueOf(numberPan);
        return isPanNoZero(stringPan);
    }

    static boolean isPandigitalNoZero(String stringPan) {
        return isPanNoZero(stringPan);
    }

    static boolean isPandigital(int numberPan) {
        String stringPan = String.valueOf(numberPan);
        return isPan(stringPan);
    }

    static boolean isPandigital(long numberPan) {
        String stringPan = String.valueOf(numberPan);
        return isPan(stringPan);
    }

    static boolean isPandigital(String stringPan) {
        return isPan(stringPan);
    }

    static boolean isPanToNNoZero(String stringPan) {
        boolean isPan = true;

        for (int i = 1; i <= stringPan.length(); i++) {
            if (stringPan.contains(Integer.toString(i))) {
                isPan = false;
            }
        }

        isPan = panExcludeZero(stringPan, isPan);

        return isPan;
    }

    private static boolean panExcludeZero(String stringPan, boolean isPan) {
        if (stringPan.contains("0")) {
            isPan = false;
        } else if (isPan) {
            for (int i = 0; i < stringPan.length(); i++) {
                for (int j = i + 1; j < stringPan.length(); j++) {
                    if (stringPan.charAt(i) == stringPan.charAt(j)) {
                        isPan = false;
                        break;
                    }
                }
            }
        }
        return isPan;
    }

    private static boolean isPanNoZero(String stringPan) {
        boolean isPan = true;

        for (int i = 9; i > stringPan.length(); i--) {
            if (stringPan.contains(Integer.toString(i))) {
                isPan = false;
            }
        }

        isPan = panExcludeZero(stringPan, isPan);

        return isPan;
    }

    private static boolean isPan(String stringPan) {
        boolean isPan = true;

        for (int i = 0; i < stringPan.length(); i++) {
            if (stringPan.contains(Integer.toString(i))) {
                isPan = false;
            }
        }

        return isPan;
    }

    /**
     * Put all permutations in a list of strings
     *
     * @param string       What to permutate
     * @param permutations Add all permutations here
     */
    static void getPermutations(String string, List<String> permutations) {
        int[] c = new int[string.length()];

        permutations.add(string);

        int i = 0;
        while (i < string.length()) {
            if (c[i] < i) {
                if (i % 2 == 0) {
                    string = switchChars(string, 0, i);
                } else {
                    string = switchChars(string, c[i], i);
                }
                permutations.add(string);
                c[i] += 1;
                i = 0;
            } else {
                c[i] = 0;
                i++;
            }
        }
    }

    /**
     * Put all permutations in a list of longs
     *
     * @param number       What to permutate
     * @param permutations Add all permutations here
     */
    static void getPermutations(Long number, List<Long> permutations) {
        String string = String.valueOf(number);
        int[] c = new int[string.length()];

        permutations.add(number);

        int i = 0;
        while (i < string.length()) {
            if (c[i] < i) {
                if (i % 2 == 0) {
                    string = switchChars(string, 0, i);
                } else {
                    string = switchChars(string, c[i], i);
                }
                permutations.add(Long.valueOf(string));
                c[i] += 1;
                i = 0;
            } else {
                c[i] = 0;
                i++;
            }
        }
    }

    /**
     * Checks if a list already contains a permutation of number
     *
     * @param number What to permutate
     * @param target Add all permutations here
     */
    private static boolean containsPermutation(Long number, Set<Long> target) {

        if (target.contains(number)) {
            return true;
        }

        List<Long> permutations = new ArrayList<>();
        getPermutations(number, permutations);
        for (Long numbers : permutations) {
            if (target.contains(numbers)) {
                return true;
            }
        }

        return false;
    }

    static Set<Long> getOnePermutation(Long maxValue) {
        Set<Long> candidates = new HashSet<>();

        //Füllt candidates mit unpermutierten Startwerten
        for(long i = 1; i <= maxValue; i++) {
            if (!MathMethods.containsPermutation(i, candidates)) {
                candidates.add(i);
            }
        }

        return candidates;
    }

    /**Put all permutations in a list of longs
     *
     * @param number        What to permutate
     * @param permutations  Add all permutations here
     */
    static void getPermutationPrimes(Long number, List<Long> permutations) {
        String string = String.valueOf(number);
        int[] c = new int[string.length()];

        if (isPrimeWithEven(number)) {
            permutations.add(number);
        }

        int i = 0;
        while (i < string.length()) {
            if (c[i] < i) {
                if (i % 2 == 0) {
                    string = switchChars(string, 0, i);
                } else {
                    string = switchChars(string, c[i], i);
                }
                if (isPrimeWithEven(Long.valueOf(string))) {
                    permutations.add(Long.valueOf(string));
                }
                c[i] += 1;
                i = 0;
            } else {
                c[i] = 0;
                i++;
            }
        }
    }

    private static String switchChars(String string, int firstPartner, int secondPartner) {
        String newString;
        char firstChar;
        char secondChar;

        char[] charArray = string.toCharArray();
        firstChar = charArray[firstPartner];
        secondChar = charArray[secondPartner];
        charArray[firstPartner] = secondChar;
        charArray[secondPartner] = firstChar;

        newString = new String(charArray);

        return newString;
    }

    //Sum of digits
    static long sumOfDigits(long number) {
        long sumOfDigits = 0;

        String numberString = String.valueOf(number);

        for (int i = 0; i < numberString.length(); i++) {
            sumOfDigits += Character.getNumericValue(numberString.charAt(i));
        }

        return sumOfDigits;
    }

    //Sum of digits
    static BigDecimal sumOfDigits(BigDecimal number) {
        BigDecimal sumOfDigits = new BigDecimal(0);

        String numberString = String.valueOf(number);

        for (int i = 0; i < numberString.length(); i++) {
            sumOfDigits = sumOfDigits.add(new BigDecimal(Character.getNumericValue(numberString.charAt(i))));
        }

        return sumOfDigits;
    }

    /** Calculate factorials of digits and sum them up
     *
     * @param number    input number to get sum of factorials
     * @return          sum of factorials
     */
    static BigDecimal sumOfFactorials(long number) {
        BigDecimal sumOfFactorials = new BigDecimal(0);
        String numberString = String.valueOf(number);

        for (int i = 0; i < numberString.length(); i++) {
            long nextDigit = Character.getNumericValue(numberString.charAt(i));
            BigDecimal nextDigitFactorial = facultyBigDecimal(nextDigit);
            sumOfFactorials = sumOfFactorials.add(nextDigitFactorial);
        }

        return sumOfFactorials;
    }

    /** Calculate factorials of digits and sum them up
     *
     * @param number    input number to get sum of factorials
     * @return          sum of factorials
     */
    static BigDecimal sumOfFactorials(BigDecimal number) {
        BigDecimal sumOfFactorials = new BigDecimal(0);
        String numberString = String.valueOf(number);

        for (int i = 0; i < numberString.length(); i++) {
            long nextDigit = Character.getNumericValue(numberString.charAt(i));
            BigDecimal nextDigitFactorial = facultyBigDecimal(nextDigit);
            sumOfFactorials = sumOfFactorials.add(nextDigitFactorial);
        }

        return sumOfFactorials;
    }

    /** Calculate factorials of digits and sum them up
     *
     * @param numberString    input number to get sum of factorials
     * @return          sum of factorials
     */
    static BigDecimal sumOfFactorials(String numberString) {
        BigDecimal sumOfFactorials = new BigDecimal(0);

        for (int i = 0; i < numberString.length(); i++) {
            long nextDigit = Character.getNumericValue(numberString.charAt(i));
            BigDecimal nextDigitFactorial = facultyBigDecimal(nextDigit);
            sumOfFactorials = sumOfFactorials.add(nextDigitFactorial);
        }

        return sumOfFactorials;
    }

    /**Get faculty of a given number as a string
     *
     * @param number
     * @return
     */
    static String facultyString(long number) {
        BigDecimal faculty = new BigDecimal(1);

        for (long n = 1; n <= number; n++) {
            faculty = faculty.multiply(BigDecimal.valueOf(n));
        }

        return String.valueOf(faculty);
    }

    /**Get faculty of a given number as a long
     *
     * @param number
     * @return
     */
    static long facultyLong(long number) {
        BigDecimal faculty = new BigDecimal(1);

        for (long n = 1; n <= number; n++) {
            faculty = faculty.multiply(BigDecimal.valueOf(n));
        }

        return Long.valueOf(String.valueOf(faculty));
    }

    /**Get faculty of a given number as a BigDecimal
     *
     * @param number
     * @return
     */
    static BigDecimal facultyBigDecimal(long number) {
        BigDecimal faculty = new BigDecimal(1);

        for (long n = 1; n <= number; n++) {
            faculty = faculty.multiply(BigDecimal.valueOf(n));
        }

        return faculty;
    }
}
