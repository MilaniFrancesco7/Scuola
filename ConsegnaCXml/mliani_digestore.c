/*	
 *  Francesco Milani
 * 	5AI
 * 	211019
 * 
 * 	Costruire un programma in C che dato in input il file xml di una
 *	macchina virtuale Virtualbox produca un report in formato "Umano" in
 *	formato solo testo o HTML (o RTF).
 *	
 *	Prevedere il flusso dati stdin e stdout oppure indicando i file da 
 *	riga di comando oppure l'immissione di tali file da programma con
 *	appositi parametri da riga di comando.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>	
#include "ezxml/ezxml.c"	//ezXML is a C library for parsing XML documents inspired by simpleXML for PHP.
#include "ezxml/ezxml.h"


FILE *FOutput;
ezxml_t FInput;
bool stdinrequest = 0;
bool stdoutrequest = 0;													// Var globale per sapere se necessito dello stdout, 0 = no, 1 = si
char *input = "";														// Var globale che contiene stringa nome file di input
char *output = "";														// Var globale che contiene stringa nome file di output
char nomeFile[] = "milani_digestore";

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

void digestisci(int stdinrequest, int stdoutrequest)
{
	if( stdinrequest == 0 )												// Se non necessito di stdout per gestire l'output
	{
		FInput = ezxml_parse_file(input);
	}
	else 																// Se stdoutNeeded == 1, ovvero se necessito di stdout per gestire l'output
	{
		printf("Inserire contenuto file xml:\n");
		input = leggiStdin();											// Tutto il codice xml andra' in "input"
		input[strlen(input)-1] = 0; 									// Tolgo l'invio, '\0'
		FInput = ezxml_parse_str(input, strlen(input));				// Come file input avro' una stringa contenente tutto il contenuto del file
		printf("\n--- Caratteristiche virtual machine ---\n");
	}
	
	if( stdoutrequest == 0 )												// Se non necessito di stdout per gestire l'output
	{
		FOutput = fopen(output,"w");									// Apre il file di output in scrittura, esso e' creato a compilation time, in quanto dato in input da terminale ( "w" crea il file se non trova file aventi già quel nome)
	}
	else 																// Se stdoutNeeded == 1, ovvero se necessito di stdout per gestire l'output
	{
		FOutput = stdout;											// Imposto come file di outout, stdout
	}
		
	
	
	
	//Inizio digestione
	
	
	//Nome macchina
	const char *machinename;											
	ezxml_t machine = ezxml_child(FInput, "Machine");				
	machinename = ezxml_attr(machine, "name"); 
	
	//Tipo sistema operativo
	const char *ostype;
	ezxml_t os = ezxml_child(FInput, "Machine");
	ostype = ezxml_attr(os, "OSType"); 
		
	//Hard Disk
	const char *formathd;
	const char *locationhd;
	ezxml_t tempdisk1 = ezxml_child(FInput, "Machine");
	ezxml_t tempdisk2 = ezxml_child(tempdisk1, "MediaRegistry");
	ezxml_t tempdisk3 = ezxml_child(tempdisk2, "HardDisks");
	ezxml_t tempdisk4 = ezxml_child(tempdisk3, "HardDisk");
	locationhd = ezxml_attr(tempdisk4, "location");
	formathd = ezxml_attr(tempdisk4, "format");
	
	//Memoria RAM
	const char *ramsize;
	ezxml_t tempram1 = ezxml_child(FInput, "Machine");
	ezxml_t tempram2 = ezxml_child(tempram1, "Hardware");
	ezxml_t ram = ezxml_child(tempram2, "Memory");
	ramsize = ezxml_attr(ram, "RAMSize"); 

	//Primo dispositivo di avvio
	const char *firstboot;
	ezxml_t tempboot1 = ezxml_child(FInput, "Machine");
	ezxml_t tempboot2 = ezxml_child(tempboot1, "Hardware");
	ezxml_t tempboot3 = ezxml_child(tempboot2, "Boot");
	ezxml_t boot = ezxml_child(tempboot3, "Order");
	firstboot = ezxml_attr(boot, "device"); 
		
	//Memoria VRAM
	const char *vramsize;
	ezxml_t tempvram1 = ezxml_child(FInput, "Machine");
	ezxml_t tempvram2 = ezxml_child(tempvram1, "Hardware");
	ezxml_t vram = ezxml_child(tempvram2, "Display");
	vramsize = ezxml_attr(vram, "VRAMSize"); 
	
	//MAC Address
	const char *macaddress;
	ezxml_t tempmac = ezxml_child(FInput, "Machine");
	ezxml_t tempmac2 = ezxml_child(tempmac, "Hardware");
	ezxml_t tempmac3 = ezxml_child(tempmac2, "Network");
	ezxml_t tempmac4 = ezxml_child(tempmac3, "Adapter");
	macaddress = ezxml_attr(tempmac4, "MACAddress");
	
	fprintf(FOutput, "Nome Client: %s\n", machinename);
	fprintf(FOutput, "Sistema Operativo: %s\n", ostype);
	fprintf(FOutput, "Formato Hard Disk: %s\n", formathd);
	fprintf(FOutput, "Locazione Hard Disk: %s\n", locationhd);
	fprintf(FOutput, "RAM: %s\n", ramsize);
	fprintf(FOutput, "First Boot: %s\n", firstboot);
	fprintf(FOutput, "VRAM: %s\n", vramsize);
	fprintf(FOutput, "MAC Address %s\n", macaddress);
	
	//Fine digestione
	
	
	ezxml_free(FInput);												// Funzione che chiude il file di input
	fclose(FOutput);	
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
		digestisci(stdinrequest, stdoutrequest);							
	}
	else if(strcmp(input, "") == 0 && strcmp(output, "") != 0)			// Se l'utente inserisce solamente file di output
	{
		stdinrequest = 1;
		digestisci(stdinrequest, stdoutrequest);		
	}
	else if(strcmp(input, "") != 0 && strcmp(output, "") == 0)			// Se l'utente inserisce solamente file di input
	{
		stdoutrequest = 1;												// Imposto la necessità di avere come file output stoudt, ovvero terminale
		digestisci(stdinrequest, stdoutrequest);
	}
	else																// Se l'utente non iserice ne' file input ne' file output
	{
		stdinrequest = 1;					
		stdoutrequest = 1;												// Stesse operazioni assenza file output ( da riga 109 a 110 )
		digestisci(stdinrequest, stdoutrequest);	
	}

	return 0;
}

