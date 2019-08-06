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
 * list.h
 *
 *  Created on: 15/03/2009
 *      Author: andreu
 */
#include "compiler.h"
#include <string.h>

#ifndef LIST_H_
#define LIST_H_

struct List{
	int count;
	struct Node *first;
	struct Node *last;
};

struct Node{
	SYMBOL *data;
	struct Node *next, *prev;
};

#define alloc_list() (malloc(sizeof(struct List)))
#define free_list(list) (free(list))

#define alloc_list_node() (malloc(sizeof(struct Node)))
#define free_list_node(node) (free(node))

void symb_list_insert(struct List*, SYMBOL *);
void symb_list_remove(struct List*, SYMBOL *);

int symb_list_contains(struct List*, char *);
struct List* symb_list_create(void);
void symb_list_destroy(struct List*);
SYMBOL * symb_list_get_first(struct List*);
SYMBOL * symb_list_get_last(struct List*);
SYMBOL * symb_list_get(struct List*, char*);






#endif /* LIST_H_ */
