/*
 */


#include <stdio.h>
#include <unistd.h>	//getpid, getppid
#include <stdlib.h>


int main()
{

	int i;
	int j;
	int pid=fork();
	
	if(pid<0)
	{
		printf("Non è stato possibile creare il processo figlio\n");
		exit(-1);
	}
	else if(pid==0)
	{
		j=rand()%10+1;
			
		sleep(j);
		
		printf("Sono nel figlio\n");
		
		for(i=0;i<2;i++)
		{
			pid=fork();
	
			j=rand()%10+1;
			
			sleep(j);
			
			printf("Fork %d pid figlio %d pid padre %d\n",(i+1),getpid(),getppid());
												
		}
	}
	else
	{
		
			
		printf("Sono nel padre\n");
		
		for(i=0;i<2;i++)
		{
			j=rand()%10+1;
			
			sleep(j);
			
			pid=fork();
			printf("Fork %d pid figlio %d pid padre %d\n",(i+1),getpid(),getppid());
		}
		
	
	}
	
	
	return 0;
}

