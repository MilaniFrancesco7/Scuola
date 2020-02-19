/*
 *
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* leggiStdin()
{
	char *input=NULL;
	char c=0;
	int pos=0;
	
	while((c=fgetc(stdin)) != EOF)
	{
		if(pos==0)
		{
			input=(char*)malloc(sizeof(char));
		}
		else
		{
			input=(char*)realloc(input,sizeof(char)*(pos+1));
		}
		
		input[pos]=c;
		pos++;
	}
	
	input[strlen(input)-1]=0;
	return input;
}

int main(int argc, char **argv)
{
	char *input=NULL;
	input=leggiStdin();
	
	fprintf(stdout,"Stringa: %s",input);
	fprintf(stderr,"Stringa ricevuta");
	
	return 0;
}

