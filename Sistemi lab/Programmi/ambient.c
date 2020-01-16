//Milani Francesco
//5 AI
//2017

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char Parametri[4096];

void getAllParams()
{
	// Verifica POST o GET
	if(getenv("REQUEST_METHOD") == 0)
	{
		printf("No REQUEST_METHOD, must be running in DOS mode");
		return;
	}
	else if(strcmp(getenv("REQUEST_METHOD"), "POST") == 0)
	{
		// POST
		char *endptr; // quite useless, but required
		char *len1 = getenv("CONTENT_LENGTH");
		int contentlength = strtol(len1, &endptr, 10);
		fread(Parametri , contentlength, 1, stdin);
	}
	else
	{
		// GET
		strcpy(Parametri, getenv("QUERY_STRING"));
	}
}

int Tokken ()
{
	const char s[2] = "&";		//Carattere da trovare per dividere le stringhe
	char *tokeno;
	int num=1;
	tokeno = strtok(Parametri, s);		//Utilizzo di una stringa globale
	
	while( tokeno != NULL )
	{
		printf("<p>%d)%s\n",num,tokeno);	//Stampa in ordine di <h> 
		num++;
		tokeno = strtok(NULL, s);
	}
	
	return(0);
}

int main()
{
	printf("Content-Type:text/html \n\n");
	printf("<html>");
	printf("<head>");
	printf("<title>");
	printf("Variabili d'ambiente - Milani Francesco");
	printf("</title>");
	printf("</head>");
	printf("<body style='background-color:black' text='white'>");
	getAllParams();
	Tokken();
	printf("</body>");
	printf("</html>");
	return 0;
} 
