#
#
all:parser.exe

lex.yy.c:lex.l
	flex lex.l
syn.tab.c:syn.y
	bison -d syn.y
parser.exe:lex.yy.c syn.tab.c gtree.c gtree.h midcode.c midcode.h
	gcc gtree.c midcode.c syn.tab.c -lfl -ly -o parser -g
codes:test
	parser test>result
	notepad++ codes
del:
	del parser result
