/*
 */


#include <stdio.h>
#include <signal.h>

void handler(int sig)
{
 printf("Bananone\n");
	
}

int main(int argc, char **argv)
{
	signal(SIGINT, handler);
	while (1) ;
	return 0;
}

