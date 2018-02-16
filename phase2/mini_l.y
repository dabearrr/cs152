%{
#define YY_NO_UNPUT

using namespace std;

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

int yyerror (char* s);
int yylex(void);
%}

%union{
int val;
string* op_val;
}

%error-verbose
%start program

%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN
%token FOREACH IN
%token AND

%token <val> NUMBER
%token <op_val> IDENT

%token L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token MULT DIV MOD ADD SUB
%token LT LTE GT GTE EQ NEQ
%token NOT

%%
program:	/* empty */
			| function program { printf("program -> function program\n"); }
			| function { printf("program -> function\n"); }
			;
			
function:	FUNCTION IDENT SEMICOLON BEGINPARAMS declaration_s ENDPARAMS BEGINLOCALS declaration_s ENDLOCALS BEGINBODY statement_ns ENDBODY { PRINTF(" FUNCTION IDENTIFIER SEMICOLON BEGINPARAMS declaration_s ENDPARAMS BEGINLOCALS declaration_s ENDLOCALS BEGINBODY statement_ns ENDBODY \n"); }
			;

declaration_s:	declaration SEMICOLON declaration_s { printf("declaration_s -> declaration semicolon declaration_s"); }
				;

statement_ns: statement SEMICOLON statement_ns | statement SEMICOLON
            ;

declaration: identifier_ns COLON arrayint
           ;

identifier_ns: IDENT COMMA identifier_ns | IDENT
             ;

arrayint: INTEGER | ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
        ;

statement: a_statement | b_statement | c_statement | d_statement | e_statement | f_statement | h_statement | i_statement
         ;

a_statement: var ASSIGN expression 
           ;

b_statement: IF bool_expr THEN statement_ns ENDIF | IF bool_expr THEN ELSE statement_ns ENDIF
           ;

c_statement: WHILE bool_expr BEGINLOOP statement_ns ENDLOOP
           ;

d_statement: DO BEGINLOOP statement_ns ENDLOOP WHILE bool_expr
           ;

e_statement: FOREACH IDENT IN IDENT BEGINLOOP statement_ns ENDLOOP
           ;

f_statement: READ var_ns
           ;

g_statement: WRITE var_ns
           ;

h_statement: CONTINUE
           ;

i_statement: RETURN expression
           ;

var: IDENT | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
   ;

var_ns: var COMMA var_ns | var COMMA
      ;

bool_expr: relation_and_expr | relation_and_expr | bool_expr
        ;

relation_and_expr: relation_expr | relation_expr AND relation_and_expr
                 ;

relation_expr: NOT rexpr | rexpr
             ;

rexpr: expression comp expression | TRUE | FALSE | L_PAREN bool_expr R_PAREN
     ;

comp: EQ | NEQ | LT | GT | LTE | GTE 
    ;

expression: multiplicative_expr exprsum_s | multiplicative_expr
          ;

exprsum_s: ADD multiplicative_expr exprsum_s | SUB multiplicative_expr exprsum_s
         ;

multiplicative_expr: term term_s | term
                   ;

term_s: MULT term term_s | DIV term term_s | MOD term term_s
      ;

term: upterm | SUB upterm | IDENT | termidentifier
    ;

upterm: var | NUMBER | L_PAREN expression R_PAREN
      ;

termidentifier: L_PAREN termexpression R_PAREN | L_PAREN R_PAREN
              ;

termexpression: expression | expression COMMA termexpression

%%

int yyerror(string s)
{
  extern int curPos;	// defined and maintained in lex.c
  extern int curLine;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}

