import java.util.Scanner;
import java.util.Arrays;

public class GCD {
  public static void main(String args[]) {
      Scanner in=new Scanner(System.in);
      String str1=in.next();
      String str2=in.next();
      String ar1[]=str1.split("(?!^)");
      String ar2[]=str2.split("(?!^)");
      Arrays.sort(ar1);
      Arrays.sort(ar2);
      if(Arrays.equals(ar1,ar2))
        System.out.println("Anagrams");
      else
        System.out.println("Not Anagrams");
  }
}  
