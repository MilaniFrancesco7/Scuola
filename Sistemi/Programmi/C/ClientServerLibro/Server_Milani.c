#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <stdio.h>

#include <signal.h>

#include <unistd.h>

#include <stdlib.h>


#define SERVER_PORT 8080               // numero di porta del server

#define SOCKET_ERROR   ((int)-1)       // codice di errore

#define FINE_RICE 88                   // valore ASCII carattere ESC

int socketComunica;

// funzione che riceve un carattere, lo trasforma in maiuscolo, lo ritrasmette  
int upper1Char(int in, int out){

  char ch, chMaiu;

  int asciVal;

  if(recv(in, &ch, 1, 0) > 0){        // riceve un carattere

    chMaiu  = toupper(ch);              // lo trasforma in maiuscolo  

    asciVal = (unsigned int)ch;         // prende il valore ASCII  

    printf("\nil carattere ricevuto e': %c con valore ASCII %d ", ch, asciVal);

    printf(" maiuscolo %d \n", (unsigned int)chMaiu);

    send(out, &chMaiu, 1, 0);          // invia il carattere maiuscolo   

    asciVal= (unsigned int)chMaiu;

  }

  return asciVal;        

}

void handler(int sig)
{
	send(socketComunica, "Il server sta chiudendo la comunicazione...", 43, 0);
	printf("\n...Sto chiudendo il programma...\n");
	
	sleep(2);
 
	close(socketComunica);
	exit(1);
}

int main (unsigned argc, char **argv) {

  signal(SIGINT, handler);	

  int socketAttesa, client_len;

  int asciLetto;                       // valore ascii ultimo char ricevuto

  struct sockaddr_in server, client;   // record con i dati del server e del client

                                                                              

  // impostazione del transport endpoint del server 
  
  printf ("socket()\n");

  if((socketAttesa = socket(AF_INET, SOCK_STREAM, 0)) == -1){

    perror("chiamata della system call socket() fallita");

    return(1);

  }

  // definizione dei dati del socket  

  server.sin_family = AF_INET;

  server.sin_addr.s_addr = htonl(INADDR_ANY);

  server.sin_port = htons(SERVER_PORT);

  

  // leghiamo l'indirizzo al transport endpoint 

  printf ("bind()\n");

  if (bind(socketAttesa, (struct sockaddr*)&server, sizeof server) == -1){

    perror("chiamata della bind() fallita");

    return(2);

  }

 

  // poniamo il server in ascolto delle richieste dei client 

  printf ("listen()\n");

  listen(socketAttesa, 10);            // può attendere fino a 10 client 



  // gestione delle connessioni dei client 

  printf ("accept()\n");

  // trasferimento della comunicazione su un nuovo socket dedicato per il client 

  client_len = sizeof(client);

  if ((socketComunica = accept(socketAttesa, (struct sockaddr*)&client, &client_len)) < 0) 

  {

    perror("connessione non accettata");

    return(3);

  }

  // inizio dialogo tra server e client   

  fprintf(stderr, "Aperta connessione col server.\n");  // echo nel client

  send(socketComunica, "Hello dal ServerMaiu: trasformo caratteri in mauscolo!\n", 56, 0);  //Devo togliere questa stringa altrimenti viene stampata come messaggio

  
  // ciclo di attesa/comunicazione di un carattere alla volta col client  

  do     // funzione che riceve un carattere, lo trasforma in miuscolo, lo ritrasmette  

    asciLetto = upper1Char(socketComunica, socketComunica);

  while (asciLetto != FINE_RICE);      // se  arriva x termina l'elaborazione
   	
  // fine della comunicazione

  fprintf(stderr, "Chiusa connessione col server.\n");  // echo nel client 

}  
