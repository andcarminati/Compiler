/*
 * code_gen.c
 *
 *  Created on: 05/03/2009
 *      Author: andreu
 */

#include "../../include/arch_instructions.h"
#include "../../include/x86/x86code_generator.h"
#include "../../include/compiler.h"
#include "../y.tab.h"
#include <math.h>

FILE *asm_io;
FILE *asm_io_data;
int stack_count = 0;
char while_str[] = ".STARTWHILE";
char start[] = "_start";
char while_end_str[] = ".ENDWHILE";
char hidden_vars[] = ".EVAR";
char if_label[] = ".ENDIF";
char else_label[] = ".ENDELSE";
char end_proc_label[] = ".END";

char *actual_end_proc;

int hidden_vars_count = 0;
int procedure_offset_count = -4;
int while_count = 0;
int while_end_count = 0;
int if_count = 0;
int else_count = 0;

fpos_t stack_offset_update;

void gen_end_proc_label(char *label){

	char *label2 = malloc(40);

	sprintf(label2, "%s%s", end_proc_label, label);


	actual_end_proc = label2;
}




char *gen_else_label(){

	char *label = malloc(20);
	char count[5];

	sprintf(count, "%d", else_count++);
	strcpy(label, else_label);
	strcat(label, count);

	return label;
}


char *gen_if_label(){

	char *label = malloc(20);
	char count[5];

	sprintf(count, "%d", if_count++);
	strcpy(label, if_label);
	strcat(label, count);

	return label;
}

char *gen_evar_name(){

	char *label = malloc(20);
	char count[5];

	sprintf(count, "%d", hidden_vars_count++);
	strcpy(label, hidden_vars);
	strcat(label, count);

	return label;
}

char *cg_insert_strl(char *str){

	char *label = gen_evar_name();
	/*.LC0:
        .string "testeteste"
        .text
	 * */
	//puts(str);
	fprintf(asm_io_data, ".data\n");
	fprintf(asm_io_data, "\n%s:\n", label);
	fprintf(asm_io_data, "\t.string %s\n", str);
	fprintf(asm_io_data, ".text\n");

	fprintf(asm_io, "\tpushl\t $%s\n", label);

	free(label);
}

int print_header(char *name){

	fprintf(asm_io, "/*C subset compiler*/\n");
	fprintf(asm_io, "/*x86 assembly output code*/\n");
	fprintf(asm_io, "/*File name %s*/\n", name);
	fprintf(asm_io, "\t.text\n");
}

int init_cg(char *asm_file){

	asm_io = fopen(asm_file, "w");
	asm_io_data = fopen("assemby_data.tmp", "w");


	if(asm_io == NULL){
		return -1;
	}

	print_header(asm_file);
}

int cleanup_cg(){

	char c;
	//rewind(asm_io_data);

	//fflush(asm_io_data);
	fclose(asm_io_data);
	asm_io_data = fopen("assemby_data.tmp", "r");

	while((c = fgetc(asm_io_data)) != EOF){
		fputc(c, asm_io);
	}


	cg_insert_comment("End of assembly output");
	fclose(asm_io);
	fclose(asm_io_data);
}

