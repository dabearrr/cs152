/*
	Raymond Farias 861158225
	Jonathan Herrera 861239801
*/
%{
	#define YY_NO_UNPUT

	#include <stdio.h>
	#include <stdlib.h>
	int yyerror (char* s);
	int yylex(void);
	extern int curPos;
	extern int curLine;
	extern char* yytext;
	FILE* inputFile;
%}

%union {
	int val;
	char* op_val;
}

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN
%token AND OR

%token <val> NUMBER
%token <op_val> IDENT

%token L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token MULT DIV MOD ADD SUB
%token LT LTE GT GTE EQ NEQ
%token NOT

%error-verbose
%start program

%%
program:	program function { printf("program -> function program\n"); }
			| function { printf("program -> function\n"); }
			;
			
function:	FUNCTION IDENT SEMICOLON function_chunk_a function_chunk_b function_chunk_c { printf(" FUNCTION IDENT SEMICOLON function_chunk_a function_chunk_b function_chunk_c \n"); }
			;

function_chunk_a: 	BEGIN_PARAMS declaration_s END_PARAMS { printf("function_chunk_a -> BEGIN_PARAMS declaration_s END_PARAMS \n"); }
					| BEGIN_PARAMS END_PARAMS { printf("function_chunk_a -> BEGIN_PARAMS END_PARAMS \n"); }

function_chunk_b: 	BEGIN_LOCALS declaration_s END_LOCALS { printf("function_chunk_b -> BEGIN_LOCALS declaration_s END_LOCALS\n"); }
					| BEGIN_LOCALS END_LOCALS { printf("function_chunk_b -> BEGIN_LOCALS END_LOCALS\n"); }

function_chunk_c: 	BEGIN_BODY statement_ns END_BODY { printf("function_chunk_c -> BEGIN_BODY statement_ns END_BODY \n"); }
					| BEGIN_BODY END_BODY { printf("function_chunk_c -> BEGIN_BODY END_BODY \n"); }
			
			
declaration_s:	declaration SEMICOLON declaration_s { printf("declaration_s -> declaration semicolon declaration_s \n"); }
				| declaration SEMICOLON { printf("declaration_s -> declaration\n"); }
				;

statement_ns: 	statement SEMICOLON statement_ns { printf("statement SEMICOLON statement_ns \n"); }
				| statement SEMICOLON { printf("statement_ns -> statement SEMICOLON \n"); }
            ;

declaration: identifier_ns COLON arrayint { printf("declaration -> identifier_ns COLON arrayint \n"); }
           ;

identifier_ns: 	IDENT COMMA identifier_ns { printf("identifier_ns -> IDENT COMMA identifier_ns \n"); }
				| IDENT { printf("identifier_ns -> IDENT \n"); }
             ;

arrayint: 	INTEGER { printf("arrayint -> INTEGER \n"); }
			| ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER { printf("arrayint -> ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER \n"); }
        ;

statement: 	a_statement { printf("statement -> a_statement \n"); }
			| b_statement { printf("statement -> b_statement \n"); }
			| c_statement { printf("statement -> c_statement \n"); }
			| d_statement { printf("statement -> d_statement \n"); }
			| e_statement { printf("statement -> e_statement \n"); }
			| f_statement { printf("statement -> f_statement \n"); }
			| g_statement { printf("statement -> g_statement \n"); }
			| h_statement { printf("statement -> h_statement \n"); }
			| i_statement { printf("statement -> i_statement \n"); }
         ;

a_statement: var ASSIGN expression { printf("a_statement -> var ASSIGN expression \n"); }
           ;

b_statement: 	IF bool_expr THEN statement_ns ENDIF { printf("b_statement -> IF bool_expr THEN statement_ns ENDIF \n"); }
				| IF bool_expr THEN ELSE statement_ns ENDIF { printf("b_statement -> IF bool_expr THEN ELSE statement_ns ENDIF \n"); }
           ;

c_statement: WHILE bool_expr BEGINLOOP statement_ns ENDLOOP { printf("c_statement -> WHILE bool_expr BEGINLOOP statement_ns ENDLOOP \n"); }
           ;

d_statement: DO BEGINLOOP statement_ns ENDLOOP WHILE bool_expr { printf("d_statement -> DO BEGINLOOP statement_ns ENDLOOP WHILE bool_expr \n"); }
           ;

