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
 * compiler.h
 *
 *  Created on: 05/03/2009
 *      Author: andreu
 */

#ifndef COMPILER_H_
#define COMPILER_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define INTCONSTANT 1
#define FUNCTION 2
#define INT8 3
#define INT16 4
#define INT32 5
#define INT64 6
#define INTLABEL 7

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef int SYMBOL_TYPE;
typedef int OFFSET;

extern int error_indicator;

/*
typedef struct reg{
	char *reg_name;
	int reg_code;
	BOOL spilled_on_stack;
	OFFSET stack_offset;

} REGISTER;
*/

enum{
	TRANSLATION_UNIT_CODE 		= -1,
	EXTERNAL_DECLARATION_CODE 	= -2,
	FUNCTION1_DEFINITION_CODE 	= -3,
	FUNCTION2_DEFINITION_CODE 	= -4,

	POSTFIX_ESPRESSION_CODE		= -5,
	POSTFIX_ESPRESSION1_CODE	= -6,
	POSTFIX_ESPRESSION2_CODE	= -7,
	POSTFIX_ESPRESSION3_CODE	= -8,
	POSTFIX_ESPRESSION4_CODE	= -9,
	POSTFIX_ESPRESSION5_CODE	= -10,
	POSTFIX_ESPRESSION6_CODE	= -11,
	POSTFIX_ESPRESSION7_CODE	= -12,
	POSTFIX_ESPRESSION8_CODE	= -13,
	ITERATION_STATEMENT_CODE	= -14,
	SELECTION_STATEMENT_CODE	= -15,
	ARGUMENT_EXPRESSION_LIST_CODE = -16,
	PRIMARY_EXPRESSION_CODE = 	-17,
	PRIMARY_EXPRESSION1_CODE = 	-18,
	PRIMARY_EXPRESSION2_CODE = 	-19,
	PRIMARY_EXPRESSION3_CODE = 	-20,
	PRIMARY_EXPRESSION4_CODE = 	-21,
	UNARY_EXPRESSION_CODE	 =	-22,
	UNARY_EXPRESSION1_CODE	 =	-23,
	UNARY_EXPRESSION2_CODE	 =	-24,
	UNARY_EXPRESSION3_CODE	 =	-25,
	UNARY_EXPRESSION4_CODE	 =	-26,
	UNARY_OPERATOR_CODE		 =  -27,
	MULTIPLICATIVE_EXPRESSION_CODE = -28,
	ADDITIVE_EXPRESSION_CODE 	= -29,
	SHIFT_EXPRESSION_CODE		= -30,
	RELATIONAL_EXPRESSION_CODE	= -31,
	EQUALITY_EXPRESSION_CODE	= -32,
	EXPRESSION_STATEMENT_CODE	= -33,
	STATEMENT_LIST_CODE			= -34,
	DECLARATION_LIST_CODE		= -35,

