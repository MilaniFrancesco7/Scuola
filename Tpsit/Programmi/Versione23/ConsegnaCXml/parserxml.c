/*
 */


#include <stdio.h>
#include <stdlib.h>
#include "ezxml/ezxml.c"	//ezXML is a C library for parsing XML documents inspired by simpleXML for PHP.

int main()
{
	FILE *fp;											
	fp = fopen("VirtualBox_Read", "w");					//Apertura del file di scrittura
	
	ezxml_t VB = ezxml_parse_file("virtualbox.xml");			//Inserisco nella libreria il file xml 
	char *machinename;											
	ezxml_t machine = ezxml_child(VB, "Machine");				
	machinename = ezxml_attr(machine, "name"); 
	printf("Nome Client: %s\n", machinename);
	
	char *ostype;
	ezxml_t os = ezxml_child(VB, "Machine");
	ostype = ezxml_attr(os, "OSType"); 
	printf("Sistema Operativo: %s\n", ostype);

	char *formathd;
	char *locationhd;
	ezxml_t tempdisk1 = ezxml_child(VB, "Machine");
	ezxml_t tempdisk2 = ezxml_child(tempdisk1, "MediaRegistry");
	ezxml_t tempdisk3 = ezxml_child(tempdisk2, "HardDisks");
	ezxml_t tempdisk4 = ezxml_child(tempdisk3, "HardDisk");
	locationhd = ezxml_attr(tempdisk4, "location");
	formathd = ezxml_attr(tempdisk4, "format");
	printf("Locazione Hard Disk: %s\n", locationhd);
	printf("Formato Hard Disk: %s\n", formathd);
	
	char *ramsize;
	ezxml_t tempram1 = ezxml_child(VB, "Machine");
	ezxml_t tempram2 = ezxml_child(tempram1, "Hardware");
	ezxml_t ram = ezxml_child(tempram2, "Memory");
	ramsize = ezxml_attr(ram, "RAMSize"); 
	printf("RAM: %s\n", ramsize);
	
	char *firstboot;
	ezxml_t tempboot1 = ezxml_child(VB, "Machine");
	ezxml_t tempboot2 = ezxml_child(tempboot1, "Hardware");
	ezxml_t tempboot3 = ezxml_child(tempboot2, "Boot");
	ezxml_t boot = ezxml_child(tempboot3, "Order");
	firstboot = ezxml_attr(boot, "device"); 
	printf("First Boot: %s\n", firstboot);
	
	char *vramsize;
	ezxml_t tempvram1 = ezxml_child(VB, "Machine");
	ezxml_t tempvram2 = ezxml_child(tempvram1, "Hardware");
	ezxml_t vram = ezxml_child(tempvram2, "Display");
	vramsize = ezxml_attr(vram, "VRAMSize"); 
	printf("VRAM: %s\n", vramsize);
	
	fprintf(fp, "Nome Client: %s\n", machinename);
	fprintf(fp, "Sistema Operativo: %s\n", ostype);
	fprintf(fp, "RAM: %s\n", ramsize);
	fprintf(fp, "First Boot: %s\n", firstboot);
	fprintf(fp, "VRAM: %s\n", vramsize);
	
	fclose(fp);
	ezxml_free(VB);
	return 0;
  
}

