#flex teste1.txt
#bison sintatica.txt -o sint.c
#gcc sint.c -ly  -g

bison -d sintatic.yacc -o y.tab.h
flex lexic.lex
bison sintatic.yacc -o sint.c
