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

digit		[0-9]
alpha		[a-fA-F]
hextail		({digit}|{alpha}){1,9}
hex		0[xX]{hextail}

%%
{hex}	printf("Found the 64 bit hexadecimal number: %s !", yytext);
.	printf("");
%%

main()
{
  printf("please input stuff\n");
  yylex();
}