	LABELED_STATEMENT_CODE		= -37,
	LABELED_STATEMENT1_CODE		= -38,
	LABELED_STATEMENT2_CODE		= -39,
	LABELED_STATEMENT3_CODE		= -40,
	STATEMENT_CODE				= -41,
	STATEMENT2_CODE				= -42,
	STATEMENT3_CODE				= -43,
	STATEMENT4_CODE				= -44,
	STATEMENT5_CODE				= -45,
	STATEMENT6_CODE				= -46,
	STATEMENT7_CODE				= -47,
	STATEMENT1_CODE				= -48,
	INITIALIZER_LIST_CODE		= -49,
	AND_EXPRESSION_CODE			= -50,
	EXCLUSIVE_OR_EXPRESSION_CODE = -51,
	INCLUSIVE_OR_EXPRESSION_CODE = -52,
	LOGICAL_AND_EXPRESSION_CODE = -53,
	LOGICAL_OR_EXPRESSION_CODE	= -54,
	CONDITIONAL_EXPRESSION_CODE = -55,
	ASSIGNMENT_EXPRESSION_CODE = -56,
	ASSIGNMENT_EXPRESSION1_CODE = -57,
	ASSIGNMENT_EXPRESSION2_CODE = -58,
	ASSIGNMENT_OPERATOR_CODE 	= -59,
	CONSTANT_EXPRESSION_CODE	= -60,
	EXPRESSION_CODE				= -61,
	DECLARATION_CODE			= -62,
	DECLARATION_SPECIFIERS_CODE = -63,
	IDENTIFIER_LIST_CODE		= -64,
	TYPE_NAMEi_CODE				= -65,
	INIT_DECLARATOR_CODE		= -66,
	INIT_DECLARATOR_LIST_CODE	= -67,
	TYPE_SPECIFIER_CODE			= -68,
	POINTER_CODE				= -69,
	PARAMETER_TYPE_LIST_CODE	= -70,
	DECLARATOR_CODE				= -71,
	DIRECT_DECLARATOR_CODE		= -72,
	DIRECT_DECLARATOR1_CODE		= -73,
	DIRECT_DECLARATOR2_CODE		= -74,
	DIRECT_DECLARATOR3_CODE		= -75,
	DIRECT_DECLARATOR4_CODE		= -76,
	DIRECT_DECLARATOR5_CODE		= -77,
	STRUCT_OR_UNION_CODE		= -78,
	STRUCT_OR_UNION_SPECIFIER_CODE = -79,
	STRUCT_OR_UNION_SPECIFIER1_CODE = -80,
	STRUCT_OR_UNION_SPECIFIER2_CODE = -81,
	STRUCT_OR_UNION_SPECIFIER3_CODE = -82,
	SPECIFIER_QUALIFIER_LIST_CODE =   -83,
	JUMP_STATEMENT_CODE				= -84,
	FUNCTION_DEFINITION_CODE		= -85,
	COMPOUND_STATEMENT_CODE		= -36,
	PARAMETER_LIST_CODE 		= -86,
	PARAMETER_DECLARATION_CODE = -87,
	PARAMETER_DECLARATION1_CODE = -88,
	INITIALIZER_CODE			= -89,
	INITIALIZER1_CODE			= -90

};

enum{
	FUNCTION_SYMB = 0,
	VAR_SYMB = 1,
};

enum{
	GLOBAL_VAR = 0,
	LOCAL_VAR = 1,
};

typedef struct symb{
	char* symbol_name;
	SYMBOL_TYPE type;
	//REGISTER *reg;
	//int symbol_type;
	int var_type;
	void *function_params;
	int function_return_type;
	void *data;
	int pointers;
	int val_initialized;
	int localization;
	int offset;
	int array;

} SYMBOL;




typedef struct tree_node{
	struct tree_node *left;
	struct tree_node *right;
	struct symb *symbolo;
	int id;

} TREE_NODE;

typedef struct {
	int type;
	int subtype;

} DEFAULT_NODE;

/******************************************************************************/

/**
 * translation_unit
	: external_declaration
	| translation_unit external_declaration
	;
 */
typedef struct translation_unit {
	struct external_declaration *ext_decl;
	struct translation_unit *trans_unit;

} TRANSLATION_UNIT;

/******************************************************************************/

/**
 * external_declaration
	: function_definition
	| declaration
	;
 */

typedef struct external_declaration {
	int type;
	int subtype;
}EXTERNAL_DECLARATION;

/******************************************************************************/

/**
 * declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;
 */

typedef struct declaration_specifiers{
	int type;
	struct type_specifier *type_specifier;
	struct declaration_specifiers *declaration_specifiers;
}DECLARATION_SPECIFIERS;


/******************************************************************************/

/**
 * function_definition
	: declaration_specifiers declarator declaration_list compound_statement {printf("#func 1#\n");}
	| declaration_specifiers declarator compound_statement {printf("#func 2#\n");}
	;
 */

typedef struct function_definition{
	EXTERNAL_DECLARATION k;
	int funtcion_type;
}FUNCTION_DEFINITION;

typedef struct function_definition1{
	FUNCTION_DEFINITION k;
	struct declaration_specifiers *dec_specifier;
	struct declarator * declarator; // 0k
	struct declaration_list * declaration_list;
	struct compound_statement * compound_statement;
}FUNCTION_DEFINITION1;


typedef struct function_definition2{
	FUNCTION_DEFINITION k;
	struct declaration_specifiers *dec_specifier;
	struct declarator * declarator; // 0k
	struct compound_statement * compound_statement;

}FUNCTION_DEFINITION2;

/******************************************************************************/

/**
 * declarator
	: pointer direct_declarator
	| direct_declarator
 */

typedef struct declarator{
	int type;
	struct direct_declarator *direct_declarator;
	struct pointer *pointer;
} DECLARATOR;

/******************************************************************************/


/**
 * pointer
	: '*'
	| '*' pointer
	;
 *
 */
 typedef struct pointer{
	 int type;
	 struct pointer *pointer;
 }POINTER;

 /******************************************************************************/

