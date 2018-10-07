import josx.platform.rcx.*;
    
public class HelloWorld
{
    public static void main(String[] args) throws Exception
    {
        LCD.clear();
        TextLCD.print ("hello");
        Thread.sleep(2500);
        TextLCD.print ("world");
        Thread.sleep(2500);
    } 
}
