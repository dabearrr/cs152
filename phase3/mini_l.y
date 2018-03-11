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
	#include "Utils.h"
	
	#include <iostream>
	#include <fstream>
	#include <vector>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <typeinfo>
	
	using namespace std;
	
	int yyerror (const char* s);
	int yylex(void);
	string intToString(int x);
	void printCode();
	string charToString(char*);
	void p(string);
	
	
	extern int curPos;
	extern int curLine;
	extern char* yytext;
	FILE* inputFile;
	int val;
	char* op_val;
	
	int testCounter = 0;
	vector<string> codeToWrite;
	MilCode mc;
	Utils utils;
	
	int IDENT_TYPE = 1;
	int IDENT_LIST_TYPE = 2;
	int INTEGER_TYPE = 3;
%}

%union{
  int val;
  char* op_val;
  Attribute* attr;
}

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN
%token AND OR

%token <val> NUMBER
%token <op_val> IDENT
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

declaration: identifier_ns COLON INTEGER {
		p("declaration integer, may want to reverse order"  + $1->toString());
		for(int i = 0; i < $1->list.size(); i++) {
			codeToWrite.push_back(mc.varName($1->list.at(i))); 
			codeToWrite.push_back(mc.copyElement($1->list.at(i), "$0")); 
		}
}
			| identifier_ns COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
		p("declaration array, may want to reverse order: " + $1->toString());
		p("the array size is: " + utils.intToString($5));
		for(int i = 0; i < $1->list.size(); i++) {
			codeToWrite.push_back(mc.arrayName($1->list.at(i), utils.intToString($5))); 
		}
}
           ;

identifier_ns: 	IDENT COMMA identifier_ns {
	p("identifier_ns new list: " + utils.charToString($1));
	p("identifier_ns checking the sub identifier_ns " + $3->toString());
	$$ = $3;
	$$->list.push_back(utils.charToString($1));
	$$->type = IDENT_LIST_TYPE;
	p("identifier_ns copied sub identifier_ns, should have two or more now " + $$->toString());
}
				| IDENT {
	p("identifier_ns -> IDENT: " + utils.charToString($1));
	$$ = new Attribute();
	$$->name = "IDENT LIST";
	$$->type = IDENT_TYPE;
	$$->list.push_back($1);
}
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
   
   p("before yyparse");
   yyparse();
   p("after yyparse");
   
   utils.printCode(codeToWrite);
  
  return 0;
}

int yyerror(const char* s) {
  printf("Error at line %d, column %d: Error at \"%s\" \n", curLine, curPos, s);
  exit(1);
  return 0;
}

void p(string log) {
	cout << "Logger #" << testCounter++ << " " << log << endl;
}

void printCode() {
	cout << "Code looks like: " << endl;
	for(int i = 0; i < codeToWrite.size(); i++) {
		cout << codeToWrite.at(i) << endl;
	}
}
