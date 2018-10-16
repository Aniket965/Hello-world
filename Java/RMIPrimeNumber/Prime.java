import java.rmi.Remote;
import java.rmi.RemoteException;

// Creating Remote interface
public interface Prime extends Remote
{
    int checkPrime(int num) throws RemoteException;
}
