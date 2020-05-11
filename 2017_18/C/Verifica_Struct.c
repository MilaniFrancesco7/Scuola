/*
 * Verifica di TPSIT del 21 04 2018
 * 
 * Milani Francesco
 * 
 * 3AI
 * 
 * File contenente le struct e le funzioni
 * 
 */


#include <stdio.h>

	typedef struct temp																		//Struct temp
	{
		int gradi;
		char modo;
		
	}temp;
	
	temp timput(temp t)																		//Funzione che mi permette di inserire i gradi
	{
		t.gradi=-1;
		
		while(t.gradi<0)
		{
			printf("Inserisci i gradi in Kelvin: ");
				scanf("%d",&t.gradi);
		
			if(t.gradi<0)
			{
				printf("Non si possono inserire gradi sotto lo 0 assoluto\n");
			}
		}
		
		return t;
	}
	
	void tprint(int t)																		//Funzione che stampa la temperatura
	{
		if(t>0)
			printf("\nStampa della temperatura: +%d",t);
		else
			printf("\nStampa della temperatura: %d",t);
		
	}
	
	void tmode(int t, char modo)															//Funzione che mi permette di cambiare la modalità di visualizzazione
	{
			
			printf("Imposta la modalità di visualizzazione a gradi Centigradi\n");			//Modalità gradi Centigradi
	
			modo='C';
		
			t=t-273.15;
			
			tprint(t);
			printf("°%c\n",modo);
			
			
			
			printf("Imposta la modalità di visualizzazione a gradi Farenheit\n");			//Modalità gradi Farenheit
			
			modo='F';
			
			t=(t*1.8)+32;
			
			tprint(t);
			printf("°%c\n",modo);
		
	}
	
	
