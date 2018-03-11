/*
	Raymond Farias 861158225
	Jonathan Herrera 861239801
*/
%{
	#define YY_NO_UNPUT
	#include "Vars.h"
	#include "MilCode.h"
	#include "SymbolTable.h"
	#include "Attribute.h"
	#include "Utils.h"
	
	#include <iostream>
	#include <fstream>
	#include <vector>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <typeinfo>
	#include <map>
	#include <stack>
	
	using namespace std;
	
	int yyerror (const char* s);
	int yylex(void);
	string intToString(int x);
	void printCode();
	string charToString(char*);
	void p(string);
	
	struct Function {
		string name;
		Function() : name() {}
		Function(string n) : name(n){}
	};
	
	enum symbol_type {INT, INTARRAY, FUNC};
	struct Symbol {
		int val;
		int size;
		string name;
		symbol_type type;
		
		Symbol() : val(0), size(0), name(), type() {}
		Symbol(int iv, int is, string sn, symbol_type st) : val(iv), size(is), name(sn), type(st) {}
		
	};
	
	extern int curPos;
	extern int curLine;
	extern char* yytext;
	FILE* inputFile;
	int val;
	char* op_val;
	
	int testCounter = 0;
	vector<string> codeToWrite;
	MilCode mc;
	Utils utils;
	Vars tempGen;
	
	int ATTR_INTEGER_TYPE = 0;
	int ATTR_LIST_TYPE = 1;
	int ATTR_FUNC_TYPE = 2;
	int NUMBER_TYPE = 3;
	
	stack<string> identStack;
	stack<string> varStack;
	stack<string> expStack;
	stack<string> paramStack;
	stack<string> labelStack;
	
	stringstream codeStream;
	ostringstream outputCodeStream;
	
	int paramCount = 0;
	
	map<string, Function> functionTable;
	map<string, Symbol> symbolTable;
	bool mainExists = false;
%}

%union{
  int val;
  char* op_val;
  Attribute* attr;
}

%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY 
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE 
%token READ WRITE TRUE FALSE SEMICOLON COLON COMMA  
%token ASSIGN RETURN
%token AND OR

%token L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token MULT DIV MOD ADD SUB
%token LT LTE GT GTE EQ NEQ
%token NOT

%token <val> NUMBER
%token <op_val> IDENT
%type <attr> identifier_ns
%type <attr> var
%type <attr> expression multiplicative_expr term rexpr
%type <op_val> comp

%error-verbose
%start start_here

%%
start_here:	program { if (!mainExists) { yyerror("Error: main does not exist"); } }

program:	
			| function program
			;
			
function:	FUNCTION IDENT { codeStream << "func " << $2 << endl; } SEMICOLON BEGIN_PARAMS declaration_s {
	while(!paramStack.empty()) {
		codeStream << "= " << paramStack.top() << ", " << "$" << paramCount++ << endl;
		paramStack.pop();
	}
}	
			END_PARAMS BEGIN_LOCALS declaration_s END_LOCALS BEGIN_BODY statement_ns END_BODY {
	outputCodeStream << "endfunc\n";
	symbolTable.clear();
	if (utils.charToString($2) == "main") {
		mainExists = true;
	}
	
	Function f($2);
	addFunction(f);
	while(!paramStack.empty()) {
		paramStack.pop();
	}
	
}
			;
			
declaration_s:	 
				| declaration SEMICOLON declaration_s
				;

statement_ns: 	
				| statement SEMICOLON statement_ns
            ;

declaration: IDENT identifier_ns COLON INTEGER {
		p("declaration integer "  + $1->toString());
		identStack.push($1);
		paramStack.push($1);
		
		while(!identStack.empty()) {
			string temp = identStack.top();
			Symbol tempSymbol(0, 0, temp, INT);
			addSymbol(tempSymbol);
			codeStream << ". " << temp << endl;
			identStack.pop();
		}
}
			| IDENT identifier_ns COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
		p("declaration array "  + $1->toString());
		identStack.push($1);
		paramStack.push($1);
		
		while(!identStack.empty()) {
			string temp = identStack.top();
			Symbol tempSymbol(0, $6, temp, INTARRAY);
			addSymbol(tempSymbol);
			codeStream << ".[] " << temp << ", " << $6 << endl;
			identStack.pop();
		}
}
           ;

