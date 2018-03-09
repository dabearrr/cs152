/*
	Raymond Farias 861158225
	Jonathan Herrera 861239801
*/
%{
	#define YY_NO_UNPUT
	#include "Vars.h"
	#include "MilCode.h"
	#include "SymbolTable.h"
	#include "Attribute.h"
	
	#include <iostream>
	#include <fstream>
	#include <vector>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	
	using namespace std;
	
	int yyerror (const char* s);
	int yylex(void);
	string intToString(int x);
	extern int curPos;
	extern int curLine;
	extern char* yytext;
	FILE* inputFile;
	int val;
	char* op_val;
	
	vector<string> codeToWrite;
	MilCode mc;
	
	int IDENT_TYPE = 1;
	int INTEGER_TYPE = 2;
%}

%union{
  int* val;
  char* op_val;
  Attribute* attr;
}

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN
%token AND OR

%token <attr> NUMBER
%token <op_val> IDENT
%type <val> INTEGER 
%type <attr> identifier_ns

%token L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token MULT DIV MOD ADD SUB
%token LT LTE GT GTE EQ NEQ
%token NOT

%error-verbose
%start program

%%
program:	program function {}
			| function {}
			;
			
function:	FUNCTION IDENT SEMICOLON function_chunk_a function_chunk_b function_chunk_c {}
			;

function_chunk_a: 	BEGIN_PARAMS declaration_s END_PARAMS {}
					| BEGIN_PARAMS END_PARAMS {}

function_chunk_b: 	BEGIN_LOCALS declaration_s END_LOCALS {}
					| BEGIN_LOCALS END_LOCALS {}

function_chunk_c: 	BEGIN_BODY statement_ns END_BODY {}
					| BEGIN_BODY END_BODY {}
			
			
declaration_s:	declaration SEMICOLON declaration_s {}
				| declaration SEMICOLON {}
				;

statement_ns: 	statement SEMICOLON statement_ns {}
				| statement SEMICOLON {}
            ;

declaration: identifier_ns COLON INTEGER {cout << "INTEGER IS " << *$3 << mc.varName($1->name) << endl << mc.copyElement($1->name, intToString(*$3)); }
			| identifier_ns COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {}
           ;

identifier_ns: 	IDENT COMMA identifier_ns {}
				| IDENT {$$ = new Attribute();
							string s($1);
							$$->name = s;}
             ;

statement: 	a_statement {}
			| b_statement {}
			| c_statement {}
			| d_statement {}
			| e_statement {}
			| f_statement {}
			| g_statement {}
			| h_statement {}
			| i_statement {}
         ;

a_statement: var ASSIGN expression {}
           ;

b_statement: 	IF bool_expr THEN statement_ns ENDIF {}
				| IF bool_expr THEN ELSE statement_ns ENDIF {}
           ;

c_statement: WHILE bool_expr BEGINLOOP statement_ns ENDLOOP {}
           ;

d_statement: DO BEGINLOOP statement_ns ENDLOOP WHILE bool_expr {}
           ;

e_statement: FOREACH IDENT IN IDENT BEGINLOOP statement_ns ENDLOOP {}
           ;

f_statement: READ var_ns {}
           ;

g_statement: WRITE var_ns {}
           ;

h_statement: CONTINUE {}
           ;

i_statement: RETURN expression {}
           ;

var: 	IDENT {} 
		| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {}
   ;

var_ns: var COMMA var_ns {} 
		| var {}
      ;

bool_expr: relation_and_expr  {}
			| relation_and_expr OR bool_expr {}
        ;

relation_and_expr: 	relation_expr {}
					| relation_expr AND relation_and_expr {}
                 ;

relation_expr: 	NOT rexpr {} 
				| rexpr {}
             ;

rexpr: 	expression comp expression {} 
		| TRUE {} 
		| FALSE {}
		| L_PAREN bool_expr R_PAREN {}
     ;

comp:	EQ {}
		| NEQ {}
		| LT {}
		| GT {}
		| LTE {}
		| GTE {}
    ;

expression: multiplicative_expr exprsum_s {} 
			| multiplicative_expr {}
          ;

exprsum_s: 	exprsum exprsum_s {} 
			| exprsum {}
         ;
		 
exprsum:	ADD multiplicative_expr {} 
			| SUB multiplicative_expr {}

multiplicative_expr: term term_s {}  
					| term {} 
                   ;
			
term_s: MULT term term_s {}
		| MULT term {}
		| DIV term term_s {}
		| DIV term {}
		| MOD term term_s {}
		| MOD term {}
		;

term: 	upterm {}
		| SUB upterm {}
		| IDENT termidentifier {}
    ;

upterm: var {}
		| NUMBER {}
		| L_PAREN expression R_PAREN {}
      ;

termidentifier: L_PAREN termexpression R_PAREN {}
				| L_PAREN R_PAREN {}
              ;

termexpression: expression {}
				| expression COMMA termexpression {}

%%

int main(int argc, char ** argv) {
  if(argc > 1) {
      inputFile = fopen(argv[1], "r");
      if(!inputFile) {
         inputFile = stdin;
      }
   }
   else {
      inputFile = stdin;
   }
   
   yyparse();
  
  return 0;
}

int yyerror(const char* s) {
  printf("Error at line %d, column %d: Error at \"%s\" \n", curLine, curPos, s);
  exit(1);
  return 0;
}

string intToString(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

