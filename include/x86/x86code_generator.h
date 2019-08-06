/*
 * x86code_genetator.h
 *
 *  Created on: 22/05/2009
 *      Author: andreu
 */

#ifndef X86CODE_GENETATOR_H_
#define X86CODE_GENETATOR_H_

#endif /* X86CODE_GENETATOR_H_ */

int init_cg(char *asm_file);

int cleanup_cg();

void cg_start_procedure(char *name);

void cg_end_procedure(char *name);

void cg_declare_global_variable(char *name, int init, int type);

void cg_declare_global_variable_string(char *name, char *string);

char *cg_while_start();
char *cg_while_end_expression(char *start);
void cg_while_end(char *start, char *end);


char *cg_if_start();
char *cg_if_end_start_else(char *label);
int cg_if_end(char *label);
int cg_else_end(char *label);
void cg_stack_aritmetical(int op, int size);
void cg_stack_relational(int op, int size);
void cg_stack_logical(int op, int size);
int cg_get_next_offset(int var_size);
int cg_get_offset();

void cg_push_local_var(int offset, int size);
void cg_store_local_var(int offset, int value, int size);

void cg_pop_local_var(int offset, int size);
void cg_function_call(char *label, int rescue, int must_ret, int ret_size);
void cg_insert_comment(char *c);

char *cg_insert_strl(char *str);

void cg_pop(int size);

void cg_push_int(int value);

void cg_push_var_pointer(int offset);

void cg_push_mem_pointer(char *test);

void cg_push_var_mem_pointer(char *test, int type);

void cg_return(int type);

void cg_load_pointer(int size);

void cg_store_pointer(int size);

void cg_stack_neg(int size);

void cg_push_char(int c);
