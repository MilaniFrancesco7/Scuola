package chatserver;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Gestore implements Runnable
{
    private final int porta;
    private final InetAddress indirizzo;
    /* Millisecondi dopo cui invia l'id per identificarsi */
    private final long attesa               = 10000;
    private final String id;
    private final DatagramSocket socket;
    
    public Gestore(InetAddress host, int porta, DatagramSocket socket, String id)
    {
        this.indirizzo = host;
        this.porta = porta;
        this.socket = socket;
        this.id = "<id>".concat(id.concat("</id>"));
    }
    
    @Override
    public void run()
    {
        try
        {
            /* Creo il buffer che avrà sempre lo stesso messaggio da inviare, ovvero l'id */
            byte[] buffer = id.getBytes("UTF-8");
            DatagramPacket invioid =new DatagramPacket(buffer, buffer.length, indirizzo, porta);
            
            /* Ogni attesa secondi invia l'id */
            while(true)
            {
                socket.send(invioid);
                Thread.sleep(attesa);
            }
        }
        /* Quando l'inviatore chiude il socket, appena il gestore prova a inviare l'id vede che il socket è chiuso
           così viene catturata l'eccezione e il thread termina l'esecuzione essendo uscito dal ciclo while */
        catch(Exception e)
        {
            System.out.println("Gestore: " + e);
        }
    }
}
