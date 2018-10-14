//Prints subsequence of a string 
import java.util.*;
class Solution {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String str = scanner.nextLine();
    subseq("",str);
  }

    public static void subseq(String processed,String unprocessed){
       if(unprocessed.isEmpty()){
           System.out.println(processed);
           return;
       }
       char ch=unprocessed.charAt(0);
       unprocessed=unprocessed.substring(1);
       subseq(processed+ch,unprocessed);
       subseq(processed,unprocessed);
   }
}
