/*
The clientThread class will be required in order to handle both read and write operations simultaneously

*/
import java.io.*;
import java.util.*;
import java.net.*;

class ClientThreadRead extends Thread
{
    protected DataInputStream datIn;
    ClientThreadRead(DataInputStream datIn)
    {
        this.datIn=datIn;
    }
    public void run()
    {
        //this class handles write operations on the client
        String message;
        Scanner sc=new Scanner(System.in);
        try{
            while(true)
            {
                message=datIn.readUTF();
                //currently we are not dealing with closing the connection
                System.out.println("\n");
                System.out.println("Friend/s: "+message);
                
            
            }
        } 
        catch(Exception e)
        {
            System.out.println("error: ClientThreadRead: ");
            e.printStackTrace();
        }
    }
}