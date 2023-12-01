% ASSIGNMENT 2
% Hy Huynh - 30087093
% November 16th, 2023


## Instruction how to run

### Prerequisite
- OS: Ubuntu 22.0.4
- Bison Version: bison (GNU Bison) 3.8.2
- Flex Version: flex version 2.5.4

### For generating the scanner, run:
`flex scanner.l`

### For generating the parser, run:
`bison -dvo parser.c parser.y`

### For executing the parser, run:
`gcc parser.c -o parser`

### ALTERNATIVE, execute make file to run all above commands:
`make clean && make`

### For testing the parser, run:
`./parser tests/<test_name>`


## Test cases
1. test1 - Standard test from previous assignment

- Below test cases are referenced from Assignment 3 documentation
2. test2 - Declaration before use
3. test3 - Redeclaration in same scope
4. test4 - Parameter Scope Redeclaration
5. test5 - Main Function Error
6. test6 - Type Checking Expressions
7. test7 - Incorrect use of function call syntax
8. test8 - Incorrect use of array index syntax
9. test9 - Incorrect function call parameters
10. test10 - Return with expression in void function
11. test11 - Empty return in int function
12. test12 - Comparision test
