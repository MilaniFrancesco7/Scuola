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
	BufferedReader   inDalClient; 
	DataOutputStream outVersoClient;

	public Socket attendi() 
	{
		try 
		{
			System.out.println("1 SERVER partito in esecuzione ...");
			// creo un server sulla porta 8888 
			server = new ServerSocket(8888);
			// rimane in attesa di un client 
			client = server.accept();
			// chiudo il server per inibire altri client
			server.close();
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
			while(stringaRicevuta != "f")
			{
				
				// rimango in attesa della riga trasmessa dal client
				System.out.println("Benvenuto client, scrivi una frase e la trasformo in maiuscolo. Attendo ...");
				stringaRicevuta = inDalClient.readLine();
				System.out.println("Ricevuta la stringa dal cliente : "+stringaRicevuta);

				//la modifico e la rispedisco al client  
				stringaModificata=stringaRicevuta.toUpperCase();
				System.out.println("Invio la stringa modificata al client ...");
				outVersoClient.writeBytes(stringaModificata+'\n');
			}

			//termina elaborazione sul server : chiudo la connessione del client 
			System.out.println("SERVER: fine elaborazione ");
			
			client.close();
		}  
		catch (Exception e) 
		{
			System.out.println(e.getMessage());
			System.out.println("Errore durante la connessione...");
			System.exit(2);
		}
	}

	public static void main(String args[])
	{
		ServerStr servente = new ServerStr();
		servente.attendi ();
		servente.comunica();
	} 
}
