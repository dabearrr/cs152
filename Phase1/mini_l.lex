digit		[0-9]
number		{digit}{1,}
letter		[a-zA-Z]
identifier	({letter})({letter}|{digit})*(_+({letter}|{digit})+)*
badida		({digit}|_+)({letter}|{digit})*((_)+({letter}|{digit})+)*
badidb		{identifier}_+

	int curPos = 1;
	int curLine = 1;
%%
"function" 	{printf("FUNCTION\n", yytext); curPos += yyleng;}
"beginparams" 	{printf("BEGIN_PARAMS\n", yytext); curPos += yyleng;}
"endparams" 	{printf("END_PARAMS\n", yytext); curPos += yyleng;}
"beginlocals" 	{printf("BEGIN_LOCALS\n", yytext); curPos += yyleng;}
"endlocals" 	{printf("END_LOCALS\n", yytext); curPos += yyleng;}
"beginbody" 	{printf("BEGIN_BODY\n", yytext); curPos += yyleng;}
"endbody" 	{printf("END_BODY\n", yytext); curPos += yyleng;}
"integer" 	{printf("INTEGER\n", yytext); curPos += yyleng;}
"array" 	{printf("ARRAY\n", yytext); curPos += yyleng;}
"of" 	{printf("OF\n", yytext); curPos += yyleng;}
"if" 	{printf("IF\n", yytext); curPos += yyleng;}
"then" 	{printf("THEN\n", yytext); curPos += yyleng;}
"endif" 	{printf("ENDIF\n", yytext); curPos += yyleng;}
"else" 	{printf("ELSE\n", yytext); curPos += yyleng;}
"while" 	{printf("WHILE\n", yytext); curPos += yyleng;}
"do" 	{printf("DO\n", yytext); curPos += yyleng;}
"beginloop" 	{printf("BEGINLOOP\n", yytext); curPos += yyleng;}
"endloop" 	{printf("ENDLOOP\n", yytext); curPos += yyleng;}
"continue" 	{printf("CONTINUE\n", yytext); curPos += yyleng;}
"read" 	{printf("READ\n", yytext); curPos += yyleng;}
"write" 	{printf("WRITE\n", yytext); curPos += yyleng;}
"and" 	{printf("AND\n", yytext); curPos += yyleng;}
"or" 	{printf("OR\n", yytext); curPos += yyleng;}
"not" 	{printf("NOT\n", yytext); curPos += yyleng;}
"true" 	{printf("TRUE\n", yytext); curPos += yyleng;}
"false" 	{printf("FALSE\n", yytext); curPos += yyleng;}
"return" 	{printf("RETURN\n", yytext); curPos += yyleng;}
"-" 	{printf("SUB\n", yytext); curPos += yyleng;}
"+" 	{printf("ADD\n", yytext); curPos += yyleng;}
"*" 	{printf("MULT\n", yytext); curPos += yyleng;}
"/" 	{printf("DIV\n", yytext); curPos += yyleng;}
"%" 	{printf("MOD\n", yytext); curPos += yyleng;}
"==" 	{printf("EQ\n", yytext); curPos += yyleng;}
"<>" 	{printf("NEQ\n", yytext); curPos += yyleng;}
"<" 	{printf("LT\n", yytext); curPos += yyleng;}
">" 	{printf("GT\n", yytext); curPos += yyleng;}
"<=" 	{printf("LTE\n", yytext); curPos += yyleng;}
">=" 	{printf("GTE\n", yytext); curPos += yyleng;}
";" 	{printf("SEMICOLON\n", yytext); curPos += yyleng;}
":" 	{printf("COLON\n", yytext); curPos += yyleng;}
"," 	{printf("COMMA\n", yytext); curPos += yyleng;}
"(" 	{printf("L_PAREN\n", yytext); curPos += yyleng;}
")" 	{printf("R_PAREN\n", yytext); curPos += yyleng;}
"[" 	{printf("L_SQUARE_BRACKET\n", yytext); curPos += yyleng;}
"]" 	{printf("R_SQUARE_BRACKET\n", yytext); curPos += yyleng;}
":=" 	{printf("ASSIGN\n", yytext); curPos += yyleng;}
"\n"	{curLine++; curPos = 1;}
" "		{curPos += yyleng;}
"	"	{curPos += yyleng;}
"##".*	{curPos += yyleng;}
{number}	{printf("NUMBER %s\n", yytext);}
{identifier}	{printf("IDENT %s\n", yytext);}
{badida}	{printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", curLine, curPos, yytext); curPos += yyleng; exit(0);}
{badidb}	{printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", curLine, curPos, yytext); curPos += yyleng; exit(0);}
.	{printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", curLine, curPos, yytext); curPos += yyleng; exit(0);}
%%

main()
{
  printf("");
  yylex();
}
