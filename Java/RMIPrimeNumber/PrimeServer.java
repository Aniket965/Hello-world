import java.rmi.*;

public class PrimeServer
{
    public static void main(String args[])
    {
        try
        {
            PrimeImpli primpli=new PrimeImpli();
            Naming.rebind("RMIPrimeNumber",primpli);
        }
        catch(Exception ex){
            System.err.println("Server exception: " + ex.toString());
            ex.printStackTrace();
        }
    }
}