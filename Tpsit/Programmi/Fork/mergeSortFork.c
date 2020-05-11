#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

//MAX_RAND è la costante che definisce il numero massimo che posso ottenere quando
//sto generando i numeri casuali per il vettore
#define MAX_RAND 100
#define LENGTH 10

//Funzioni da fare
//MergeSort modificato

//Nel main
//Utilizzo dei fork per programmare l'ordine di esecuzioni dei vari mergesort

//Questa funzione popola un array di valori casuali
//L'array è passato all'interno della funzione con un puntatore
void popolaVettore(int *vettore, int length)
{
	int i,num;
	
	//Generazione del seed per i numeri random
	srand(time(NULL));
	
	//Popolamento del vettore
	for(i=0; i<length; i++)
	{
		num = rand() % MAX_RAND + 1;
		vettore[i]=num;
    }
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

//Questa funzione unisce gli elementi di due vettori e li inserisce in uno solo
void unisci(int arr1[],int arr2[],int len1, int len2, int *arr3)
{	
	int i,j;
	//Inserisci i valori del primo array nel vettore risultante
	for(i=0;i<len1;i++)
	{
		arr3[i] = arr1[i];
	}
	
	//Inserisci i valori del secondo array nel vettore risultante
	//Partendo da dove ha finito il for precedente continua finché
	//non ho copiato tutti i valori del secondo array
	for(j=0;j<len2;j++)
	{
		arr3[i] = arr2[j];
		i++;
	}
	
	
}

//######################################################################
int minIndex(int vett[], int i, int j) 
{ 
	if(i == j)
	{
		return i;
	}

    //Find minimum of remaining elements 
	int k = minIndex(vett, i + 1, j); 
	
	// Return minimum of current and remaining. 
	if(vett[i] < vett[k])
	{
		return i;
	}else
	{
		return k;
	}
}

// Recursive selection sort. n is size of a[] and index
// is index of starting element.
void recurSelectionSort(int a[], int n, int index) 
{
	int tmp;
	// Return when starting and size are same
	if (index == n)
	{
		return;
	}

	// calling minimum index function for minimum index
	int k = minIndex(a, index, n-1);

	// Swapping when index nd minimum index are not same
	if (k != index)
	{
		//swap(a[k], a[index]);
		tmp=a[k];
		a[k]=a[index];
		a[index]=tmp;
	}

	//Recursively calling selection sort function
	recurSelectionSort(a, n, index + 1);
}
//######################################################################

int main()
{
	int vet1[LENGTH];
	popolaVettore(vet1,LENGTH);
	printf("\nVETTORE 1:\n");
	stampaVettore(vet1,LENGTH);
	
	recurSelectionSort(vet1,LENGTH/2,0);
	
	
	printf("\nVETTORE ORDINATO\n\n");
	stampaVettore(vet1,LENGTH);
	
	//int vet3[LENGTH*2];
	//unisci(vet1,vet2,LENGTH,LENGTH,vet3);
	//printf("\nSTAMPA DEL VETTORE \"UNITO\"\n");
	//stampaVettore(vet3,LENGTH*2);
	
	return 0;
}
