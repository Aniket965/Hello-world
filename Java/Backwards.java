public class HelloWorld {
	public static void main(String args[]) {
		String oldStr = "!dlroW olleH";
		String newStr = "";
		for (char c : oldStr.toCharArray()) {
			newStr = c + newStr;
		}
		System.out.println(newStr);
	}
}
