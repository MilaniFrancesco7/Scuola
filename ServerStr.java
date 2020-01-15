/*
 * Milani Francesco
 * 5AI
 * 140120 
 * 
 * Server in Java che presa una stringa da client input restituisce la stringa in caratteri maiuscoli
 * 
 */
import java.io.*;
import java.net.*;
import java.util.*;

public class ServerStr 
{
	ServerSocket server      = null;  	// Variabile per la creazione del server
	Socket client            = null;  	// Variabile per l'accettazione del client
	String stringaRicevuta   = null;  	// Stringa di supporto per l'input
	String stringaModificata = null;  	// Stringa di supporto per l'output
	String quit	= "quit";
	int PORTA = 8888;
	int contaclient = 1;
	int contaserver = 1;
	BufferedReader   inDalClient; 
	DataOutputStream outVersoClient;

	public Socket attendi() 
	{
		try 
		{
			System.out.println("Server numero "+contaserver+" in esecuzione...\n");
			System.out.println("\tPorta = "+PORTA);
			System.out.println("\tStabilire una connessione= nc localhost "+PORTA);
			System.out.println("\tPer uscire inserire: "+quit+"\n");
			// creo un server sulla porta 8888 
			server = new ServerSocket(PORTA);
			// rimane in attesa di un client 
			client = server.accept();
			// chiudo il server per inibire altri client
			server.close();
			contaserver++;
			//associo due oggetti al socket del client per effettuare la scrittura e la lettura 
			inDalClient = new BufferedReader(new InputStreamReader (client.getInputStream()));
			outVersoClient = new DataOutputStream(client.getOutputStream());
		}
		catch (Exception e) 
		{
			System.out.println(e.getMessage());
			System.out.println("Errore durante l'istanza del server !");
			System.exit(1);
		}
		
		return client;
	} 
	
	public void comunica() 
	{
		try
		{
			System.out.println("Benvenuto client, scrivi una frase e la trasformo in maiuscolo.");
			outVersoClient.writeBytes("Server UPPA stringhe\n");
			System.out.println("\nAttendo la stringa dal cliente");
			
			while(stringaRicevuta != quit)
			{
				stringaRicevuta = inDalClient.readLine();	// Rimango in attesa della stringa dal client
				
				if(stringaRicevuta.equals(quit))		// Controllo per chiudere la connessione
				{
					System.out.println("\n\n\tChiudo la connessione...\n");
					contaclient = 1;
					client.close();
				}
				else
				{
					//modifico la stringa e la rispedisco al client  
					System.out.println("\nRichiesta numero "+contaclient+"\n"); 
					System.out.println("Ricevuta la stringa dal cliente : "+stringaRicevuta);
					contaclient++;
					stringaModificata=stringaRicevuta.toUpperCase();
					System.out.println("Invio la stringa modificata al client ...\n");
					outVersoClient.writeBytes(stringaModificata+'\n');
					System.out.println("Attendo la stringa dal cliente");
				}
				
				
				
			}
		}  
		catch (Exception e) 		// Cattura le eccezioni
		{
			//System.out.println(e.getMessage());
			//System.out.println("Errore durante la connessione...");
		}
	}
	
	public static ServerStr servente = new ServerStr();
	
	public static void main(String args[])
	{
		while(true)
		{
			servente.attendi();
			servente.comunica();
		}
	} 
} 
