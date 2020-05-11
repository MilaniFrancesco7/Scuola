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

#define MAXCLIENT 50

char *ROOT;
int client[MAXCLIENT];
int listenfd;

void startServer(char *porta)
{
	struct addrinfo hints, *res, *p;
	
	//getaddrinfo per gli host
	memset (&hints, 0, sizeof(hints));
	
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	if(getaddrinfo(NULL, porta, &hints, &res) != 0)
	{
		perror("getaddrinfo() fallito");
		exit(1);
	}
	//socket
	for(p = res; p != NULL; p = p -> ai_next)
	{
		listenfd = socket (p -> ai_family, p -> ai_socktype, 0);
		if(listenfd == -1)
		{
			continue;
		}
		if(bind(listenfd, p -> ai_addr, p -> ai_addrlen) == 0)
		{
			break;
		}
	}
	if(p == NULL)
	{
		perror("socket() o bind() fallito");
		exit(1);
	}
	
	freeaddrinfo(res);
	
	if(listen (listenfd, 1000000) != 0)
	{
		perror("listen() fallito");
		exit(1);
	}
}

void connessione(int x)
{
	char mesg[99999], *reqline[3], data_to_send[1024], path[99999];
	int rcvd, fd, bytes_read;
	
	memset( (void*)mesg, (int)'\0', 99999 );
	
	rcvd=recv(client[x], mesg, 99999, 0);
	
	if(rcvd < 0) //errore
	{
		fprintf(stderr, "recv() fallito \n");
	}
	else if(rcvd == 0) //riceve la chiusura di un socket
	{
		fprintf(stderr, "Client disconnesso inaspettatamente \n");
	}
	else
	{
		printf("\n\tNUOVA CONNESSIONE\n\n");
		printf("%s", mesg);
		reqline[0] = strtok (mesg, " \t\n");		//Tokenizzatore, divide il messaggio in pezzi, pezzo 1
		if(strncmp(reqline[0], "GET\0", 4) == 0)
		{
			reqline[1] = strtok (NULL, " \t");		//Pezzo 2
			reqline[2] = strtok (NULL, " \t\n");	//Pezzo 3
			
			if(strncmp(reqline[2], "HTTP/1.0", 8) != 0 && strncmp(reqline[2], "HTTP/1.1", 8) != 0)
			{
				write(client[x], "HTTP/1.0 400 Bad Request\n", 25);
			}
			else
			{
				//Se non vengono specificati file di default visualizzerà "index.html"
				if(strncmp(reqline[1], "/\0", 2) == 0)
				{
					reqline[1] = "/index.html";
				}
				strcpy(path, ROOT);
				strcpy(&path[strlen(ROOT)], reqline[1]);
				printf("File: %s \n", path);
				
				//Se trova il file
				if((fd = open(path, O_RDONLY)) != -1)
				{
					send(client[x], "HTTP/1.0 200 OK\n\n", 17, 0);
					while((bytes_read = read(fd, data_to_send, 1024)) > 0 )
					{
						write(client[x], data_to_send, bytes_read);
					}
				}
				//File non trovato
				else
				{
					write(client[x], "HTTP/1.0 404 Not Found\n", 23);
				}
			}
		}
	}
	
	shutdown(client[x], SHUT_RDWR);
	close(client[x]);
	client[x] = -1;
}

int main(int argc, char **argv)
{
	//Variabili utili al funzionamento del programma
	int i, slot = 0;
	
	//Variabili socket
	struct sockaddr_in clientaddress;
	socklen_t lunghezzaaddress;
	
	//PATH di default = ~/
	//Porta = 10000
	char PORT[6];
	ROOT = getenv("PWD");
	strcpy(PORT,"10000");
	
	printf("Server avviato !\n\t- Porta: %s \n\t- Directory: %s \n", PORT, ROOT);
	
	//Setto tutti gli elementi a -1
	//ciò significa che non ci sono client connessi 
	for(i = 0; i < MAXCLIENT; i++)
	{
		client[i] = -1;
	}
	
	//Avvio Server
	startServer(PORT);
	
	while(1)
	{
		lunghezzaaddress = sizeof(clientaddress);
		client[slot] = accept(listenfd, (struct sockaddr *) &clientaddress, &lunghezzaaddress);
		
		if(client[slot] < 0)
		{
			perror("accept() fallito");
		}
		else
		{
			if(fork() == 0)
			{
				//Esegue la procedura di risposta alla connessione di un client
				connessione(slot);
				exit(0);
			}
		}
		
		while(client[slot] != -1)
		{
			slot = (slot + 1) % MAXCLIENT;
		}
	}
	
	return 0;
}
