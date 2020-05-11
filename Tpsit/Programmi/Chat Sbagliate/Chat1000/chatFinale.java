/*
	Francesco Milani
	5^AI
	110220
*/

import java.io.*;
import java.net.*;
import java.util.*;

class MessageSender implements Runnable {
    
    public final static int PORT = 2345;  					// Porta di connessione
    private DatagramSocket socket;						// Variabile socket
    private String hostname;							// Variabile per l'ip
    
    MessageSender(DatagramSocket s, String host) 				// Costruttore per l'unione di socket e hostname
    {
        socket = s;
        hostname = host;
    }
    
    private void sendMessage(String s) throws Exception 		//Funzione per inviare il messaggio s
    {
        byte buffer[] = s.getBytes();
        InetAddress address = InetAddress.getByName(hostname);			//Incapsulazione dell'hostname con l'indirizzo IP
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length, address, PORT); //Impacchettazione dei dati
        socket.send(packet);				//Spedizione dei dati
    }
    
    public void run()
    {
        boolean connected = false;
        
        do 
        {
            try 
            {
                sendMessage("<msg id=\"Xx_JustFraMilani00_xX\">Il Migliore si e' connesso</msg>");			//Messaggio di benvenuto
                connected = true;
            } 
            catch (Exception e) 
            {
                System.err.println(e);
            } 
                       
        }while (!connected);	//do while finchè non si è connesso
       
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));		//Lettura stringhe
        
        while (true) //Ciclo infinito
        {
            
            try 
            {
                while (!in.ready()) 
                {
                    Thread.sleep(100);
                }
                
                sendMessage("<msg>"+in.readLine()+"</msg>");			//Messaggio
            } 
            catch(Exception e) 
            {
                System.err.println(e);
            }
        }
    }
}

class MessageReceiver implements Runnable {
   
    DatagramSocket socket;
    byte buffer[];
    
    MessageReceiver(DatagramSocket s) 	//Costruttore per unire socket e buffer
    {
        socket = s;
        buffer = new byte[1024];
    }
    
    public void run() 
    {
        while (true) 
        {
            try 
            {
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);	//Incapsulazione dell'hostname con l'indirizzo IP
                socket.receive(packet);											  	//Ricevimento dei dati
                String received = new String(packet.getData(), 0, packet.getLength());	
                System.out.println("\nRicevuto: "+received);						//Stampa della stringa ricevuta
            } 
            catch(Exception e) 
            {
                System.err.println(e);
            }
        }
    }
}

public class chatFinale {
    
    public static void main(String args[]) throws Exception 
    {
        String host = null;
        /*
        if (args.length < 1) {											//Utile per la richiesta degli argomenti da terminale
            System.out.println("Usage: java ChatClient <server_hostname>");
            System.exit(0);
        } else {
            host = args[0];
        }
        */
        
        host = "172.30.4.255";								//Indirizzo di broadcast
        System.out.println("* * * CHAT BROADCAST * * * ");
        DatagramSocket socket = new DatagramSocket();			//Incapsulazione dell'hostname con l'indirizzo IP
        MessageReceiver r = new MessageReceiver(socket);
        MessageSender s = new MessageSender(socket, host);
        Thread rt = new Thread(r);								//Istanza dei thread
        Thread st = new Thread(s);

        ChatCenter reciever = new ChatCenter();					//Ricevente
        reciever.start();
		//rt.start
        st.start();
    }
}



class ChatCenter extends Thread {						//Classe per la configurazione di ricezione dei messaggi
    
    public final static int PORT = 2345;
    private final static int BUFFER = 1024;
    
    private DatagramSocket socket;						
    private ArrayList<InetAddress> clientAddresses;		//Arraylist per gli indirizzi ip
    private ArrayList<Integer> clientPorts;				//Arraylist per le porte
    private HashSet<String> existingClients;			//HashSet -> Tipo predefinito che rappresenta insiemi di oggetti
    
    public ChatCenter() throws IOException 
    {
        socket = new DatagramSocket(PORT);
        clientAddresses = new ArrayList();
        clientPorts = new ArrayList();
        existingClients = new HashSet();
    }
    
    @Override
    public void run() 
    {
		
        byte[] buffer = new byte[BUFFER];
        
        while (true) 
        {			
            try 
            {
                Arrays.fill(buffer, (byte)0);							//Riempimento dell'array con il buffer
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length);		//Incapsulazione del buffer con la sua lunghezza
                socket.receive(packet);									//Ricevimento del pacchetto
                
                String content = new String(buffer, buffer.length);		
                
                InetAddress clientAddress = packet.getAddress();		//Indirizzo del client
                int clientPort = packet.getPort();						//Porta del client
                
                String id = clientAddress.toString() + "," + clientPort;	//Stampa dello string id
                
                if (!existingClients.contains(id)) {
                    existingClients.add( id );
                    clientPorts.add( clientPort );
                    clientAddresses.add(clientAddress);
                }
                
                System.out.println(id + " : " + content);
                
                byte[] data = (id + " : " +  content).getBytes();
                
                for (int i=0; i < clientAddresses.size(); i++) 
                {
					InetAddress cl = clientAddresses.get(i);
                    int cp = clientPorts.get(i);
                    packet = new DatagramPacket(data, data.length, cl, cp);
                    socket.send(packet);								//Invio del pacchetto
                }
            }
            catch(Exception e) 
            {
                System.err.println(e);
            }
        }
    }
}
