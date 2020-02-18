/*
	Federcio Guazzo
	5^AI
	01/10/2019
	
	-Costruire un programma in C che dato in input il file xml di una
	macchina virtuale Virtualbox produca un report in formato "Umano" in
	formato solo testo o HTML (o RTF).
	
	Prevedere il flusso dati stdin e stdout oppure indicando i file da 
	riga di comando oppure l'immissione di tali file da programma con
	appositi parametri da riga di comando.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>														// strcmp 0=uguali 1=diversi
#include "ezxml.h"														// Libreria
#include "ezxml.c"														
	
FILE *fileOutput;
ezxml_t fileInput;
bool stdinNeeded = 0;
bool stdoutNeeded = 0;													// Var globale per sapere se necessito dello stdout, 0 = no, 1 = si
char *input = "";														// Var globale che contiene stringa nome file di input
char *output = "";														// Var globale che contiene stringa nome file di input
char nomeFile[] = "digestore_guazzo";

void quit()
{
	printf("\n");
	exit(0);
}

void help() 															// ./nomefile -h stampa a terminale "guida" per l'utente per l'esecuzione del programma
{
	printf("Input necessari: ./%s -i nomeFileInput.xml -o nomeFileOutput.txt", nomeFile);
	printf("\nSe non specificati è previsto flusso dati stdin e stdout");
	quit();
}

void check(char **argv, int i)
{
	if (strcmp(argv[i], "-h") == 0)										// -h per menu' aiuto
		help();
	
	if (strcmp(argv[i], "-i") == 0)										// Questo è il mio argv [digestore_guazzo, -i, copiaclient.xml, -o, output.txt]
		input = argv[i + 1];											// Metto nella variabile input il nome del file da prnedere in input che è nella poszione argv[i + 1]; 		
	
	if(strcmp(argv[i], "-o") == 0)										// Questo è il mio argv [digestore_guazzo, -i, copiaclient.xml, -o, output.txt]
		output = argv[i + 1];											// Metto nella variabile output il nome del file da usare output come che è nella poszione argv[i + 1]; 									
}

char* leggiStdin()
{
	char* input = NULL;
	int c = 0;
	int pos = 0;

	// fino a quando il flusso di stdin non termina
	while( (c = fgetc(stdin)) != EOF )
	{
		if(input == NULL)
		{
			// alloco un char per il primo carattere
            input = (char*) malloc(sizeof(char));
		}
        else
        {
			// alloco altri char per i successivi caratteri
            input = (char*) realloc(input, sizeof(char)*(pos+1));
		}
        
        // salva il carttere letto in input
        input[pos] = c;
        
        // tengo conto della dimensione della mia stringa
		pos++;
	}

	return input;
}

void digestisci(int stdinNeeded, int stdoutNeeded)
{	
	if( stdinNeeded == 0 )												// Se non necessito di stdout per gestire l'output
	{
		fileInput = ezxml_parse_file(input);
	}
	else 																// Se stdoutNeeded == 1, ovvero se necessito di stdout per gestire l'output
	{
		printf("Inserire contenuto file xml:\n");
		input = leggiStdin();											// Tutto il codice xml andra' in "input"
		input[strlen(input)-1] = 0; 									// Tolgo l'invio, '\0'
		fileInput = ezxml_parse_str(input, strlen(input));				// Come file input avro' una stringa contenente tutto il contenuto del file
		printf("\n--- Caratteristiche virtual machine ---\n");
	}
	
	if( stdoutNeeded == 0 )												// Se non necessito di stdout per gestire l'output
	{
		fileOutput = fopen(output,"w");									// Apre il file di output in scrittura, esso e' creato a compilation time, in quanto dato in input da terminale ( "w" crea il file se non trova file aventi già quel nome)
	}
	else 																// Se stdoutNeeded == 1, ovvero se necessito di stdout per gestire l'output
	{
		fileOutput = stdout;											// Imposto come file di outout, stdout
	}
	// INIZIO DIGESTIONE
	// Nome macchina
	const char *nomeMacchina;											// nomeMacchina variabile dove metto nome VM presa dal file .xml
	ezxml_t getMeToMachine = ezxml_child(fileInput, "Machine");			// ezxml_child - Si posiziona all'interno del tag <Machine>
	nomeMacchina = ezxml_attr(getMeToMachine, "name");					// in nomeMacchina il contenuto dell'attributo "name"
	fprintf(fileOutput,"Nome della macchina: %s\n", nomeMacchina);		// Lo stampo nel file

	// Tipo Sistema operativo
	const char *tipoOS;
	ezxml_t getMeToOS = ezxml_child(fileInput, "Machine");	
	tipoOS = ezxml_attr(getMeToOS, "OSType"); 							// in tipoOS il contenuto dell'attributo "OSType"			
	fprintf(fileOutput,"Sistema Operativo: %s\n", tipoOS);	

	// Grandezza RAM
	const char *sizeRam;
	ezxml_t getMeToRam1 = ezxml_child(fileInput, "Machine");
	ezxml_t getMeToRam2 = ezxml_child(getMeToRam1, "Hardware");
	ezxml_t grandezzaRam = ezxml_child(getMeToRam2, "Memory");
	sizeRam = ezxml_attr(grandezzaRam, "RAMSize"); 						// in sizeRam il contenuto dell'attributo "RAMSize"
	fprintf(fileOutput,"RAM size: %sMb\n", sizeRam);	
	
	// Boot order
	const char *firstBoot;
	const char *secBoot;
	const char *thirdBoot;
	const char *fourthBoot;
	const char *posizione_1;
	const char *posizione_2;
	const char *posizione_3;
	const char *posizione_4;
	// (primo dispositivo di avvio)
	ezxml_t getMeToFirstBoot1 = ezxml_child(fileInput, "Machine");
	ezxml_t getMeToFirstBoot2 = ezxml_child(getMeToFirstBoot1, "Hardware");
	ezxml_t getMeToFirstBoot3 = ezxml_child(getMeToFirstBoot2, "Boot");
	ezxml_t primoBoot = ezxml_child(getMeToFirstBoot3, "Order");
	firstBoot = ezxml_attr(primoBoot, "device"); 						
	posizione_1 = ezxml_attr(primoBoot, "position"); 
	// (secondo dispositivo di avvio)
	ezxml_t secondoBoot = ezxml_next(primoBoot);
	secBoot = ezxml_attr(secondoBoot, "device");						
	posizione_2 = ezxml_attr(secondoBoot, "position"); 
	// (terzo dispositivo di avvio)
	ezxml_t terzoBoot = ezxml_next(secondoBoot);
	thirdBoot = ezxml_attr(terzoBoot, "device");						
	posizione_3 = ezxml_attr(terzoBoot, "position");
	// (quarto dispositivo di avvio)
	ezxml_t quartoBoot = ezxml_next(terzoBoot);
	fourthBoot = ezxml_attr(quartoBoot, "device");						
	posizione_4 = ezxml_attr(quartoBoot, "position");
	
	fprintf(fileOutput,"Boot order: %s - %s\n", posizione_1, firstBoot);	
	fprintf(fileOutput,"\t    %s - %s\n", posizione_2, secBoot);
	fprintf(fileOutput,"\t    %s - %s\n", posizione_3, thirdBoot);	
	fprintf(fileOutput,"\t    %s - %s\n", posizione_4, fourthBoot);		
	
	// MACAddress
	const char *MACAddress;
	ezxml_t getMeToMAC1 = ezxml_child(fileInput, "Machine");
	ezxml_t getMeToMAC2 = ezxml_child(getMeToMAC1, "Hardware");
	ezxml_t getMeToMAC3 = ezxml_child(getMeToMAC2, "Network");
	ezxml_t indirizzoMAC = ezxml_child(getMeToMAC3, "Adapter");
	MACAddress = ezxml_attr(indirizzoMAC, "MACAddress"); 				// in sizeRam il contenuto dell'attributo "RAMSize"
	fprintf(fileOutput,"Indirizzo MAC scheda di rete: %s\n", MACAddress);
	// FINE DIGESTIONE
	ezxml_free(fileInput);												// Funzione che chiude il file di input
	fclose(fileOutput);	
}

int main(int argc, char **argv)											
{	
	if(argc > 1)														// Se ci sono più paramatri in input, li controllo
	{
		for (int i = 1; i < argc; i++)									// argc è il numero di argomenti digitati, compreso nome programma
		{
			check(argv, i);
		}
	}
	
	if(strcmp(input, "") != 0 && strcmp(output, "") != 0)				// Se l'utente inserisce sia file input sia file output
	{		
		digestisci(stdinNeeded, stdoutNeeded);							
	}
	else if(strcmp(input, "") == 0 && strcmp(output, "") != 0)			// Se l'utente inserisce solamente file di output
	{
		stdinNeeded = 1;
		digestisci(stdinNeeded, stdoutNeeded);		
	}
	else if(strcmp(input, "") != 0 && strcmp(output, "") == 0)			// Se l'utente inserisce solamente file di input
	{
		stdoutNeeded = 1;												// Imposto la necessità di avere come file output stoudt, ovvero terminale
		digestisci(stdinNeeded, stdoutNeeded);
	}
	else																// Se l'utente non iserice ne' file input ne' file output
	{
		stdinNeeded = 1;					
		stdoutNeeded = 1;												// Stesse operazioni assenza file output ( da riga 109 a 110 )
		digestisci(stdinNeeded, stdoutNeeded);	
	}

	return 0;
}
