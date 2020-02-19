#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

//MAX_RAND è la costante che definisce il numero massimo che posso ottenere quando
//sto generando i numeri casuali per il vettore
#define MAX_RAND 100
#define LENGTH 100000
int vet[LENGTH];

//Questa funzione popola un array di valori casuali
//L'array è passato all'interno della funzione con un puntatore
void popolaVettore(int *vettore, int length,int elemento)
{
	int i,num;
	
	//Generazione del seed per i numeri random
	srand(time(NULL));
	
	//Popolamento del vettore
	for(i=0; i<length; i++)
	{
		num = rand() % LENGTH + 1;
		//Se la funzione genera un elemento che vale 50
		//Sostituiscilo con 23 e inseriscilo alla fine della funzione in
		//una posizione random
		if(num==elemento)
		{
			do
			{
				num = rand() % LENGTH + 1;
			}while(vettore[i]==elemento);
		}
		vettore[i]=num;
    }
    
	vettore[(rand()%LENGTH+1)]=elemento;
}

//Funzione che stampa il contenuto di un vettore
void stampaVettore(int vettore[], int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",vettore[i]);
	}
}

int ricercaElemento(int vet[],int elemento,int start, int stop)
{
	int i;
	for(i=start;i<stop;i++)
	{
		if(vet[i]==elemento)
		{
			return i;
		}else if(i==(stop-1))
		{
			return -1;
		}
	}
	return -1;
}

int main()
{
	//L'utente inserisce l'elemento che verrà cercato nel vettore
	int elemento;
	printf("Che elemento vuoi ricercare (i numeri vanno da 0 a 100)? ");
	scanf("%d",&elemento);
	
	//Popolamento del vettore
	popolaVettore(vet,LENGTH,elemento);
	
	printf("Inserisci il numero di figli da generare: ");
	int numfigli;
	scanf("%d",&numfigli);
	
	//La lunghezza di un sottoarray (in cui si effettuerà la ricerca)
	//si ottiene dividendo la lunghezza totale per il numero di figli da generare
	int parte = LENGTH/numfigli;
	
	pid_t figli[numfigli];
	int i,flag;
	clock_t begin = clock();
	for(i=1;i<numfigli;i++)
	{
		
		figli[i] = fork();
		
		//Controllo che il fork sia andato a buon fine
		if(figli[i]<0)
		{
			printf("Processo figlio non creato.\n\n");
			exit(0);
		}
		//Controllo che il fork sia andato a buon fine e mi trovo nel processo figlio
		if(figli[i]==0)
		{
			if(i==0)//In caso questo sia il primo processo figlio da controllare
			{
				//Controlla i numeri da 0 a parte*(i+1)
				flag=ricercaElemento(vet,elemento,0,parte*(i+1));
				if(flag!=-1)
				{
					printf("\nL'elemento è stato trovato in posizione %d dal figlio numero %d\n",flag,i);
				}
				exit(0);
			}else if(i==numfigli-1)//Nel caso sia l'ultimo processo figlio che devo controllare
			{
				//Controlla i valori che vanno da parte*i a LENGTH
				flag=ricercaElemento(vet,elemento,parte*i,LENGTH);
				if(flag!=-1)
				{
					printf("\nL'elemento è stato trovato in posizione %d dal figlio numero %d\n",flag,i);
				}
				exit(0);
			}else if(i!=1 && i!=numfigli-1)//In caso non sia il primo processo figlio e nemmeno l'ultimo
			{
				//Ricerca dell'elemento da parte*i a parte*(i+1)
				flag = ricercaElemento(vet,elemento,parte*i,parte*(i+1));
				if(flag!=-1)
				{
					printf("\nL'elemento è stato trovato in posizione %d dal figlio numero %d\n",flag,i);
				}
				exit(0);
			}
		}else
		{
			wait(NULL);
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n\nTEMPO IMPIEGATO RICERCA FORK: %f\n\n",time_spent);
	
	clock_t begin2 = clock();
	printf("L'elemento è stato trovato in posizione %d\n",ricercaElemento(vet,elemento,0,LENGTH));
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	printf("\n\nTEMPO IMPIEGATO RICERCA SEQUENZIALE: %f\n\n",time_spent2);
	
	return 0;
}
