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
 * semantic.c
 *
 *  Created on: 06/03/2009
 *      Author: andreu
 */
#include "../include/semantic.h"
#include "../include/symbol_table.h"
#include "../include/x86/x86code_generator.h"
#include "y.tab.h"
#include "../include/error_report.h"

//#define COMPILER_DEBUG

int select_action(DEFAULT_NODE *df);
int action_function_def1(FUNCTION_DEFINITION1 *f);
int action_function_def2(FUNCTION_DEFINITION2 *f);
void abort_not_implemented(char *);

int error_indicator = 0;
int deep_scope = 0;
FUNCTION_DEFINITION *actual_function_definition = NULL;

int FUNCTION_DEFINITION2_visitor(FUNCTION_DEFINITION2 *fd);

int DECLARATION_SPECIFIERS_visitor(DECLARATION_SPECIFIERS *ds);

int TYPE_SPECIFIER_visitor(TYPE_SPECIFIER *ds);

int DECLARATOR_visitor(DECLARATOR *dcl);

int DIRECT_DECLARATOR1_visitor(DIRECT_DECLARATOR1 *dcl);

int DIRECT_DECLARATOR2_visitor(DIRECT_DECLARATOR2 *dcl);

int DIRECT_DECLARATOR3_visitor(DIRECT_DECLARATOR3 *dcl);

int DIRECT_DECLARATOR4_visitor(DIRECT_DECLARATOR4 *dcl);

int COMPOUND_STATEMENT_visitor(COMPOUND_STATEMENT *dcl);

int DECLARATION_LIST_visitor(DECLARATION_LIST *dcl);

int DECLARATION_visitor(DECLARATION *dcl);

int STATEMENT_LIST_visitor(STATEMENT_LIST *stmt);

int SELECTION_STATEMENT_visitor(SELECTION_STATEMENT *sel);

int ITERATION_STATEMENT_visitor(ITERATION_STATEMENT *it);

int STATEMENT5_visitor(STATEMENT5 *st);

int STATEMENT6_visitor(STATEMENT6 *st);

int EXPRESSION_visitor(EXPRESSION *ex);

int ASSIGNMENT_EXPRESSION1_visitor(ASSIGNMENT_EXPRESSION1 *ex);

int CONDITIONAL_EXPRESSION_visitor(CONDITIONAL_EXPRESSION *ex);

int LOGICAL_OR_EXPRESSION_visitor(LOGICAL_OR_EXPRESSION *ex);

int LOGICAL_AND_EXPRESSION_visitor(LOGICAL_AND_EXPRESSION *ex);

int INCLUSIVE_OR_EXPRESSION_visitor(INCLUSIVE_OR_EXPRESSION *ex);

int EXCLUSIVE_OR_EXPRESSION_visitor(EXCLUSIVE_OR_EXPRESSION *ex);

int AND_EXPRESSION_visitor(AND_EXPRESSION *ex);

int EQUALITY_EXPRESSION_visitor(EQUALITY_EXPRESSION *ex);

int RELATIONAL_EXPRESSION_visitor(RELATIONAL_EXPRESSION *ex);

int SHIFT_EXPRESSION_visitor(SHIFT_EXPRESSION *ex);

int ADDITIVE_EXPRESSION_visitor(ADDITIVE_EXPRESSION *ex);

int MULTIPLICATIVE_EXPRESSION_visitor(MULTIPLICATIVE_EXPRESSION *ex);

int UNARY_EXPRESSION_visitor(UNARY_EXPRESSION *ex);

int POSTFIX_EXPRESSION_visitor(POSTFIX_ESPRESSION *ex);

int PRIMARY_EXPRESSION_visitor(PRIMARY_EXPRESSION *ex);

int CONSTANT_EXPRESSION_visitor(CONSTANT_EXPRESSION *ex);

int EXTERNAL_DECLARATION_visitor(EXTERNAL_DECLARATION *dcl);

int ASSIGNMENT_EXPRESSION2_visitor(ASSIGNMENT_EXPRESSION2 *ex);

int POSTFIX_ESPRESSION4_visitor(POSTFIX_ESPRESSION4 *ex);

int EXPRESSION_STATEMENT_visitor(EXPRESSION_STATEMENT *ex);

int JUMP_STATEMENT_visitor(JUMP_STATEMENT *jmp);

int POSTFIX_ESPRESSION2_visitor(POSTFIX_ESPRESSION2 *ex);

int mach_params(PARAMETER_TYPE_LIST *ptl, ARGUMENT_EXPRESSION_LIST *arg);

int PARAMETER_LIST_visitor(PARAMETER_LIST * pl);

int get_type_size(int type);

int is_return_type(int type);

int builtin_function(char *func, ARGUMENT_EXPRESSION_LIST *args);

/**
 * Recursive semantic entry:
 * is recursive to preserve the declaration order.
 */
int semantic_entry(TRANSLATION_UNIT *tu){

	//printf("<<Semantic Analysis starts here>>>\n");

	if(tu->trans_unit != NULL){
		semantic_entry(tu->trans_unit);
	}

	select_action((DEFAULT_NODE *) tu->ext_decl);


	return 0;
}
/**
 * Function Selector:
 * Selects a function to process a node
 */
