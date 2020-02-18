//Milani Francesco
//5AI
//221119

/*
Si vuole realizzare un programma in linguaggio C in grado di:
Generare due processi padre/figlio in cui:
- Il processo padre scrive la sequenza di caratteri [A-Z][a-z] in
un file di testo (aperto prima di eseguire la fork) e
successivamente chiude e rimuove il file creato
- Il processo figlio attende 5 secondi (tramite la funzione “sleep
(num_secs)”) e stampa il contenuto del file precedentemente
gestito dal processo padre
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void scriviAlfabetoMaiuscolo(FILE* fp)
{
	char ch = 'A';
	for(int i = 0; i < 26; i++)
	{
		fprintf(fp, "%c ", ch);
		ch++;
	}
	fprintf(fp, "\n");
}

void scriviAlfabetoMinuscolo(FILE* fp)
{
	char ch = 'a';
	for(int i = 0; i < 26; i++)
	{
		fprintf(fp, "%c ", ch);
		ch++;
	}
	fprintf(fp, "\n");
}

// funzione per lettura di un fp e quindi del messaggio (allocato dinamicamente in memoria)
char* leggiFp(FILE* fp)
{
	// dichiarazione variabili
	// c = carattere di lettura
	// input = memorizza l'informazione in stdin
	// pos = memorizza la posizione nella stringa in cui inserire il carattere e, anche il numero del carattere a cui siamo arrivati
	char *input = NULL;
	char c = 0;
	int pos = 0;
	
	// finchè non leggo il carattere EOF (End Of File), esegui il ciclo
	while( (c = fgetc(fp)) != EOF )
	{
		// se sto leggendo il primo carattere
		if(pos == 0)
		{
			// alloco la memoria per il primo carattere
			input = (char*) malloc(sizeof(char));
		}
		// se sto leggendo caratteri successivi al primo
		else
		{
			// rialloco la memoria per la stringa input, tenendo conto della precedente dimensione e aggiungendone un'altra per il carattere appena letto
			input = (char*) realloc(input, sizeof(char)*(pos+1));
		}
		
		// salvo quindi il carattere nella stringa
		input[pos] = c;
		
		// incremento la posizione (intesa anche come numero di allocazioni char attribuite alla stringa input)
		pos++;
	}
	
	// tolgo il "a capo" ('\n') di fine stringa, aggiungendo il carattere terminatore di stringa 0 ('\0')
	input[strlen(input)-1] = 0;
	
	// ritorno l'informazione letta in stdin
	return input;
}

int main()
{
	FILE* fp = fopen("alfabeto.txt", "w");
	
	scriviAlfabetoMaiuscolo(fp);
	scriviAlfabetoMinuscolo(fp);
	
	pid_t p1 = fork();
	
	if(p1 > 0) // padre
	{
		fclose(fp);
		wait(0);
		remove("alfabeto.txt");
	}
	else if(p1 == 0) // figlio
	{
		sleep(5);
		fp = fopen("alfabeto.txt", "r");
		printf("%s", leggiFp(fp));
		fclose(fp);
	}
	else
	{
		printf("\nErrore nella fork()\n");
	}
	
	return 0;
