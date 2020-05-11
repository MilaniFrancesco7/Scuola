package chatserver;

import java.net.*;

public class Ricevitore implements Runnable
{
    /* Dimensione del buffer e dell'array che contiene gli id e ip */
    private final int dim                       = 64;
    /* L'ip dell'interfaccia di rete scelta nella classe principale, non il localhost */
    private final String iplocale;
    /* Di default false, se true stampa anche i messaggi senza tag o con tag non riconosciuti (utile per controllare cosa riceve il thread) */
    private final boolean noTag                 = false;
    /* Ciò che riceve */
    private String msg;
    /* L'id che comunica ogni tot tempo */
    private final String idlocale;
    /* ip[] contiene gli ip di tutti gli host che inviano pacchetti */
    private String[] ip =new String[dim];
    /* id[] contiene gli id che gli host inviano. Le posizioni tra ip e id sono collegate (logicamente) ovvero,
       id[i] identifica l'host che ha l'ip equivalente a ip[i] */
    private String[] id =new String[dim];
    private final DatagramSocket server;
    
    public Ricevitore(DatagramSocket socket, String ip, String id)
    {
        this.server = socket;
        this.iplocale = ip;
        this.idlocale = id;
    }
    
    /* Controlla il tag del messaggio ricevuto, i vari return sono gestiti dalla prossima funzione */
    private String controllaTag(String s)
    {
        /* Se il messaggio non parte con < sicuramente non è un tag */
        if(s.charAt(0) == '<')
        {
            /* Se dopo < c'è scritto id> */
            if(s.charAt(1) == 'i' && s.charAt(2) == 'd' && s.charAt(3) == '>')
                return "id";
            /* Se dopo < c'è scritto msg, ci sono due casi */
            if(s.charAt(1) == 'm' && s.charAt(2) == 's' && s.charAt(3) == 'g')
            {
                /* Se il tag si chiude, quindi è <msg>, è un messaggio pubblico */
                if(s.charAt(4) == '>')
                    return "msg";
                /* Se dopo <msg c'è scritto id=" vuol dire che il messaggio è privato */
                if(s.charAt(4) == ' ' && s.charAt(5) == 'i' && s.charAt(6) == 'd' && s.charAt(7) == '=' && s.charAt(8) == '"')
                    return "pvt";
            }
        }
        return "errore";
    }
    
