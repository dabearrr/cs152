%%
"function" 	{printf("FUNCTION");}
"beginparams" 	{printf("BEGIN_PARAMS");}
"endparams" 	{printf("END_PARAMS");}
"beginlocals" 	{printf("BEGIN_LOCALS");}
"endlocals" 	{printf("END_LOCALS");}
"beginbody" 	{printf("BEGIN_BODY");}
"endbody" 	{printf("END_BODY");}
"integer" 	{printf("INTEGER");}
"array" 	{printf("ARRAY");}
"of" 	{printf("OF");}
"if" 	{printf("IF");}
"then" 	{printf("THEN");}
"endif" 	{printf("ENDIF");}
"else" 	{printf("ELSE");}
"while" 	{printf("WHILE");}
"do" 	{printf("DO");}
"beginloop" 	{printf("BEGINLOOP");}
"endloop" 	{printf("ENDLOOP");}
"continue" 	{printf("CONTINUE");}
"read" 	{printf("READ");}
"write" 	{printf("WRITE");}
"and" 	{printf("AND");}
"or" 	{printf("OR");}
"not" 	{printf("NOT");}
"true" 	{printf("TRUE");}
"false" 	{printf("FALSE");}
"return" 	{printf("RETURN");}
"-" 	{printf("SUB");}
"+" 	{printf("ADD");}
"*" 	{printf("MULT");}
"/" 	{printf("DIV");}
"%" 	{printf("MOD");}
"==" 	{printf("EQ");}
"<>" 	{printf("NEQ");}
"<" 	{printf("LT");}
">" 	{printf("GT");}
"<=" 	{printf("LTE");}
">=" 	{printf("GTE");}
";" 	{printf("SEMICOLON");}
":" 	{printf("COLON");}
"," 	{printf("COMMA");}
"(" 	{printf("L_PAREN");}
")" 	{printf("R_PAREN");}
"[" 	{printf("L_SQUARE_BRACKET");}
"]" 	{printf("R_SQUARE_BRACKET");}
":=" 	{printf("ASSIGN");}
%%

main()
{
  printf("please input stuff\n");
  yylex();
}