identifier_ns: 	
				| COMMA IDENT identifier_ns {
	identStack.push($2);
	paramStack.push($2);
}
             ;

statement: 	var ASSIGN expression {
	if ($1->type == ATTR_INTEGER_TYPE) {
		codeStream << mc.copyElement($1->name, $3->name) << endl;
	} else {
		codeStream << mc.arrayAccessAssignTo($1->name, $1->index, $3->name) << endl;
	}
	
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
}
			| IF bool_expr THEN {
	string st = tempGen.getLabel();
	string en = tempGen.getLabel();
	labelStack.push(en);
	
	codeStream << mc.condGotoLabel(st, $2->name) << endl;
	codeStream << mc.goToLabel(en) << endl;
	codeStream << mc.label(st) << endl;

}			
			statement SEMICOLON statement_ns else_ns ENDIF {
	codeStream << mc.label(labelStack.top()) << endl;
	labelStack.pop();
	
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
}
			| WHILE bool_expr BEGINLOOP {
	string cond = tempGen.getLabel();
	string endLabel = tempGen.getLabel();
	string start = tempGen.getLabel();
	outputCodeStream << mc.label(start) << endl;
	
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
	
	codeStream << mc.condGotoLabel(cond, $2->name) << endl;
	codeStream << mc.goToLabel(endLabel) << endl;
	codeStream << mc.label(cond) << endl;
	
	labelStack.push(start);
	labelStack.push(endLabel);
}			
			statement SEMICOLON statement_ns ENDLOOP {
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
	
	string endLabel = labelStack.top();
	labelStack.pop();
	string start = labelStack.top();
	labelStack.pop();
	
	codeStream << mc.goToLabel(start) << endl;
	codeStream << mc.label(endLabel) << endl;
	
	
}
			| DO BEGINLOOP {
	string start = tempGen.getLabel();
	labelStack.push(start);
	
	outputCodeStream << mc.label(start) << endl;
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
}
			statement SEMICOLON statement_ns ENDLOOP WHILE bool_expr {
	string start = labelStack.top();
	codeStream << mc.condGotoLabel(start, $9->name) << endl;
	labelStack.pop();
	
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
}
			| FOREACH IDENT IN IDENT BEGINLOOP statement SEMICOLON statement_ns ENDLOOP {
				//give up
}
			| READ var var_ns {
	varStack.push($2->name);
	while(!varStack.empty()) {
		if($2->type == ATTR_INTEGER_TYPE) {
			codeStream << mc.readIntoDest(varStack.top()) << endl;
			varStack.pop();
		} else {
			codeStream << mc.readIntoDestArray(varStack.top(), $2->index) << endl;
			varStack.pop();
		}
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
	}
}
			| WRITE var var_ns {
	varStack.push($2->name);
	while(!varStack.empty()) {
		if($2->type == ATTR_INTEGER_TYPE) {
			codeStream << mc.writeSourceToOut(varStack.top()) << endl;
			varStack.pop();
		} else {
			codeStream << mc.writeSourceArrayToOut(varStack.top(), $2->index) << endl;
			varStack.pop();
		}
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
	}
}
			| CONTINUE { 
	if(!labelStack.empty()) {
		codeStream << mc.goToLabel(labelStack.top()) << endl;
		outputCodeStream << codeStream.rdbuf();
		codeStream.clear();
		codeStream.str(" ");
	} else {
		yyerror("Cannot use CONTINUE outside of a loop");
	}
}
			| RETURN expression {
	$$ = new Attribute();
	$$->number_val = $2->number_val;
	$$->name = $2->name;
	codeStream << mc.ret($2->name) << endl;
	outputCodeStream << codeStream.rdbuf();
	codeStream.clear();
	codeStream.str(" ");
}
         ;

var: 	IDENT {
	$$ = new Attribute();
	$$->type = ATTR_INTEGER_TYPE;
	$$->name = utils.charToString($1);
	p("var here: " + $$->toString());
} 
		| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
	if($3->type == ATTR_LIST_TYPE) {
		string temp = tempGen.getTemp();
		$$ = new Attribute();
		$$->type = ATTR_LIST_TYPE;
		$$->index = temp;
		$$->name = utils.charToString($1);
		
		codeStream << ". " << temp << endl;
		codeStream << "=[] " << temp << ", " << $3->name << ", " << index << endl;
	} else {
		$$ = new Attribute();
		$$->name = utils.charToString($1);
		$$->type = ATTR_LIST_TYPE;
		$$->index = $3->name;
	}
}
   ;