void cg_start_procedure(char *name){

	procedure_offset_count = -4;

	if(strcmp(name, "main") == 0){
		name = start;
		gen_end_proc_label(name);
		fprintf(asm_io, "\n\n/*start of procedure*/\n");
		fprintf(asm_io, ".globl %s\n\t.type   %s, @function\n", name, name);
		fprintf(asm_io, "%s:\n\n", name);
		/*fprintf(asm_io, "%s%s%s%s%s%s",
				"\tleal\t4(%esp), %ecx\n",
				"\tandl\t$-16, %esp\n",
				"\tpushl\t-4(%ecx)\n",
				"\tpushl\t%ebp\n",
				"\tmovl\t%esp, %ebp\n",
				"\tpushl\t%ecx\n");
		 */
		fprintf(asm_io, "%s%s%s",
						"\tpushl\t%ebp\n",
						"\tmovl\t%esp, %ebp\n",
						"\tpushl\t%ecx\n");


		/*for foward back update the esp*/
		fgetpos(asm_io, &stack_offset_update);

		fprintf(asm_io, "\tsubl\t$%d, %%esp\n\n", 36);


	} else {
		gen_end_proc_label(name);
		fprintf(asm_io, "\n\n/*start of procedure*/\n");
		fprintf(asm_io, ".globl %s\n\t.type   %s, @function\n", name, name);
		fprintf(asm_io, "%s:\n\n", name);
		fprintf(asm_io, "\tpushl\t%%ebp\n\tmovl\t%%esp, %%ebp\n");

		fgetpos(asm_io, &stack_offset_update);

		fprintf(asm_io, "\tsubl\t$%d, %%esp\n\n", 20);


	}



	return;
}

void cg_end_procedure(char *name){

	fpos_t actual_pos;
	int offset;

	if(strcmp(name, "main") == 0){
		name = start;
		offset = 36 + fabs(procedure_offset_count);

		fprintf(asm_io, "\taddl\t$%d, %%esp\n", offset);

		/*
		fprintf(asm_io, "\n\n%s%s%s%s%s\n\n",
			     "\tpopl\t%ecx\n",
			     "\tpopl\t%ebp\n",
			    // "\tleal\t-4(%ecx), %esp\n",
			    // "\tret");
			    "\tmovl\t$1, %eax\n",
			    "\tmovl\t$0, %ebx\n",
			    "\tint $0x80\n");
		*/

		fprintf(asm_io, "\n%s:\n", actual_end_proc);

		fprintf(asm_io, "\tmovl \t%%eax, %%ebx\n");



		fprintf(asm_io, "\n\n%s%s\n\n",
					    "\tmovl\t$1, %eax\n",
					    "\tint\t$0x80\n");



	} else {

		fprintf(asm_io, "\n%s:\n", actual_end_proc);

		fprintf(asm_io, "\tleave\n\tret\n");

		offset = 20 + fabs(procedure_offset_count);
	}

	/*we must update the esp*/
	fgetpos(asm_io, &actual_pos);
	fsetpos(asm_io, &stack_offset_update);

	fprintf(asm_io, "\tsubl\t$%d, %%esp\n\n", offset);

	fsetpos(asm_io, &actual_pos);

	fprintf(asm_io, "/*end of procedure*/\n");

	free(actual_end_proc);
}

void cg_declare_global_variable_string(char *name, char *string){


	fprintf(asm_io, "\n\n/*start of string declaration*/\n");
	fprintf(asm_io, ".globl %s\n", name);
	fprintf(asm_io, "\t.section	.rodata");
	fprintf(asm_io, "\t.type	%s\n", name);
	fprintf(asm_io, "\t.size	%s, %d\n", name, (strlen(string)+1));
	fprintf(asm_io, "%s:", name);
	fprintf(asm_io, "\t.string \"%s\"\n", string);
	fprintf(asm_io, "\t.text\n");
}

char *next_while_start(){

	char *label = malloc(20);
	char count[5];

	sprintf(count, "%d", while_count++);
	strcpy(label, while_str);
	strcat(label, count);

	return label;
}
char *next_while_end(){

	char *label = malloc(20);
	char count[5];

	sprintf(count, "%d", while_end_count++);
	strcpy(label, while_end_str);
	strcat(label, count);

	return label;
}

char *cg_while_start(){

	char *label = next_while_start();

	fprintf(asm_io, "\n\n/*while start*/");

	fprintf(asm_io, "\n\n%s:\n\n", label);

	return label;

}
char *cg_while_end_expression(char *start){

	char *label = next_while_end();

	fprintf(asm_io, "\taddl \t$4, %%esp\n");
	fprintf(asm_io, "\tcmpl \t$0, -4(%%esp)\n");
	fprintf(asm_io, "\tje \t%s\n\n", label);

	return label;


}

