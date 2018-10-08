import java.util.*;

class ReverseString {

    public static void main(String[] args) {
        //Scanner sc = new Scanner(System.in);
        //System.out.print("Enter String => ");
        //String in = sc.nextLine();
        String in = "abc";
        String [] sp = in.split("");
        String ans = "";
        for (int i = 0; i < sp.length; i++) {
            ans = sp[i] + ans;
        }
        System.out.println(ans);
    }
}