else_ns: 
		| ELSE {
			string label = tempGen.getLabel();
			codeStream << ":= " << label << endl;
			codeStream << ": " << labelStack.top() << endl;
			labelStack.pop();
			labelStack.push(label);
		} statement SEMICOLON statement_ns
			;
   
var_ns: 
		| COMMA var var_ns {
	varStack.push($2->name);
}		
      ;

bool_expr: bool_expr OR relation_and_expr  {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	$$->name = temp;
	codeStream << "|| " << temp << ", " << $1->name << ", " << $3->name << endl;
}
			| relation_and_expr {
	$$ = new Attribute();
	$$->name = $1->name;
}
        ;

relation_and_expr: 	relation_and_expr AND relation_expr {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	$$->name = temp;
	codeStream << "&& " << temp << ", " << $1->name << ", " << $3->name << endl;
}
					| relation_expr {
	$$ = new Attribute();
	$$->name = $1->name;
}
                 ;

relation_expr: 	rexpr {
	$$ = new Attribute();
	$$->name = $1->name;
} 
				| NOT rexpr {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	$$->name = temp;
	codeStream << "! " << temp << ", " << $2->name << endl;
}
             ;

rexpr: 	expression comp expression {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	$$->name = temp;
	codeStream << ". " << temp << endl;
	codeStream << $2 << " " << temp << ", " << $1->name << ", " << $3->name << endl;
} 
		| TRUE {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	$$->name = temp;
	codeStream << ". " << temp << endl;
	codeStream << "= " << temp << ", " << "1" << endl;
} 
		| FALSE {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	$$->name = temp;
	codeStream << ". " << temp << endl;
	codeStream << "= " << temp << ", " << "0" << endl;
}
		| L_PAREN bool_expr R_PAREN {
	$$ = new Attribute();
	$$->name = $2->name;
}
     ;

comp:	EQ { $$ = const_cast<char*>("=="); }
		| NEQ { $$ = const_cast<char*>("!="); }
		| LT { $$ = const_cast<char*>("<"); }
		| GT { $$ = const_cast<char*>(">"); }
		| LTE { $$ = const_cast<char*>("<="); }
		| GTE { $$ = const_cast<char*>(">="); }
    ;

expression: multiplicative_expr ADD multiplicative_expr {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "+ " << temp << $1->name << ", " << $3->name << endl;
	$$->name = temp;
} 
			| multiplicative_expr SUB multiplicative_expr {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "- " << temp << $1->name << ", " << $3->name << endl;
	$$->name = temp;
}
			| multiplicative_expr {
	$$ = new Attribute();
	$$->name = $1->name;
	$1->type = $1->type;
}
          ;

multiplicative_expr: multiplicative_expr MULT term {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "* " << temp << $1->name << ", " << $3->name << endl;
	$$->name = temp;
}  
					| multiplicative_expr DIV term {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "/ " << temp << $1->name << ", " << $3->name << endl;
	$$->name = temp;
} 
					| multiplicative_expr MOD term {
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "% " << temp << $1->name << ", " << $3->name << endl;
	$$->name = temp;
} 
					| term {
	$$ = new Attribute();
	$$->name = $1->name;
	$1->type = $1->type;
} 
                   ;

