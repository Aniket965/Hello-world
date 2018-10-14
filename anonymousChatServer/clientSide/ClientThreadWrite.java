/*
The clientThread class will be required in order to handle both read and write operations simultaneously

*/
import java.io.*;
import java.util.*;
import java.net.*;

class ClientThreadWrite extends Thread
{
    //here we will need DataOutputStream class object

    protected DataOutputStream datOut;
    ClientThreadWrite(DataOutputStream datOut)
    {
        this.datOut=datOut;
    }
    public void run()
    {
        //this class handles write operations on the client
        String message;
        Scanner sc=new Scanner(System.in);
        try{
            
            while(true)
            {
                
                message=sc.nextLine();
                datOut.writeUTF(message);
            }
    
        }
        catch(Exception e)
        {
            System.out.println("error: ClientThreadWrite ");
            e.printStackTrace();
        }
    }
}