int select_action(DEFAULT_NODE *df){

	switch(df->type){
		case TRANSLATION_UNIT_CODE:
			abort_not_implemented("TRANSLATION_UNIT_CODE");
			break;
		case EXTERNAL_DECLARATION_CODE:
			EXTERNAL_DECLARATION_visitor(df);
			//abort_not_implemented("EXTERNAL_DECLARATION_CODE");
		//	break;
		case FUNCTION_DEFINITION_CODE:
			switch(df->subtype){
				case FUNCTION1_DEFINITION_CODE:

					abort_not_implemented("FUNCTION1_DEFINITION_CODE");
					break;
				case FUNCTION2_DEFINITION_CODE:
					return FUNCTION_DEFINITION2_visitor(df);
					//abort_not_implemented("FUNCTION2_DEFINITION_CODE");
					break;
			}

		case POSTFIX_ESPRESSION_CODE:
			switch(df->subtype){
				case POSTFIX_ESPRESSION1_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION1_CODE");
					break;
				case POSTFIX_ESPRESSION2_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION2_CODE");
					break;
				case POSTFIX_ESPRESSION3_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION3_CODE");
					break;
				case POSTFIX_ESPRESSION4_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION4_CODE");
					break;
				case POSTFIX_ESPRESSION5_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION5_CODE");
					break;
				case POSTFIX_ESPRESSION6_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION6_CODE");
					break;
				case POSTFIX_ESPRESSION7_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION7_CODE");
					break;
				case POSTFIX_ESPRESSION8_CODE:
					abort_not_implemented("POSTFIX_ESPRESSION8_CODE");
					break;
			}
			break;
		case ITERATION_STATEMENT_CODE:
			return ITERATION_STATEMENT_visitor(df);
			//abort_not_implemented("POSTFIX_ESPRESSION8_CODE");
			break;
		case SELECTION_STATEMENT_CODE:
			return SELECTION_STATEMENT_visitor(df);
			//abort_not_implemented("SELECTION_STATEMENT_CODE");
			break;
		case ARGUMENT_EXPRESSION_LIST_CODE:
			abort_not_implemented("ARGUMENT_EXPRESSION_LIST_CODE");
			break;
		case PRIMARY_EXPRESSION_CODE:
			switch(df->subtype){
				case PRIMARY_EXPRESSION1_CODE:
					abort_not_implemented("PRIMARY_EXPRESSION1_CODE");
					break;
				case PRIMARY_EXPRESSION2_CODE:
					abort_not_implemented("PRIMARY_EXPRESSION2_CODE");
					break;
				case PRIMARY_EXPRESSION3_CODE:
					abort_not_implemented("PRIMARY_EXPRESSION3_CODE");
					break;
				case PRIMARY_EXPRESSION4_CODE:
					abort_not_implemented("PRIMARY_EXPRESSION4_CODE");
					break;
			}

		case UNARY_EXPRESSION_CODE:
			switch(df->subtype){
				case UNARY_EXPRESSION1_CODE:
					abort_not_implemented("UNARY_EXPRESSION1_CODE");
					break;
				case UNARY_EXPRESSION2_CODE:
					abort_not_implemented("UNARY_EXPRESSION2_CODE");
					break;
				case UNARY_EXPRESSION3_CODE:
					abort_not_implemented("UNARY_EXPRESSION3_CODE");
					break;
				case UNARY_EXPRESSION4_CODE:
					abort_not_implemented("UNARY_EXPRESSION4_CODE");
					break;
			}

		case UNARY_OPERATOR_CODE:
			abort_not_implemented("1");
			break;
		case MULTIPLICATIVE_EXPRESSION_CODE:
			abort_not_implemented("2");
			break;
		case ADDITIVE_EXPRESSION_CODE:
			abort_not_implemented("3");
			break;
		case SHIFT_EXPRESSION_CODE:
			abort_not_implemented("4");
			break;
		case RELATIONAL_EXPRESSION_CODE:
			abort_not_implemented("5");
			break;
		case EQUALITY_EXPRESSION_CODE:
			abort_not_implemented("6");
			break;
		case EXPRESSION_STATEMENT_CODE:
			abort_not_implemented("7");
			break;
		case STATEMENT_LIST_CODE:
			//abort_not_implemented("STATEMENT_LIST_CODE");
			return STATEMENT_LIST_visitor(df);
			break;
		case DECLARATION_LIST_CODE:
			return DECLARATION_LIST_visitor(df);
			//abort_not_implemented("");
			break;
		case COMPOUND_STATEMENT_CODE:
			return COMPOUND_STATEMENT_visitor(df);
			//abort_not_implemented("COMPOUND_STATEMENT_CODE");
			break;
		case LABELED_STATEMENT_CODE:
			switch(df->subtype){
				case LABELED_STATEMENT1_CODE:
					abort_not_implemented("8");
					break;
				case LABELED_STATEMENT2_CODE:
					abort_not_implemented("9");
					break;
				case LABELED_STATEMENT3_CODE:
					abort_not_implemented("10");
					break;
			}
			break;
		case STATEMENT_CODE:
			switch(df->subtype){
				case STATEMENT2_CODE:
					COMPOUND_STATEMENT_visitor(((STATEMENT2*)df)->compound_statement);
					//abort_not_implemented("11");
					break;
				case STATEMENT3_CODE:
					return EXPRESSION_STATEMENT_visitor(((STATEMENT3*)df)->expression_statement);
					//abort_not_implemented("12");
					break;
				case STATEMENT4_CODE:
					return SELECTION_STATEMENT_visitor(((STATEMENT3*)df)->expression_statement);
					//abort_not_implemented("13");
					break;
				case STATEMENT5_CODE:
					return STATEMENT5_visitor(df);
					//abort_not_implemented("14");
					break;
				case STATEMENT6_CODE:
					return STATEMENT6_visitor(df);
					//abort_not_implemented("15");
					break;
				case STATEMENT7_CODE:
					JUMP_STATEMENT_visitor(((STATEMENT7*)df)->jump_statement);
					//abort_not_implemented("16");
					break;
				case STATEMENT1_CODE:
					abort_not_implemented("17");
					break;
			}
			break;
		case INITIALIZER_LIST_CODE:
			abort_not_implemented("");
			break;
		case AND_EXPRESSION_CODE:
			abort_not_implemented("");
			break;
		case EXCLUSIVE_OR_EXPRESSION_CODE:
			abort_not_implemented("");
			break;
		case INCLUSIVE_OR_EXPRESSION_CODE:
			abort_not_implemented("");
			break;
		case LOGICAL_AND_EXPRESSION_CODE:
			abort_not_implemented("");
			break;
		case LOGICAL_OR_EXPRESSION_CODE:
			abort_not_implemented("");
			break;
		case CONDITIONAL_EXPRESSION_CODE:
			abort_not_implemented("");
			break;
		case ASSIGNMENT_EXPRESSION_CODE:
			switch(df->subtype){
				case ASSIGNMENT_EXPRESSION1_CODE:
					return ASSIGNMENT_EXPRESSION1_visitor(df);
					//abort_not_implemented("");
					break;
				case ASSIGNMENT_EXPRESSION2_CODE:
					ASSIGNMENT_EXPRESSION2_visitor(df);
					//abort_not_implemented("ASSIGNMENT_EXPRESSION2_CODE");
					break;
			}

		case CONSTANT_EXPRESSION_CODE:
			return CONSTANT_EXPRESSION_visitor(df);
			//abort_not_implemented("CONSTANT_EXPRESSION_CODE");
			break;
		case EXPRESSION_CODE:
			return EXPRESSION_visitor(df);
			//abort_not_implemented("");
			break;
		case DECLARATION_CODE:
			return DECLARATION_visitor(df);
			//abort_not_implemented("DECLARATION_CODE");
			break;
		case DECLARATION_SPECIFIERS_CODE:
			return DECLARATION_SPECIFIERS_visitor(df);
			//abort_not_implemented("DECLARATION_SPECIFIERS_CODE");
			break;
		case IDENTIFIER_LIST_CODE:
			abort_not_implemented("");
			break;
		case TYPE_NAMEi_CODE:
			abort_not_implemented("");
			break;
		case INIT_DECLARATOR_CODE:
			abort_not_implemented("");
			break;
		case INIT_DECLARATOR_LIST_CODE:
			abort_not_implemented("");
			break;
		case TYPE_SPECIFIER_CODE:
			return TYPE_SPECIFIER_visitor(df);
			//abort_not_implemented("");
			break;
		case POINTER_CODE:
			abort_not_implemented("");
			break;
		case PARAMETER_TYPE_LIST_CODE:
			abort_not_implemented("");
			break;
		case DECLARATOR_CODE:
			return DECLARATOR_visitor(df);
			//abort_not_implemented("");
			break;
		case DIRECT_DECLARATOR_CODE:
			switch(df->subtype){
				case DIRECT_DECLARATOR1_CODE:
					return DIRECT_DECLARATOR1_visitor(df);
					//abort_not_implemented("DIRECT_DECLARATOR1_CODE");
					break;
				case DIRECT_DECLARATOR2_CODE:
					abort_not_implemented("DIRECT_DECLARATOR2_CODE");
					break;
				case DIRECT_DECLARATOR3_CODE:
					abort_not_implemented("DIRECT_DECLARATOR3_CODE");
					break;
				case DIRECT_DECLARATOR4_CODE:
					return DIRECT_DECLARATOR4_visitor(df);
					//abort_not_implemented("DIRECT_DECLARATOR4_CODE");
					break;
				case DIRECT_DECLARATOR5_CODE:
					abort_not_implemented("DIRECT_DECLARATOR5_CODE");
					break;
			}
			break;
		case STRUCT_OR_UNION_CODE:
			abort_not_implemented("");
			break;
		case STRUCT_OR_UNION_SPECIFIER_CODE:
			abort_not_implemented("");
			break;
		case STRUCT_OR_UNION_SPECIFIER1_CODE:
			abort_not_implemented("");
			break;
		case STRUCT_OR_UNION_SPECIFIER2_CODE:
			abort_not_implemented("");
			break;
		case STRUCT_OR_UNION_SPECIFIER3_CODE:
			abort_not_implemented("");
			break;
		case SPECIFIER_QUALIFIER_LIST_CODE:
			abort_not_implemented("");
			break;
		case JUMP_STATEMENT_CODE:
			JUMP_STATEMENT_visitor(df);
			//abort_not_implemented("");
			break;
	}

	return 0;
}
/**
 *
 * Function not implemented indicator
 *
 */

void abort_not_implemented(char *s){

	printf("ABORT: %s not implemented!\n", s);
	//exit(1);
	error_indicator = 1;
}

