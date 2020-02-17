// Milani Francesco
// 5 AI
// 280120

import java.io.*;
import java.net.*;
import java.util.*;

class NuovoClient extends Thread
{
	ServerSocket server      = null;
	Socket client  			 = null;
	String stringaRicevuta   = null;
	String stringaModificata = null;
	BufferedReader   	       inDalClient;
	DataOutputStream		   outVersoClient;
	
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
			MultiJavaWeb.Array.add(client.toString());
			inDalClient = new BufferedReader(new InputStreamReader (client.getInputStream()));
			outVersoClient = new DataOutputStream(client.getOutputStream());
			outVersoClient.writeBytes("HTTP/1.1 200 OK\nContent-Type: text/html; charset=UTF-8\nConnection: keep-alive\n\n");
			outVersoClient.writeBytes("<html><head><title>MultiServer Java</title></head><h2>MultiServer Java</h2></br><p>" + MultiJavaWeb.Array +"</p></html>");
			
			for(;;)
			{
				//rimango in attesa della riga trasmessa dal client
				stringaRicevuta = inDalClient.readLine();
				if(stringaRicevuta.equals(MultiJavaWeb.exit) || stringaRicevuta.equals(MultiJavaWeb.quit))
				{
					outVersoClient.writeBytes("La connessione verra' interrotta\n");
					client.close();
					inDalClient.close();
					outVersoClient.close();
					break;
				}
			}
			outVersoClient.close();
			inDalClient.close();
			System.out.println("Chiusura " + client);
			client.close();
		}
		catch(Exception e)
		{
			//System.out.println(e.getMessage());
			//System.out.println("Errore durante la connessione !");
		}
	}
}

public class MultiJavaWeb
{
	int Temp2 = 0;			//Variabile utilizzata per verificare se non si è ancora connesso nessun client
	public static int Porta= 7777;
	static String exit = "exit";
	static String quit = "quit";
	static String kill = "kill";
	static ArrayList<String> Array = new ArrayList<String>();
	
	public void StartServer()
	{
		try
		{
			//Contatore = 1;
			ServerSocket server = new ServerSocket(Porta);
			for(;;)
			{
				if(Temp2 == 0)
				{
					System.out.println("Server in attesa ");
					//System.out.println("Server avviato ! \n\tPorta " + Porta + "\n\tStringa di chiusura: \033[0;1m" + "exit" + "\033[0m/\033[0;1m" + "quit" + "\033[0m\n\tStringa di kill: \033[0;1m" + "kill" + "\033[0m\nAttendo Connessioni...");
					Socket socket = server.accept();
					NuovoClient NuovoThread = new NuovoClient(socket);
					NuovoThread.start();
					Temp2++;
				}
				else
				{
					Socket socket = server.accept();
					NuovoClient NuovoThread = new NuovoClient(socket);
					NuovoThread.start();
				}
			}
		}
		catch(Exception e)
		{
			System.out.println(e.getMessage());
			System.out.println("Errore durante l'istanza del server !");
			System.exit(1);
		}
	}

	public static MultiJavaWeb servente = new MultiJavaWeb();

	public static void main(String args[])
	{
		servente.StartServer();
	}
}
