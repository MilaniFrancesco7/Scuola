/*
 * CodiceFiscale_Milani.c									
 * 
 * Copyright 2018 Unknown <s01244@lab12-pc1>
 * 
 * Milani Francesco
 * 
 * 3 AI
 * 
 * 20180120
 * 
 * Calcolo del codice fiscale in C
 * 
 * 
 */
 
 
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include <stdbool.h>
 
 
size_t strlen(const char *s);

int isvocale(const char *s,int i)															//Funzione che controlla se il carattere è una vocale
{
	
		if(s[i]==65 || s[i]==69 || s[i]==73 || s[i]==79 || s[i]==85)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
		return 0;
	
} 

int controlloconsonanti(const char *s)														//Funzione che controlla il numero di consonanti all'interno di una stringa
{
	int nconsonanti;
	int controllo;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		controllo=isvocale(s,i);
		
		if(controllo==1)
		{
		}
		else
		{
			nconsonanti++;
		}
		
	}
	
	return nconsonanti;
	
}

void stampacognome(const char *cognome)														//Funzione che stampa il cognome										
{
	int length;
	int flag=0;
	int	i=0;
	int vocale;
	
	length=strlen(cognome);																	
	
	if(length>3)
	{
		
		while(flag<3)																		//Ciclo per la stampa del cognome
		{
			vocale=isvocale(cognome,i);
			
			if(vocale==1)
			{
			}
			else
			{
				
				printf("%c",cognome[i]);
				flag++;
				
			}
			
			i++;
	
		}
	
		
	}
	else																					//Se il nome è lungo solo due caratteri
	{
		printf("%sX",cognome);
		
	}
		
	
}

void stampanome(const char *nome)															//Funzione che stampa il nome
{
	int flag=0;
	int i=0;
	int vocale;

	while(flag<4)
	{
		vocale=isvocale(nome,i);
		
		if(vocale==1)																		//Se è una vocale
		{	
			i++;
		}
		else
		{
			if(flag==1)
		{	
			flag++;
			i++;
		}
		else
		{
				
			printf("%c",nome[i]);
			flag++;
			i++;
			
		}
				
		}
		
	}
	
}


void stampaanno(int anno)																	//Funzione che stampa l'anno di nascita
{
	
	if(anno==2000 || anno==1900)
	{
		
		printf("00");
		
	}
	else if((anno>1900 && anno < 1910) || (anno>2000 && anno<2010))
	{
		anno=anno-2000;
		printf("0%d",anno);
	}
	else
	{
	printf("%d",(anno%100));												
	}
	
}


char stampamese(int mese)																	//Funzione che stampa il mese di nascita
{
	char letteramese;
	
	switch(mese)
	{
	
			case 1:
			letteramese='A';
			break;
	
			case 2:
			letteramese='B';
			break;
	
			case 3:
			letteramese='C';
			break;	
			
			case 4:
			letteramese='D';
			break;
			
			case 5:
			letteramese='E';
			break;
			
			case 6:
			letteramese='H';
			break;
			
			case 7:	
			letteramese='L';
			break;
	
			case 8:
			letteramese='M';
			break;
	
			case 9:
			letteramese='P';
			break;
	
			case 10:
			letteramese='R';
			break;
			
			case 11:
			letteramese='S';
			break;
	
			case 12:
			letteramese='T';
			break;
			
	}
	
	return letteramese;
	
}

void stampagiorno(int giorno, int sesso)													//Funzione che stampa il giorno di nascita
{
	if(giorno<10)
	{
	
		if(sesso==1)
		{
			printf("0%d",giorno);
		}
		else
		{
			printf("%d",(giorno+40));
		}
	}
	else
	{
		if(sesso==1)
			printf("%d",giorno);
		else
			printf("%d",(giorno+40));
	}
	
}

bool isdatevalid(date Datex)														//Funzione che controlla il mese e il giorno di nascita
{
	bool flag=false;
	
	if(mese==1 || mese==3 || mese==5 || mese==7 || mese==8 || mese==10 || mese==12)			 
	{
		if(giorno<1 || giorno>31)
		{
		
		printf("\n Hai sbagliato il mese o il giorno");
		
		flag=true;
		
		return flag;
		
		}
	}
	
	
	
	if(mese==4 || mese==6 || mese==9 || mese==11)
	{
		if(giorno>30 || giorno<1)
		{
		
		printf("\n Hai sbagliato il mese o il giorno");
		
		flag=true;
		
		return flag;
		
		}
		
	}
	
	
	
	if(mese==2)
	{
		if(giorno<1 || giorno>29)
		{
		
		printf("\n Hai sbagliato il mese o il giorno");
		
		flag=true;
		
		return flag;
		
		}
	}

	return flag;
}
	


int main()
{
	char nome[20];
	char cognome[20];
	int  anno;
	int  mese;
	int  giorno;
	int  sesso;
	int  i;
	char letteramese;
	bool controllo=false;
	char codicecomune[4];
	
	printf("*************************** \n");												//Stampa del Menù
	printf("*                         * \n");
	printf("*       Calcolo del       * \n");
	printf("*      Codice Fiscale     * \n");
	printf("*                         * \n");
	printf("*************************** \n");
	
	printf("\n Inserisci il tuo nome : ");													//Input del Nome
		scanf("%s",nome);
	
	for(i=0;i<strlen(nome); i++)															//Trasporto del nome in maiuscolo
		nome[i]= toupper(nome[i]);
	
	
	printf("\n Inserisci il tuo cognome: ");												//Input del Cognome
		scanf("%s",cognome);
	
	for(i=0;i<strlen(cognome); i++)															//Trasporto del cognome in maiuscolo
		cognome[i]= toupper(cognome[i]);
	
	
	printf("\n Inserisci l'anno di nascita : ");											//Input dell'anno di nascita
		scanf("%d",&anno);


	if(anno<1900 || anno>2018)																//Controllo dell'anno di nascita
	{
		
		printf("\n Anno di nascita errato");
	
		return 0;
		
	}
	
	
	printf("\n Inserisci il tuo mese di nascita: ");										//Input del mese di nascita
		scanf("%d",&mese);
	
	if(mese<1 || mese>12)																	//Controllo del mese di nascita
	{
		
		printf("\n Mese di nascita errato");
		
		return 0;
	}
	
	
	printf("\n Inserisci il tuo giorno di nascita: ");										//Input del giorno di nascita
		scanf("%d",&giorno);
	
		
	controllo=controllomese(mese,giorno);													//Controllo del mese di nascita
	
	if(controllo==true)
		return 0;
	



	printf("\n Inserisci il tuo sesso (1-M 2-F):");											//Input del sesso 
		scanf("%d",&sesso); 
		
	if(sesso!=1 && sesso!=2)																//Controllo del sesso
	{
		
		printf("Hai inserito un numero sbagliato");
		
		return 0;	
		
	}
	
	printf("\n Inserisci il codice del tuo comune di nascita: ");
		scanf("%s",codicecomune);
	
	
	
	printf("\n Il tuo codice fiscale e': ");												//Stampa del codice fiscale


	stampacognome(cognome);																	//Richiamo la funzione di stampa del cognome
	
	stampanome(nome);																		//Richiamo la funzione di stampa del nome
	
	stampaanno(anno);																		//Richiamo la funzione di stampa dell'anno
	
	letteramese=stampamese(mese);															//Richiamo la funzione di stampa del mese
	
	printf("%c",letteramese);
	
	stampagiorno(giorno,sesso);																//Stampa del giorno di nascita
	
	printf("%s",codicecomune);																//Stampa del codice del comune di nascita

	
	
	
	return 0;
}

