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

%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN

%token <val> NUMBER
%token <op_val> IDENT

%token LPAREN RPAREN LSQUARE RSQUARE
%token MULT DIV MOD ADD SUB
%token LT LTE GT GTE EQ NEQ
%token NOT

%error-verbose
%start program

%%
program:	/* empty */
			| function program { printf("program -> function program\n"); }
			| function { printf("program -> function\n"); }
			;
			
function:	function identifier semicolon beginparams declaration_s endparams beginlocals declaration_s endlocals beginbody statement_ns endbody { printf("Function -> function identifier ; beginparams DeclarationS endparams beginlocals DeclarationS endlocals beginbody StatementNS endbody \n"); }
			;

declaration_s:	declaration semicolon declaration_s { printf("declaration_s -> declaration semicolon declaration_s"); }
				;



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