/**
 * direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;
 */

 typedef struct direct_declarator{
	 int type;
	 int subtype;
 }DIRECT_DECLARATOR;

 /**
  * : IDENTIFIER
  */
 typedef struct direct_declarator1{
	 DIRECT_DECLARATOR k;
 	 char *identifier;
  }DIRECT_DECLARATOR1;

  typedef struct direct_declarator2{
 	 DIRECT_DECLARATOR k;
  	 struct declarator *declarator;
   }DIRECT_DECLARATOR2;

/**
 * | direct_declarator '[' constant_expression ']'
 * | direct_declarator '[' ']' ->>>>>>> constant_expression = NULL
 */

 typedef struct direct_declarator3{
  	DIRECT_DECLARATOR k;
  	struct direct_declarator *direct_declarator;
  	//struct constant_expression *constant_expression;
  	int constant;
 }DIRECT_DECLARATOR3;

/**
 * 	| direct_declarator '(' parameter_type_list ')'
 */

 typedef struct direct_declarator4{
   	DIRECT_DECLARATOR k;
   	struct direct_declarator *direct_declarator;
   	struct parameter_type_list *parameter_type_list;
  }DIRECT_DECLARATOR4;


  /**
   * | direct_declarator '(' identifier_list ')'
   */
  /**
     * | direct_declarator '(' ')'
     */

  typedef struct direct_declarator5{
    	DIRECT_DECLARATOR k;
    	struct direct_declarator *direct_declarator;
    	struct identifier_list *identifier_list;
   }DIRECT_DECLARATOR5;


 /******************************************************************************/


/**
 * constant_expression
	: conditional_expression
	;
 *
 */

 typedef struct constant_expression{
	 int type;
	 struct conditional_expression * conditional_expression;
 }CONSTANT_EXPRESSION;

/******************************************************************************/
 /**
  * conditional_expression
	: logical_or_expression
	;
  */

 typedef struct conditional_expression{
 	 int type;
 	 struct logical_or_expression * logical_or_expression;
  }CONDITIONAL_EXPRESSION;

 /******************************************************************************/


/**
 * logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;
 */

 typedef struct logical_or_expression{
   	 int type;
   	 struct logical_or_expression * logical_or_expression;
   	 struct logical_and_expression * logical_and_expression;
 }LOGICAL_OR_EXPRESSION;

/******************************************************************************/

 /**
  * logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;
  */

 typedef struct logical_and_expression{
   	 int type;
   	 struct inclusive_or_expression * inclusive_or_expression;
   	 struct logical_and_expression * logical_and_expression;
 }LOGICAL_AND_EXPRESSION;

 /******************************************************************************/

 /**
  * inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;
  */

 typedef struct inclusive_or_expression{
   	 int type;
   	 struct inclusive_or_expression * inclusive_or_expression;
   	 struct exclusive_or_expression * exclusive_or_expression;
 }INCLUSIVE_OR_EXPRESSION;

 /******************************************************************************/

 /**
  * exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;
  */
 typedef struct exclusive_or_expression{
   	 int type;
   	 struct and_expression * and_expression;
   	 struct exclusive_or_expression * exclusive_or_expression;
 }EXCLUSIVE_OR_EXPRESSION;

 /******************************************************************************/

 /**
  * and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;
  */
 typedef struct and_expression{
   	 int type;
   	 struct and_expression * and_expression;
   	 struct equality_expression * equality_expression;
 }AND_EXPRESSION;

 /******************************************************************************/

 /**
  * equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;
  */

 typedef struct equality_expression{
   	 int type;
   	 int op;
   	 struct relational_expression * relational_expression;
   	 struct equality_expression * equality_expression;
 }EQUALITY_EXPRESSION;

 /******************************************************************************/

/**
 * relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;
 */

 typedef struct relational_expression{
   	 int type;
   	 int op;
   	 struct relational_expression * relational_expression;
   	 struct shift_expression * shift_expression;
 }RELATIONAL_EXPRESSION;

 /******************************************************************************/

 /**
  * shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
  */

 typedef struct shift_expression{
   	 int type;
   	 int op;
   	 struct shift_expression * shift_expression;
   	 struct additive_expression * additive_expression;
 }SHIFT_EXPRESSION;

 /******************************************************************************/

