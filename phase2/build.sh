#!/bin/bash
echo "Building the parser"

bison -v -d --file-prefix=y mini_l.y

sleep 0.1s

flex mini_l.lex

sleep 0.1s

gcc -o parser y.tab.c lex.yy.c -lfl