e_statement: FOREACH IDENT IN IDENT BEGINLOOP statement_ns ENDLOOP { printf("e_statement -> FOREACH IDENT IN IDENT BEGINLOOP statement_ns ENDLOOP \n"); }
           ;

f_statement: READ var_ns { printf("f_statement -> READ var_ns \n"); }
           ;

g_statement: WRITE var_ns { printf("g_statement -> WRITE var_ns \n"); }
           ;

h_statement: CONTINUE { printf("h_statement -> CONTINUE \n"); }
           ;

i_statement: RETURN expression { printf("i_statement -> RETURN expression \n"); }
           ;

var: 	IDENT { printf("var -> IDENT \n"); } 
		| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET { printf("var -> IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET \n"); }
   ;

var_ns: var COMMA var_ns { printf("var_ns -> var COMMA var_ns \n"); } 
		| var { printf("var_ns -> var \n"); }
      ;

bool_expr: relation_and_expr  { printf("bool_expr -> relation_and_expr \n"); }
			| relation_and_expr OR bool_expr { printf("bool_expr -> relation_and_expr OR bool_expr \n"); }
        ;

relation_and_expr: 	relation_expr { printf("relation_and_expr -> relation_expr \n"); }
					| relation_expr AND relation_and_expr { printf("relation_and_expr -> relation_expr AND relation_and_expr \n"); }
                 ;

relation_expr: 	NOT rexpr { printf("relation_expr -> NOT rexpr \n"); } 
				| rexpr { printf("relation_expr -> rexpr \n"); }
             ;

rexpr: 	expression comp expression { printf("rexpr -> expression comp expression \n"); } 
		| TRUE { printf("rexpr -> TRUE \n"); } 
		| FALSE { printf("rexpr -> FALSE \n"); }
		| L_PAREN bool_expr R_PAREN { printf("rexpr -> L_PAREN bool_expr R_PAREN \n"); }
     ;

comp:	EQ { printf("comp -> EQ \n"); }
		| NEQ { printf("comp -> NEQ \n"); }
		| LT { printf("comp -> LT \n"); }
		| GT { printf("comp -> GT \n"); }
		| LTE { printf("comp -> LTE \n"); }
		| GTE { printf("comp -> GTE \n"); }
    ;

expression: multiplicative_expr exprsum_s { printf("expression -> multiplicative_expr exprsum_s \n"); } 
			| multiplicative_expr { printf("expression -> multiplicative_expr \n"); }
          ;

exprsum_s: 	exprsum exprsum_s { printf("exprsum_s -> exprsum exprsum_s \n"); } 
			| exprsum { printf("exprsum_s -> exprsum \n"); }
         ;
		 
exprsum:	ADD multiplicative_expr { printf("exprsum -> ADD multiplicative_expr \n"); } 
			| SUB multiplicative_expr { printf("exprsum -> SUB multiplicative_expr \n"); }

multiplicative_expr: term term_s { printf("multiplicative_expr -> term term_s \n"); }  
					| term { printf("multiplicative_expr -> term \n"); } 
                   ;
			
term_s: MULT term term_s { printf("term_s -> MULT term term_s \n"); }
		| MULT term { printf("term_s -> MULT term \n"); }
		| DIV term term_s { printf("term_s -> DIV term term_s \n"); }
		| DIV term { printf("term_s -> DIV term \n"); }
		| MOD term term_s { printf("term_s -> MOD term term_s \n"); }
		| MOD term { printf("term_s -> MOD term \n"); }
		;

term: 	upterm { printf("term -> upterm \n"); }
		| SUB upterm { printf("term -> SUB upterm \n"); }
		| IDENT termidentifier { printf("term -> IDENT termidentifier \n"); }
    ;

upterm: var { printf("upterm -> var \n"); }
		| NUMBER { printf("upterm -> NUMBER \n"); }
		| L_PAREN expression R_PAREN { printf("upterm -> L_PAREN expression R_PAREN \n"); }
      ;

termidentifier: L_PAREN termexpression R_PAREN { printf("termidentifier -> L_PAREN termexpression R_PAREN \n"); }
				| L_PAREN R_PAREN { printf("termidentifier -> L_PAREN R_PAREN \n"); }
              ;

termexpression: expression { printf("termexpression -> expression \n"); }
				| expression COMMA termexpression { printf("termexpression -> expression COMMA termexpression \n"); }

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

int yyerror(char* s) {
  printf("Error at line %d, column %d: Error at \"%s\" \n", curLine, curPos, s);
  exit(1);
}