/**
 *
 * Implements function definition semantics.
 *
 */

int FUNCTION_DEFINITION2_visitor(FUNCTION_DEFINITION2 *fd){

	DECLARATION_SPECIFIERS * ds = fd->dec_specifier;
	DECLARATOR *d = fd->declarator;
	int function_return_type;
	char *function_name;
	SYMBOL *symb = malloc(sizeof(SYMBOL));
	PARAMETER_TYPE_LIST *ptl;

	deep_scope++;

	// get the function name
	function_name = ((DIRECT_DECLARATOR1*)
			((DIRECT_DECLARATOR4*)d->direct_declarator)->direct_declarator)->identifier;
	// one type only;
	function_return_type = ds->type_specifier->datatype;

	ptl = ((DIRECT_DECLARATOR4*)d->direct_declarator)->parameter_type_list;
#ifdef DEBUG_COMPILER
	printf("Function Return Type: %d, Symbol name:  %s\n",
			function_return_type, function_name);
#endif

	// set symbol type as function
	symb->type = FUNCTION_SYMB;
	symb->symbol_name = function_name;
	symb->function_return_type = function_return_type;
	symb->function_params = ptl;


	// symbol is on symbol table?
	if(symbol_table_get(function_name) != NULL){
		printf("Function name %s is already declared, aborting...\n", function_name);
		exit(1);

	} else{
		symbol_table_insert(symb);
	}
	push_scope();


	/*insert parameters on symbol table*/
	//puts(ptl->parameter_list);
	//puts("&&&&");
	if(ptl != NULL){
		PARAMETER_LIST_visitor(ptl->parameter_list);
	}



	/*Code Generation*/
	cg_start_procedure(function_name);
	/*Code Generation*/

	//while(1);
	//puts(fd->compound_statement);
	// Now, we have to process the function body
	if(fd->compound_statement != NULL){
		select_action((DEFAULT_NODE*)fd->compound_statement);
	}

	//while(1);

	/*Code Generation*/
	cg_end_procedure(function_name);
	/*Code Generation*/

	pop_scope();

	deep_scope--;

	return 0;
}

int DECLARATION_SPECIFIERS_visitor(DECLARATION_SPECIFIERS *ds){

	while(ds != NULL){
			select_action((DEFAULT_NODE*)ds->type_specifier);
			ds = ds->declaration_specifiers;
	}
	return 0;
}

int TYPE_SPECIFIER_visitor(TYPE_SPECIFIER *ds){
	//printf("@\n");
	return 0;
}

int DECLARATOR_visitor(DECLARATOR *dcl){

		select_action(dcl->direct_declarator);

		return 0;
}
/**
 * Obsolete now
 */

int DIRECT_DECLARATOR1_visitor(DIRECT_DECLARATOR1 *dcl){

	SYMBOL *symb = malloc(sizeof(SYMBOL));

	symb->symbol_name = dcl->identifier;
	symb->type = FUNCTION_DEFINITION_CODE;

	symbol_table_insert(symb);

	//puts(symb->symbol_name);

	//puts("SYMBOL inserted");

	return 0;
}

int DIRECT_DECLARATOR2_visitor(DIRECT_DECLARATOR2 *dcl){

	return 0;
}

int DIRECT_DECLARATOR3_visitor(DIRECT_DECLARATOR3 *dcl){

	return 0;
}

/**
 * Obsolete now.
 */

int DIRECT_DECLARATOR4_visitor(DIRECT_DECLARATOR4 *dcl){

	//select_action(dcl->direct_declarator);
	SYMBOL *symb = malloc(sizeof(SYMBOL));


	// get the function name
	symb->symbol_name = ((DIRECT_DECLARATOR1*)dcl->direct_declarator)->identifier;
	// set symbol type as function
	symb->type = FUNCTION_SYMB;



	symbol_table_insert(symb);

	puts(symb->symbol_name);

	puts("SYMBOL inserted");

	return 0;

}
/**
 *
 * Implements compound {} statement semantics with
 * calls to code generator.
 *
 *
 */


int COMPOUND_STATEMENT_visitor(COMPOUND_STATEMENT *comp){

	/*add a layer on symbol table to handle this*/
	push_scope();

	/*add declarations to the symbol table*/
	if(comp->declaration_list != NULL){
		select_action(comp->declaration_list);
	}


	/*do the statement analisys*/
	if(comp->statement_list != NULL){
		select_action(comp->statement_list);
	}


	/*remove the last layer on our symbol table*/
	pop_scope();

	return 0;
}

int DECLARATION_LIST_visitor(DECLARATION_LIST *dcl){

	if(dcl->declaration_list != NULL){
		//select_action(dcl->declaration);
		DECLARATION_LIST_visitor(dcl->declaration_list);
	}
	select_action(dcl->declaration);

	return 0;
}
/**
 *
 * Handles var declarations with possible initializators
 *
 */

int do_var_declarations(INIT_DECLARATOR_LIST *i, DECLARATION_SPECIFIERS *d){

	SYMBOL *symb;
	int var_type;
	char *var_name;
	int pointers = 0;

	if(i->init_declarator_list != NULL){
		do_var_declarations(i->init_declarator_list, d);
	}
	DIRECT_DECLARATOR1 *d1;
	DIRECT_DECLARATOR2 *d2;
	DIRECT_DECLARATOR3 *d3;
	DIRECT_DECLARATOR4 *d4;
	INITIALIZER *init = i->init_declarator->initializer;
	//if(init == NULL){
	//	puts("NULL");
	//}
	//INITIALIZER1 *init1;
	int alloc_size;

	switch(i->init_declarator->declarator->direct_declarator->subtype){

		// single variables
		case DIRECT_DECLARATOR1_CODE:

			//i->init_declarator->initializer->
			d1 = ((DIRECT_DECLARATOR1*)
					i->init_declarator->declarator->direct_declarator);
			var_name = d1->identifier;
			var_type = d->type_specifier->datatype;

			//puts(d1->identifier);

			// is already present on symbol table?
			if(symbol_table_get(var_name) != NULL){
				error_indicator = 1;
				printf("Var name %s is already declared, aborting...\n", var_name);
				//exit(1);
			}
			symb = malloc(sizeof(SYMBOL));
			symb->type = VAR_SYMB;
			symb->symbol_name = var_name;
			symb->var_type = var_type;
			symb->pointers = pointers; // FIX IT

			if(deep_scope == 0){
			/*is a global variable*/
				symb->localization = GLOBAL_VAR;
				//puts("-----------------------------------------------");
				//printf("GLOBAL VAR  =============================");
				cg_declare_global_variable(symb->symbol_name, 0, var_type);

				//if(){

				//}

			} else {
			symb->localization = LOCAL_VAR;
			symb->array = 0;
			/*is a local variable*/
				if(var_type == INT){

					symb->offset = cg_get_next_offset(4);
					//cg_store_local_var32(symb->offset, 666);

				} else if(var_type == CHAR){

					symb->offset = cg_get_next_offset(1);

				} else if(var_type == FLOAT){

					symb->offset = cg_get_next_offset(4);
				}
				/*initialized?*/
				if(init != NULL){
					if(init->subtype == INITIALIZER1_CODE){
						INITIALIZER1 *init1 = (INITIALIZER1*) init;

						int ret = ASSIGNMENT_EXPRESSION1_visitor(init1->assignment_expression);

						if((symb->var_type == CHAR) && (ret == (CHAR | INT))){
								//puts("OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKk");
								//ok
						} else if(ret != symb->var_type){
							error_indicator = 1;
							//puts("aqui");
							type_incompatibility(0, symb->var_type, ret);
						}
						cg_pop_local_var(symb->offset, get_type_size(symb->var_type));
						symb->val_initialized = 1;
					} else{
						error_indicator = 1;
						printf("Error on var inialialization, invalid initializator\n");
					}
				} else {
					symb->val_initialized = 0;
				}
			}
			break;

		/*this type of declarator handles arrays*/
		case DIRECT_DECLARATOR3_CODE:

			d3 = ((DIRECT_DECLARATOR3*)
								i->init_declarator->declarator->direct_declarator);
			d1 = (DIRECT_DECLARATOR1*) d3->direct_declarator;

			if(((DIRECT_DECLARATOR*)d1)->subtype != DIRECT_DECLARATOR1_CODE){
				printf("Multidimentional array is not supported in this version\n");
				exit(1);
			} else{

				if(symbol_table_get(d1->identifier) != NULL){
					error_indicator = 1;
									printf("Var (array) name %s is already declared, aborting...\n", d1->identifier);
				}

				symb = malloc(sizeof(SYMBOL));
				var_type = d->type_specifier->datatype;
				var_name = d1->identifier;



				symb->type = VAR_SYMB;
				symb->symbol_name = var_name;
				symb->var_type = var_type;
				symb->array = 1;
				//symb->pointers = pointers; // FIX IT

				if(deep_scope == 0){
					/*global*/


				} else {
					symb->localization = LOCAL_VAR;
					//symb->
					int size = d3->constant;
					//printf("=>>>>>>>>>>>>>>>>>>>>>>>>> %d", size);
					if(size == 0){
						error_indicator = 1;
						printf("Compiler error: array size cannot be 0\n");
					}
					symb->offset = cg_get_next_offset(get_type_size(var_type)*size);
					//printf("=>>>>>>>>>>>>>>>>>>>>>>>>> %d", symb->offset);
					if(init != NULL){
						printf("Compiler warning: initialization of arrays has no effect\n");
					}


				}

			}

		}




#ifdef COMPILER_DEBUG
	printf("Var name: %s, Var type: %d\n", var_name, var_type);
#endif
/*************************AQUI AQUI******************************/


	symbol_table_insert(symb);

	return 0;

}

