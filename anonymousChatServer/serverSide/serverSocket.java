import java.io.*;
import java.net.*;
import java.util.*;

class serverSocket

{
    static int numClients=0;
    static ServerThread threads[]=new ServerThread[100];
    static Socket clients[]=new Socket[100];
    //this is going to be a char server that will be established between 2 clients

    /*one important idea is that multiple clients can be handled only when you have
    2 threads for 2 clients. A single thread cannot handle 2 clients.
    Another important idea is that when we use reading and writing for 2 clients then we essentially would also need 2 threads one for reading and one for writing.
    */
    static final int port=1337;

    public static void main(String args[])throws IOException
    {
        /*
        The ServerSocket class is used for creating a socket for the server.
        */

        ServerSocket serverSoc=new ServerSocket(port); 
        //here the port number to be listening is given

        /*
        Socket client1=null;
        Socket client2=null;
        */

        //So we are allowing a max number of 100 clients per group.

        //since this program actually can handle multiple clients, it can accept multiple socket connections and so whenever a client wants to join, 
        //it should be allowed to join and each such time we are gonna call the accept() function.
        int i;
        System.out.println("intialized server, running at port 1337");
        
        while(numClients<100)
        {
            
            try
            {
                        
                clients[numClients]=serverSoc.accept();
                System.out.println("new client added");
                
                //once a client has joined we can create a thread immediately.
                
                /*
                accept function will listen to connections made to this socket and will accept it if any.
                */
                System.out.println("numClients now:"+numClients);
                
                for(i=0;i<numClients;i++)
                {
                    System.out.println("from server side, updated client: "+ i);
                    System.out.println("numClients now:"+numClients);
                    threads[i].updateThread();
                }

                threads[numClients]=new ServerThread(numClients+1,numClients,clients[numClients], clients);
                threads[numClients].start();//starts running the thread
                numClients++;
                //System.out.println("numClients at end of loop:");
                
                
            }
            catch(IOException e)
            {
                System.out.println("Error:");
                e.printStackTrace();
            }
            //ServerThread is a class that we have written capable of starting a new thread and finally 
            //being able to handle all communications with that client.
            
            //after 2 threads (basically 2 clients no more clients will be added or in other words no more users will be added)

            
        }
        

        

    }
    



}