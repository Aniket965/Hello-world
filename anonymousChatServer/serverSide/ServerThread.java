import java.io.*;
import java.util.*;
import java.net.*;

//thread for dataIn1 read operation.

class ServerThread extends Thread
{
    int clientNum;
    Socket clientSoc;
    Socket otherClients[];
    String message;
    int totalClients;

    OutputStream out[]=new OutputStream[100];
    DataOutputStream dataOut[]=new DataOutputStream[100];

    ServerThread(int totalClients,int clientNum,Socket clientSoc, Socket otherClients[])
    {
        this.totalClients=totalClients;
        this.clientNum=clientNum;
        this.clientSoc=clientSoc;
        this.otherClients=otherClients;
    }
    ServerThread()
    {

    }
    
    public void run()//this function is essentially overriden, this function is called when the thread is started.
    {

        try
        {
            /*OutputStream out1=clientSoc1.getOutputStream();
            DataOutputStream dataOut1=new DataOutputStream(out1);*/

            
            DataInputStream dataIn;

           

            InputStream in=clientSoc.getInputStream();
            dataIn=new DataInputStream(in);



            //there will be only one input stream but many output streams
            
            int i;


            for(i=0;i<this.totalClients;i++)
            {
                if(i!=clientNum)
                {
                    
                    out[i]=otherClients[i].getOutputStream();
                    dataOut[i]=new DataOutputStream(out[i]);
                    //creating dataOutStream for previous clients already added.
                }
            }

            while(true)
            {
                
                //whenever this client sends a message it has to be received by all other clients
                message=dataIn.readUTF();
                System.out.println("message from some client:"+message);
                for(i=0;i<this.totalClients;i++)
                {
                    if(i!=clientNum)
                    {
                        dataOut[i].writeUTF(message);
                    }
                }
            }


        }
        catch(Exception e)
        {
            System.out.println("error: ");
            e.printStackTrace();
        }
        
    }
    public void updateThread()
    {
        System.out.println("totalClients: "+this.totalClients+"  for thread:"+this.clientNum);
        try{
            /*for(int i=this.totalClients;i<totalC;i++)
            {
                System.out.println("made outputStream for:i"+i);
                   
            }*/
            out[this.totalClients]=otherClients[this.totalClients].getOutputStream();
            dataOut[this.totalClients]=new DataOutputStream(out[this.totalClients]);
            this.totalClients++;
            //creating DataOutputStream for next client.
        }
        catch(Exception e)
        {
            System.out.println("could not update thread");
            e.printStackTrace();
        }
        
    }
}