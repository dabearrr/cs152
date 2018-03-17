#!/bin/bash
echo "Building the parser"

bison -v -d --file-prefix=y mini_l.y

sleep 0.1s

flex mini_l.lex

sleep 0.1s

g++ -std=c++11 -o parser y.tab.c lex.yy.c -lfl

sleep 0.1s
echo "parsing fib"
./parser < fibonacci.min.txt
sleep 0.1s
echo "testing fib with 5"
./mil_run mil_code.mil < milInput.txt
sleep 0.1s
echo "parsing primes"
./parser < primes.min.txt
sleep 0.1s
echo "testing primes with 5"
./mil_run mil_code.mil < milInput.txt
sleep 0.1s
echo "parsing mytest"
./parser < mytest.min.txt
sleep 0.1s
echo "testing mytest with 5 5"
./mil_run mil_code.mil < milInput.txt
sleep 0.1s
echo "semantic tests"
./parser < semanticfails.min.txt
sleep 0.1s