int DECLARATION_visitor(DECLARATION *dcl){


		SYMBOL *symb = malloc(sizeof(SYMBOL));

		INIT_DECLARATOR_LIST *idl = dcl->init_declarator_list;
		DECLARATION_SPECIFIERS *ds = dcl->declaration_specifiers;

		do_var_declarations(idl, ds);

		return 0;
}

int STATEMENT_LIST_visitor(STATEMENT_LIST *stmt){

#ifdef COMPILER_DEBUG
	printf("STATEMENT LIST VISITOR\n");
#endif

	if(stmt->statement_list != NULL){
		STATEMENT_LIST_visitor(stmt->statement_list);
	}

	select_action((DEFAULT_NODE*)stmt->statement);

	return 0;
}
/**
 *
 * If then else statements handler
 *
 */

int SELECTION_STATEMENT_visitor(SELECTION_STATEMENT *sel){

#ifdef COMPILER_DEBUG
	printf("SELECTION STATEMENT VISITOR -> not implemented\n");

#endif

	int return_type = EXPRESSION_visitor(sel->expression);

	if(return_type != INT){
		printf("Warning: if expression don't produce an integer result\n");
	}

	char *if_label = cg_if_start();

	select_action((DEFAULT_NODE*) sel->statement);


	if(sel->statement2 != NULL){

		char *else_label = cg_if_end_start_else(if_label);

		select_action((DEFAULT_NODE*)sel->statement2);

		cg_else_end(else_label);

	} else {

		cg_if_end(if_label);
	}
	//sel->

	return 0;
}
/**
 *
 * This function handles while and do-while iteration
 * statements.
 *
 */


int ITERATION_STATEMENT_visitor(ITERATION_STATEMENT *it){

#ifdef COMPILER_DEBUG
	printf("ITERATION STATEMENT VISITOR\n");
#endif

	int result_type;



	if(it->subtype == WHILE){
#ifdef COMPILER_DEBUG
	printf("WHILE\n");
#endif
	char *start = cg_while_start();

	//char *start1 = cg_while_start();
	//char *end1 = cg_while_end_expression(start1);
	//cg_while_end(start1, end1);

	result_type = EXPRESSION_visitor(it->expression);
	//puts("qqqqqq");
	if(result_type != INT){

		//printf("Iteration Expression must produce a INT result \n");
		iteration_type_incompatibility(0, result_type);
		//exit(1);
		error_indicator = 1;
	}
	char *end = cg_while_end_expression(start);


	select_action((DEFAULT_NODE*)it->statement);

	cg_while_end(start, end);


	} else if(it->subtype == (DO+WHILE)){
#ifdef COMPILER_DEBUG
	printf("DO WHILE\n");
#endif
	}

	return 0;
}

int STATEMENT5_visitor(STATEMENT5 *st){

#ifdef COMPILER_DEBUG
	printf("FUNCTION DEFINITION STATEMENT VISITOR -> not implemented\n");

#endif

	return 0;
}

int STATEMENT6_visitor(STATEMENT6 *st){

	ITERATION_STATEMENT_visitor(st->iteration_statement);

	return 0;
}

/**
 *
 * Expressions like while, if and argument expressions
 *
 */

int EXPRESSION_visitor(EXPRESSION *ex){

	int result = 0, result2;
	if(ex->expression != NULL){

		result = EXPRESSION_visitor(ex->expression);
	}

//	puts("????");
	result2 = select_action((DEFAULT_NODE*) ex->assignment_expression);

	if(result != 0){

		if(result != result2){
			//printf("Abort, type incompatibility\n");
			type_incompatibility(0, result, result2);
			error_indicator = 1;
		}
	}

	//puts("teste");
	return result2;
	//return INT;
}

/**
 *
 * The functions bellow handles all types of function expressions
 *
 *
 */


int ASSIGNMENT_EXPRESSION1_visitor(ASSIGNMENT_EXPRESSION1 *ex){
#ifdef COMPILER_DEBUG
	printf("ASSIGNMENT_EXPRESSION1_visitor\n");
#endif
	// for type verification
	return CONDITIONAL_EXPRESSION_visitor(ex->conditional_expression);

}



int CONDITIONAL_EXPRESSION_visitor(CONDITIONAL_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("CONDITIONAL_EXPRESSION_visitor\n");
#endif

	return LOGICAL_OR_EXPRESSION_visitor(ex->logical_or_expression);
}

int LOGICAL_OR_EXPRESSION_visitor(LOGICAL_OR_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("LOGICAL_OR_EXPRESSION_visitor\n");
#endif

	int or_type = 0, and_type = 0;

	if(ex->logical_or_expression != NULL){
		or_type = LOGICAL_OR_EXPRESSION_visitor(ex->logical_or_expression);
	}

    and_type = LOGICAL_AND_EXPRESSION_visitor(ex->logical_and_expression);
//    puts("++++++");

    if(or_type != 0){

    	if(or_type != and_type){
    		//printf("Abort, type incompatibility\n");
    		//puts("aqui");
    		type_incompatibility(0, or_type, and_type);
    		//exit(1);
    		error_indicator = 1;
    	}
    }

	if(ex->logical_or_expression != NULL){
		cg_stack_logical(OR_OP, and_type);
	}


    return and_type;
}

int LOGICAL_AND_EXPRESSION_visitor(LOGICAL_AND_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("LOGICAL_AND_EXPRESSION_visitor\n");
#endif


	int or_type = 0, and_type = 0;

	if(ex->logical_and_expression != NULL){
		or_type = LOGICAL_AND_EXPRESSION_visitor(ex->logical_and_expression);
	}

    and_type = INCLUSIVE_OR_EXPRESSION_visitor(ex->inclusive_or_expression);
//    puts("%%%%");

    if(or_type != 0){

    	if(or_type != and_type){
    		//printf("Abort, type incompatibility\n");
    		type_incompatibility(0, or_type, and_type);
    		//exit(1);
    		error_indicator = 1;
    	}
    }

	if(ex->logical_and_expression != NULL){
		cg_stack_logical(AND_OP, and_type);
	}

    return and_type;
    //return INT;

}

