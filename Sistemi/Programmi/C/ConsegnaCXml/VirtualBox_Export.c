#include <stdio.h>
#include <string.h>
#include "ezxml.c"

int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("Dati_VirtualBox.txt", "w");
	
	ezxml_t f1 = ezxml_parse_file("parse.xml");
	char *machinename;
	ezxml_t machine = ezxml_child(f1, "Machine");
	machinename = ezxml_attr(machine, "name"); //Contiene il Nome del client
	printf("Nome Client: %s\n", machinename);
	
	char *ostype;
	ezxml_t os = ezxml_child(f1, "Machine");
	ostype = ezxml_attr(os, "OSType"); //Contiene il Sistema Operativo
	printf("Sistema Operativo: %s\n", ostype);
	
	char *ramsize;
	ezxml_t tempram1 = ezxml_child(f1, "Machine");
	ezxml_t tempram2 = ezxml_child(tempram1, "Hardware");
	ezxml_t ram = ezxml_child(tempram2, "Memory");
	ramsize = ezxml_attr(ram, "RAMSize"); //Contiene la Quantità di RAM
	printf("RAM: %s\n", ramsize);
	
	char *firstboot;
	ezxml_t tempboot1 = ezxml_child(f1, "Machine");
	ezxml_t tempboot2 = ezxml_child(tempboot1, "Hardware");
	ezxml_t tempboot3 = ezxml_child(tempboot2, "Boot");
	ezxml_t boot = ezxml_child(tempboot3, "Order");
	firstboot = ezxml_attr(boot, "device"); //Contiene la Quantità di VRAM
	printf("First Boot: %s\n", firstboot);
	
	char *vramsize;
	ezxml_t tempvram1 = ezxml_child(f1, "Machine");
	ezxml_t tempvram2 = ezxml_child(tempvram1, "Hardware");
	ezxml_t vram = ezxml_child(tempvram2, "Display");
	vramsize = ezxml_attr(vram, "VRAMSize"); //Contiene la Quantità di VRAM
	printf("VRAM: %s\n", vramsize);
	
	fprintf(fp, "Nome Client: %s\n", machinename);
	fprintf(fp, "Sistema Operativo: %s\n", ostype);
	fprintf(fp, "RAM: %s\n", ramsize);
	fprintf(fp, "First Boot: %s\n", firstboot);
	fprintf(fp, "VRAM: %s\n", vramsize);
	
	fclose(fp);
	ezxml_free(f1);
	return 0;
}
