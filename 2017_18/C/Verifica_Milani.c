/*
 * Verifica di TPSIT del 21 04 2018
 * 
 * Milani Francesco
 * 
 * 3AI
 * 
 * File che utilizza le struct
 * 
 */


#include <stdio.h>
#include "Verifica_Struct.c"

int main()
{
	temp t=timput(t);
	
	t.modo='K';
	
	tprint(t.gradi);
	
	printf("°%c\n",t.modo);;;;;;
	
	tmode(t.gradi,t.modo);
		
		
	
	return 0;
}