int INCLUSIVE_OR_EXPRESSION_visitor(INCLUSIVE_OR_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("INCLUSIVE_OR_EXPRESSION_visitor\n");
#endif


	int inclusive_or_type = 0, exclusive_or_type = 0;

	if(ex->inclusive_or_expression != NULL){
		inclusive_or_type = INCLUSIVE_OR_EXPRESSION_visitor(ex->inclusive_or_expression);
	}

	exclusive_or_type = EXCLUSIVE_OR_EXPRESSION_visitor(ex->exclusive_or_expression);
	//puts("@@@@");

    if(inclusive_or_type != 0){

    	if(inclusive_or_type != exclusive_or_type){
    		//printf("Abort, type incompatibility\n");
    		type_incompatibility(0, inclusive_or_type, exclusive_or_type);
    		//exit(1);
    		error_indicator = 1;
    	}
    }

	if(ex->inclusive_or_expression != NULL){
		cg_stack_logical('|', exclusive_or_type);
	}

    return exclusive_or_type;

}

int EXCLUSIVE_OR_EXPRESSION_visitor(EXCLUSIVE_OR_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("EXCLUSIVE_OR_EXPRESSION_visitor\n");
#endif

	int or_type = 0, and_type = 0;

	if(ex->exclusive_or_expression != NULL){
		or_type = EXCLUSIVE_OR_EXPRESSION_visitor(ex->exclusive_or_expression);
	}

    and_type = AND_EXPRESSION_visitor(ex->and_expression);

    //cg_stack_logical('^', get_type_size(and_type));

    //puts("$$$");
    if(or_type != 0){

    	if(or_type != and_type){
    		//printf("Abort, type incompatibility\n");
    		type_incompatibility(0, or_type, and_type);
    		//exit(1);
    		error_indicator = 1;
    	}
    }

	if(ex->exclusive_or_expression != NULL){
		cg_stack_logical('^', and_type);
	}

   return and_type;
    //return INT;

}

int AND_EXPRESSION_visitor(AND_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("AND_EXPRESSION_visitor\n");
#endif

	int and_type = 0, eq_type = 0;

	if(ex->and_expression != NULL){
		and_type = AND_EXPRESSION_visitor(ex->and_expression);
	}

    eq_type = EQUALITY_EXPRESSION_visitor(ex->equality_expression);
   // puts("=======");
    if(and_type != 0){

    	if(and_type != eq_type){
    		//printf("Abort, type incompatibility\n");
    		type_incompatibility(0, and_type, eq_type);
    		//exit(1);
    		error_indicator = 1;
    	}
    }
    //puts("=====================");
	if(ex->and_expression != NULL){
		cg_stack_logical('&', eq_type);
	}

   return eq_type;
   //return INT;
}

int EQUALITY_EXPRESSION_visitor(EQUALITY_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("EQUALITY_EXPRESSION_visitor\n");
#endif

	int eq_type = 0, rel_type;

	if(ex->equality_expression != NULL){
		eq_type = EQUALITY_EXPRESSION_visitor(ex->equality_expression);
	}

	rel_type = RELATIONAL_EXPRESSION_visitor(ex->relational_expression);

	// here we have a relational expression alone
	if(ex->op == 0){

#ifdef COMPILER_DEBUG
	printf("EQUALITY_EXPRESSION operator zero\n");
#endif
		//return the result type of the expression
		// code gen here
		return rel_type;
		//return INT;
	} /*not equal*/else if(ex->op == NE_OP){
#ifdef COMPILER_DEBUG
	printf("EQUALITY_EXPRESSION operator NE_OP\n");
#endif
	// code gen here
	cg_stack_relational(NE_OP, rel_type);

	} /*equal operator*/else if(ex->op == EQ_OP){
#ifdef COMPILER_DEBUG
	printf("EQUALITY_EXPRESSION operator EQ_OP\n");
#endif
	// code gen here
	cg_stack_relational(EQ_OP, rel_type);

	} else {
		printf("BUG, invalid operator on equality expression\n");
		exit(1);
	}

	   if(eq_type != 0){

	    	if(eq_type != rel_type){
	    		//printf("Abort, type incompatibility\n");
	    		type_incompatibility(0, eq_type, rel_type);
	    		//exit(1);
	    		error_indicator = 1;
	    	}
	    }

	   return rel_type;
	   //return INT;
}

int RELATIONAL_EXPRESSION_visitor(RELATIONAL_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("RELATIONAL_EXPRESSION_visitor\n");
#endif

	int rel_type = 0, shift_type = 0;

	if(ex->relational_expression != NULL){

		rel_type= RELATIONAL_EXPRESSION_visitor(ex->relational_expression);
	}

	shift_type = SHIFT_EXPRESSION_visitor(ex->shift_expression);

	if(ex->op == 0){
#ifdef COMPILER_DEBUG
	printf("RELATIONAL_EXPRESSION operator zero\n");
#endif



	} else if(ex->op == '<'){
#ifdef COMPILER_DEBUG
	printf("RELATIONAL_EXPRESSION operator <\n");
#endif

	cg_stack_relational('<', shift_type);


	} else if(ex->op == '>'){
#ifdef COMPILER_DEBUG
	printf("RELATIONAL_EXPRESSION operator >\n");
#endif

	cg_stack_relational('>', shift_type);


	} else if(ex->op == LE_OP){
#ifdef COMPILER_DEBUG
	printf("RELATIONAL_EXPRESSION operator LE_OP\n");
#endif

	cg_stack_relational(LE_OP, shift_type);

	}
	else if(ex->op == GE_OP){
#ifdef COMPILER_DEBUG
	printf("RELATIONAL_EXPRESSION operator GE_OP\n");
#endif

	cg_stack_relational(GE_OP, shift_type);

	}else {
		printf("BUG, invalid operator on relational expression\n");
		exit(1);

	}

	 if(rel_type != 0){
	    if(rel_type != shift_type){
	    	//printf("Abort, type incompatibility\n");
	    	type_incompatibility(0, get_type_size(shift_type), get_type_name(rel_type));
	    	//exit(1);
	    	error_indicator = 1;
	    }
	 }

	  return shift_type;

}

int SHIFT_EXPRESSION_visitor(SHIFT_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("SHIFT_EXPRESSION_visitor\n");
#endif

		int shift_type =0, add_type;

		if(ex->shift_expression != NULL){

			shift_type = SHIFT_EXPRESSION_visitor(ex->shift_expression);
		}

		add_type = ADDITIVE_EXPRESSION_visitor(ex->additive_expression);

		switch(ex->op){
			case 0:

				break;

			case LEFT_OP:

				break;

			case RIGHT_OP:

				break;
		}

		if(shift_type != 0){
			if(shift_type != add_type){
		    	//printf("Abort, type incompatibility\n");
				type_incompatibility(0, shift_type, add_type);
		    	//exit(1);
		    	error_indicator = 1;
			}
		}
		return add_type;
}

int ADDITIVE_EXPRESSION_visitor(ADDITIVE_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf(" ADDITIVE_EXPRESSION_visitor\n");
#endif

	int add_type = 0, mult_type;

	if(ex->additive_expression != NULL){
		add_type = ADDITIVE_EXPRESSION_visitor(ex->additive_expression);
	}

	mult_type = MULTIPLICATIVE_EXPRESSION_visitor(ex->multiplicative_expression);

	switch(ex->op){
		case 0:

			/*nothing to do*/

			break;
		case '+':

			//cg_stack_add32();
			cg_stack_aritmetical('+', 4);

			break;

		case '-':

			cg_stack_aritmetical('-', 4);

			break;
	}

	if((add_type != 0) && (add_type != mult_type)){
    	//printf("Abort, type incompatibility\n");
		type_incompatibility(0, add_type, mult_type);
    	//exit(1);
    	error_indicator = 1;
	}

	return mult_type;
}

