import java.util.Scanner;

public class PigLatin {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("What would you like to code?");
		System.out.println(code(input.nextLine()));
		input.close();

	}
	
	public static String code(String eng) {
		String pig = "";
		String vowels = "aeiou";
		Scanner reader = new Scanner(eng);
		while(reader.hasNext()){
			String word = reader.next();
			if(vowels.contains(word.substring(0,1))) {
				word += "way";
			}
			else {
				int cons = 0;
				//to ensure that words that use y as a vowel don't get messed up or throw an error
				if(word.substring(0,1).equals("y")) {
					cons++;
				}
				while(!vowels.contains(word.substring(cons,cons+1))&&!word.substring(cons,cons+1).equals("y")) {
					cons++;
				}
				word = word.substring(cons) + word.substring(0,cons) + "ay";
			}
			pig += word + " ";
		}
		reader.close();
		return pig;
	}
}