term: 	SUB var {
	$$ = new Attribute();
	$$->number_val = $2->number_val * -1;
	$$->type = $2->type;
	if ($2->type != ATTR_LIST_TYPE) {
		string tempZero = tempGen.getTemp();
		string tempNum = tempGen.getTemp();;
		codeStream << ". " << tempZero << endl << "= " << tempZero << ", " << "0" << endl;
		codeStream << ". " << tempNum << endl << "= " << tempNum << ", " << $2->name << endl;
		$$->name = tempGen.getTemp();
		codeStream << ". " << $$->name << endl;
		codeStream << "- " << $$->name << ", " << tempZero << ", " << tempNum << endl;
	} else {
		string tempZero = tempGen.getTemp();
		string tempNum = tempGen.getTemp();
		codeStream << ". " << tempZero << endl << "= " << tempZero << ", " << "0" << endl;
		codeStream << ". " << tempNum << endl << "=[] " << tempNum << ", " << $2->name << ", " << $2->index << endl;
		$$->name = tempGen.getTemp();
		codeStream << ". " << $$->name << endl;
		codeStream << "- " << $$->name << ", " << tempZero << ", " << tempNum << endl;
		
	}
}
		| var { 
	p("term, var: " + $1->toString());
	$$ = new Attribute();
	$$->number_val = $1->number_val;
	$$->type = $1->type;
	if($1->type != ATTR_LIST_TYPE) {
		$$->name = tempGen.getTemp();
		$$->index = $$->name;
		codeStream << ". " << $$->name << endl;
		codeStream << "= " << $$->name << ", " << $1->name << endl;
	} else {
		$$->name = tempGen.getTemp();
		codeStream << ". " << $$->name << endl;
		codeStream << "=[] " << $$->name << ", " << $1->name << ", " << $1->index << endl;
	}
}
		| SUB NUMBER {
	$$ = new Attribute();
	$$->val = $2 * -1;
	$$->type = ATTR_INTEGER_TYPE;
	string tempZero = tempGen.getTemp();
	string tempNum = tempGen.getTemp();
	codeStream << ". " << tempZero << endl;
	codeStream << "= " << tempZero << ", " << "0" << endl;
	codeStream << ". " << tempNum << endl;
	codeStream << "= " << tempNum << ", " << $2 << endl;
	
	$$->name = tempGen.getTemp();
	codeStream << ". " << $$->name << endl;
	codeStream << "= " << $$->name << ", " << $$->number_val << endl;
	
		}
		| NUMBER  { 
	p("NUMBER, value is: " + utils.intToString($1));
	$$ = new Attribute();
	$$->number_val = $1; 
	$$->type = ATTR_INTEGER_TYPE;
	
	$$->name = tempGen.getTemp();
	$$->index = $$->name;
	
	$$->list.push_back(utils.intToString($1));
	
	codeStream << ". " << $$->name << endl;
	codeStream << "= " << $$->name << ", " << $$->number_val << endl;
}
		| SUB L_PAREN expression R_PAREN {
	$$ = new Attribute();
	string tempZero = tempGen.getTemp();
	
	codeStream << ". " << tempZero << endl;
	codeStream << "= " << tempZero << ", " << "0" << endl;
	
	$$->name = tempGen.getTemp();
	
	codeStream << ". " << $$->name << endl;
	codeStream << "- " << $$->name << ", " << tempZero << ", " << $3->name << endl;
}
		| L_PAREN expression R_PAREN { $$ = new Attribute() ; $$->name = $2->name; }
		| IDENT L_PAREN expression exp_s R_PAREN {
	// check for function
	$$ = new Attribute();
	expStack.push($3->name);
	while(!expStack.empty()) {
		codeStream << "param " << expStack.top() << endl;
		expStack.pop();
	}
	
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "call " << $1 << ", " << temp << endl;
	$$->name = temp;
}
		| IDENT L_PAREN R_PAREN {
	// check for function
	$$ = new Attribute();
	string temp = tempGen.getTemp();
	codeStream << ". " << temp << endl;
	codeStream << "call " << $1 << ", " << temp << endl;
	$$->name = temp;
}
    ;

	exp_s: COMMA expression exp_s {
                   expStack.push($2->name); 
                 }
               |
               ;
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
   
   p("before yyparse");
   yyparse();
   p("after yyparse");
   
   utils.printCode(codeToWrite);
  
  return 0;
}

int yyerror(const char* s) {
  printf("Error at line %d, column %d: Error at \"%s\" \n", curLine, curPos, s);
  exit(1);
  return 0;
}

void p(string log) {
	cout << "Logger #" << testCounter++ << " " << log << endl;
}

void addFunction(Function f) {
	if(functionTable.find(f.name) == functionTable.end()) {
		functionTable[f.name] = f;
	} else {
		yyerror("Function " + f.name " has already been declared");
	}
}

void addSymbol(Symbol s) {
	if(symbolTable.find(s.name) == symbolTable.end()) {
		functionTable[s.name] = s;
	} else {
		yyerror("Symbol " + s.name " has already been declared");
	}
}