int MULTIPLICATIVE_EXPRESSION_visitor(MULTIPLICATIVE_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("MULTIPLICATIVE_EXPRESSION_visitor\n");
#endif

	int mult_type = 0, unary_type;

	if(ex->multiplicative_expression != NULL){
		mult_type = MULTIPLICATIVE_EXPRESSION_visitor(ex->multiplicative_expression);
	}

	unary_type = UNARY_EXPRESSION_visitor(ex->unary_expression);

	switch(ex->op){
		case 0:

			break;
		case '*':
			//puts("---------------------------------");
			cg_stack_aritmetical('*', unary_type);

			break;
		case '/':
			cg_stack_aritmetical('/', unary_type);

			break;
		case '%':

			break;
	}
	if((mult_type != 0) && (mult_type != unary_type)){
	  	//printf("Abort, type incompatibility\n");
		type_incompatibility(0, mult_type, unary_type);
	    //exit(1);
	  	error_indicator = 1;
	}

	return unary_type;
}

int UNARY_EXPRESSION_visitor(UNARY_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("UNARY_EXPRESSION_visitor\n");
#endif

	int unary_type = 0, other_type;
	UNARY_EXPRESSION1 *ex1;
	UNARY_EXPRESSION2 *ex2;
	UNARY_EXPRESSION3 *ex3;
	UNARY_EXPRESSION4 *ex4;

	switch(ex->subtype){
		/*postfix_expression*/
		case UNARY_EXPRESSION1_CODE:
			ex1 = (UNARY_EXPRESSION1*) ex;

			return POSTFIX_EXPRESSION_visitor(ex1->postfix_expression);

			break;
		/*unary_operator unary_expression*/
		case UNARY_EXPRESSION2_CODE:
			ex2 = (UNARY_EXPRESSION2*) ex;

			unary_type = UNARY_EXPRESSION_visitor(ex2->unary_expression);
			switch(ex2->unary_operator->op){
			/**
			 * This operator gives a var reference
			 *
			 */
				case '&':
				{
					//puts("unary1");
					if(ex2->unary_expression->subtype ==
						UNARY_EXPRESSION1_CODE){
						UNARY_EXPRESSION1 *uex1 =
							(UNARY_EXPRESSION1*) ex2->unary_expression;

						if(uex1->postfix_expression->subtype ==
							POSTFIX_ESPRESSION1_CODE){
							POSTFIX_ESPRESSION1 *post1 =
								(POSTFIX_ESPRESSION1*) uex1->postfix_expression;
							if(post1->primary_expression->subtype ==
									PRIMARY_EXPRESSION1_CODE){
								PRIMARY_EXPRESSION1 *priex1 = (PRIMARY_EXPRESSION1*)
									post1->primary_expression;

								SYMBOL *symb = symbol_table_get(priex1->identifier);
								if(symb != NULL){
									cg_push_var_pointer(symb->offset);

								} else {
									error_indicator = 1;
									printf("Compiler error: Undeclared symbol %s\n", priex1->identifier);
								}

							} else{
								error_indicator = 1;
								printf("Compiler error: Invalid use of reference operator & \n");
							}

						}else{
							error_indicator = 1;
							printf("Compiler error: Invalid use of reference operator & \n");
						}

					}else{
						error_indicator = 1;
						printf("Compiler error: Invalid use of reference operator & \n");
					}


				}

					break;
				case '*':



					break;
				case '+':



					break;
				case '-':
				{
					//cg_push_int(-1);
					//int ret = UNARY_EXPRESSION_visitor(ex2->unary_expression);
					cg_stack_neg(unary_type);
					//cg_stack_aritmetical('*', ret);
					//puts("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
					//return ret;
					return unary_type;

				}

				case '~':



					break;
				case '!':


					break;

				return unary_type;
			}


			break;
		/*SIZEOF unary_expression*/
		case UNARY_EXPRESSION3_CODE:
			ex3 = (UNARY_EXPRESSION3*) ex;
			unary_type = UNARY_EXPRESSION_visitor(ex3->unary_expression);

			return unary_type;
			break;
		/* SIZEOF '(' type_name ')'*/
		/*actually is not implemented*/
		case UNARY_EXPRESSION4_CODE:
			ex4 = (UNARY_EXPRESSION4*) ex;

			/*
			switch(ex4->type_name->){
				case INT:

					break;
				case FLOAT:

					break
				case CHAR:

					break;
			}
			*/

			return INT;
			break;
	}
	return 0;
}

int POSTFIX_EXPRESSION_visitor(POSTFIX_ESPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("POSTFIX_EXPRESSION_visitor\n");
#endif

	POSTFIX_ESPRESSION1 *ex1;
	POSTFIX_ESPRESSION4 *ex4;
	POSTFIX_ESPRESSION4 *ex2;

	switch(ex->subtype){
		case POSTFIX_ESPRESSION1_CODE:
			ex1 = (POSTFIX_ESPRESSION1*) ex;

			//puts("aqui");
			return PRIMARY_EXPRESSION_visitor(ex1->primary_expression);

			break;

		case POSTFIX_ESPRESSION4_CODE:
			ex4 = (POSTFIX_ESPRESSION4*) ex;
			//puts("here");
			POSTFIX_ESPRESSION4_visitor(ex4);

			break;

		case POSTFIX_ESPRESSION2_CODE:
			ex2 = (POSTFIX_ESPRESSION2*) ex;
			//puts("here");
			POSTFIX_ESPRESSION2_visitor(ex2);

			break;
	}

}
/**
 *
 * Primary expressions handles identifiers, constants
 * and literals.
 *
 */

int PRIMARY_EXPRESSION_visitor(PRIMARY_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("PRIMARY_EXPRESSION_visitor\n");
#endif

	PRIMARY_EXPRESSION1 *ex1;
	PRIMARY_EXPRESSION2 *ex2;
	PRIMARY_EXPRESSION3 *ex3;
	PRIMARY_EXPRESSION4 *ex4;
	char * id;
	SYMBOL *smb;
	//puts("aqui1");

	switch(ex->subtype){
		case PRIMARY_EXPRESSION1_CODE:
			ex1 = (PRIMARY_EXPRESSION1*) ex;

			id = ex1->identifier;
			smb = symbol_table_get(id);
			if(smb == NULL){
				printf("Undeclared Symbol %s\n", id);
				//exit(1);
				error_indicator = 1;

			} else {

				if(smb->localization == LOCAL_VAR){
					cg_push_local_var(smb->offset, 4);
						if(smb->val_initialized == 0){
							error_indicator = 1;
							printf("Not initialized variable %s\n", smb->symbol_name);
						}
						//puts("ttttttttttttttttttttttttttttttttttttttttttt");
					return smb->var_type;
				} else if(smb->localization == GLOBAL_VAR){

					cg_push_var_mem_pointer(smb->symbol_name, smb->var_type);


				}


			}
			//puts(id);


			break;
		case PRIMARY_EXPRESSION2_CODE:
			ex2 = (PRIMARY_EXPRESSION2*) ex;
			//printf("=> %d\n", ex2->constant);
			if(ex2->constant < 128 && ex2->constant >= -128){
				cg_push_char(ex2->constant);
				//puts("teeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
				//printf("%d\n", ex2->constant);
				return INT;
			}
			cg_push_int(ex2->constant);

			return INT;
			//return ex2->
			break;
		case PRIMARY_EXPRESSION3_CODE:
			//puts("aqui");
			ex3 = (PRIMARY_EXPRESSION3*) ex;
			//ex3->string_literal;
			cg_insert_strl(ex3->string_literal);

			//puts(ex3->string_literal);
			return STRING_LITERAL;
			break;
		case PRIMARY_EXPRESSION4_CODE:
			ex4 = (PRIMARY_EXPRESSION4*) ex;
			return EXPRESSION_visitor(ex4->expression);
			puts("here4");
			break;
	}
}

int CONSTANT_EXPRESSION_visitor(CONSTANT_EXPRESSION *ex){
#ifdef COMPILER_DEBUG
	printf("CONSTANT_EXPRESSION_visitor\n");
#endif
	//puts("Constant");

	return INT;
}
/**
 *
 * Not suported on this compiler
 *
 */

