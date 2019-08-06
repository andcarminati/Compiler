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
 * list.c
 *
 *  Created on: 15/03/2009
 *      Author: andreu
 */

#include "../include/list.h"
#include <stdlib.h>


struct List *symb_list_create(){
	struct List *new_list;
	struct Node *node;

	new_list = alloc_list_node();
	node = alloc_list_node();

	new_list->count = 0;
	new_list->first = new_list->last = node;

	node->data = NULL;
	node->next = node->prev = NULL;

	return new_list;
}

void symb_list_insert(struct List* list, SYMBOL *data){

	struct Node *old_last, *new_last;
	new_last = alloc_list_node();

	if(list->count++ == 0){
		old_last = list->first;
	} else {
		old_last = list->last;
	}

	new_last->data = NULL;
	new_last->next = NULL;
	new_last->prev = old_last;

	old_last->next = new_last;
	old_last->data = data;
	old_last->next = new_last;

	list->last = new_last;

	return;
}

void symb_list_remove(struct List* list, SYMBOL *data){

	struct Node *node = list->first;

	while(node){
		if(node->data){
			if(strcmp(data->symbol_name, node->data->symbol_name) == 0){
				//continuar
			}
		}
	}

}

int symb_list_contains(struct List* list, char *data){

	struct Node *node = list->first;

	if(list->count == 0){
		return 0;
	}
	while(node != NULL){
		if(node->data != NULL){
			//puts(node->data->symbol_name);
			if(strcmp(data, node->data->symbol_name) == 0){
						return 1;
			}
		}

		node = node->next;
	}

	return 0;
}

void symb_list_destroy(struct List* list){

	struct Node *node;
	node = list->first;

	while(node){
		if (node->data) {
			free(node->data);
		}
		node = node->next;
	}
	free(list->first);
	free(list);
}

SYMBOL * symb_list_get(struct List *list, char *name){

	struct Node *node = list->first;

		if(list->count == 0){
			return 0;
		}
		while(node != NULL){
			if(node->data != NULL){
				//puts(node->data->symbol_name);
				if(strcmp(name, node->data->symbol_name) == 0){
							return node->data;
				}
			}

			node = node->next;
		}

		return NULL;

}


