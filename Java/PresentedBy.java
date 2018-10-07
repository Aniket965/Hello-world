import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class PresentedBy {
    public static void main(String[] args) {
        ArrayList<String> presenters = new ArrayList<String>(Arrays.asList("DigitalOcean","Github","Twilio"));
        Collections.shuffle(presenters);
        String space = "     ";
        String presentedMsg = "Hacktoberfest is presented by:";
        for(String s : presenters){
            presentedMsg += space + s;
        }
        System.out.println(presentedMsg);

    }
}
