package chatserver;

import java.net.*;
import java.util.Scanner;

public class Inviatore implements Runnable
{
    private final int porta;
    private final InetAddress indirizzo;
    private final DatagramSocket client;
    
    public Inviatore(InetAddress host, int porta, DatagramSocket socket)
    {
        this.indirizzo = host;
        this.porta = porta;
        this.client = socket;
    }
    
    @Override
    public void run()
    {
        String msg = "";
        
        try
        {
            Scanner scan =new Scanner(System.in);
            /* Inizializzo il buffer per inizializzare il pacchetto udp */
            byte[] buffer = msg.getBytes();
            DatagramPacket inviomessaggio =new DatagramPacket(buffer, 0, indirizzo, porta);
            
            do
            {
                msg = scan.nextLine();
                
                /* Se il messaggio non è "q", cioè non voglio uscire dal processo */
                if(!msg.equals("q") && !msg.equals(""))
                {
                    /* Controllo se il messaggio e' privato o pubblico e lo invio */
                    if(msg.charAt(0) == ':')
                    {
                        /* Se il messaggio è privato prendo l'id e il messaggio e li concateno con il tag <msg> */
                        String id = msg.substring(1, msg.indexOf(' '));
                        msg = msg.substring(msg.indexOf(' ') + 1);
                        msg = "<msg id=\"".concat(id.concat("\">".concat(msg.concat("</msg>"))));
                    }
                    else
                    {
                        /* Sennò concateno direttamente il messaggio con il tag */
                        msg = "<msg>".concat(msg.concat("</msg>"));
                    }
                    /* Imposto il pacchetto udp con il buffer contenente il messaggio */
                    buffer = msg.getBytes("UTF-8");
                    inviomessaggio.setData(buffer);
                    inviomessaggio.setLength(buffer.length);
                    /* Invio il pacchetto */
                    client.send(inviomessaggio);
                }
            }
            while(!msg.equals("q"));
            
            /* Quando esco chiudo il socket così gli altri thread catturano l'eccezione del socket chiuso
               e terminano la loro esecuzione */
            client.close();
            System.out.println("Connessione terminata con successo");
        }
        catch (Exception e)
        {
            System.out.println("Inviatore: " + e);
        }
    }
}
