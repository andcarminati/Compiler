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
 * error_report.c
 *
 *  Created on: 18/06/2009
 *      Author: andreu
 */

#include "../include/error_report.h"
#include "y.tab.h"
#include <stdio.h>

const char *type_int = "int";
const char *type_char = "char";
const char *type_float = "float";

const char *get_type_name(int type){

	switch(type){
		case INT:
					return type_int;
		case CHAR:
					return type_char;
		case FLOAT:
					return type_float;
	}

	return (char*)0;

}

void type_incompatibility(int line, int type_n1, int type_n2){

	printf("Type compatibility error, one is %s and another is %s. line: %d\n",
			get_type_name(type_n1), get_type_name(type_n2), line);
}

void iteration_type_incompatibility(int line, int type_n){

	printf("Iteration condition exp. must return int value, returned is %s. line: %d\n",
			get_type_name(type_n), line);
}
