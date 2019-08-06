%{ 
#include <stdio.h>
#include "../include/compiler.h" 
#include "../include/semantic.h"

char *id;
char *str;
int erro = 0;

TRANSLATION_UNIT *aa;
%} 

%union {
	int ivalue;		/* integer value */
	char sIndex;	/* symbol table index */
	char *str;
	void *nPtr;		/* node pointer */
}
%type <nPtr> parameter_declaration
%type <nPtr> translation_unit
%type <nPtr> declaration
%type <nPtr> external_declaration 
%type <nPtr> function_definition
%type <nPtr> declaration_specifiers 
%type <nPtr> declarator 
%type <nPtr> declaration_list 
%type <nPtr> compound_statement 
%type <nPtr> primary_expression
%type <nPtr> postfix_expression
%type <nPtr> argument_expression_list
%type <nPtr> iteration_statement
%type <nPtr> statement
%type <nPtr> expression
%type <nPtr> selection_statement
%type <nPtr> assignment_expression
%type <nPtr> unary_expression
%type <nPtr> unary_operator
%type <nPtr> multiplicative_expression
%type <nPtr> additive_expression
%type <nPtr> type_name
%type <nPtr> shift_expression
%type <nPtr> relational_expression
%type <nPtr> equality_expression
%type <nPtr> expression_statement
%type <nPtr> statement_list
%type <nPtr> labeled_statement
%type <nPtr> constant_expression
%type <nPtr> jump_statement
%type <nPtr> initializer_list
%type <nPtr> initializer
%type <nPtr> and_expression
%type <nPtr> exclusive_or_expression
%type <nPtr> inclusive_or_expression
%type <nPtr> logical_and_expression
%type <nPtr> logical_or_expression
%type <nPtr> conditional_expression
%type <nPtr> init_declarator_list
%type <nPtr> type_specifier 
%type <nPtr> identifier_list
%type <nPtr> assignment_operator
%type <nPtr> specifier_qualifier_list
%type <nPtr> abstract_declarator
%type <nPtr> init_declarator
%type <nPtr> struct_or_union_specifier
%type <nPtr> pointer
%type <nPtr> parameter_list
%type <nPtr> parameter_type_list
%type <nPtr> direct_declarator
%type <nPtr> struct_or_union
%type <nPtr> struct_declaration_list


%token <str> IDENTIFIER 
%token <ivalue> CONSTANT 
%token <str> STRING_LITERAL 
%token SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER 
	{
		PRIMARY_EXPRESSION1 *e = malloc(sizeof(PRIMARY_EXPRESSION1));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION1_CODE;
		
		e->identifier = $1;
	
		$$ = e;
		
	}
	
	| CONSTANT
	{
		PRIMARY_EXPRESSION2 *e = malloc(sizeof(PRIMARY_EXPRESSION2));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION2_CODE;
		
		e->constant = $1;
		
		$$ = e;
		
	}	
	
	| STRING_LITERAL
	{
		PRIMARY_EXPRESSION3 *e = malloc(sizeof(PRIMARY_EXPRESSION3));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION3_CODE;
		
		e->string_literal = $1;
		//puts(e->string_literal);
		
		$$ = e;
		
	}	
	
	| '(' expression ')'
	{
		PRIMARY_EXPRESSION4 *e = malloc(sizeof(PRIMARY_EXPRESSION4));
		((DEFAULT_NODE *) e)->type = PRIMARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = PRIMARY_EXPRESSION4_CODE;
		
		e->expression = $2;
		
		$$ = e;
		
	}		
	
	;

postfix_expression
	: primary_expression
	{
		POSTFIX_ESPRESSION1 *e = malloc(sizeof(POSTFIX_ESPRESSION1));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION1_CODE;
		e->primary_expression = $1;
		$$ = e;
	
	}
	
	| postfix_expression '[' expression ']' 
	{
		POSTFIX_ESPRESSION2 *e = malloc(sizeof(POSTFIX_ESPRESSION2));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION2_CODE;
		e->postfix_expression = $1;
		e->expression = $3;
		$$ = e;
	}
	
	| postfix_expression '(' ')'
	{
		POSTFIX_ESPRESSION3 *e = malloc(sizeof(POSTFIX_ESPRESSION3));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION3_CODE;
		e->postfix_expression = $1;
		$$ = e;
	}
	
	| postfix_expression '(' argument_expression_list ')' 
	{
		POSTFIX_ESPRESSION4 *e = malloc(sizeof(POSTFIX_ESPRESSION4));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION4_CODE;
		e->postfix_expression = $1;
		e->argument_expression_list = $3;
		$$ = e;
	}
	
	| postfix_expression '.' IDENTIFIER
	{
		POSTFIX_ESPRESSION5 *e = malloc(sizeof(POSTFIX_ESPRESSION5));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION5_CODE;
		e->postfix_expression = $1;
		e->identifier = $3;
		$$ = e;
	}
	
	| postfix_expression PTR_OP IDENTIFIER
	{
		POSTFIX_ESPRESSION6 *e = malloc(sizeof(POSTFIX_ESPRESSION6));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION6_CODE;
		e->postfix_expression = $1;
		e->identifier = $3;
		$$ = e;
	}
	
	| postfix_expression INC_OP
	{
		POSTFIX_ESPRESSION7 *e = malloc(sizeof(POSTFIX_ESPRESSION7));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION7_CODE;
		e->postfix_expression = $1;
		e->op = INC_OP;
		$$ = e;
	}	
	
	| postfix_expression DEC_OP
		{
		POSTFIX_ESPRESSION8 *e = malloc(sizeof(POSTFIX_ESPRESSION8));
		((POSTFIX_ESPRESSION *) e)->type = POSTFIX_ESPRESSION_CODE;
		((POSTFIX_ESPRESSION *) e)->subtype = POSTFIX_ESPRESSION8_CODE;
		e->postfix_expression = $1;
		e->op = DEC_OP;
		$$ = e;
	}	
	;

