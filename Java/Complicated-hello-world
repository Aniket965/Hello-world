import java.util.ArrayList;
import java.util.Collections;

public class Main
{
    public static void main(String[] args)
    {
        // Creating letters array
        String[] toTransfer = {"H", "E", "L", "L", "O", " ", "W", "O", "R", "L", "D"};
        ArrayList<String> letters = new ArrayList<>();
        // Copying letters into ArrayList
        for(int i = 0; i < toTransfer.length; i++)
        {
            letters.add(toTransfer[i]);
        }
        // Randomizing the letters array
        Collections.shuffle(letters);
        // Creating the "Hello World" string
        String result = "";
        for(int i = 0; i < toTransfer.length; i++)
        {
            for(int i2 = 0; i2 < letters.size(); i2++)
            {
                if(letters.get(i2).equals(toTransfer[i]))
                {
                    result += letters.get(i2);
                    break;
                }
            }  
        }
        // Printing out result
        System.out.println(result);
    }
}
