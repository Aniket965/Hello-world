import java.util.Scanner;
import static java.lang.System.out;
import java.lang.Math;

public class StringToInteger {

    final static Scanner sc = new Scanner(System.in);

    /*
    Manually converts a string to integer. Throws an exception if the string cannot be converted.
     */
     
    private static int str2Int(String str) {
        int result = 0;
        boolean negative = false;

        for (int i=0; i<str.length(); i++) {
            if (i == 0 && str.charAt(i) == 45) {
                negative = true;
            } else if (str.charAt(i)<48 || str.charAt(i)>57) {
                throw new IllegalArgumentException("Not a valid number.");
            } else {
                result += (str.charAt(i) - 48) * Math.pow(10, str.length()-i-1);
            }
        }

        if (negative) {
            return result * (-1);
        }

        return result;
    }

    public static void main(String[] args) {
        while (true) {
            try {
                out.println(str2Int(sc.nextLine()));
            }
            catch (IllegalArgumentException e) {
                out.println(e);
            }
        }
    }
}
