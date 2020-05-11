#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	printf("INIZIO DEL PROGRAMMA\n\n");
	
	printf("ESEGUO IL FORK\n\n");
	int pid=fork();
	
	//Operazione che calcola un tempo che va da 0,5 a 2 secondi (i valori sono espressi in microsecondi)
	//int num = (rand() % (20000000 - 5000000 + 1)) + 5000000; 
	int num = 0;
	
	usleep(num);
	if(pid<0)
	{
		printf("\nLa creazione del processo figlio non è andata a buon fine");
		return -1;
	}else if(pid==0)
	{
		printf("PID PROCESSO FIGLIO: %d\n",getpid());
		printf("PID DEL PADRE: %d\n\n",getppid());
		usleep(num);
	}else if(getpid()>0)
	{
		printf("PID PROCESSO PADRE: %d\n\n",getpid());
		usleep(num);
	}
	
	wait(NULL);
	printf("\nUn processo ha raggiunto il termine programma\nEcco il PID del processo: %d\n\n",getpid());
	
	return 0;
}
