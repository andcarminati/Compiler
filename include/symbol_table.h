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
 * symbol_table.h
 *
 *  Created on: 31/03/2009
 *      Author: andreu
 */

#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include "list.h"
#include <stdio.h>

#define MAX_SCOPES 10

typedef struct Symbol_tab{
	/*Store the stacked scopes*/
	struct List *scopes[MAX_SCOPES];
	/*Count the stacked scoped*/
	int scope_count;

} SYMBOL_TABLE;

/*implemented*/
void create_symbol_table();

void push_scope(void);
void pop_scope(void);

int symbol_table_contains(char *);
void symbol_table_insert(SYMBOL *);
void symbol_table_remove(SYMBOL *symb);
SYMBOL *symbol_table_get(char *);
//int symbol_table_hash(char*);

void symbol_table_insert_id(int token, char *name);


#endif /* SYMBOL_TABLE_H_ */
