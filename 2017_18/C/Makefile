# Francesco Milani Verifica TPSIT 21 04 18

PROGRAMMA="Verifica_Milani"


all:	compila esegui pulisci
		
		
compila:
	gcc -o ${PROGRAMMA} ${PROGRAMMA}.c
	
pulisci:	
	if [-f ${PROGRAMMA}]; then rm ${PROGRAMMA}; fi						
	if [-f ${PROGRAMMA}.c~]; then rm ${PROGRAMMA}.c~; fi
	
esegui:
	./${PROGRAMMA}
