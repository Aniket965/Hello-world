import java.rmi.*;
import java.rmi.server.*;

// Implementing the remote interface
public class PrimeImpli extends UnicastRemoteObject implements Prime
{
    public PrimeImpli() throws Exception
    {
    }

    // Implementing the interface method
    public int checkPrime(int num) throws RemoteException
    {
        int i,count = 0;
        for(i=2;i<=num/2;i++)
            if(num%i==0)
            {
                count++;
                break;
            }
        return (count);
    }
}