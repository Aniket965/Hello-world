import java.io.*;
import java.rmi.*;
public class PrimeNumberRMI
{
    public static void main(String args[])
    {
        try
        {
            String url="rmi://127.0.0.1/RMIPrimeNumber";
            Prime interf=(Prime)Naming.lookup(url);

            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter the number: ");
            int num=Integer.parseInt(br.readLine());
            if(interf.checkPrime(num)==0)
                System.out.println(num+" is a prime number");
            else
                System.out.println(num+" is not a prime number");
        }
        catch(Exception ex){
            System.err.println("Server exception: " + ex.toString());
            ex.printStackTrace();
        }
    }
}
