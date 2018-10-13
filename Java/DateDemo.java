import java.util.Date;
import java.text.SimpleDateFormat;
public class DateDemo {

   public static void main(String args[]) {
      // Instantiate a Date object
      Date date = new Date();

      // display time and date using toString()
      System.out.println(date.toString());
      
      //format date to day-month-year
      SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy");
	   String format = formatter.format(date);
	   System.out.println(format);
   }
}