/**
 * additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;
 */

 typedef struct additive_expression{
   	 int type;
   	 int op;
   	 struct multiplicative_expression * multiplicative_expression;
   	 struct additive_expression * additive_expression;
 }ADDITIVE_EXPRESSION;

 /******************************************************************************/

 /**
  * multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	| multiplicative_expression '%' unary_expression
	;
  *
  */

 typedef struct multiplicative_expression{
   	 int type;
   	 int op;
   	 struct multiplicative_expression * multiplicative_expression;
   	 struct unary_expression * unary_expression;
 }MULTIPLICATIVE_EXPRESSION;

 /******************************************************************************/

 /**
  * unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;
  */

 typedef struct unary_operator{
   	 int type;
   	 int op;
 }UNARY_OPERATOR;

 /******************************************************************************/

 /**
  * unary_expression
	: postfix_expression
	| unary_operator unary_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;
  */

 typedef struct unary_expression{
   	 int type;
   	 int subtype;
 }UNARY_EXPRESSION;

 //	: postfix_expression
 typedef struct unary_expression1{
	 UNARY_EXPRESSION k;
	 struct postfix_expression * postfix_expression;
 }UNARY_EXPRESSION1;

 //| unary_operator unary_expression
 typedef struct unary_expression2{
	 UNARY_EXPRESSION k;
	 struct unary_operator * unary_operator;
	 struct unary_expression * unary_expression;
 }UNARY_EXPRESSION2;

 //	| SIZEOF unary_expression
 typedef struct unary_expression3{
	 UNARY_EXPRESSION k;
	 struct unary_expression * unary_expression;
 }UNARY_EXPRESSION3;

 //	| SIZEOF '(' type_name ')'
 typedef struct unary_expression4{
	 UNARY_EXPRESSION k;
	 struct type_name * type_name;
 }UNARY_EXPRESSION4;

 /******************************************************************************/

 //duvida: se nao da pra dexa ele null e tal jah q eh parecido

/**
 * type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;
 */

 typedef struct type_name{
    	 int type;
    	 int subtype;
    	 struct specifier_qualifier_list * specifier_qualifier_list;
         struct abstract_declarator * abstract_declarator;
  }TYPE_NAMEi;

  /*
  //: specifier_qualifier_list
  typedef struct type_name1{
	  TYPE_NAMEi k;
     	 struct specifier_qualifier_list * specifier_qualifier_list;
   }TYPE_NAME1;

   //: specifier_qualifier_list abstract_declarator
   typedef struct type_name2{
		 TYPE_NAMEi k;
      	 struct specifier_qualifier_list * specifier_qualifier_list;
      	 struct abstract_declarator * abstract_declarator;
    }TYPE_NAME2;
*/
 /******************************************************************************/

    //duvida se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

 /**argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;
	*/

 typedef struct argument_expression_list{
    	 int type;
    	 struct argument_expression_list * argument_expression_list;
    	 struct assignment_expression * assignment_expression;
  }ARGUMENT_EXPRESSION_LIST;

 /******************************************************************************/

  /**
   * assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;
   */

  typedef struct assignment_expression{
     	 int type;
     	 int subtype;
   }ASSIGNMENT_EXPRESSION;

   //conditional_expression
   typedef struct assignment_expression1{
	   ASSIGNMENT_EXPRESSION k;
  	 struct conditional_expression * conditional_expression;
   }ASSIGNMENT_EXPRESSION1;

   //| unary_expression assignment_operator assignment_expression
   typedef struct assignment_expression2{
   	   ASSIGNMENT_EXPRESSION k;
   	   struct unary_expression * unary_expression;
   	   struct assignment_operator * assignment_operator;
   	   struct assignment_expression * assignment_expression;
   }ASSIGNMENT_EXPRESSION2;

 /******************************************************************************/

   //duvida: se eh soh meter um op ou se precisa por ele

   /**
    * assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	;
    */

   typedef struct assignment_operator{
      	 int type;
      	 int op;
    }ASSIGNMENT_OPERATOR;

 /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

    /**
     * specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;
     */

    typedef struct specifier_qualifier_list{
       	 int type;
       	 struct specifier_qualifier_list * specifier_qualifier_list;
       	 struct type_specifier * type_specifier;
     }SPECIFIER_QUALIFIER_LIST;

 /******************************************************************************/

     //duvida: fiquei na duvida do q fazer com essas paradas todas

     /**
      * type_specifier
	: VOID
	| CHAR
	| INT
	| FLOAT
	| struct_or_union_specifier
	| TYPE_NAME
	;
      */

    typedef struct type_specifier{
		int type;
		int	 datatype;
     	struct struct_or_union_specifier * struct_or_union_specifier;
    }TYPE_SPECIFIER;

 /******************************************************************************/

    //duvida: tem coisas q repete, nao da d otimizar?

