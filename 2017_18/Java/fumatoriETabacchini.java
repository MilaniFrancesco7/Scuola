/* Brunello Cesare - Milani Francesco
 * 
 * 3 fumatori, per fumare debbono avere 3 cose
 * ognuno di loro ha una cosa a testa, hanno una quantità indeterminata
 * (boolean forse, non int)
 * 
 * Il tabacchino è un altra entità che possiede tutte e tre le cose che
 * servono, ne può vendere solo due alla volta
 * 
 * le risorse sono:
 * cartina
 * tabacco
 * accendino
 * 
 * quando un fumatore finisce di fumare rimette a disposizione delle
 * nuove risorse a caso,
 * 
 * per esempio
 * F1 ha le cartine
 * F2 ha il tabacco
 * F3 ha l'accendino
 * */
import java.util.concurrent.Semaphore;
import java.util.Random;
import java.util.Scanner;

public class fumatoriETabacchini {
	
	private static Random rand = new Random();
	
	private static final int MAX_AVAILABLE = 1;	//Moltiplicità del semaforo
	private static final int MAX_FUMATE = 5;	//Numero di interazioni fra tabacchino e fumatori
	private static final int MAX_TEMPO = 4000;	//Tempo massimo che un thread può aspettare
	private static final int MIN_TEMPO = 1000;	//Tempo minimo che un thread può aspettare
	
	//Per fare in modo che i thread scambino informazioni fra di loro,
	//facciamo ricorso ad una soluzione forse poco elegante, la comunicazione
	//fra i thread è gestita tramite tre variabili globali alle quali
	//i thread possono accedere ad ogni momento durante la loro esecuzione
	public static boolean tcartine,ttabacco,taccendino;
	public static int i=0;
	
	private final static Semaphore available = new Semaphore(MAX_AVAILABLE, true);
	
	public static class fumatore implements Runnable
	{
		//Queste sono le risorse di cui ogni fumatore dispone
		private boolean cartine;
		private boolean tabacco;
		private boolean accendino;
		//Contatore per tutte le volte che il fumatore ha fumato
		private int fumate;
		
		//Semplice metodo costruttore in cui vengono settati i parametri
		//in base all'input dell'utente
		fumatore(boolean cartine, boolean tabacco, boolean accendino)
		{
			this.cartine=cartine;
			this.tabacco=tabacco;
			this.accendino=accendino;
			fumate=0;
		}
		
		public void run()
		{
			//L'intero spezzone codice viene messo in un try-catch per gestire
			//eventuali errori di runtime ed eccezioni
			try
			{
				do
				{
					//Occupa una moltiplicità del semaforo
					available.acquire();
					if(cartine==true && (ttabacco==true && taccendino))
					{
						fumate++;
						Thread.sleep((rand.nextInt(MAX_TEMPO) + MIN_TEMPO));
						//Stampe di controllo
						System.out.println("Il fumatore: 1 ha fumato "+fumate+" volte");
						//System.out.println("CARTINE"+cartine+" tabacco "+ttabacco+" accendino"+taccendino);
						ttabacco=false;
						taccendino=false;
					}else if((tabacco==true && (tcartine==true && taccendino)))
					{
						fumate++;
						Thread.sleep((rand.nextInt(MAX_TEMPO) + MIN_TEMPO));
						System.out.println("Il fumatore: 2 ha fumato "+fumate+" volte");
						//System.out.println("cartine"+tcartine+" TABACCO "+tabacco+" accendino"+taccendino);
						tcartine=false;
						taccendino=false;
					}else if((accendino==true && (tcartine==true && ttabacco)))
					{
						fumate++;
						Thread.sleep((rand.nextInt(MAX_TEMPO) + MIN_TEMPO));
						System.out.println("Il fumatore: 3 ha fumato "+fumate+" volte");
						//System.out.println("cartine"+tcartine+" tabacco "+ttabacco+" ACCENDINO"+accendino);
						tcartine=false;
						ttabacco=false;
					}
					available.release();
				}while(i<MAX_FUMATE);
			}catch(Exception e){}
		}
	}
	