void cg_while_end(char *start, char *end){

	fprintf(asm_io, "\tjmp \t%s\n", start);
	fprintf(asm_io, "\n\n%s:\n", end);

	free(start);
	free(end);

	fprintf(asm_io, "/*while end*/\n\n");
}
void cg_push_char(int c){
	fprintf(asm_io, "\tpush \t$%d\n", c);
}

void cg_push_int(int value){

	fprintf(asm_io, "\tpush \t$%d\n", value);

	//fprintf(asm_io, "\tsubl \t$4, %%esp\n");
	//fprintf(asm_io, "\tmovl \t$%d, (%%esp)\n", value);
}

void cg_stack_aritmetical(int op, int size){


	if(op == '+'){

		fprintf(asm_io, "\tmovl \t(%%esp), %%edx\n");
		fprintf(asm_io, "\taddl \t$4, %%esp\n");
		fprintf(asm_io, "\taddl \t%%edx, (%%esp)\n");

	} else if (op == '-'){

		fprintf(asm_io, "\tmovl \t(%%esp), %%edx\n");
		fprintf(asm_io, "\taddl \t$4, %%esp\n");
		fprintf(asm_io, "\tsubl \t%%edx, (%%esp)\n");

	} else if (op == '&') {

		// implemented in another place

	} else if (op == '*'){
		//puts("---------------------------------");
		fprintf(asm_io, "\tmovl \t(%%esp), %%eax\n");
		fprintf(asm_io, "\taddl \t$4, %%esp\n");
		fprintf(asm_io, "\timull \t(%%esp)\n");
		fprintf(asm_io, "\tmovl \t%%eax, (%%esp)\n");

	} else if(op == '/'){

		fprintf(asm_io, "\tmovl \t-4(%%esp), %%eax\n");

		//fprintf(asm_io, "\taddl \t$4, %%esp\n");

		fprintf(asm_io, "\tsarl \t$31, %%edx\n");

		fprintf(asm_io, "\tidivl \t(%%esp)\n");

		fprintf(asm_io, "\taddl \t$4, %%esp\n");

		fprintf(asm_io, "\tmovl \t%%eax, (%%esp)\n");
	}


}


int cg_get_next_offset(int var_size){

	int offset = procedure_offset_count;

	procedure_offset_count -= var_size;

	return offset;
}
/*from local var to stack*/
void cg_push_local_var(int offset, int size){


	if(size == 4){
		//fprintf(asm_io, "\tsubl \t$4, %%esp\n");
		//fprintf(asm_io, "\tmovl %d(%%ebp), (%%esp)\n", offset);

		fprintf(asm_io, "\tpushl \t%d(%%ebp)\n", offset);

	} else if(size == 1){
		fprintf(asm_io, "\tsubb \t$4, %%esp\n");
		fprintf(asm_io, "\tmovb \t%d(%%ebp), (%%esp)\n", offset);
	}


}

