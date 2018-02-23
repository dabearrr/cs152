/* 
 * Sample Scanner1: 
 * Description: Replace the string "username" from standard input 
 *              with the user's login name (e.g. lgao)
 * Usage: (1) $ flex sample1.lex
 *        (2) $ gcc lex.yy.c -lfl
 *        (3) $ ./a.out
 *            stdin> username
 *	      stdin> Ctrl-D
 * Question: What is the purpose of '%{' and '%}'?
 *           What else could be included in this section?
 */

number		[0-9]{1,}
operation		["+","-","/","*"]
expression		{number}({operation}{number}){1,}
calculate		({number}|{expression})[=]

%%
{operation}	printf("Found the op: %s ! \n", yytext);
{number} printf("Found the num: %s ! \n", yytext);
{expression} printf("Found the expres: %s ! \n", yytext);
{calculate} printf("Found the calculate: %s ! \n", yytext);
. printf("Unrecognized character"); exit(0);
%%

main()
{
  printf("please input stuff\n");
  yylex();
}