/**
 * struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;
 */

    typedef struct struct_or_union_specifier{
      	int type;
       	int subtype;
    }STRUCT_OR_UNION_SPECIFIER;

    //: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
    typedef struct struct_or_union_specifier1{
    	STRUCT_OR_UNION_SPECIFIER k;
       	char *identifier;
       	struct struct_or_union * struct_or_union;
       	struct struct_declaration_list * struct_declaration_list;
    }STRUCT_OR_UNION_SPECIFIER1;

    //| struct_or_union '{' struct_declaration_list '}'
    typedef struct struct_or_union_specifier2{
    	STRUCT_OR_UNION_SPECIFIER k;
       	struct struct_or_union * struct_or_union;
      	struct struct_declaration_list * struct_declaration_list;
    }STRUCT_OR_UNION_SPECIFIER2;

    //	| struct_or_union IDENTIFIER
    typedef struct struct_or_union_specifier3{
    	STRUCT_OR_UNION_SPECIFIER k;
      	char *identifier;
      	struct struct_or_union * struct_or_union;
    }STRUCT_OR_UNION_SPECIFIER3;

 /******************************************************************************/

    //duvida: eh soh assim/?

/**
 * struct_or_union
	: STRUCT
	| UNION
	;
 */

    typedef struct struct_or_union{
      	int type;
      	int datatype;
    }STRUCT_OR_UNION;

    /******************************************************************************/

    //duvida: se esse da pra faze com null parecido com o q falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * init_declarator
	: declarator
	| declarator '=' initializer
	;
 */

    typedef struct init_declarator{
       	int type;
     	struct declarator * declarator;
        struct initializer * initializer;
    }INIT_DECLARATOR;
/*
    typedef struct init_declarator1{
    	INIT_DECLARATOR k;
      	struct declarator * declarator;
    }INIT_DECLARATOR1;

    typedef struct init_declarator2{
    	INIT_DECLARATOR k;
       	struct declarator * declarator;
       	struct initializer * initializer;
    }INIT_DECLARATOR2;
*/
    /******************************************************************************/

    //duvida: nao sei como fazer esse

/**
 * primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;
 */
  typedef struct primary_expression{
          	int type;
          	int subtype;
  }PRIMARY_EXPRESSION;

  typedef struct primary_expression1{
		  PRIMARY_EXPRESSION k;
		  char *identifier;
  }PRIMARY_EXPRESSION1;

  typedef struct primary_expression2{
  		  PRIMARY_EXPRESSION k;
  		  int constant;
    }PRIMARY_EXPRESSION2;

typedef struct primary_expression3{
      	 PRIMARY_EXPRESSION k;
          char *string_literal;
	}PRIMARY_EXPRESSION3;

typedef struct primary_expression4{
	      	 PRIMARY_EXPRESSION k;
	         struct expression *expression;
}PRIMARY_EXPRESSION4;


    //typedef struct declarator{
    //   	int type;
   //    	struct expression * expression;
   // }DECLARATOR;

    /******************************************************************************/

    //duvida: nao sei se direito como fazer esse aqui mtas coisas parecidas, nao sei se da
    //pra simplificar ou algo assim, nao sei se alguns precisam d op e tal

