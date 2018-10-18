public class Fun {
	
	public static void main(String[] args) {
		int a = 7;
		int b = 35;
		swap(a, b);
		System.out.println(a + " " + b);
	}

	public static void swap(int a, int b) {
		int temp = a;
		a = b;
		b = temp;
        System.out.println(a + " " + b);

	}
}