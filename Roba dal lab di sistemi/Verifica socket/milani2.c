/*
 * Milani Francesco
 * 5AI
 * 101219
 * 
 * Verifica di TPSIT Laboratorio
 * 
 * Esercizio 2
 * 
 * Realizzare in C un piccolo client che dato come parametro da riga di comando 
 * un indirizzo ip effettui una connessione in porta 22 all'host indicato.
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

#define PORTA 22
#define MAXBUF 1024

char *leggiStdin()			//Funzione per prendere in ingresso l'indirizzo ip
{
	char *input = NULL;
	char c=0;
	int pos=0;
	
	while(scanf("%c",&c) != EOF)
	{
		if(pos==0)
		{
			input=(char*)malloc(sizeof(char));		//Allocazione dinamica
		}
		else
		{
			input=(char*)realloc(input,sizeof(char)*(pos+1));	//Reallocazione dinamica
		}	
	
		input[pos]=c;
		pos++;
	}
	
	return input;	
}


int main()
{
	int clientSocket, retlen=0;
	char buffer[MAXBUF];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	
	char *input=NULL;
	
	input=leggiStdin();				//Non sono riuscito a far inserire l'indirizzo direttamente come parametro,
									//quindi lo faccio inserire tramite una lettura da stdin con conseguente Ctrl+D per l'invio
	
	printf("Avvio del client\n");
	
	clientSocket = socket(PF_INET, SOCK_STREAM, 0);		//Avvio della comunicazione

	serverAddr.sin_family = AF_INET;	//AF_INET = TCP
	serverAddr.sin_port = htons(PORTA);			//htons s=short
	serverAddr.sin_addr.s_addr = inet_addr(input);
	
	memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

	addr_size = sizeof serverAddr;
	connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
	
	retlen=strlen("SSH-2.0-OpenSSH_6.7p1 Debian-3");	// (return lenght) Lunghezza massima, in quanto risposta più lunga ottenibile
	
	recv(clientSocket, buffer, retlen, 0);					//Stringa ricevuta
	printf("Il server ha risposto: %s\n", buffer);
	printf("Termine del codice\n");
	return 0;
}