/**
 * postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')' {}
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;
 */

    typedef struct postfix_expression{
       	int type;
       	int subtype;
    }POSTFIX_ESPRESSION;

    //	: primary_expression
    typedef struct postfix_expression1{
    	POSTFIX_ESPRESSION k;
       	struct primary_expression * primary_expression;
    }POSTFIX_ESPRESSION1;

    //	| postfix_expression '[' expression ']'
    typedef struct postfix_expression2{
       	POSTFIX_ESPRESSION k;
       	struct postfix_expression * postfix_expression;
       	struct expression * expression;
    }POSTFIX_ESPRESSION2;

    //	| postfix_expression '(' ')'
    typedef struct postfix_expression3{
       	POSTFIX_ESPRESSION k;
       	struct postfix_expression * postfix_expression;
     }POSTFIX_ESPRESSION3;

     //	| postfix_expression '(' argument_expression_list ')' {}
     typedef struct postfix_expression4{
       	POSTFIX_ESPRESSION k;
       	struct postfix_expression * postfix_expression;
       	struct argument_expression_list * argument_expression_list;
     }POSTFIX_ESPRESSION4;

     //	| postfix_expression '.' IDENTIFIER
     typedef struct postfix_expression5{
       	POSTFIX_ESPRESSION k;
      	struct postfix_expression * postfix_expression;
       	char * identifier;
     }POSTFIX_ESPRESSION5;

     //	| postfix_expression PTR_OP IDENTIFIER
     typedef struct postfix_expression6{
      	POSTFIX_ESPRESSION k;
      	struct postfix_expression * postfix_expression;
       	//int op;
       	char * identifier;
     }POSTFIX_ESPRESSION6;

     //		| postfix_expression INC_OP
     typedef struct postfix_expression7{
      	POSTFIX_ESPRESSION k;
      	struct postfix_expression * postfix_expression;
       	int op;
     }POSTFIX_ESPRESSION7;

     //		| postfix_expression DEC_OP
     typedef struct postfix_expression8{
      	POSTFIX_ESPRESSION k;
      	struct postfix_expression * postfix_expression;
       	int op;
     }POSTFIX_ESPRESSION8;


    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * expression
	: assignment_expression
	| expression ',' assignment_expression
	;
 */

    typedef struct expression{
        int type;
        struct expression * expression;
        struct assignment_expression * assignment_expression;
    }EXPRESSION;

    /******************************************************************************/

    //duvida: se esse da pra faze com null parecido com o q falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * declaration
	: declaration_specifiers ';' {}
	| declaration_specifiers init_declarator_list ';' {}
	;
 */

    typedef struct declaration{
        int type;
        //int subtype;
        struct declaration_specifiers * declaration_specifiers;
        struct init_declarator_list * init_declarator_list;
    }DECLARATION;
/*
    //	: declaration_specifiers ';' {}
    typedef struct declaration1{
    	DECLARATION k;
        struct declaration_specifiers * declaration_specifiers;
    }DECLARATION1;

    //| declaration_specifiers init_declarator_list ';' {}
    typedef struct declaration2{
    	DECLARATION k;
        struct declaration_specifiers * declaration_specifiers;
        struct init_declarator_list * init_declarator_list;
    }DECLARATION2;
*/
    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;
 */

    typedef struct init_declarator_list{
        int type;
        struct init_declarator_list * init_declarator_list;
        struct init_declarator * init_declarator;
    }INIT_DECLARATOR_LIST;

    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;
 */

    typedef struct struct_declaration_list{
        int type;
        struct struct_declaration_list * struct_declaration_list;
        struct struct_declaration * struct_declaration;
    }STRUCT_DECLARATION_LIST;

    /******************************************************************************/

/**
 * struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;
 */

    typedef struct struct_declaration{
       int type;
       struct specifier_qualifier_list * specifier_qualifier_list;
       struct struct_declarator_list * struct_declarator_list;
    }STRUCT_DECLARATION;

    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;
 */

    typedef struct struct_declarator_list{
        int type;
        struct struct_declarator_list * struct_declarator_list;
        struct struct_declarator * struct_declarator;
    }STRUCT_DECLARATOR_LIST;

    /******************************************************************************/

/**
 * parameter_type_list
	: parameter_list
	;
 */

    typedef struct parameter_type_list{
        int type;
        struct parameter_list * parameter_list;
    }PARAMETER_TYPE_LIST;

    /******************************************************************************/

    //duvida: a estrutura da parada ta cortada nao tem ; talvez esteja faltando partes

/**
 * struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
 */

    typedef struct struct_declarator{
        int type;
        int subtype;
    }STRUCT_DECLARATOR;

    //	: declarator
    typedef struct struct_declarator1{
    	STRUCT_DECLARATOR k;
        struct declarator * declarator;
    }STRUCT_DECLARATOR1;

    //	| ':' constant_expression
    typedef struct struct_declarator2{
    	STRUCT_DECLARATOR k;
        struct constant_expression * constant_expression;
    }STRUCT_DECLARATOR2;

    //	| declarator ':' constant_expression
    typedef struct struct_declarator3{
    	STRUCT_DECLARATOR k;
        struct declarator * declarator;
        struct constant_expression * constant_expression;
    }STRUCT_DECLARATOR3;

    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;
 */

    typedef struct parameter_list{
        int type;
        struct parameter_list * parameter_list;
        struct parameter_declaration * parameter_declaration;
    }PARAMETER_LIST;

    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier
    //ou tipo dar uma otimizada pq declaration_specifieres tem em todos

