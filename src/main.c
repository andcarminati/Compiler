/*
 * Compiler
Copyright (C) 2019  Andreu Carminati
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * main.c
 *
 *  Created on: 05/03/2009
 *      Author: andreu
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/symbol_table.h"
#include "../include/x86/x86code_generator.h"
#include "../include/x86/assembler.h"
#include "../include/semantic.h"
#define VERSION "0.1"
#define MAX_INPUT_FILES 10

char input_files[MAX_INPUT_FILES][20];
char output_file[20] = "a.out";
int input_files_count=0;
int erro;
typedef union
{
	int ivalue;		/* integer value */
	char sIndex;	/* symbol table index */
	void *nPtr;		/* node pointer */
}YYSTYPE;

//YYSTYPE yyval;
YYSTYPE yyval;
TRANSLATION_UNIT *aa;

void parse_arguments(int argc, char **argv);
int validate_inputs(void);
int compile(void);
int yyparse();


FILE *yyin;
/*Tests*/

//int yyparse();
/*
void test_symbol_table(){

	SYMBOL *symb1, *symb2, *symb3;
	symb1 = malloc(sizeof(SYMBOL));
	symb2 = malloc(sizeof(SYMBOL));
	symb3 = malloc(sizeof(SYMBOL));

	puts("Testes");

	symb1->symbol_name = "simbolo1";
	symb2->symbol_name = "simbolo2";
	symb3->symbol_name = "simbolo3";

	symbol_table_insert(symb1);

	if(symbol_table_contains("simbolo1")){
		puts("Teste 1 ok");
	}
	if(!symbol_table_contains("simboloK")){
		puts("Teste 2 ok");
	}
	symbol_table_insert(symb2);

	if(symbol_table_contains("simbolo2")){
		puts("Teste 3 ok");
	}

	push_scope();

	symbol_table_insert(symb3);

	if(symbol_table_contains("simbolo3")){
		puts("Teste 4 ok");
	}
	if(symbol_table_contains("simbolo2")){
		puts("Teste 5 ok");
	}

	pop_scope();

	if(symbol_table_contains("simbolo2")){
		puts("Teste 6 ok");
	}
	if(!symbol_table_contains("simbolo3")){
		puts("Teste 7 ok");
	}
}
*/

int main(int argc, char **argv) {


	error_indicator = 0;
	create_symbol_table();
	//test_symbol_table();
	parse_arguments(argc, argv);
	validate_inputs();
	compile();

	return 0;

}
/**
 * Parse the command line arguments
 */
void parse_arguments(int argc, char **argv){

	char *str;
	int count = 1;

	if(argc == 1){
		printf("Compiler error: No input files\n");
		_exit(1);
	}

	str = argv[count++];
/*Finite automata representation of the command line grammar:
 * ( 0 )-----------------" -h "----------------> ( F )
 *   |
 *   |----------------------------
 *   V                           |
 * ( 1 )-----------------"[...]"--
 *   |
 *   |-------------------"-o"-----
 *                               |
 *   ----------------------------| .....
 *  .                        .
 *  .                          .
 *  .                            .
 *
 *Implementation
 */
	if(strcmp("-h", str) == 0){
		goto help;
	}

start:

	if(strcmp("-i", str) == 0){
		goto inputs;
	}
	if(strcmp("-o", str) == 0){
		goto output;
	}

help:
	printf("No help available\n");
	goto exit;

inputs:
	if(count == argc){
		goto exit;
	}
	str = argv[count++];
	if(strcmp("-o", str) == 0){
		goto output;
	}
	if(strcmp("-i", str) == 0){
		goto inputs;
	}
	strcpy(input_files[input_files_count++], str);
	goto inputs;


output:
	if(count == argc){
		goto exit;
	}
	str = argv[count++];
	if(strcmp("-i", str) == 0){
		goto inputs;
	}
	strcpy(output_file, str);
	if(count < argc){
		str = argv[count++];
		goto start;
	}

	goto exit;

exit:
	return;

}
/**
 * Do the validation of the inputs and output
 */
int validate_inputs(){

	if(input_files_count == 0){
		printf("No input files!\n");
		return 0;
	}

	int i;

	printf("Input files: ");
	for(i = 0; i < input_files_count; i++){
		printf("%s ", input_files[i]);
	}
	printf("\nOutput file: %s\n", output_file);


	return 1;
}
/**
 * Execute the compilation of all files
 */
int compile(){
	int var;
	for (var = 0; var < input_files_count; ++var) {
		if(input_files[var] == NULL){
			break;
		}

		printf("<<<<<<<<<<<<<<<<<Compiling %s>>>>>>>>>>>>>>>>>>>\n", input_files[var]);
		yyin = fopen(input_files[var], "r+");
		yyparse();

		if(erro == 1){

			puts("\nAbort.");
		} else {
			//TRANSLATION_UNIT *tu = yyval.nPtr;
			TRANSLATION_UNIT *tu = aa;
			init_cg("assembly.s");
			create_symbol_table();
			semantic_entry(tu);

			cleanup_cg();
			if(error_indicator){
				puts("Compiler finalized with semantic error.");
			} else {

				assemble_file("assembly.s", output_file);
			}
		}

		fclose(yyin);
	}
	return 0;
}

