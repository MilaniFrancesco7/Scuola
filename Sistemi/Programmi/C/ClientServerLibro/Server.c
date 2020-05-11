#include <stdio.h>                          // lezione lab 10 UA3 
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>  

#define SOCKET_ERROR   ((int)-1)
#define SERVER_PORT 8080                   // numero di porta del server
#define MAXSIZE 10                          // dimensione del messaggio

int main(int argc, char *argv[]){
  char indirizzoServer[] = "127.0.0.1";     // indirizzo del server 
  char messaggio[] = "ciao";                // messaggio da inviare 
  char buffer[MAXSIZE];                     // messaggio ricevuto 
  char ch, chMaiu;                          // singolo carattere inviato e ricevuto 
  int ris, nwrite, len;                  
    
  int socketfd;                             // identificatore della socket
  struct sockaddr_in locale, remoto;        // dati dei socket 
  
  // settaggio del socket locale   
  locale.sin_family	     = AF_INET;
  locale.sin_addr.s_addr = htonl(INADDR_ANY);                      
  locale.sin_port	     = htons(0);
  // assegnazione parametri del server 
  remoto.sin_family	     = AF_INET;
  remoto.sin_addr.s_addr = inet_addr(indirizzoServer);
  remoto.sin_port		 = htons(SERVER_PORT);
  
  // impostazione del transport endpoint 
  printf("creazione del socket()\n");
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == SOCKET_ERROR){
    printf ("fallito socket(), errore: %d \"%s\"\n", errno, strerror(errno));
    return(1);
  }
 
  // leghiamo l'indirizzo al transport endpoint 
  printf("bind()\n");
  ris = bind(socketfd, (struct sockaddr*) &locale, sizeof(locale));
  if (ris == SOCKET_ERROR){
    printf ("fallito il bind(), errore: %d \"%s\"\n", errno, strerror(errno));
    fflush(stdout);  
    return(3);
  }
 
  // richiesta di connessione al server   
  printf("connect()\n");
  ris = connect(socketfd, (struct sockaddr*) &remoto, sizeof(remoto));
  if (ris == SOCKET_ERROR){
    printf("fallita la connect(), errore: %d \"%s\"\n", errno, strerror(errno));
    fflush(stdout);  
    return(4);
  }
 
  // ciclo che invia la stringa (1 char alla volta) al server 
  len = strlen(messaggio);
  printf("\nstringa lunga: %d \n", len);
  for (nwrite = 0; nwrite < len; nwrite++){
    write(socketfd, &(messaggio[nwrite]), 1);     // invia un carattere 
    if (read(socketfd, &chMaiu, 1) > 0){          // lettura della risposta 
      printf("carattere ricevuto: %c\n", chMaiu); // stampa singolo carattere
      buffer[nwrite] = chMaiu;
    }
  }
 
  // stampa risultato 
  printf("\nstringa ricevuta: %s\n", buffer);
  printf("\nChiusura connessione...\n");
  sleep(2);
  fflush(stdout);        

  // chiusura socket 
  close(socketfd);
  return(0);
}

