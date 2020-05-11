// Milani Francesco
// 5 AI
// 280120

import java.io.*;
import java.net.*;
import java.util.*;

class NuovoClient extends Thread
{
	ServerSocket server      = null;
	Socket client            = null;
	String stringaRicevuta   = null;
	String stringaModificata = null;
	BufferedReader   	       inDalClient;
	DataOutputStream		   outVersoClient;
	
	String exit = "exit";
	String quit = "quit";
	String kill = "kill";
	public static int Contatore = 1;
	
	public NuovoClient (Socket socket)
	{
		this.client = socket;
	}
	
	public void run()
	{
		try
		{
			comunica();
		}
		catch(Exception e)
		{
			e.printStackTrace(System.out);
		}
	}
	
	public void comunica() throws Exception
	{
		try
		{
			inDalClient = new BufferedReader(new InputStreamReader (client.getInputStream()));
			outVersoClient = new DataOutputStream(client.getOutputStream());
			System.out.println("Client Connesso. Questo server riceve una stringa e la riinvia in maiuscolo");
			outVersoClient.writeBytes("Benvenuto nel Server | v1.5\n");
			outVersoClient.writeBytes("Inserisci una stringa per convertirla in maiuscolo\n");
			for(;;)
			{
				//rimango in attesa della riga trasmessa dal client
				System.out.println(MultiJava.ContatoreClient + "° Client");
				System.out.println("\t" + NuovoClient.Contatore + "° transazione");
				stringaRicevuta = inDalClient.readLine();
				if(stringaRicevuta.equals(exit) || stringaRicevuta.equals(quit))
				{
					outVersoClient.writeBytes("La connessione verra' interrotta\n");
					client.close();
					inDalClient.close();
					outVersoClient.close();
					MultiJava.ContatoreClient++;
					break;
				}
				else
				{
					System.out.println("\t\tStringa ricevuta: " + stringaRicevuta);

					//la modifico e la rispedisco al client  
					stringaModificata = stringaRicevuta.toUpperCase();
					System.out.println("\t\tRiinvio stringa in maiuscolo");
					outVersoClient.writeBytes(stringaModificata + '\n');
					NuovoClient.Contatore++;
					outVersoClient.writeBytes("Inserisci un'altra stringa\n");
				}
			}
			outVersoClient.close();
			inDalClient.close();
			System.out.println("Chiusura socket" + client);
			client.close();
		}
		catch(Exception e)
		{
			//System.out.println(e.getMessage());
			//System.out.println("Errore durante la connessione !");
		}
	}
}

public class MultiJava
{
	public static int Porta= 7777;
	public static int ContatoreClient = 0;
	public void StartServer()
	{
		try
		{
			//Contatore = 1;
			ServerSocket server = new ServerSocket(Porta);
			for(;;)
			{
				System.out.println("Server in attesa ");
				//System.out.println("Server avviato ! \n\tPorta " + Porta + "\n\tStringa di chiusura: \033[0;1m" + exit + "\033[0m/\033[0;1m" + quit + "\033[0m\n\tStringa di kill: \033[0;1m" + kill + "\033[0m\nAttendo Connessioni...");
				Socket socket = server.accept();
				NuovoClient NuovoThread = new NuovoClient(socket);
				NuovoThread.start();
			}
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
			System.out.println("Errore durante l'istanza del server !");
			System.exit(1);
		}
	}

	public static MultiJava servente = new MultiJava();

	public static void main(String args[])
	{
		servente.StartServer();
	}
}