int EXTERNAL_DECLARATION_visitor(EXTERNAL_DECLARATION *dcl){


	//switch(dcl->subtype){

	//}
	//puts("teste");
	//cg_declare_global_variable_string("my_str", "the string");

	return 0;
}
/**
 *
 * This function do the semantic analysis of statements
 * like var = expression
 *
 */

int ASSIGNMENT_EXPRESSION2_visitor(ASSIGNMENT_EXPRESSION2 *ex){
#ifdef COMPILER_DEBUG
	printf("ASSIGNMENT_EXPRESSION2_visitor\n");
#endif
	/*must satisfy these conditions*/
	if(ex->unary_expression->subtype  == UNARY_EXPRESSION1_CODE){
		UNARY_EXPRESSION1 *ex1 = (UNARY_EXPRESSION1*) ex->unary_expression;

		if(ex1->postfix_expression->subtype == POSTFIX_ESPRESSION1_CODE){
			POSTFIX_ESPRESSION1 *poex = (POSTFIX_ESPRESSION1*) ex1->postfix_expression;

			if(poex->primary_expression->subtype == PRIMARY_EXPRESSION1_CODE){

					PRIMARY_EXPRESSION1 *priex =
						(PRIMARY_EXPRESSION1*) poex->primary_expression;
					SYMBOL *symb = symbol_table_get(priex->identifier);

					if(symb != NULL){
						int ret = select_action((DEFAULT_NODE*)ex->assignment_expression);
						/*type verification*/


						if(ret != symb->var_type){

							error_indicator = 1;
							type_incompatibility(0, symb->var_type, ret);
						}
						/*select the operator*/
						switch(ex->assignment_operator->op){
						case '=':
							cg_insert_comment("= operation (var = exp)");
							//cg_
							if(symb->localization == LOCAL_VAR){
								cg_pop_local_var(symb->offset,
										get_type_size(symb->var_type));

							} else {
								//cg_push_var_mem_pointer(symb->symbol_name, symb->var_type);
								cg_push_mem_pointer(symb->symbol_name);
								cg_store_pointer(symb->var_type);
							}

							break;
						case ADD_ASSIGN:

							if(symb->val_initialized == 0){
								error_indicator = 1;
								printf("Not initialized var %s\n", symb->symbol_name);
							}

							cg_insert_comment("+= operation");
							/*push var*/
							cg_push_local_var(symb->offset,
									get_type_size(symb->var_type));

							/*add the expression*/
							cg_stack_aritmetical('+', get_type_size(symb->var_type));


							/*pop the result on variable*/
							cg_pop_local_var(symb->offset,
									get_type_size(symb->var_type));
							break;

						case SUB_ASSIGN:

							if(symb->val_initialized == 0){
									error_indicator = 1;
									printf("Not initialized var %s\n", symb->symbol_name);
							}

							cg_insert_comment("-= operation");
							/*push var*/
							cg_push_local_var(symb->offset,
									get_type_size(symb->var_type));

							/*add the expression*/
							cg_stack_aritmetical('-', get_type_size(symb->var_type));


							/*pop the result on variable*/
							cg_pop_local_var(symb->offset,
									get_type_size(symb->var_type));
							break;
						default:
							error_indicator = 1;
							printf("Assign operator %c not implemented yet\n",
									ex->assignment_operator->op);
						}

						symb->val_initialized = 1;

					} else {
						error_indicator = 1;
						printf("Undeclared symbol %s \n", priex->identifier);
					}
			}
		/**
		 *
		 * Assign some value to an array position
		 *
		 *
		 */
		} else if (ex1->postfix_expression->subtype == POSTFIX_ESPRESSION2_CODE){

			POSTFIX_ESPRESSION2 *poex1 =
				(POSTFIX_ESPRESSION2*) ex1->postfix_expression;

			/*constinuar*/
			//printf("AAAAAAQQQQQQUUUUUUUIIIIIIII>>>>>>>>>>\n");

			int ret1 = select_action((DEFAULT_NODE*)ex->assignment_expression);

			POSTFIX_ESPRESSION1 *poex = (POSTFIX_ESPRESSION1*) poex1->postfix_expression;

			if(poex->primary_expression->subtype == PRIMARY_EXPRESSION1_CODE){
				PRIMARY_EXPRESSION1 *priex =
							(PRIMARY_EXPRESSION1*) poex->primary_expression;
						SYMBOL *symb = symbol_table_get(priex->identifier);

						if(symb != NULL){
							if(ret1 != symb->var_type){
								error_indicator = 1;
								type_incompatibility(0, symb->var_type, ret1);
							}


							cg_insert_comment("array index");
							//int ret = select_action((DEFAULT_NODE*)poex1->expression);
							int ret = EXPRESSION_visitor(poex1->expression);

							/*type verification*/
							if(ret != symb->var_type){
								error_indicator = 1;
								type_incompatibility(0, symb->var_type, ret);
							}
							/*select the operator*/
							switch(ex->assignment_operator->op){
							case '=':
								cg_insert_comment("= operation (var[] = exp)");
								//cg_

								cg_push_int(get_type_size(symb->var_type));
								cg_insert_comment("= operation (var[] = exp) ------");
								cg_stack_aritmetical('*', INT);
								cg_insert_comment("load var position");
								cg_push_var_pointer(symb->offset);
								cg_stack_aritmetical('+', INT);
								cg_insert_comment("load pointer");
								//cg_load_pointer(INT);
								cg_store_pointer(symb->var_type);

								break;
							default:
								error_indicator = 1;
								printf("Assign operator %c not implemented yet\n",
										ex->assignment_operator->op);
							}

							symb->val_initialized = 1;

						} else {
							error_indicator = 1;
							printf("Undeclared symbol %s \n", priex->identifier);
						}
				}

		}
	}
	//ex->unary_expression->

}


int POSTFIX_ESPRESSION4_visitor(POSTFIX_ESPRESSION4 *ex){

	SYMBOL *sym = NULL;

	if(ex->postfix_expression->subtype == POSTFIX_ESPRESSION1_CODE){
		POSTFIX_ESPRESSION1 *ex1 = ex->postfix_expression;
		if(ex1->primary_expression->subtype == PRIMARY_EXPRESSION1_CODE){

			PRIMARY_EXPRESSION1 *p = ex1->primary_expression;
			char *func = p->identifier;
			int built_in_ret = builtin_function(func, ex->argument_expression_list);

			if(built_in_ret){

				return built_in_ret;
			}


			sym = symbol_table_get(func);

			if(sym == NULL){
				error_indicator = 1;
				printf("Error, calling ghost function %s\n", func);

			} else{

				/*push parameters on stack*/
				ARGUMENT_EXPRESSION_LIST *ar = ex->argument_expression_list;

				int to_pop = mach_params(sym->function_params, ar);

				/*call func*/
				cg_function_call(func,
						to_pop,
						is_return_type(sym->function_return_type),
						get_type_size(sym->function_return_type));

				/*pop the stacked parameters*/
				//cg_insert_comment("remove the parameters which are on stack (caller must remove)");
				//cg_pop(to_pop);

				//printf("RETURNNNNNNNN %d\n", sym->function_return_type);
				return sym->function_return_type;

			}
		} else {
			error_indicator = 1;
			puts("Invalid fcall");
		}
	} else {
		error_indicator = 1;
		puts("Invalid fcall");
	}

	if(sym != NULL){
		return sym->function_return_type;
	} else {
		return 0;
	}
}

int EXPRESSION_STATEMENT_visitor(EXPRESSION_STATEMENT *ex){

	//puts("aqui");
	if(ex->expression != NULL){

		int stack = EXPRESSION_visitor(ex->expression);

		/*new version*/
		if(stack != VOID){
			cg_pop(get_type_size(stack));
		}

	}
}

/**
 *
 * Makes the parameter/formal parameter matching
 * for function calls.
 *
 */