/**
 * parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;
 */

    typedef struct parameter_declaration{
        int type;
        int subtype;
    }PARAMETER_DECLARATION;

    //	: declaration_specifiers declarator
    typedef struct parameter_declaration1{
    	PARAMETER_DECLARATION k;
    	struct declaration_specifiers * declaration_specifiers;
    	struct declarator * declarator;
    }PARAMETER_DECLARATION1;

    //	| declaration_specifiers abstract_declarator
    typedef struct parameter_declaration2{
    	PARAMETER_DECLARATION k;
    	struct declaration_specifiers * declaration_specifiers;
    	struct abstract_declarator * abstract_declarator;
    }PARAMETER_DECLARATION2;

    //	| declaration_specifiers
    typedef struct parameter_declaration3{
    	PARAMETER_DECLARATION k;
    	struct declaration_specifiers * declaration_specifiers;
    }PARAMETER_DECLARATION3;

    /******************************************************************************/

    //duvida: se esse da pra faze com null parecido com o q  falasse nos primeiros
    //lah tipo o declaration_specifier

/**
 * identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;
 */

    typedef struct identifier_list{
        int type;
        char * identifier;
    	struct identifier_list * identifier_list;
    }IDENTIFIER_LIST;

    /******************************************************************************/

    //duvida: se nao da pra otimizar jah q sao parecidos

/**
 * abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;
 */

    typedef struct abstract_declarator{
        int type;
        int subtype;
    }ABSTRACT_DECLARATOR;

    //	: pointer
    typedef struct abstract_declarator1{
    	ABSTRACT_DECLARATOR K;
    	struct pointer * pointer;
    }ABSTRACT_DECLARATOR1;

    //	| direct_abstract_declarator
    typedef struct abstract_declarator2{
    	ABSTRACT_DECLARATOR K;
    	struct direct_abstract_declarator * direct_abstract_declarator;
    }ABSTRACT_DECLARATOR2;

	//| pointer direct_abstract_declarator
    typedef struct abstract_declarator3{
    	ABSTRACT_DECLARATOR K;
    	struct pointer * pointer;
    	struct direct_abstract_declarator * direct_abstract_declarator;
    }ABSTRACT_DECLARATOR3;

    /******************************************************************************/

    //duvida: se nao da pra otimizar algo aih no meio e se precisa fazer algo pra esses
    //q sao tipo vazios "'[' ']'" e "'(' ')'"

    /**
     * direct_abstract_declarator
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
     */


    /******************************************************************************/

    //duvida: queria saber se tem diferen�a entre '{' initializer_list '}' e
    //'{' initializer_list ',' '}' tipo a strcut seria a mesma nao?? dai teria q fazer a
    //mesma coisa 2 vezes??

    /**
     * initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;
     */

    typedef struct initializer{
    	int type;
    	int subtype;
    }INITIALIZER;

    typedef struct initializer1{
    	INITIALIZER k;
    	struct assignment_expression * assignment_expression;
    }INITIALIZER1;

    typedef struct initializer2{
    	INITIALIZER k;
    	struct initializer_list *initializer_list;
    }INITIALIZER2;

    typedef struct initializer3{
    	INITIALIZER k;
    	struct initializer_list *initializer_list;
    }INITIALIZER3;


    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

    /**
     * initializer_list
	: initializer
	| initializer_list ',' initializer
	;
     */

    typedef struct initializer_list{
    	int type;
    	struct initializer_list *initializer_list;
    	struct initializer *initializer;
    }INITIALIZER_LIST;

    /******************************************************************************/

    /**
     * statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| function_definition
	| iteration_statement
	| jump_statement
	;
     */

    typedef struct statement{
    	int type;
    	int subtype;
    }STATEMENT;

    //: labeled_statement
    typedef struct statement1{
    	STATEMENT k;
    	struct labeled_statement *labeled_statement;
    }STATEMENT1;

    //	| compound_statement
    typedef struct statement2{
    	STATEMENT k;
    	struct compound_statement *compound_statement;
    }STATEMENT2;

    //	| expression_statement
    typedef struct statement3{
    	STATEMENT k;
    	struct expression_statement *expression_statement;
    }STATEMENT3;

    //	| selection_statement
    typedef struct statement4{
    	STATEMENT k;
    	struct selection_statement *selection_statement;
    }STATEMENT4;

    //	| function_definition
    typedef struct statement5{
    	STATEMENT k;
    	struct function_definition *function_definition;
    }STATEMENT5;

    //	| iteration_statement
    typedef struct statement6{
    	STATEMENT k;
    	struct iteration_statement *iteration_statement;
    }STATEMENT6;

	//| jump_statement
    typedef struct statement7{
        STATEMENT k;
        struct jump_statement *jump_statement;
    }STATEMENT7;


    /******************************************************************************/

    //duvida: se da pra otimizar pq todos tem statement

    /**
     * labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;
     */

    typedef struct labeled_statement{
        int type;
        int subtype;
    }LABELED_STATEMENT;

    //: IDENTIFIER ':' statement
    typedef struct labeled_statement1{
      	LABELED_STATEMENT k;
       	char *identifier;
      	struct statement *statement;
    }LABELED_STATEMENT1;

    //| CASE constant_expression ':' statement
    typedef struct labeled_statement2{
       	LABELED_STATEMENT k;
       	struct constant_expression *constant_expression;
       	struct statement *statement;
    }LABELED_STATEMENT2;

    //	| DEFAULT ':' statement
    typedef struct labeled_statement3{
       	LABELED_STATEMENT k;
      	struct statement *statement;
    }LABELED_STATEMENT3;

    /******************************************************************************/

    //duvida: esse '{' '}' simplesmente ignora?? e tb se nao tem uma otimiza�ao aih

    /**
     * compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;
     */

    typedef struct compound_statement{
    	int type;
        struct declaration_list *declaration_list;
        struct statement_list * statement_list;
    }COMPOUND_STATEMENT;
