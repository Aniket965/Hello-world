import java.util.*;
import java.io.*;
import java.net.*;
class chat{
final static String end="end";
static boolean quit=false;
static String name;
	public static void main(String args[]) throws Exception{
		
		try{
			InetAddress ip=InetAddress.getByName(args[0]);
			int port=Integer.parseInt(args[1]);
			MulticastSocket socket=new MulticastSocket(port);
			socket.joinGroup(ip);
			System.out.println("Enter your name:");
			Scanner sc=new Scanner(System.in);
			name=sc.nextLine();
			NewThread t=new NewThread(socket,ip,port);

			System.out.println("Type message:");
			
			while(true){
			String msg=sc.nextLine();
			String data=name+": "+msg;
				try{
				if(msg.equals(end)){
					System.out.println("bbyee...");
					quit=true;
					String leaved=name+" leaved the chat\n";
					byte buf[]=leaved.getBytes();
					DatagramPacket dp=new DatagramPacket(buf,buf.length,ip,port);
					socket.send(dp);
					socket.leaveGroup(ip);
					socket.close();
					break;
				}else{
				
				byte buf[]=data.getBytes();
				DatagramPacket dp=new DatagramPacket(buf,buf.length,ip,port);
				socket.send(dp);}
				}catch(Exception e){System.out.println(e);}
				}
			}
			catch(Exception e){System.out.println(e);}
		}
	
}
class NewThread implements Runnable{
	Thread t;
	private MulticastSocket socket;
	private int port;
	private InetAddress ip;
	NewThread(MulticastSocket s,InetAddress i,int p){
		t=new Thread(this);
		this.socket=s;
		this.ip=i;
		this.port=p;
		t.start();
	}
	public void run(){
	while(!chat.quit){
		try{
			byte buf[]=new byte[1024];
			DatagramPacket dp=new DatagramPacket(buf,buf.length,ip,port);
			socket.receive(dp);
			String msg= new String(dp.getData(),0,dp.getLength());
			if(!msg.startsWith(chat.name))
				System.out.println(msg);
		}catch(Exception e){System.out.println(e);}
	}
	}
}