int mach_params(PARAMETER_TYPE_LIST *ptl, ARGUMENT_EXPRESSION_LIST *arg){

	PARAMETER_LIST *pl = ptl->parameter_list;
	int params = 0;

	if((pl == NULL) & (arg != NULL)){
			error_indicator = 1;
			printf("Parameter Match error on function call 2\n");
		}
		if((pl != NULL) & (arg == NULL)){
			error_indicator = 1;
			printf("Parameter Match error on function call 2\n");
		}

	while((pl != NULL) & (arg != NULL) ){

		//puts("aqui+++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		/*very simple comparation*/
		PARAMETER_DECLARATION1 *p = (PARAMETER_DECLARATION1*)
			pl->parameter_declaration;
		ASSIGNMENT_EXPRESSION1 *a = arg->assignment_expression;


		int type1 = p->declaration_specifiers->type_specifier->datatype;
		int type2 = CONDITIONAL_EXPRESSION_visitor(a->conditional_expression);


		/*for pop the stack later*/
		//if(type1 == INT){
		//	params += 4;
		//} else if(type1 == CHAR){
		//	params += 1;
		//}  else if(type1 == FLOAT){
		//	params += 4;
		//}
		params += get_type_size(type1);

		if(type1 != type2){
			error_indicator = 1;
			printf("Parameter Match error on function call 1\n");
		}
		pl = pl->parameter_list;
		arg = arg->argument_expression_list;

		if((pl == NULL) & (arg != NULL)){
			error_indicator = 1;
			printf("Parameter Match error on function call 2\n");
		}
		if((pl != NULL) & (arg == NULL)){
			error_indicator = 1;
			printf("Parameter Match error on function call 2\n");
		}
	}
	return params;
}

/*
 *
 * Create Symbol table entries for the parameters of
 * a function and allocate space on code generation
 *
 */


int PARAMETER_LIST_visitor(PARAMETER_LIST * pl){

	PARAMETER_DECLARATION1 *pd1;
	PARAMETER_DECLARATION2 *pd2;
	PARAMETER_DECLARATION3 *pd3;

	int offsets = 8;

	while(pl != NULL){

		SYMBOL *symb;

		switch(pl->parameter_declaration->subtype){

			case PARAMETER_DECLARATION1_CODE:
				pd1 = pl->parameter_declaration;
				symb = malloc(sizeof(SYMBOL));

				symb->localization= LOCAL_VAR;
				symb->var_type = pd1->declaration_specifiers->type_specifier->datatype;

				symb->offset = offsets;

				//if(symb->var_type == INT){
				//	offsets += 4;
				//} else if(symb->var_type == CHAR){
				//	offsets += 1;
				//}
				offsets += get_type_size(symb->var_type);

				symb->symbol_name = ((DIRECT_DECLARATOR1*)pd1->
						declarator->direct_declarator)->identifier;

				symb->val_initialized = 1;

				symbol_table_insert(symb);

				break;

		}
		pl = pl->parameter_list;
	}
}
/**
 *
 * Return in byte, the length of a var type
 * (storage size)
 *
 */

int get_type_size(int type){

	switch(type){
	case INT:
		return 4;
	case CHAR:
		return 1;
	case FLOAT:
		return 4;
	case SHORT:
		return 2;
	case STRING_LITERAL:
		return 4;
	}

}

/**
 *
 * Verify if the especified type is "void"
 *
 */

int is_return_type(int type){

	if(type == VOID){
		return 0;
	}
	return 1;
}
/**
 *
 * Implements compiler built-in functions
 * like puts
 *
 *
 */
int builtin_function(char *func, ARGUMENT_EXPRESSION_LIST * args){

	/**
	 *
	 * Symply puts a string on terminal.
	 *
	 *
	 */
	if(strcmp("puts", func) == 0){
		//puts("puts");
		if(args->argument_expression_list != NULL){
			error_indicator = 1;
			printf("To much arguments to puts function\n");
		}
		if(args->assignment_expression->subtype != ASSIGNMENT_EXPRESSION1_CODE){
			error_indicator = 1;
			printf("Invalid puts parameter\n");
		} else {
				int returned =
					ASSIGNMENT_EXPRESSION1_visitor((ASSIGNMENT_EXPRESSION1*)args->assignment_expression);
				if(returned != STRING_LITERAL){
					//error_indicator = 1;
					printf("Warning: call puts with no strinng literal type argument\n");
				}

				cg_function_call("puts", 4, 1, 4);
			}

			return INT;

		/**
		 *
		 * This is the best known function of c: printf
		 *
		 */

		} else if(strcmp("printf", func) == 0){
			if(args->assignment_expression->subtype != ASSIGNMENT_EXPRESSION1_CODE){
				error_indicator = 1;
				printf("Invalid printf parameter\n");
			} else {
					int returned =
						ASSIGNMENT_EXPRESSION1_visitor((ASSIGNMENT_EXPRESSION1*)args->assignment_expression);
					//if(returned != STRING_LITERAL){
						//error_indicator = 1;
					//	printf("Warning: call printf with no strinng literal type argument\n");
					//}
					args = args->argument_expression_list;
					/*guard*/
					int param_reclaim_size = 4;
					while(args != NULL){
						int ret = ASSIGNMENT_EXPRESSION1_visitor(
								(ASSIGNMENT_EXPRESSION1*)args->assignment_expression);
						ret += get_type_size(ret);
						args = args->argument_expression_list;
					}

					cg_function_call("printf", 4, 1, param_reclaim_size);
				}

				return INT;
		/**
		 *
		 * This implements scanf for data input
		 *
		 */
		} else if(strcmp("scanf", func) == 0){
			if(args->assignment_expression->subtype != ASSIGNMENT_EXPRESSION1_CODE){
				error_indicator = 1;
				printf("Invalid scanf parameter\n");
			} else {
				int param_reclaim_size = 4;
				while(args != NULL){
						int ret = ASSIGNMENT_EXPRESSION1_visitor(
									(ASSIGNMENT_EXPRESSION1*)args->assignment_expression);
						ret += get_type_size(ret);
						args = args->argument_expression_list;
						}

						cg_function_call("scanf", 4, 1, param_reclaim_size);
			}


			return INT;
		}

	return 0;

}


int JUMP_STATEMENT_visitor(JUMP_STATEMENT *jmp){

	switch(jmp->jump){
	case RETURN:
		{
			if(jmp->expression != NULL){
				int ret = EXPRESSION_visitor(jmp->expression);
				cg_return(ret);
			} else{
				cg_return(VOID);
			}
		}

	}
}

int POSTFIX_ESPRESSION2_visitor(POSTFIX_ESPRESSION2 *ex){

	if(ex->expression == NULL){
		error_indicator = 1;
		printf("Compiler error: empty array access expression\n");
	} else {
		int ret = EXPRESSION_visitor(ex->expression);

		if(ret != INT){
			printf("Compiler warning: array access expression is no returning int\n");
		}
		if(ex->postfix_expression->subtype != POSTFIX_ESPRESSION1_CODE){
			error_indicator = 1;
			printf("Compiler error: malformed array access expression\n");
		} else {
			POSTFIX_ESPRESSION1 *pos1 = (POSTFIX_ESPRESSION1*) ex->postfix_expression;

			if(pos1->primary_expression->subtype != PRIMARY_EXPRESSION1_CODE){
				error_indicator = 1;
				printf("Compiler error: malformed array access expression\n");
			} else {
				PRIMARY_EXPRESSION1 *pri =
					(PRIMARY_EXPRESSION1*) pos1->primary_expression;
				char *array_name = pri->identifier;

				SYMBOL *symb = symbol_table_get(array_name);
				if(symb == NULL){
					error_indicator = 1;
					printf("Compiler error: unknown array var\n");
				} else{
					cg_push_int(get_type_size(symb->var_type));
					cg_stack_aritmetical('*', INT);
					cg_push_var_pointer(symb->offset);
					cg_stack_aritmetical('+', INT);
					cg_load_pointer(symb->var_type);
				}
			}
		}
	}
}