void cg_store_local_var(int offset, int value, int size){

	if(size == 4){
		fprintf(asm_io, "\tmovl \t$%d, %d(%%ebp)\n", value, offset);
	} else if(size == 4){
		fprintf(asm_io, "\tmovb \t$%d, %d(%%ebp)\n", value, offset);
	}

}
/*from stack to local var*/
void cg_pop_local_var(int offset, int size){

	//fprintf(asm_io, "\tmovl (%%esp), %d(%%ebp)\n", offset);
	if(size == 4){
		//fprintf(asm_io, "\tsubl \t$4, %%esp\n");
		//fprintf(asm_io, "\tmovl %d(%%ebp), (%%esp)\n", offset);

		//fprintf(asm_io, "\tpopl \t%d(%%ebp)\n", offset);

		fprintf(asm_io, "\tmovl \t(%%esp), %%edx\n", offset);

		fprintf(asm_io, "\tmovl \t%%edx, %d(%%ebp)\n", offset);

	} else if(size == 1){
		//fprintf(asm_io, "\tsubb \t$4, %%esp\n");
		//fprintf(asm_io, "\tmovb %d(%%ebp), (%%esp)\n", offset);
		//fprintf(asm_io, "\tpopb \t%d(%%ebp)\n", offset);

		//fprintf(asm_io, "\tmovb \t(%%esp), %%edx\n", offset);
		fprintf(asm_io, "\tmovb \t(%%esp), %%dl\n", offset);

		//fprintf(asm_io, "\tmovb \t%%edx, %d(%%ebp)\n", offset);
		fprintf(asm_io, "\tmovb \t%%dl, %d(%%ebp)\n", offset);
	}
}

void cg_function_call(char *label, int rescue, int must_ret, int ret_size){

	cg_insert_comment("calling function");
	fprintf(asm_io, "\tcall \t%s\n", label);
	cg_pop(rescue);
	if(must_ret != VOID){
		switch(ret_size){
		case 4:
			cg_insert_comment("push the return of function (is in eax) on stack");
			fprintf(asm_io, "\tpushl \t%%eax\n");
			break;
		case 1:
			cg_insert_comment("push the return of function (is in eax) on stack");
			fprintf(asm_io, "\tpushl \t%%eax\n");
		}

	}
}


int cg_get_offset(){
	return procedure_offset_count;
}

void cg_pop(int size){
	fprintf(asm_io, "\taddl \t$%d, %%esp\n", size);
}

void cg_insert_comment(char *c){
	fprintf(asm_io, "//*%s*/\n", c);
}

char *cg_if_start(){

	char *label = gen_if_label();

	fprintf(asm_io, "\taddl \t$4, %%esp\n");
	fprintf(asm_io, "\tcmpl \t$0, -4(%%esp)\n");
	fprintf(asm_io, "\tje \t%s\n\n", label);


	return label;
}

char *cg_if_end_start_else(char *label){

	char *label_else = gen_else_label();

	fprintf(asm_io, "\tjmp \t%s\n", label_else);
	fprintf(asm_io, "\%s:\n", label);

	free(label);

	return label_else;
}

int cg_if_end(char *label){

	fprintf(asm_io, "\%s:\n", label);

	free(label);

}

int cg_else_end(char *label){

	fprintf(asm_io, "\%s:\n", label);

	free(label);
}

void cg_push_var_pointer(int offset){

	cg_insert_comment("pushing var reference");
	fprintf(asm_io, "\tpushl \t%%ebp\n");
	fprintf(asm_io, "\taddl \t$%d, (%%esp)\n", offset);
	//push
}


void cg_stack_relational(int op, int size){

	switch(size){
	case INT:
		//if((op == EQ_OP) ||  (op == NE_OP)){
		//	fprintf(asm_io, "\tpopl \t%%edx\n");
		//	fprintf(asm_io, "\ttestl \t%%edx, (%%esp)\n");
		//} else{
			fprintf(asm_io, "\tpopl \t%%edx\n");
			fprintf(asm_io, "\tcmpl \t%%edx, (%%esp)\n");
		//}

	}

	switch(op){

	/*equality*/
	case EQ_OP:

		fprintf(asm_io, "\tsete \t%%dl\n");
		fprintf(asm_io, "\tmovl \t%%edx, (%%esp)\n");
		break;

	case NE_OP:

		fprintf(asm_io, "\tsetne \t%%dl\n");
		fprintf(asm_io, "\tmovl \t%%edx, (%%esp)\n");
		break;


	/*relational_expression*/
	case '<':

		fprintf(asm_io, "\tsetl \t%%dl\n");
		fprintf(asm_io, "\tmovl \t%%edx, (%%esp)\n");
		break;



	case '>':

		fprintf(asm_io, "\tsetg \t%%dl\n");
		fprintf(asm_io, "\tmovl \t%%edx, (%%esp)\n");
		break;



	case LE_OP:

		fprintf(asm_io, "\tsetle \t%%dl\n");
		fprintf(asm_io, "\tmovl \t%%edx, (%%esp)\n");
		break;



	case GE_OP:

		fprintf(asm_io, "\tsetge \t%%dl\n");
		fprintf(asm_io, "\tmovl \t%%edx, (%%esp)\n");
		break;

	}

}