	public static class tabacchino implements Runnable
	{
		//Possiede tutte e tre le cose, a random genera de delle cose
		//che servono per fumare e le mette a disposizione dei fumatori
		//quando un fumatore ha finito di fumare, "distrugge"
		private boolean cartine;
		private boolean tabacco;
		private boolean accendino;
		private int randomInt;
		
		tabacchino(){
			randomInt = rand.nextInt(3) + 1;
			switch(randomInt)
			{
				case 1:
					//1 1 0
					cartine=true;
					tabacco=true;
					accendino=false;
					break;
				case 2:
					//1 0 1
					cartine=true;
					tabacco=false;
					accendino=true;
					break;
				case 3:
					//0 1 1
					cartine=false;
					tabacco=true;
					accendino=true;
					break;
				default:
					break;
			}
			tcartine=cartine;
			ttabacco=tabacco;
			taccendino=accendino;
		}
		
		public void run(){
			synchronized(this)
			{
				try{
					//INIZIO DELLA VITA DEL THREAD
					do
					{
						//Occupa una moltiplicità del semaforo
						available.acquire();
						Thread.sleep(MIN_TEMPO);
						
						//Generazione dei 3 casi possibili in cui il tabacchino
						//fornisce le risorse disponibili ai fumatori
						randomInt = rand.nextInt(3) + 1;
						switch(randomInt)
						{
							case 1:
								//1 1 0
								cartine=true;
								tabacco=true;
								accendino=false;
								break;
							case 2:
								//1 0 1
								cartine=true;
								tabacco=false;
								accendino=true;
								break;
							case 3:
								//0 1 1
								cartine=false;
								tabacco=true;
								accendino=true;
								break;
							default:
								break;
						}
						System.out.println("IL TABACCHINO HA LE SEGUENTI RISORSE");
						System.out.println("Cartine?	"+cartine);
						System.out.println("Tabacco? 	"+tabacco);
						System.out.println("Accendino?	"+accendino);
						tcartine=cartine;
						ttabacco=tabacco;
						taccendino=accendino;
						available.release();
						i++;
					}while(i<MAX_FUMATE);
				}catch(Exception e){}
			}
		}
	}
	
	public static void main (String args[]) throws InterruptedException {
		
		tabacchino t1 = new tabacchino();
		
		fumatore f1 = new fumatore(true, false, false);
		fumatore f2 = new fumatore(false, true, false);
		fumatore f3 = new fumatore(false, false, true);
		
		/*System.out.println("Fumatore 1:");
			System.out.println("Cartine: "+f1.cartine);
			System.out.println("Tabacco: "+f1.tabacco);
			System.out.println("Accendino: "+f1.accendino);
		
		System.out.println("Fumatore 2:");
			System.out.println("Cartine: "+f2.cartine);
			System.out.println("Tabacco: "+f2.tabacco);
			System.out.println("Accendino: "+f2.accendino);
		
		System.out.println("Fumatore 3:");
			System.out.println("Cartine: "+f3.cartine);
			System.out.println("Tabacco: "+f3.tabacco);
			System.out.println("Accendino: "+f3.accendino);*/
			
		Thread tf1 = new Thread(f1);
		Thread tf2 = new Thread(f2);
		Thread tf3 = new Thread(f3);
		Thread tt1 = new Thread(t1);
		
		tt1.start();
		tf1.start();
		tf2.start();
		tf3.start();
		
		tt1.join();
		tf1.join();
		tf2.join();
		tf3.join();
		
		if(i==MAX_FUMATE)
		{	
			System.out.println("Fumatore 1: "+f1.fumate);
			System.out.println("Fumatore 2: "+f2.fumate);
			System.out.println("Fumatore 3: "+f3.fumate);
		}
	}
}
