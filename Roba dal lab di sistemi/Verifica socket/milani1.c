/*
 * Milani Francesco
 * 5AI
 * 101219
 * 
 * Verifica di TPSIT Laboratorio
 * 
 * Esercizio 1
 * 
 * Realizzare in C un multi-server, in ascolto sulla porta 9002, 
 * che ricevuta una stringa la restituisca rovesciata (Es. Ambulanza, aznalubmA) 
 * e stampi lato server il numero di caratteri elaborati.
 * Collaudare con telnet o netcat
 * 
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <fcntl.h>

#define BUFFER_LENGTH 9999		//Lunghezza massima stringa
#define MAXCON  9999			//Numero massimo connessioni
int PORTA= 9999;				//Numero della porta

void reverse(int fd)
{
	/* Funzione che riceve una stringa,
	 * la rovescia, e la invia al client.
	 */
	
	char msg[BUFFER_LENGTH];			
	char supporto[BUFFER_LENGTH];		//Stringa che riceverà l'input dal client e tornerà utile nella fase di rovescio della stringa
	char rovescio[BUFFER_LENGTH];		//Stringa che conterrà la stringa inviata rovesciata
	int i=0,pos=0;

	sprintf(msg,"\n****** SERVER RABALTA STRINGHE ******\n");
	send(fd,msg,strlen(msg), 0);

	sprintf(msg, "\nInserisci stringa da rovesciare: ");
	send(fd, msg, strlen(msg), 0);		//Invia messaggio su un socket

	recv(fd, supporto, BUFFER_LENGTH, 0);	//Riceve un messaggio da un socket
	
	printf("Ho ricevuto la stringa : %s\n", supporto);
	
	printf("Lunghezza stringa ricevuta : %d.\n", (int)strlen(supporto) - 2);
	
	pos=strlen(supporto)-3;		//Il messaggio inviato con il buffer si allunga di 2 caratteri
	
	//printf("Lunghezza pos per controllo: %d\n",pos); //Stampa di controllo
	
	for(i=0;i<=strlen(supporto)-3; i++)
	{
		rovescio[i]=supporto[pos];
		pos--;
	}
	
	printf("La stringa rovesciata e' : %s \n",rovescio);
	
	sprintf(msg,"La stringa rovesciata e' : %s \n",rovescio);			//Messaggi al client
	send(fd,msg,strlen(msg),0);
	sprintf(msg,"Chiusura della comunicazione con il server\n");
	send(fd,msg,strlen(msg),0);
	close(fd);
}

int main()
{
	int newsocket, client_len, wsocket, pid;	
	struct sockaddr_in servizio, cliente;
	int cont = 0;		//Contatore per il numero di connessioni
	
	if((newsocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)		//AF_INET = ipv4, SOCK_STREAM = TCP, 0 = identifica protocollo
	{
		perror("Crezione del socket() fallito\n");
		return(1);
	}
	printf ("socket()\n");  //Stampa di controllo

	servizio.sin_family = AF_INET;
	servizio.sin_addr.s_addr = htonl(INADDR_ANY);		//htonl l= long
	servizio.sin_port = htons(PORTA);					//htons s= short

	printf ("bind()\n");	//Stampa di controllo

	if(bind(newsocket, (struct sockaddr *)&servizio, sizeof(servizio)) == -1)		//Bind()
	{
		perror("bind() fallito, prova a cambiare porta\n");
		return(2);
	}	
	
	printf ("listen() in porta %d\n", PORTA);		//Stampa della porta in cui mi metto in ascolto
	
	listen(newsocket, MAXCON);		
	
	while (1)				//Ciclo per le connessioni multiple
	{
		if(cont < MAXCON)		//Fino al numero massimo di connessioni
		{
			cont++;
			client_len = sizeof(cliente);
			
			printf ("accept()\n");		//Stampa di controllo
			if((wsocket = accept(newsocket, (struct sockaddr *)&cliente, &client_len)) < 0)			//Se c'è un'errore nella creazione della connessione
			{
				perror("Connessione non accettata");
				return(3);
			}
			
			if((pid = fork()) < 0)		//Se c'è un errore nella creazione del fork
			{
				perror("Errore nella creazione del nuovo processo.\n");
				exit(1);
			}
			
			else if(pid == 0)	//Processo figlio
			{
				fprintf(stderr, "Aperta connessione col server.\n");  	
				fprintf(stderr, "In esecuzione processo.\n");
				reverse(wsocket);						
				close(wsocket);
				fprintf(stderr, "Chiusa connessione col server.\n");  
				exit(0);
			}
			else
			{
				close(wsocket);		//Chiusura del socket
			}
		}
		else
		{
			printf("\nNumero massimo di connessioni raggiunto, esecuzione ultima stringa\n");		//La connessione si chiude ma rimane aperto l'ultimo figlio generato
			exit(1);
		}
	}
	
	return 0;
}


