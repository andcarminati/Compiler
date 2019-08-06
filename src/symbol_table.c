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
 * symbol_table.c
 *
 *  Created on: 31/03/2009
 *      Author: andreu
 */
#include "../include/symbol_table.h"
#include "../include/list.h"

/*General symbol table*/
SYMBOL_TABLE * symbol_table;

/**
 * Construction of the Symbol Table
 * */
void create_symbol_table(){

	symbol_table = malloc(sizeof(SYMBOL_TABLE));

	symbol_table->scope_count = 0;
	symbol_table->scopes[0] = symb_list_create(); /*We need a hash table?*/

}

/**
 * Allocate a nested scope over the global scope
 * */
void push_scope(void){
	/*verify if the max scopes was reached*/
	if(symbol_table->scope_count >= (MAX_SCOPES - 1)){
		printf("Error, max scopes reached!\n");
		exit(1);
	}
	/*alloc a new scope*/
	symbol_table->scope_count++;
	symbol_table->scopes[symbol_table->scope_count] = symb_list_create();
}

/**
 * Deallocate the last scope in the symbol table
 */
void pop_scope(void){

	if(symbol_table->scope_count <= 0){
		printf("Error, min scopes reached!\n");
	    exit(1);
	}

	symb_list_destroy(symbol_table->scopes[symbol_table->scope_count]);

	symbol_table->scope_count--;
}

/**
 * Verify if the symbol table contains a id
 */
int symbol_table_contains(char *name){
	int i;

	for (i = 0; i <= symbol_table->scope_count; ++i) {

		if(symb_list_contains(symbol_table->scopes[i], name)){
			return 1;
		}
	}
	return 0;
}

/**
 * Insert a Symbol in the Symbol Table
 */
void symbol_table_insert(SYMBOL *symb){

	symb_list_insert(symbol_table->scopes[symbol_table->scope_count], symb);
}

/**
 * Remove a Symbol in the Symbol Table
 */
void symbol_table_remove(SYMBOL *symb){

	symb_list_remove(symbol_table->scopes[symbol_table->scope_count], symb);
}

SYMBOL *symbol_table_get(char *name){

	int i;
	for(i = 0; i <= symbol_table->scope_count; i++ ){
		SYMBOL *symb = symb_list_get(symbol_table->scopes[i], name);
		if(symb != NULL){
			return symb;
		}
	}
	//return symb_list_get(symbol_table->scopes[symbol_table->scope_count], name);
	return NULL;
}

void symbol_table_insert_id(int token, char *name){

		SYMBOL *new_symb;

		new_symb = malloc(sizeof(SYMBOL));

		new_symb->type = token;
		new_symb->symbol_name = malloc(strlen(name)+1);
		memcpy(new_symb->symbol_name, name, strlen(name));

		symbol_table_insert(new_symb);

		return;
}