argument_expression_list
	: assignment_expression 
	{
		ARGUMENT_EXPRESSION_LIST *ael = malloc(sizeof(ARGUMENT_EXPRESSION_LIST));
		((DEFAULT_NODE *) ael)->type = ARGUMENT_EXPRESSION_LIST_CODE;
		ael->assignment_expression = $1;
		ael->argument_expression_list = NULL;
		
		$$ = ael;
	}
	| argument_expression_list ',' assignment_expression
	{
		ARGUMENT_EXPRESSION_LIST *ael = malloc(sizeof(ARGUMENT_EXPRESSION_LIST));
		((DEFAULT_NODE *) ael)->type = ARGUMENT_EXPRESSION_LIST_CODE;
		ael->assignment_expression = $3;
		ael->argument_expression_list = $1;
		
		$$ = ael;
	
	}
	;
//ok
unary_expression
	: postfix_expression
	{
		UNARY_EXPRESSION1 *e = malloc(sizeof(UNARY_EXPRESSION1));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION1_CODE;
		e->postfix_expression = $1;
		
		$$ = e;
	}
	
	| unary_operator unary_expression
	{
		UNARY_EXPRESSION2 *e = malloc(sizeof(UNARY_EXPRESSION2));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION2_CODE;
		e->unary_operator = $1;
		e->unary_expression = $2;
		
		$$ = e;	
	}
	
	| SIZEOF unary_expression
	{
		UNARY_EXPRESSION3 *e = malloc(sizeof(UNARY_EXPRESSION3));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION3_CODE;
		e->unary_expression = $2;
		
		$$ = e;	
	}
		
	| SIZEOF '(' type_name ')'
	{
		UNARY_EXPRESSION4 *e = malloc(sizeof(UNARY_EXPRESSION4));
		((DEFAULT_NODE *) e)->type = UNARY_EXPRESSION_CODE;
		((DEFAULT_NODE *) e)->subtype = UNARY_EXPRESSION4_CODE;
		e->type_name = $3;
		
		$$ = e;	
	}	
	;
//ok
unary_operator
	: '&'
	{
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '&';
		
		$$ = uop;
	}
	
	| '*'
	{
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '*';
		
		$$ = uop;
	}
	
	| '+'
	{
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '+';
		
		$$ = uop;
	}	
	
	| '-'
	{
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '-';
		
		$$ = uop;
	}
		
	| '~'
	{
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '~';
		
		$$ = uop;
	}
		
	| '!'
	{
		UNARY_OPERATOR *uop = malloc(sizeof(UNARY_OPERATOR));
		((DEFAULT_NODE *) uop)->type = UNARY_OPERATOR_CODE;
		uop->op = '!';
		
		$$ = uop;
	}	
	;

//ok
multiplicative_expression
	: unary_expression
	{
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		me->unary_expression = $1;
		me->multiplicative_expression = NULL;
		me->op = 0;
		
		$$ = me;
	}
	
	| multiplicative_expression '*' unary_expression
	{
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		
		me->multiplicative_expression = $1;
		me->op = '*';
		me->unary_expression = $3;
		
		$$ = me;
	}	
	
	| multiplicative_expression '/' unary_expression
	{
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		
		me->multiplicative_expression = $1;
		me->op = '/';
		me->unary_expression = $3;
		
		$$ = me;
	}		
	
	
	| multiplicative_expression '%' unary_expression
	{
		MULTIPLICATIVE_EXPRESSION *me = malloc(sizeof(MULTIPLICATIVE_EXPRESSION));
		((DEFAULT_NODE *) me)->type = MULTIPLICATIVE_EXPRESSION_CODE;
		
		me->multiplicative_expression = $1;
		me->op = '%';
		me->unary_expression = $3;
		
		$$ = me;
	}		
	;



//ok
additive_expression
	: multiplicative_expression
	{
		//puts("aqui");
		ADDITIVE_EXPRESSION *ae = malloc(sizeof(ADDITIVE_EXPRESSION));
		((DEFAULT_NODE *) ae)->type = ADDITIVE_EXPRESSION_CODE;
		ae->additive_expression = NULL;
		ae->multiplicative_expression = $1;
		ae->op = 0;
		
		$$ = ae;
	}
		
	| additive_expression '+' multiplicative_expression
	{
		//puts("aqui");
		ADDITIVE_EXPRESSION *ae = malloc(sizeof(ADDITIVE_EXPRESSION));
		((DEFAULT_NODE *) ae)->type = ADDITIVE_EXPRESSION_CODE;
		ae->additive_expression = $1;
		ae->op = '+';
		ae->multiplicative_expression = $3;
		
		
		$$ = ae;
	}
		
	| additive_expression '-' multiplicative_expression
		{
		//puts("aqui");
		ADDITIVE_EXPRESSION *ae = malloc(sizeof(ADDITIVE_EXPRESSION));
		((DEFAULT_NODE *) ae)->type = ADDITIVE_EXPRESSION_CODE;
		ae->additive_expression = $1;
		ae->op = '-';
		ae->multiplicative_expression = $3;
		
		
		$$ = ae;
	}
	;