/*
    typedef struct compound_statement1{
    	COMPOUND_STATEMENT k;
    }COMPOUND_STATEMENT1;

    typedef struct compound_statement2{
    	COMPOUND_STATEMENT k;
       	struct statement_list * statement_list;
    }COMPOUND_STATEMENT2;

    typedef struct compound_statement3{
    	COMPOUND_STATEMENT k;
       	struct declaration_list *declaration_list;
    }COMPOUND_STATEMENT3;

    typedef struct compound_statement4{
        COMPOUND_STATEMENT k;
        struct declaration_list *declaration_list;
        struct statement_list * statement_list;
    }COMPOUND_STATEMENT4;
*/
    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

    /**
     * declaration_list
	: declaration
	| declaration_list declaration
	;
     */

    typedef struct declaration_list{
    	int type;
    	struct declaration_list *declaration_list;
    	struct declaration *declaration;
    }DECLARATION_LIST;

    /******************************************************************************/

    //duvida: se esse da pra faze com null como falasse nos primeiros
    //lah tipo o declaration_specifier

    /**
     * statement_list
	: statement
	| statement_list statement
	;
     */

    typedef struct statement_list{
    	int type;
    	struct statement_list *statement_list;
    	struct statement *statement;
    }STATEMENT_LIST;

    /******************************************************************************/

    //duvida: essa estrutura q eh soh um ; precisa fazer algo??? RE: OK

    /**
     * expression_statement
	: ';'
	| expression ';'
	;
     */

    typedef struct expression_statement{
    	int type;
    	struct expression * expression;
    }EXPRESSION_STATEMENT;

    /******************************************************************************/

    //duvida: se nao da pra faze em 1 struct soh com 2 statement se nao tem else
    //ele um deles eh null

    /**
     * selection_statement
	: IF '(' expression ')' statement {}
	| IF '(' expression ')' statement ELSE statement {}
	;
     */

    typedef struct selection_statement{
    	int type;
    	struct expression * expression;
    	struct statement * statement;
    	struct statement * statement2;
    }SELECTION_STATEMENT;


    /******************************************************************************/

    //duvida: esses 2 nao da pra mata em uma soh??? jah q soh muda a ordem, nao??

    /**
     * iteration_statement
	: WHILE '(' expression ')' statement {}
	| DO statement WHILE '(' expression ')' ';' {}
	;
     */

    typedef struct iteration_statement{
    	int type;
    	int subtype;
    	struct expression * expression;
    	struct statement * statement;
    }ITERATION_STATEMENT;

    /******************************************************************************/

    //duvida: nao vejo nada pra fazer alem dakele expression ali e tal
    //dai to meio perdido

    /**
     * jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;
     */
    typedef struct jump_statement{
    	int type;
    	int jump;
    	char *identifier;
    	struct expression *expression;
    }JUMP_STATEMENT;


    /******************************************************************************/


#endif /* COMPILER_H_ */
