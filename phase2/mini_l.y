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
@start prog_start

%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE SEMICOLON COLON COMMA LPAREN RPAREN LSQUARE RSQUARE ASSIGN RETURN
%token <val> NUMBERS
%token <op_val> IDENTIFIERS
%left MULT DIV MOD ADD SUB
%left LT LTE GT GTE EQ NEQ

%%
program:				PROGRAM IDENT SEMICOLON 