
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




 int ricerca(int valore,int V[],int I, int F)
 {
	 int i;
	 
	 for(i=I;i<F;i++)
	 {
		if(V[i]==valore)
		{
			return i;
		}
	 }
	 
	 return -1;	
 }
  
 int main()
 {
 	int MAXELEM,ValMax,X;
 	
 	printf("Di quanti elementi vuoi creare l'array? ");
 	scanf("%d",&MAXELEM);
 	
 	int V[MAXELEM];
 	int i;
	
	printf("Inserisci valore massimo: ");
 	scanf("%d",&ValMax);
 	
 	i=0;
 	
 	//Creazione Vettore casuale
	while(i<MAXELEM)
	{
		V[i]=rand()%ValMax+1;
		i++;
	}
 	
 	printf("Vettore: ");
 	for(i=0;i<MAXELEM;i++)
 	printf("%d ",V[i]);
 	
 	printf("\nChe numero vuoi cercare? ");
 	scanf("%d",&X);
 	
 	int figlio1,figlio2,figlio3;
 	
	
		if((figlio1 = fork()) == 0)
		{
			printf("\nFIGLIO 1 Valore trovato in posizione %d",ricerca(X,V,0,MAXELEM/3));	
			exit(0);	
		}
		if((figlio2 = fork()) == 0)
		{
			printf("\nFIGLIO 2 Valore trovato in posizione %d ",ricerca(X,V,(MAXELEM/3+1),((MAXELEM/3)+(MAXELEM/3))));
			exit(0);
		}
		if((figlio3 = fork()) == 0)
		{
			printf("\nFIGLIO 3 Valore trovato in posizione %d ",ricerca(X,V,((MAXELEM/3)+(MAXELEM/3)+1),MAXELEM));	
			exit(0);
		}	
		

		
	wait(NULL);
	wait(NULL);
	wait(NULL);
		
 	return 0;
 		
 }
