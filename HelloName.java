import java.util.*;

class HelloWorld {
	public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("What's your name?");
        String name = in.next();
        System.out.println("\nHello, " + name + "! Welcome to Hacktoberfest!");
	}
}
