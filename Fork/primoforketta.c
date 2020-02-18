/*
 *
 * 
 */


#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Inizio programma\n");
	
	//FILE *f1;
	
	int pid=fork();
	//int padre;
	//int figlio;
	
	usleep(500);
	if(pid<0)
	{
		perror("Il processo figlio non è stato creato\n");
		return -1;
	}
	else if(pid>0)
	{
		printf("Sono il padre");
		
	}
	else
	{
		printf("Sono il figlio");
	}
	
	printf("\nUn processo ha raggiunto la fine, pid %d\n",getpid());
	return 0;
}
