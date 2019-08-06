/*
 * assembler.c
 *
 *  Created on: 23/06/2009
 *      Author: andreu
 */
#include "../../include/x86/assembler.h"
#include <stdio.h>
#include <stdlib.h>


int assemble_file(char *asm_file, char *bin_file){

	char command_line[100];
	int ret;

	sprintf(command_line, "as %s -o temp", asm_file);

	ret = system(command_line);

	if(ret){
		puts("assembler error");
		return ret;
	}

	sprintf(command_line, "ld -dynamic-linker /lib/ld-linux.so.2 -o %s -s temp -lc", bin_file);

	ret = system(command_line);

	if(ret){
		puts("linker error");
		return ret;
	}


	return ret;
}
