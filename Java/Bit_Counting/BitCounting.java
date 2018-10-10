
public class BitCounting {
	
	public static void main(String[] args) {
		System.out.println(countBits(3));
	}

	public static int countBits(int n) {
		String binary = Integer.toBinaryString(n);
		int counter = 0;
		for (int i = 0; i < binary.length(); i++) {
			if (binary.charAt(i) == '1') {
				counter++;
			}
		}
		return counter;
	}

}
