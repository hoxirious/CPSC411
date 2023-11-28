# Makefile for building and running the parser

all: parser

parser: parser.c
	gcc parser.c -o parser

parser.c: parser.y
	bison -dvo parser.c parser.y

run: parser
	./parser test

clean:
	rm -f parser parser.c parser.h