//ok
shift_expression
	: additive_expression
	{
		SHIFT_EXPRESSION *se = malloc(sizeof(SHIFT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = SHIFT_EXPRESSION_CODE;
		se->shift_expression = NULL;
		se->op = 0;
		se->additive_expression = $1;
		
		$$ = se;
	}
	
	| shift_expression LEFT_OP additive_expression
	{
		SHIFT_EXPRESSION *se = malloc(sizeof(SHIFT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = SHIFT_EXPRESSION_CODE;
		se->shift_expression = $1;
		se->op = LEFT_OP;
		se->additive_expression = $3;
		
		$$ = se;
	}	
	
	| shift_expression RIGHT_OP additive_expression
	{
		SHIFT_EXPRESSION *se = malloc(sizeof(SHIFT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = SHIFT_EXPRESSION_CODE;
		se->shift_expression = $1;
		se->op = RIGHT_OP;
		se->additive_expression = $3;
		
		$$ = se;
	}	
		
	
	;
//ok
relational_expression
	: shift_expression
	{
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = NULL;
		se->op = 0;
		se->shift_expression = $1;
		
		
		$$ = se;
	}
			
	| relational_expression '<' shift_expression
	{
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = $1;
		se->op = '<';
		se->shift_expression = $3;
		
		
		$$ = se;
	}
				
	| relational_expression '>' shift_expression
	{
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = $1;
		se->op = '>';
		se->shift_expression = $3;
		
		
		$$ = se;
	}			
	
	| relational_expression LE_OP shift_expression
	{
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = $1;
		se->op = LE_OP;
		se->shift_expression = $3;
		
		
		$$ = se;
	}		
	
	| relational_expression GE_OP shift_expression
	{
		RELATIONAL_EXPRESSION *se = malloc(sizeof(RELATIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = RELATIONAL_EXPRESSION_CODE;
		se->relational_expression = $1;
		se->op = GE_OP;
		se->shift_expression = $3;
		
		
		$$ = se;
	}			
	
	;
//ok
equality_expression
	: relational_expression
	{
		EQUALITY_EXPRESSION *se = malloc(sizeof(EQUALITY_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EQUALITY_EXPRESSION_CODE;
		se->equality_expression = NULL;
		se->op = 0;
		se->relational_expression = $1;
		
		
		$$ = se;
	}		
	
	
	| equality_expression EQ_OP relational_expression
	{
		EQUALITY_EXPRESSION *se = malloc(sizeof(EQUALITY_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EQUALITY_EXPRESSION_CODE;
		se->equality_expression = $1;
		se->op = EQ_OP;
		se->relational_expression = $3;
		
		
		$$ = se;
	}		
	
	| equality_expression NE_OP relational_expression
	{
		EQUALITY_EXPRESSION *se = malloc(sizeof(EQUALITY_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EQUALITY_EXPRESSION_CODE;
		se->equality_expression = $1;
		se->op = NE_OP;
		se->relational_expression = $3;
		
		
		$$ = se;
	}			
	
	;
//ok
and_expression
	: equality_expression
	{
		AND_EXPRESSION *se = malloc(sizeof(AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = AND_EXPRESSION_CODE;
		se->equality_expression = $1;
		se->and_expression = NULL;
		
		
		$$ = se;
	}			
	
	| and_expression '&' equality_expression
	
	{
		AND_EXPRESSION *se = malloc(sizeof(AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = AND_EXPRESSION_CODE;
		se->and_expression = $1;
		se->equality_expression = $3;
		
		
		$$ = se;
	}		
	
	;
//ok
exclusive_or_expression
	: and_expression
	{
		EXCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(EXCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXCLUSIVE_OR_EXPRESSION_CODE;
		se->exclusive_or_expression = NULL;
		se->and_expression = $1;
		
		
		$$ = se;
	}			
	
	| exclusive_or_expression '^' and_expression
	{
		EXCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(EXCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXCLUSIVE_OR_EXPRESSION_CODE;
		se->exclusive_or_expression = $1;
		se->and_expression = $3;
		
		
		$$ = se;
	}			
		
	
	;
//ok
inclusive_or_expression
	: exclusive_or_expression
	{
		INCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(INCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = INCLUSIVE_OR_EXPRESSION_CODE;
		se->inclusive_or_expression = NULL;
		se->exclusive_or_expression = $1;	
		
		
		$$ = se;
	}		
	
	
	| inclusive_or_expression '|' exclusive_or_expression
	{
		INCLUSIVE_OR_EXPRESSION *se = malloc(sizeof(INCLUSIVE_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = INCLUSIVE_OR_EXPRESSION_CODE;
		se->inclusive_or_expression = $1;
		se->exclusive_or_expression = $3;	
		
		
		$$ = se;
	}		
	
	;
//ok
logical_and_expression
	: inclusive_or_expression
	{
		LOGICAL_AND_EXPRESSION *se = malloc(sizeof(LOGICAL_AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_AND_EXPRESSION_CODE;
		se->logical_and_expression = NULL;
		se->inclusive_or_expression = $1;	
		
		
		$$ = se;
	}			
	
	| logical_and_expression AND_OP inclusive_or_expression
	{
		LOGICAL_AND_EXPRESSION *se = malloc(sizeof(LOGICAL_AND_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_AND_EXPRESSION_CODE;
		se->logical_and_expression = $1;
		se->inclusive_or_expression = $3;	
		
		
		$$ = se;
	}			
	;

//ok
logical_or_expression
	: logical_and_expression
	{
		LOGICAL_OR_EXPRESSION *se = malloc(sizeof(LOGICAL_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_OR_EXPRESSION_CODE;
		se->logical_or_expression = NULL;
		se->logical_and_expression = $1;	
		
		
		$$ = se;
	}				
	
	| logical_or_expression OR_OP logical_and_expression
	{
		LOGICAL_OR_EXPRESSION *se = malloc(sizeof(LOGICAL_OR_EXPRESSION));
		((DEFAULT_NODE *) se)->type = LOGICAL_OR_EXPRESSION_CODE;
		se->logical_or_expression = $1;
		se->logical_and_expression = $3;	
		
		
		$$ = se;
	}			
	
	;

//ok
conditional_expression
	: logical_or_expression
	{
		CONDITIONAL_EXPRESSION *se = malloc(sizeof(CONDITIONAL_EXPRESSION));
		((DEFAULT_NODE *) se)->type = CONDITIONAL_EXPRESSION_CODE;
		se->logical_or_expression = $1;	
		
		
		$$ = se;
	}	
	;

assignment_expression
	: conditional_expression
	{
		ASSIGNMENT_EXPRESSION1 *se = malloc(sizeof(ASSIGNMENT_EXPRESSION1));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_EXPRESSION_CODE;
		((DEFAULT_NODE *) se)->subtype = ASSIGNMENT_EXPRESSION1_CODE;
		
		se->conditional_expression = $1;
		
		$$ = se;
	}	
	
	| unary_expression assignment_operator assignment_expression
	{
		ASSIGNMENT_EXPRESSION2 *se = malloc(sizeof(ASSIGNMENT_EXPRESSION2));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_EXPRESSION_CODE;
		((DEFAULT_NODE *) se)->subtype = ASSIGNMENT_EXPRESSION2_CODE;
		
		se->unary_expression = $1;
		se->assignment_operator = $2;
		se->assignment_expression = $3;
		
		$$ = se;
	}		
	
	;

assignment_operator
	: '='
	{
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = '=';
		
		$$ = se;
	}
	
	| MUL_ASSIGN
	{
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = MUL_ASSIGN;
		
		$$ = se;
	}	
	
	| DIV_ASSIGN
	{
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = DIV_ASSIGN;
		
		$$ = se;
	}	
	
	| ADD_ASSIGN
	{
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = ADD_ASSIGN;
		
		$$ = se;
	}	
	
	| SUB_ASSIGN
	{
		ASSIGNMENT_OPERATOR *se = malloc(sizeof(ASSIGNMENT_OPERATOR));
		((DEFAULT_NODE *) se)->type = ASSIGNMENT_OPERATOR_CODE;
		
		se->op = SUB_ASSIGN;
		
		$$ = se;
	}
	;

expression
	: assignment_expression
	{	
		EXPRESSION *se = malloc(sizeof(EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXPRESSION_CODE;
		
		se->assignment_expression = $1;
		
		$$ = se;
	}
	
	| expression ',' assignment_expression
	{	
		EXPRESSION *se = malloc(sizeof(EXPRESSION));
		((DEFAULT_NODE *) se)->type = EXPRESSION_CODE;
		
		se->expression = $1;
		se->assignment_expression = $3;
		
		$$ = se;
	}	
	;

//ok
constant_expression
	: conditional_expression
	{	
		CONSTANT_EXPRESSION *se = malloc(sizeof(CONSTANT_EXPRESSION));
		((DEFAULT_NODE *) se)->type = CONSTANT_EXPRESSION_CODE;
		
		se->conditional_expression = $1;
		
		$$ = se;
	}		
	;

declaration
	: declaration_specifiers ';'
	{
		DECLARATION *se = malloc(sizeof(DECLARATION));
		((DEFAULT_NODE *) se)->type = DECLARATION_CODE;
		
		se->declaration_specifiers = $1;
		se->init_declarator_list = NULL;
	
		$$ = se;
	}
	
	| declaration_specifiers init_declarator_list ';'
	{
		DECLARATION *se = malloc(sizeof(DECLARATION));
		((DEFAULT_NODE *) se)->type = DECLARATION_CODE;
		
		se->declaration_specifiers = $1;
		se->init_declarator_list = $2;
	
		$$ = se;
	}	

	
	;

//ok
declaration_specifiers
	: type_specifier
	{
		DECLARATION_SPECIFIERS *se = malloc(sizeof(DECLARATION_SPECIFIERS));
		((DEFAULT_NODE *) se)->type = DECLARATION_SPECIFIERS_CODE;
		
		se->type_specifier = $1;
		se->declaration_specifiers = NULL;
	
		$$ = se;
	}	
	
	| type_specifier declaration_specifiers
	{
		DECLARATION_SPECIFIERS *se = malloc(sizeof(DECLARATION_SPECIFIERS));
		((DEFAULT_NODE *) se)->type = DECLARATION_SPECIFIERS_CODE;
		
		se->type_specifier = $1;
		se->declaration_specifiers = $2;
	
		$$ = se;
	}		
	;

init_declarator_list
	: init_declarator
	{
		INIT_DECLARATOR_LIST *se = malloc(sizeof(INIT_DECLARATOR_LIST));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_LIST_CODE;
		
		se->init_declarator_list = NULL;
		se->init_declarator = $1;
		
		$$ = se;
	}
	
	| init_declarator_list ',' init_declarator
	{
		INIT_DECLARATOR_LIST *se = malloc(sizeof(INIT_DECLARATOR_LIST));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_LIST_CODE;
		
		se->init_declarator_list = $1;
		se->init_declarator = $3;
		
		$$ = se;
	}	
	
	;

init_declarator
	: declarator
	{
		INIT_DECLARATOR *se = malloc(sizeof(INIT_DECLARATOR));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_CODE;
		
		se->declarator = $1;
		se->initializer = NULL;
		
		$$ = se;
	}
	
	| declarator '=' initializer
	{
		INIT_DECLARATOR *se = malloc(sizeof(INIT_DECLARATOR));
		((DEFAULT_NODE *) se)->type = INIT_DECLARATOR_CODE;
		
		se->declarator = $1;
		se->initializer = $3;
		
		$$ = se;
	}
		
	
	;

type_specifier
	: VOID
	{
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = VOID;
		se->struct_or_union_specifier = NULL;
		
		$$ = se;
	}
	
	| CHAR
	{
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = CHAR;
		se->struct_or_union_specifier = NULL;
		
		$$ = se;
	}
		
	| INT
	{
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = INT;
		se->struct_or_union_specifier = NULL;
		
		$$ = se;
	}	
	
	| FLOAT
	{
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = FLOAT;
		se->struct_or_union_specifier = NULL;
		
		$$ = se;
	}	
	
	| struct_or_union_specifier
	{
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = 0;
		se->struct_or_union_specifier = $1;
		
		$$ = se;
	}	
	
	| TYPE_NAME
	{
		TYPE_SPECIFIER *se = malloc(sizeof(TYPE_SPECIFIER));
		((DEFAULT_NODE *) se)->type = TYPE_SPECIFIER_CODE;
		
		se->datatype = TYPE_NAME;
		se->struct_or_union_specifier = NULL;
		
		$$ = se;
	}	
	
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	{
		STRUCT_OR_UNION_SPECIFIER1 *se = malloc(sizeof(STRUCT_OR_UNION_SPECIFIER1));
		((DEFAULT_NODE *) se)->type = STRUCT_OR_UNION_SPECIFIER_CODE;
		((DEFAULT_NODE *) se)->subtype = STRUCT_OR_UNION_SPECIFIER1_CODE;
		
		se->struct_or_union = $1;
		se->identifier = $2;
		se->struct_declaration_list = $4;
		
		$$ = se;
	}
	
	
	| struct_or_union '{' struct_declaration_list '}'
	{
		STRUCT_OR_UNION_SPECIFIER2 *se = malloc(sizeof(STRUCT_OR_UNION_SPECIFIER2));
		((DEFAULT_NODE *) se)->type = STRUCT_OR_UNION_SPECIFIER_CODE;
		((DEFAULT_NODE *) se)->subtype = STRUCT_OR_UNION_SPECIFIER2_CODE;
		
		se->struct_or_union = $1;
		se->struct_declaration_list = $3;
		
		$$ = se;
	}	
	
	| struct_or_union IDENTIFIER
	{
		STRUCT_OR_UNION_SPECIFIER3 *se = malloc(sizeof(STRUCT_OR_UNION_SPECIFIER3));
		((DEFAULT_NODE *) se)->type = STRUCT_OR_UNION_SPECIFIER_CODE;
		((DEFAULT_NODE *) se)->subtype = STRUCT_OR_UNION_SPECIFIER3_CODE;
		
		se->struct_or_union = $1;
		se->identifier = $2;
		
		$$ = se;
	}	
		
	
	;

struct_or_union
	: STRUCT
	{
		STRUCT_OR_UNION *s = malloc(sizeof(STRUCT_OR_UNION));
		((DEFAULT_NODE *) s)->type = STRUCT_OR_UNION_CODE;
		
		s->datatype = STRUCT;
		
		$$ = s;
	}
	
	| UNION
	{
		STRUCT_OR_UNION *s = malloc(sizeof(STRUCT_OR_UNION));
		((DEFAULT_NODE *) s)->type = STRUCT_OR_UNION_CODE;
		
		s->datatype = UNION;
		
		$$ = s;
	}	
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		SPECIFIER_QUALIFIER_LIST *s = malloc(sizeof(SPECIFIER_QUALIFIER_LIST));
		((DEFAULT_NODE *) s)->type = SPECIFIER_QUALIFIER_LIST_CODE;
		
		s->type_specifier = $1;
		s->specifier_qualifier_list = $2;
	}
	
	| type_specifier
	{
		SPECIFIER_QUALIFIER_LIST *s = malloc(sizeof(SPECIFIER_QUALIFIER_LIST));
		((DEFAULT_NODE *) s)->type = SPECIFIER_QUALIFIER_LIST_CODE;
		
		s->type_specifier = $1;
		s->specifier_qualifier_list = NULL;;
	}	
	
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	
//ok	
declarator
	: pointer direct_declarator
	{	
		DECLARATOR *s = malloc(sizeof(DECLARATOR));
		((DEFAULT_NODE *) s)->type = DECLARATOR_CODE;
		
		s->pointer = $1;
		s->direct_declarator = $2;
		
		$$ = s;
	}
	
	| direct_declarator
	{	
		DECLARATOR *s = malloc(sizeof(DECLARATOR));
		((DEFAULT_NODE *) s)->type = DECLARATOR_CODE;
		
		s->pointer = NULL;
		s->direct_declarator = $1;
		
		$$ = s;
	}	
	;

// ok
direct_declarator
	: IDENTIFIER 
		{	
		DIRECT_DECLARATOR1 *s = malloc(sizeof(DIRECT_DECLARATOR1));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR1_CODE;
		
		int len = strlen($1);
		
		//char *str = malloc(len);
		//strcpy(str, $1);
		
		s->identifier = $1;
		
		//puts(str);
		
		$$ = s;
	}	
	
	| '(' declarator ')'
	{	
		DIRECT_DECLARATOR2 *s = malloc(sizeof(DIRECT_DECLARATOR2));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR2_CODE;
		
		s->declarator = $2;
		
		$$ = s;
	}		
	
	| direct_declarator '[' CONSTANT ']'
	{	
		DIRECT_DECLARATOR3 *s = malloc(sizeof(DIRECT_DECLARATOR3));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR3_CODE;
		
		s->direct_declarator = $1;
		s->constant = $3;
		
		$$ = s;
	}		
	
	| direct_declarator '[' ']'
	{	
		DIRECT_DECLARATOR3 *s = malloc(sizeof(DIRECT_DECLARATOR3));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR3_CODE;
		
		s->direct_declarator = $1;
		s->constant = 0;
		
		$$ = s;
	}		
	
	| direct_declarator '(' parameter_type_list ')'
	{	
		DIRECT_DECLARATOR4 *s = malloc(sizeof(DIRECT_DECLARATOR4));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR4_CODE;
		
		s->direct_declarator = $1;
		s->parameter_type_list = $3;
		
		$$ = s;
	}			
	
	| direct_declarator '(' identifier_list ')'
	{	
		DIRECT_DECLARATOR5 *s = malloc(sizeof(DIRECT_DECLARATOR5));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR5_CODE;
		
		s->direct_declarator = $1;
		s->identifier_list = $3;
		
		$$ = s;
	}				
	
	| direct_declarator '(' ')'
	{	
		DIRECT_DECLARATOR4 *s = malloc(sizeof(DIRECT_DECLARATOR4));
		((DEFAULT_NODE *) s)->type = DIRECT_DECLARATOR_CODE;
		((DEFAULT_NODE *) s)->subtype = DIRECT_DECLARATOR4_CODE;
		
		//puts("aqui");
		s->direct_declarator = $1;
		s->parameter_type_list = NULL;
		
		$$ = s;
	}				
	;

//ok
pointer
	: '*'
	{
		POINTER *s = malloc(sizeof(POINTER));
		((DEFAULT_NODE *) s)->type = POINTER_CODE;
		
		s->pointer = NULL;
		
		$$ = s;
	}
	
	| '*' pointer
	{
		POINTER *s = malloc(sizeof(POINTER));
		((DEFAULT_NODE *) s)->type = POINTER_CODE;
		
		s->pointer = $2;
		
		$$ = s;
	}	
	;


parameter_type_list
	: parameter_list
	{
		PARAMETER_TYPE_LIST *s = malloc(sizeof(PARAMETER_TYPE_LIST));
		((DEFAULT_NODE *) s)->type = PARAMETER_TYPE_LIST_CODE;
		
		s->parameter_list = $1;
		
		$$ = s;
	}
	;

parameter_list
	: parameter_declaration
	{
		PARAMETER_LIST *p = malloc(sizeof(PARAMETER_LIST));
		((DEFAULT_NODE *) p)->type = PARAMETER_LIST_CODE;
		p->parameter_declaration = $1;
		p->parameter_list = NULL;
		
		$$ = p;
	
	}
	| parameter_list ',' parameter_declaration
	{
		PARAMETER_LIST *p = malloc(sizeof(PARAMETER_LIST));
		((DEFAULT_NODE *) p)->type = PARAMETER_LIST_CODE;
		p->parameter_declaration = $3;
		p->parameter_list = $1;
		
		$$ = p;
	}
	;

parameter_declaration
	: declaration_specifiers declarator
	{
		PARAMETER_DECLARATION1 *p = malloc(sizeof(PARAMETER_DECLARATION1));
		((DEFAULT_NODE *) p)->type = PARAMETER_DECLARATION_CODE;
		((DEFAULT_NODE *) p)->subtype = PARAMETER_DECLARATION1_CODE;
		
		p->declaration_specifiers = $1;
		p->declarator = $2;
	
		//puts("Este1");
		$$ = p;
	
	}
	| declaration_specifiers abstract_declarator
	{
		
		//puts("Este2");
	}
	| declaration_specifiers
	{
	
		//puts("Este3");
	}
	;

identifier_list
	: IDENTIFIER
	{
		IDENTIFIER_LIST *s = malloc(sizeof(IDENTIFIER_LIST));
		((DEFAULT_NODE *) s)->type = IDENTIFIER_LIST_CODE;
		
		s->identifier = $1;
		s->identifier_list = NULL;
		
		$$ = s;
		
	}
	
	| identifier_list ',' IDENTIFIER
	{
		IDENTIFIER_LIST *s = malloc(sizeof(IDENTIFIER_LIST));
		((DEFAULT_NODE *) s)->type = IDENTIFIER_LIST_CODE;
		
		s->identifier = $3;
		s->identifier_list = $1;
		
		$$ = s;
		
	}	
	
	;
//ok
type_name
	: specifier_qualifier_list
	{
		TYPE_NAMEi *s = malloc(sizeof(TYPE_NAMEi));
		((DEFAULT_NODE *) s)->type = TYPE_NAMEi_CODE;
		
		s->specifier_qualifier_list  = $1;
		s->abstract_declarator = NULL;
	}
	
	| specifier_qualifier_list abstract_declarator
	{
		TYPE_NAMEi *s = malloc(sizeof(TYPE_NAMEi));
		((DEFAULT_NODE *) s)->type = TYPE_NAMEi_CODE;
		
		s->specifier_qualifier_list  = $1;
		s->abstract_declarator = $2;
	}	
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	{
		INITIALIZER1 *i = malloc(sizeof(INITIALIZER1));
		((DEFAULT_NODE *) i)->type = INITIALIZER_CODE;
		((DEFAULT_NODE *) i)->subtype = INITIALIZER1_CODE;
		
		i->assignment_expression = $1;
	
		$$ = i;
	}
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	{
		INITIALIZER_LIST *s = malloc(sizeof(INITIALIZER_LIST));
		((DEFAULT_NODE *) s)->type = INITIALIZER_LIST_CODE;
		
		s->initializer_list = NULL;
		s->initializer = $1;
		
		$$ = s;
	}
	| initializer_list ',' initializer
	{
		INITIALIZER_LIST *s = malloc(sizeof(INITIALIZER_LIST));
		((DEFAULT_NODE *) s)->type = INITIALIZER_LIST_CODE;
		
		s->initializer_list = $1;
		s->initializer = $3;
		
		$$ = s;
	}	
	
	;

statement
	: labeled_statement
	{
		STATEMENT1 *s = malloc(sizeof(STATEMENT1));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT1_CODE;
		
		s->labeled_statement = $1;
		
		$$ = s;
	}
	
	| compound_statement
	{
		STATEMENT2 *s = malloc(sizeof(STATEMENT2));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT2_CODE;
		
		s->compound_statement = $1;
		
		$$ = s;
	}	
	
	| expression_statement
	{
		STATEMENT3 *s = malloc(sizeof(STATEMENT3));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT3_CODE;
		
		s->expression_statement = $1;
		
		$$ = s;
	}		
	
	| selection_statement
	{
		STATEMENT4 *s = malloc(sizeof(STATEMENT4));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT4_CODE;
		
		s->selection_statement = $1;
		
		$$ = s;
	}		
	
	| function_definition
	{
		STATEMENT5 *s = malloc(sizeof(STATEMENT5));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT5_CODE;
		
		s->function_definition = $1;
		
		$$ = s;
	}	
	
	| iteration_statement
	{
		STATEMENT6 *s = malloc(sizeof(STATEMENT6));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT6_CODE;
		
		s->iteration_statement = $1;
		
		$$ = s;
	}	
		
	| jump_statement
	{
		STATEMENT7 *s = malloc(sizeof(STATEMENT7));
		((DEFAULT_NODE *) s)->type = STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = STATEMENT7_CODE;
		
		s->jump_statement = $1;
		
		$$ = s;
	}	
	
	;

labeled_statement
	: IDENTIFIER ':' statement
	{
		LABELED_STATEMENT1 *s = malloc(sizeof(LABELED_STATEMENT1));
		((DEFAULT_NODE *) s)->type = LABELED_STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = LABELED_STATEMENT1_CODE;
		
		s->identifier = $1;
		s->statement = $3;
		
		$$ = s;
	}	
	
	| CASE constant_expression ':' statement
	{
		LABELED_STATEMENT2 *s = malloc(sizeof(LABELED_STATEMENT2));
		((DEFAULT_NODE *) s)->type = LABELED_STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = LABELED_STATEMENT2_CODE;
		
		s->constant_expression = $2;
		s->statement = $4;
		
		$$ = s;
	}		
	
	| DEFAULT ':' statement
	{
		LABELED_STATEMENT3 *s = malloc(sizeof(LABELED_STATEMENT3));
		((DEFAULT_NODE *) s)->type = LABELED_STATEMENT_CODE;
		((DEFAULT_NODE *) s)->subtype = LABELED_STATEMENT3_CODE;
		
		s->statement = $3;
		
		$$ = s;
	}		
	
	;

compound_statement
	: '{' '}'
	{
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = NULL;
		s->declaration_list = NULL;
		//puts("aqui");
		
		$$ = s;
	}
	
	| '{' statement_list '}'
	{
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = $2;
		s->declaration_list = NULL;
		//puts("aqui1");
		$$ = s;
	}	
	
	| '{' declaration_list '}'
	{
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = NULL;
		s->declaration_list = $2;
		//puts("aqui2");
		$$ = s;
	}		
	
	| '{' declaration_list statement_list '}'
	
	{
		COMPOUND_STATEMENT *s = malloc(sizeof(COMPOUND_STATEMENT));
		((DEFAULT_NODE *) s)->type = COMPOUND_STATEMENT_CODE;
		
		s->statement_list = $3;
		s->declaration_list = $2;
		//puts("aqui3");
		$$ = s;
	}			
	
	;

declaration_list
	: declaration
	{
		DECLARATION_LIST *sel = malloc(sizeof(DECLARATION_LIST));
		((DEFAULT_NODE *) sel)->type = DECLARATION_LIST_CODE;
		sel->declaration = $1;
		sel->declaration_list = NULL;
		
		$$ = sel;
	}	
	
	
	| declaration_list declaration
	{
		DECLARATION_LIST *sel = malloc(sizeof(DECLARATION_LIST));
		((DEFAULT_NODE *) sel)->type = DECLARATION_LIST_CODE;
		sel->declaration = $2;
		sel->declaration_list = $1;
		
		$$ = sel;
	}		
	;

statement_list
	: statement
	{
		STATEMENT_LIST *sel = malloc(sizeof(STATEMENT_LIST));
		((DEFAULT_NODE *) sel)->type = STATEMENT_LIST_CODE;
		sel->statement = $1;
		sel->statement_list = NULL;
		
		$$ = sel;
	}
	
	
	| statement_list statement
	{
		STATEMENT_LIST *sel = malloc(sizeof(STATEMENT_LIST));
		((DEFAULT_NODE *) sel)->type = STATEMENT_LIST_CODE;
		sel->statement = $2;
		sel->statement_list = $1;
		
		$$ = sel;
	}	
	;

expression_statement
	: ';'
	{
		EXPRESSION_STATEMENT *sel = malloc(sizeof(EXPRESSION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = EXPRESSION_STATEMENT_CODE;
		sel->expression = NULL;
		
		$$ = sel;
	}
	
	| expression ';' 
	{
		//puts("esp....");
		EXPRESSION_STATEMENT *sel = malloc(sizeof(EXPRESSION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = EXPRESSION_STATEMENT_CODE;
		sel->expression = $1;
		
		$$ = sel;
		
		
	}
	
	| error ';' 
	;

selection_statement
	: IF '(' expression ')' statement 
	{
		SELECTION_STATEMENT *sel = malloc(sizeof(SELECTION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = SELECTION_STATEMENT_CODE;
		sel->expression = $3;
		sel->statement = $5;
		sel->statement2 = NULL;
		
		$$ = sel;
	}
	| IF '(' expression ')' statement ELSE statement 
	{
		SELECTION_STATEMENT *sel = malloc(sizeof(SELECTION_STATEMENT));
		((DEFAULT_NODE *) sel)->type = SELECTION_STATEMENT_CODE;
		sel->expression = $3;
		sel->statement = $5;
		sel->statement2 = $7;
		
		$$ = sel;
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement 
	{
		//puts("WHILE NODE1");
		ITERATION_STATEMENT *it = malloc(sizeof(ITERATION_STATEMENT));
		((POSTFIX_ESPRESSION *) it)->type = ITERATION_STATEMENT_CODE;
		((POSTFIX_ESPRESSION *) it)->subtype = WHILE;
		it->expression = $3;
		it->statement = $5;
		
		$$ = it;
	}
	| DO statement WHILE '(' expression ')' ';' 
	{
		//puts("DO WHILE NODE");
		ITERATION_STATEMENT *it = malloc(sizeof(ITERATION_STATEMENT));
		((POSTFIX_ESPRESSION *) it)->type = ITERATION_STATEMENT_CODE;
		((POSTFIX_ESPRESSION *) it)->subtype = DO+WHILE;
		it->expression = $5;
		it->statement = $2;
		
		$$ = it;
	}
//	| FOR '(' expression_statement expression_statement ')' statement
//	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = GOTO;
		jmp->identifier = $2;
		jmp->expression = NULL;
		
		$$ = jmp;
	}
	
	| CONTINUE ';'
		{
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = CONTINUE;
		jmp->identifier = NULL;
		jmp->expression = NULL;
		
		$$ = jmp;
	}
	
	| BREAK ';'
		{
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = BREAK;
		jmp->identifier = NULL;
		jmp->expression = NULL;
		
		$$ = jmp;
	}
	
	| RETURN ';'
		{
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = RETURN;
		jmp->identifier = NULL;
		jmp->expression = NULL;
		
		$$ = jmp;
	}
	
	| RETURN expression ';'
		{
		JUMP_STATEMENT *jmp = malloc(sizeof(JUMP_STATEMENT));
		((DEFAULT_NODE *) jmp)->type = JUMP_STATEMENT_CODE;
		
		jmp->jump = RETURN;
		jmp->identifier = NULL;
		jmp->expression = $2;
		
		$$ = jmp;
	}
	
	;
//ok
translation_unit
	: external_declaration 
	{ 
		//puts("\nTU1");
		TRANSLATION_UNIT *a =  malloc(sizeof(TRANSLATION_UNIT));
		a->ext_decl = $1;
		a->trans_unit = NULL;
		$$ = a;
		//semantic_entry(a);
		aa = a;
								
	}
	| translation_unit external_declaration 
	{
		//puts("\nTU2 NODE");
		TRANSLATION_UNIT *a =  malloc(sizeof(TRANSLATION_UNIT));
		a->ext_decl = $2;
		a->trans_unit = $1;
		$$ = a;
		//semantic_entry(a);
		aa = a;
	}
	;
//ok
external_declaration
	: function_definition
	{
		//puts("Montando EXTERNAL DECLARATION1 NODE");
		$$ = $1;
	}
	| declaration
	{
		//puts("Montando EXTERNAL DECLARATION2 NODE");
		$$ = $1;
	}
	;
//ok

function_definition
	: declaration_specifiers declarator declaration_list compound_statement 
	{//1
		//puts("FUNCTION_DEFINITION1 NODE");
		
		FUNCTION_DEFINITION1 *f = malloc(sizeof(FUNCTION_DEFINITION1));
		//((EXTERNAL_DECLARATION*) f)->type = EXTERNAL_DECLARATION_CODE;
		//((EXTERNAL_DECLARATION*) f)->subtype = FUNCTION1_DEFINITION_CODE;
		((EXTERNAL_DECLARATION*) f)->type = FUNCTION_DEFINITION_CODE;
		((EXTERNAL_DECLARATION*) f)->subtype = FUNCTION1_DEFINITION_CODE;
		
		
		f->dec_specifier = $1;
		f->declarator = $2;
		f->declaration_list = $3;
		f->compound_statement = $4;
		$$ = f;
	}
	| declaration_specifiers declarator compound_statement 
	{ 
		//puts("FUNCTION_DEFINITION2 NODE");
		
		FUNCTION_DEFINITION2 *f = malloc(sizeof(FUNCTION_DEFINITION2));
		((EXTERNAL_DECLARATION*) f)->type = FUNCTION_DEFINITION_CODE;
		((EXTERNAL_DECLARATION*) f)->subtype = FUNCTION2_DEFINITION_CODE;
		
		
		f->dec_specifier = $1;
		f->declarator = $2;
		f->compound_statement = $3;
		
		//printf("%d \n", f->compound_statement->type);
		
		$$ = f;
	}
	;


%%
#include <stdio.h>
#include "../include/compiler.h"


//extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
	erro = 1;
}
