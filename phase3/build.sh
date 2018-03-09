#!/bin/bash
echo "Building the parser"

bison -v -d --file-prefix=y mini_l.y

sleep 0.1s

flex mini_l.lex

sleep 0.1s

g++ -std=c++11 -o parser y.tab.c lex.yy.c -lfl

