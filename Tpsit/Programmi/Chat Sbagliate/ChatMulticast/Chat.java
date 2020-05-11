// Francesco Milani

import java.net.*; 
import java.io.*; 
import java.util.*; 

public class Chat 
{ 
    private static final String TERMINATE = "Exit"; 					//Stringa di terminazione
    static String name; 
    static volatile boolean finished = false; 
    public static void main(String[] args) 
    { 
        if (args.length != 2) 											//Controllo per l'inserimento dell'indirizzo multicast e della porta
            System.out.println("Two arguments required: <multicast-host> <port-number>"); 
        else
        { 
            try
            { 
                InetAddress group = InetAddress.getByName(args[0]); 	//Incapsulazione dell'hostname con l'indirizzo IP
                int port = Integer.parseInt(args[1]); 					//Prende una stringa e restituisce un numero intero
                Scanner sc = new Scanner(System.in); 
                System.out.print("Enter your name: "); 
                name = sc.nextLine(); 								
                MulticastSocket socket = new MulticastSocket(port); 	//Istanza di un nuovo socket multicast
              
                socket.setTimeToLive(1); 								//Per la subnet 1, per il localhost 0. Il setTimeToLive permette di controllare la diffusione del multicast					 
                  
                socket.joinGroup(group); 								//Il socket entra in un gruppo multicast
                
                Thread t = new Thread(new ReadThread(socket,group,port)); //Istanza di un nuovo thread, passando le variabili di socket, gruppo e porta 
              
                t.start();												//Parte il thread per spedire i messaggi  
                  
                System.out.println("Start typing messages...\n"); 
                while(true) 
                { 
                    String message; 
                    message = sc.nextLine(); 
                    if(message.equalsIgnoreCase(Chat.TERMINATE))		//Confronto con la stringa di terminazione 
                    { 
                        finished = true; 
                        socket.leaveGroup(group);						//Il socket esce dal gruppo multicast 
                        socket.close(); 								//Il socket viene chiuso
                        break; 
                    } 
                    message = name + ": " + message; 	
                    byte[] buffer = message.getBytes(); 
                    DatagramPacket datagram = new DatagramPacket(buffer,buffer.length,group,port); //Istanza un DatagramPacket
                    socket.send(datagram); 
                } 
            } 
            catch(SocketException se) 
            { 
                System.out.println("Error creating socket"); 
                se.printStackTrace(); 
            } 
            catch(IOException ie) 
            { 
                System.out.println("Error reading/writing from/to socket"); 
                ie.printStackTrace(); 
            } 
        } 
    } 
} 
class ReadThread implements Runnable 
{ 
    private MulticastSocket socket; 
    private InetAddress group; 
    private int port; 
    private static final int MAX_LEN = 1000; 
    ReadThread(MulticastSocket socket,InetAddress group,int port) 
    { 
        this.socket = socket; 
        this.group = group; 
        this.port = port; 
    } 
      
    @Override
    public void run() 
    { 
        while(!Chat.finished) 
        { 
                byte[] buffer = new byte[ReadThread.MAX_LEN]; 
                DatagramPacket datagram = new
                DatagramPacket(buffer,buffer.length,group,port); 
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
