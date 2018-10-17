import java.util.Scanner;
public class GutenTagWelt{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Sprache?/Language?/n");
        System.out.println("Deutsch = de/n");
        System.out.println("English = en/n");
        System.out.println("Magyar = hu/n");
        
        String sprache = sc.next();
        sc.close();

        System.out.println(sprache(sprache));

    }

    public static String sprache(String a){
        switch(a){
            case "de":
                return "Guten Tag Welt!";
            case "en":
                return "Hello World!";
            case "hu":
                return "Szia!";
            default:
                return "Ich habe diese Sprache nicht";
        }
    }
}