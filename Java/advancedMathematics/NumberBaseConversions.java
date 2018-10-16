package advancedMathematics;

public class NumberBaseConversions {

    public long binaryToDecimal(String binary) {
        long decimal = 0;
        int power = 0;
        for (int i = binary.length() - 1; i >= 0; i--) {
            String digit = "" + binary.charAt(i);
            decimal += Integer.parseInt(digit) * Math.pow(2, power++);
        }
        return decimal;
    }

    public String decimalToBinary(int decimal) {
        String binaryRep = "";
        int digit;
        while (decimal != 0) {
            digit = decimal % 10;
            decimal = decimal / 10;
            binaryRep = binaryRep + (digit % 2);
        }
        return binaryRep;
    }

    public long octalToDecimal(String octal) {
        long decimal = 0;
        int power = 0;
        for (int i = octal.length() - 1; i >= 0; i--) {
            String digit = "" + octal.charAt(i);
            decimal += Integer.parseInt(digit) * Math.pow(8, power++);
        }
        return decimal;
    }
}
