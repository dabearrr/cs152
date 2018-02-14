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
@start program


%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN

%token <val> NUMBER
%token <op_val> IDENT

%left LPAREN RPAREN LSQUARE RSQUARE
%left MULT DIV MOD ADD SUB
%left LT LTE GT GTE EQ NEQ
%right NOT ASSIGN

%error-verbose
%start program

%%
program:	function program { printf("program -> function program\n"); }
			| function { printf("program -> function\n"); }
			
function:	function identifier semicolon beginparams declaration_s endparams beginlocals declaration_s endlocals beginbody statement_ns endbody { printf("Function -> function identifier ; beginparams DeclarationS endparams beginlocals DeclarationS endlocals beginbody StatementNS endbody \n"); }
