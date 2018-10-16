import java.io.*;
import java.util.Scanner;
public class readFromFile{
  public static void main(String[] arg){
      File f = new File("words_alpha.txt");
      String word = arg[0];
      double start = System.currentTimeMillis()/1000.0;
      try{
        Scanner s = new Scanner(f);
        while(s.hasNext()){
          if(s.next().equals(word)){
            //System.out.println(word + " was found");
            break;
          }
        }
        s.close();
      }
      catch(FileNotFoundException e){
        e.printStackTrace();
      }
      start = (System.currentTimeMillis()/1000.0)-start;
      File f2 = new File("logs/javalog.txt");
      try {
            BufferedWriter out = new BufferedWriter(
                   new FileWriter(f2, true));
            out.write(start + "\n");
            out.close();
        }
        catch (IOException e) {
            System.out.println("exception occoured" + e);
        }
      //System.out.println(start);
  }
}
