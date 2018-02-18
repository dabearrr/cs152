
%{   
	#include "y.tab.h"
	int curPos = 1;
	int curLine = 1;
%}
	
digit		[0-9]
number		{digit}{1,}
letter		[a-zA-Z]
ident	({letter})({letter}|{digit})*(_+({letter}|{digit})+)*
badida		({digit}|_+)({letter}|{digit})*((_)+({letter}|{digit})+)*
badidb		{ident}_+
%%
"function" 	{curPos += yyleng; return FUNCTION;}
"beginparams" 	{curPos += yyleng; return BEGIN_PARAMS;}
"endparams" 	{curPos += yyleng; return END_PARAMS;}
"beginlocals" 	{curPos += yyleng; return BEGIN_LOCALS;}
"endlocals" 	{curPos += yyleng; return END_LOCALS;}
"beginbody" 	{curPos += yyleng; return BEGIN_BODY;}
"endbody" 	{curPos += yyleng; return END_BODY;}
"integer" 	{curPos += yyleng; return INTEGER;}
"array" 	{curPos += yyleng; return ARRAY;}
"of" 	{curPos += yyleng; return OF;}
"if" 	{curPos += yyleng; return IF;}
"then" 	{curPos += yyleng; return THEN;}
"endif" 	{curPos += yyleng; return ENDIF;}
"else" 	{curPos += yyleng; return ELSE;}
"while" 	{curPos += yyleng; return WHILE;}
"do" 	{curPos += yyleng; return DO;}
"beginloop" 	{curPos += yyleng; return BEGINLOOP;}
"endloop" 	{curPos += yyleng; return ENDLOOP;}
"continue" 	{curPos += yyleng; return CONTINUE;}
"read" 	{curPos += yyleng; return READ;}
"write" 	{curPos += yyleng; return WRITE;}
"and" 	{curPos += yyleng; return AND;}
"or" 	{curPos += yyleng; return OR;}
"not" 	{curPos += yyleng; return NOT;}
"true" 	{curPos += yyleng; return TRUE;}
"false" 	{curPos += yyleng; return FALSE;}
"return" 	{curPos += yyleng; return RETURN;}
"-" 	{curPos += yyleng; return SUB;}
"+" 	{curPos += yyleng; return ADD;}
"*" 	{curPos += yyleng; return MULT;}
"/" 	{curPos += yyleng; return DIV;}
"%" 	{curPos += yyleng; return MOD;}
"==" 	{curPos += yyleng; return EQ;}
"<>" 	{curPos += yyleng; return NEQ;}
"<" 	{curPos += yyleng; return LT;}
">" 	{curPos += yyleng; return GT;}
"<=" 	{curPos += yyleng; return LTE;}
">=" 	{curPos += yyleng; return GTE;}
";" 	{curPos += yyleng; return SEMICOLON;}
":" 	{curPos += yyleng; return COLON;}
"," 	{curPos += yyleng; return COMMA;}
"(" 	{curPos += yyleng; return L_PAREN;}
")" 	{curPos += yyleng; return R_PAREN;}
"[" 	{curPos += yyleng; return L_SQUARE_BRACKET;}
"]" 	{curPos += yyleng; return R_SQUARE_BRACKET;}
":=" 	{curPos += yyleng; return ASSIGN;}
"\n"	{curLine++; curPos = 1;}
" "		{curPos += yyleng;}
"	"	{curPos += yyleng;}
"##".*	{curPos += yyleng;}
{number}	{return NUMBER;}
{ident}	{return IDENT;}
{badida}	{printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", curLine, curPos, yytext); curPos += yyleng; exit(0);}
{badidb}	{printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", curLine, curPos, yytext); curPos += yyleng; exit(0);}
.	{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", curLine, curPos, yytext); curPos += yyleng; exit(0);}
%%
