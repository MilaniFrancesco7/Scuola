import java.net.*;
import java.io.*;
import java.util.*;

/* 
 * Per eseguire correttamente il programma bisogna eseguire da terminale il seguente comando
 * java Chat IP PORTA
 * L'IP deve essere di tipo broadcast, cioè 172.30.4.255
 * 
 * Esempio. java Chat 172.30.4.255 8888
 */

public class Chat
{
	// Stringa di chiusura connessione
    private static final String exit = "Exit";
    static String name;
    
    // Variabile per la verifica della continuità della chat
    static volatile boolean finished = false;
    
    public static void main(String[] args)
    {
		// Controllo se sono stati inviati corettamente IP(Broadcast) e Porta
        if (args.length != 2)
        {
            System.out.println("2 arguments richiesti: <broadcast-host> <port-number>");
		}
        else
        {
            try
            {
				// Converto IP e Porta
                broadcast("Hello", InetAddress.getByName("172.30.4.255"));
                System.out.println("Sent")
                
                // Richiedo nome con cui identificarsi
                Scanner input = new Scanner(System.in);
                System.out.print("Inserisci il tuo nome: ");
                name = input.nextLine();
                
                // Creazione socket Multicast
                DatagramSocket socket = new DatagramSocket(port);
                
                socket.setBroadcast(true);
                
                // Per chat solo in localhost settare a 0, altrimenti settare a 1
                //socket.setTimeToLive(1);
                
                // Entra nel "gruppo" della chat
                //socket.joinGroup(group);
                //Thread t = new Thread(new ReadThread(socket,group,port));
                
                // Creazione thread per leggere i messaggi
                //t.start();
                
                // Join della chat
                System.out.println("Manda un messaggio ...\n");
                while(true)
                {
                    String message;
                    message = input.nextLine();
                    
                    // Controllo se la stringa è "Exit"
                    if(message.equalsIgnoreCase(Chat.exit))
                    {
                        finished = true;
                        //socket.leaveGroup(group);
                        socket.close();
                        break;
                    }
                    message = name + ": " + message;
                    
                    // Aggiunta al buffer e invio messaggio
                    byte[] buffer = message.getBytes();
                    DatagramPacket datagram = new DatagramPacket(buffer,buffer.length,group,port);
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
    }
}

class ReadThread implements Runnable
{
    private MulticastSocket socket;
    private InetAddress group;
    private int port;
    private static final int MAX_LEN = 1000;
    
    // "Legge" il thread
    ReadThread(MulticastSocket socket,InetAddress group,int port)
    {
        this.socket = socket;
        this.group = group;
        this.port = port;
    }
    
    public void run()
    {
        while(!Chat.finished)
        {
			byte[] buffer = new byte[ReadThread.MAX_LEN];
			DatagramPacket datagram = new DatagramPacket(buffer,buffer.length,group,port);
			String message;
            try
            {
                socket.receive(datagram);
                message = new String(buffer,0,datagram.getLength(),"UTF-8");
                
                // Controllo del nome
                if(!message.startsWith(Chat.name))
                {
                    System.out.println(message);
				}
            }
            catch(IOException e)
            {
                System.out.println("Socket closed!");
            }
        }
    }
}
