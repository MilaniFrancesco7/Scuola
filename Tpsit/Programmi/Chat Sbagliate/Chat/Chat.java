import java.net.*;
import java.io.*;
import java.util.*;

public class Chat{
	
	private static final String TERMINATE = "Exit";
    static String name;
    
    static volatile boolean finished = false;
    
    private static DatagramSocket socket = null;
    
    private static InetAddress indirizzo = null;
    
    private static int port = 8888;
    
     public static void main(String[] args)
    {
		
		try
		{ 
			indirizzo= InetAddress.getByName("172.30.4.255");
            System.out.println("Sent");
			
			Scanner input = new Scanner(System.in);
            System.out.print("Inserisci il tuo nome: ");
            name = input.nextLine();
            
          
			socket= new DatagramSocket(port);
            socket.setBroadcast(true);
            
            Thread t = new Thread(new ReadThread(socket,indirizzo,port));
              
            t.start();
            
            System.out.println("Inserisci un messaggio: ");
            
            while(true)
            {
				String message; 
				Scanner sc = new Scanner(System.in);
				message = sc.nextLine(); 
				
				if(message.equalsIgnoreCase(Chat.TERMINATE))		//Confronto con la stringa di terminazione 
                { 
					finished = true; 					//Il socket esce dal gruppo multicast 
					socket.close(); 								//Il socket viene chiuso
					break; 
                }
                
                message = name + ": " + message;
                
                byte[] buffer = message.getBytes();
				DatagramPacket datagram = new DatagramPacket(buffer,buffer.length,indirizzo,8888);
				socket.send(datagram);
			}
		
		}
		catch(SocketException se)
        {
            System.out.println("Errore creazione socket");
            se.printStackTrace();
        }
        catch(IOException ie)
        {
            System.out.println("Errore scrittura/lettura nel socket");
            ie.printStackTrace();
        }  
}


class ReadThread implements Runnable 
{ 
    private DatagramSocket socket; 
    private InetAddress indirizzo; 
    private int port;
    private static final int MAX_LEN = 1000; 
    
    ReadThread(DatagramSocket socket,InetAddress indirizzo,int port) 
    { 
        this.socket = socket; 
        this.indirizzo = indirizzo; 
        this.port = port; 
    } 
      
    @Override
    public void run() 
    { 
        while(!Chat.finished) 
        { 
                byte[] buffer = new byte[ReadThread.MAX_LEN]; 
                DatagramPacket datagram = new
                DatagramPacket(buffer,buffer.length,indirizzo,port); 
                String message; 
            try
            { 
                socket.receive(datagram); 
                message = new
                String(buffer,0,datagram.getLength(),"UTF-8"); 
                
                if(!message.startsWith(Chat.name)) 
                    System.out.println(message); 
            } 
            catch(IOException e) 
            { 
                System.out.println("Socket closed!"); 
            } 
        } 
    } 
}
}