void cg_stack_logical(int op, int size){

	char *prefix;
	if(size == INT){
		prefix = "l";
		fprintf(asm_io, "\tpopl \t%%edx\n");
	} else if(size == CHAR){
		prefix = "b";
		fprintf(asm_io, "\tpopb \t%%edx\n");
	}

	switch(op){
	/*logical_and_expression*/
	case AND_OP:

		//fprintf(asm_io, "\tand%s \t%%edx, (%%esp)\n");

		break;

	/*logical_or_expression*/
	case OR_OP:

		break;

	/*inclusive_or_expression*/
	case '|':

		fprintf(asm_io, "\tor%s \t%%edx, (%%esp)\n", prefix);

		break;

	/*exclusive_or_expression*/
	case '^':

		fprintf(asm_io, "\txor%s \t%%edx, (%%esp)\n", prefix);


		break;

	/*and_expression*/
	case '&':

		fprintf(asm_io, "\tand%s \t%%edx, (%%esp)\n", prefix);

		break;

	}

}

void cg_return(int type){


	switch(type){
	case INT:
		fprintf(asm_io, "\tmovl \t(%%esp), %%eax\n");
		break;
	case CHAR:
		fprintf(asm_io, "\tmovb \t(%%esp), %%eax\n");
		break;
	}


	fprintf(asm_io, "\tjmp \t%s\n", actual_end_proc);
}

void cg_load_pointer(int size){

	fprintf(asm_io, "\tpopl \t%%edx\n");
	if(size == INT){
		fprintf(asm_io, "\tpushl \t(%%edx)\n");
	}else	if(size == CHAR){
		fprintf(asm_io, "\tpushb \t(%%edx)\n");
	}


}

void cg_store_pointer(int size){

	fprintf(asm_io, "\tpopl \t%%edx\n");

	if(size == INT){
		fprintf(asm_io, "\tmovl \t(%%esp), %%ebx\n");
		fprintf(asm_io, "\tmovl \t%%ebx, (%%edx)\n");
		//puts("aqui====================");

	}else	if(size == CHAR){
		fprintf(asm_io, "\tmovb \t(%%esp), %%ebx\n");
		fprintf(asm_io, "\tmovb \t%%ebx, (%%edx)\n");

	}
}

void cg_declare_global_variable(char *name, int init, int type){

	fprintf(asm_io, ".globl %s\n", name);
	fprintf(asm_io, "\t.data\n\t.align 4\n");
	fprintf(asm_io, "%s:\n", name);

	if(type == INT){
		fprintf(asm_io, "\t.long ");

	} else if(type == CHAR){
		fprintf(asm_io, "\t.byte ");
	}

	fprintf(asm_io, "%d\n", init);
	fprintf(asm_io, "\t.text\n");
}

void cg_push_var_mem_pointer(char *var_name, int type){

	if(type == INT){
		fprintf(asm_io, "\tpushl \t%s\n", var_name);

	} else if(type == CHAR){
		fprintf(asm_io, "\t.byte \t%s\n", var_name);
	}

}

void cg_push_mem_pointer(char *var_name){

	fprintf(asm_io, "\tpushl \t$%s\n", var_name);


}

void cg_stack_neg(int size){

	fprintf(asm_io, "\tnegl \t(%%esp)\n");
}