    /* Funzione che in base al tag, esegue certe operazioni */
    private void gestisciInput(String s, DatagramPacket pacchetto)
    {
        String contenuto;
        boolean esco = false;
        int posLibera = -1;
        
        /* Se il tag è <id> */
        if(controllaTag(s).equals("id"))
        {
            /* Legge il contenuto del tag ovvero la stringa dal primo carattere dopo <id> fino a prima di </id> */
            contenuto = s.substring(4, s.indexOf("</id>"));
            /* for che scorre tutto l'array degli ip */
            for(int i = 0; i < dim && esco == false; i++)
            {
                /* Se l'ip sorgente del pacchetto è già nell'array */
                if(ip[i].equals(pacchetto.getAddress().toString().substring(1)))
                {
                    /* Se l'id associato a quell'ip è diverso da quello inviato dall'utente */
                    if(!id[i].equals(contenuto))
                    {
                        /* Cambialo ed esci */
                        System.out.println("[" + ip[i] + "] " + id[i] + " ha cambiato username in " + contenuto);
                        id[i] = contenuto;
                    }
                    /* Se l'id è uguale a quello ricevuto, non fare nulla perchè è tutto appost ed esci */
                    esco = true;
                }
                /* Mentre scorro l'array, controllo la prima posizione libera che trovo e me la salvo */
                if(id[i].equals("") || ip[i].equals("") && posLibera == -1)
                    posLibera = i;
            }
            /* Se non sono uscito, quindi non ho trovato l'ip nell'array, vuol dire che è la prima volta che ricevo
               un pacchetto da questo host, quindi lo inserisco nella prima posizione libera. posLibera serve semplicemente
               a non dover scorrere un altra volta l'array in cerca di un posto dove mettere l'ip e l'id */
            if(!esco)
            {
                id[posLibera] = contenuto;
                ip[posLibera] = pacchetto.getAddress().toString().substring(1);
                System.out.println("[" + ip[posLibera] + "] " + contenuto + " e' online!");
            }
        }
        /* Se invece il tag è <msg> */
        else if(controllaTag(s).equals("msg"))
        {
            /* Legge il contenuto del tag ovvero la stringa dal primo carattere dopo <msg> fino a prima di </msg> */
            contenuto = s.substring(5, s.indexOf("</msg>"));
            /* for che scorre tutto l'array degli ip */
            for(int i = 0; i < dim && esco == false; i++)
            {
                /* Se l'ip sorgente del pacchetto è già nell'array e l'id corrispondente non è "" */
                if(ip[i].equals(pacchetto.getAddress().toString().substring(1)) && !id[i].equals(""))
                {
                    /* Stampa che questo id ha inviato il messaggio */
                    System.out.println(id[i] + ": " + contenuto);
                    esco = true;
                }
            }
            /* Se non sono uscito, quindi non ha trovato l'ip nell'array, stampo il messaggio con mittente
               l'ip sorgente del pacchetto udp */
            if(!esco)
            {
                System.out.println(pacchetto.getAddress().toString().substring(1) + ": " + contenuto);
            }
        }
        /* Se il messaggio è privato, quindi con tag <msg id=" */
        else if(controllaTag(s).equals("pvt"))
        {
            /* Legge il contenuto del sottotag id ovvero la stringa dal primo carattere dopo <msg id=" fino a prima di "> */
            String destinatario = s.substring(9, s.indexOf("\">"));
            contenuto = s.substring(2 + s.indexOf("\">"), s.indexOf("</msg>"));
            /* for che scorre tutto l'array degli ip */
            for(int i = 0; i < dim && esco == false && !destinatario.equals(""); i++)
            {
                /* Se l'ip sorgente del pacchetto è già nell'array e l'id corrispondente non è "" */
                if(ip[i].equals(pacchetto.getAddress().toString().substring(1)) && !id[i].equals(""))
                {
                    /* Stampa che questo id ha inviato il messaggio privato, controllando se il destinatario è questo host */
                    if(destinatario.equals(idlocale))
                        System.out.println(id[i] + " verso <<<" + destinatario + ">>>: " + contenuto);
                    else
                        System.out.println(id[i] + " verso " + destinatario + ": " + contenuto);
                    esco = true;
                }
            }
            /* Se non sono uscito, quindi non ha trovato l'ip nell'array */
            if(!esco && !destinatario.equals(""))
            {
                System.out.println(pacchetto.getAddress().toString().substring(1) + " verso " + destinatario + ": " + contenuto);
            }
        }
        /* Se il tag non viene riconosciuto, e il noTag è true */
        else if(noTag && controllaTag(s).equals("errore"))
        {
            /* for che scorre tutto l'array degli ip */
            for(int i = 0; i < dim && esco == false; i++)
            {
                /* Se l'ip sorgente del pacchetto è già nell'array e l'id corrispondente non è "" */
                if(ip[i].equals(pacchetto.getAddress().toString().substring(1)) && !id[i].equals(""))
                {
                    /* Stampo l'intera stringa che ha come mittente l'id */
                    System.out.println(id[i] + "->noTag: " + s); 
                    esco = true;
                }
            }
            /* Se non sono uscito, quindi non ha trovato l'ip nell'array */
            if(!esco)
            {
                System.out.println(pacchetto.getAddress().toString().substring(1) + "->noTag: " + s);
            }
        }
    }
    
    @Override
    public void run()
    {
        /* Creo il buffer di dimensione dim e lo associo al pacchetto udp */
        byte[] ricevo =new byte[dim];
        DatagramPacket ricevopacchetto =new DatagramPacket(ricevo, ricevo.length);
        
        /* Inizializzo gli array che contengono id e ip */
        for(int i = 0; i < ip.length; i++)
        {
            ip[i] = "";
            id[i] = "";
        }
        
        try
        {            
            while(true)
            {
                /* Pulisco il buffer e aspetto di ricevere qualcosa */
                for (int i = 0; i < dim; i++)
                    ricevo[i] = 0;
                server.receive(ricevopacchetto);
                
                /* Controlla che l'ip sorgente non sia quello della scheda di rete scelta nella classe principale.
                   Utile perchè se l'ip di destinazione è il broadcast, il router reindirizza il pacchetto anche
                   a questo host, che però deve ignorarlo dato che è lui stesso il mittente */
                if(!ricevopacchetto.getAddress().toString().equals(iplocale))
                {
                    msg =new String(ricevopacchetto.getData());
                    gestisciInput(msg, ricevopacchetto);
                }
            }
        } catch(Exception e)
        {
            System.out.println("Ricevitore: " + e);
        }
    }
}
