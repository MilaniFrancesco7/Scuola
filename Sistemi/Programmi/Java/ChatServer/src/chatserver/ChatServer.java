/* 
Creare una chat peer to peer (non un server centralizzato) che utilizza il protocollo UDP
Il socket utilizza la porta 2345, il timeout con cui il processo invia l'id è di 30 secondi
Si possono inviare messaggi privati o pubblici
    I messaggi privati non sono realmente privati perchè tutti possono leggerli (dato che la destinazione è l'ip di broadcast),
    ma il destinatario segnala il messaggio per diversificarlo
Bisogna gestire il tutto con i tag (convenzioni)
<id></id> per identificare il mittente
<msg></msg> per segnalare i messaggi pubblici
<msg id=""> per i messaggi privati con destinatario
Poi:
    Più avanti prevedere la gestione di tag html più comuni es. <b></b>, <u></u>
*/
package chatserver;

import java.io.*;
import java.net.*;
import java.util.Collections;
import java.util.Enumeration;

import java.text.SimpleDateFormat;
import java.util.Date;

public class ChatServer
{
    private static final int porta          = 2345;
    private static final String hostname    = "172.30.4.255";
    private static final String id          = "Il migliore";
    /* Serve per ignorare i messaggi inviati dal processo stesso che tornano indietro */
    private static final String scheda      = "br0";
    
    /* Funzione che a partire dalla lista di schede di rete dell'host, cattura l'ip scelto tramite la posizione */
    public static String getIP(int posizione) throws SocketException
    {
        /* schede è la "lista" di tutte le schede di rete di questo host */
        Enumeration<NetworkInterface> schede = NetworkInterface.getNetworkInterfaces();  
        /* indirizziSchedeRete è la "lista" di tutti gli ip (sia ipv4 sia ipv6) di una scheda di rete */
        Enumeration<InetAddress> indirizziSchedeRete;
        /* Per ogni scheda di rete */
        for(NetworkInterface netint: Collections.list(schede))
        {
            /* Se il nome della scheda della lista equivale alla variabile scheda (variabile della classe) */
           if(netint.getName().equals(scheda))
           {
               /* indirizziSchedeRete prende tutti gli ip della scheda di rete */
               indirizziSchedeRete = netint.getInetAddresses();
               /* Per ogni ip della scheda di rete */
               int i = 0;
               for(InetAddress inetAddress : Collections.list(indirizziSchedeRete))
               {
                   if(i == posizione)
                       return inetAddress.toString();
                   i++;
               }
           }
        }
        /* Non dovrebbe mai arrivare a questo punto */
        return null;
    }
    
    public static void main(String[] args) throws SocketException, UnknownHostException, IOException
    {
        /* Creo il socket e prendo l'ip partendo da un hostname */
        DatagramSocket socket =new DatagramSocket(porta);
        InetAddress indirizzo = InetAddress.getByName(hostname);
        
        /* Prendo l'ip con cui la scheda di rete si identifica in rete (Serve al thread ricevitore) */
        String ip = getIP(1);
        
        /* Creo i vari oggetti e i rispettivi thread che gestiscono il tutto */
        Inviatore invio =new Inviatore(indirizzo, porta, socket);
        Ricevitore ricevo =new Ricevitore(socket, ip, id);
        Gestore gestisco =new Gestore(indirizzo, porta, socket, id);
        
        System.out.println("Benvenuto nel client di Gusella Michele");
        System.out.println("L'IP con cui ti presenti in rete e': " + ip.substring(1));
        System.out.println("Sintassi per inviare un messaggio privato -> :iddestinatario messaggio");
        System.out.println("Scrivi q per uscire dal programma");
        System.out.println("---------------- Inizio Chat ----------------");
        Thread tinvio =new Thread(invio);
        Thread tricevo =new Thread(ricevo);
        Thread tgestisco =new Thread(gestisco);
        
        tgestisco.start();
        tinvio.start();
        tricevo.start();
        
        //String timeStamp = new SimpleDateFormat("dd MM yyyy HH mm ss").format(new Date());
        //System.out.println("Data: " + timeStamp);
        
    }
}