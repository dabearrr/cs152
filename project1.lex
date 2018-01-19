digit		[0-9]
number		{digit}{1,}
letter		[a-zA-Z]
identifier	({letter})({letter}|{digit})*(_({letter}|{digit})+)*

%%
"function" 	{printf("FUNCTION\n", yytext);}
"beginparams" 	{printf("BEGIN_PARAMS\n", yytext);}
"endparams" 	{printf("END_PARAMS\n", yytext);}
"beginlocals" 	{printf("BEGIN_LOCALS\n", yytext);}
"endlocals" 	{printf("END_LOCALS\n", yytext);}
"beginbody" 	{printf("BEGIN_BODY\n", yytext);}
"endbody" 	{printf("END_BODY\n", yytext);}
"integer" 	{printf("INTEGER\n", yytext);}
"array" 	{printf("ARRAY\n", yytext);}
"of" 	{printf("OF\n", yytext);}
"if" 	{printf("IF\n", yytext);}
"then" 	{printf("THEN\n", yytext);}
"endif" 	{printf("ENDIF\n", yytext);}
"else" 	{printf("ELSE\n", yytext);}
"while" 	{printf("WHILE\n", yytext);}
"do" 	{printf("DO\n", yytext);}
"beginloop" 	{printf("BEGINLOOP\n", yytext);}
"endloop" 	{printf("ENDLOOP\n", yytext);}
"continue" 	{printf("CONTINUE\n", yytext);}
"read" 	{printf("READ\n", yytext);}
"write" 	{printf("WRITE\n", yytext);}
"and" 	{printf("AND\n", yytext);}
"or" 	{printf("OR\n", yytext);}
"not" 	{printf("NOT\n", yytext);}
"true" 	{printf("TRUE\n", yytext);}
"false" 	{printf("FALSE\n", yytext);}
"return" 	{printf("RETURN\n", yytext);}
"-" 	{printf("SUB\n", yytext);}
"+" 	{printf("ADD\n", yytext);}
"*" 	{printf("MULT\n", yytext);}
"/" 	{printf("DIV\n", yytext);}
"%" 	{printf("MOD\n", yytext);}
"==" 	{printf("EQ\n", yytext);}
"<>" 	{printf("NEQ\n", yytext);}
"<" 	{printf("LT\n", yytext);}
">" 	{printf("GT\n", yytext);}
"<=" 	{printf("LTE\n", yytext);}
">=" 	{printf("GTE\n", yytext);}
";" 	{printf("SEMICOLON\n", yytext);}
":" 	{printf("COLON\n", yytext);}
"," 	{printf("COMMA\n", yytext);}
"(" 	{printf("L_PAREN\n", yytext);}
")" 	{printf("R_PAREN\n", yytext);}
"[" 	{printf("L_SQUARE_BRACKET\n", yytext);}
"]" 	{printf("R_SQUARE_BRACKET\n", yytext);}
":=" 	{printf("ASSIGN\n", yytext);}
"\n"	{;}
"##".*	{;}
{number}	{printf("NUMBER %s\n", yytext);}
{identifier}	{printf("IDENT %s\n", yytext);}
.	{;}
%%

main()
{
  printf("");
  yylex();
}
