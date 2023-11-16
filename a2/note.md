- Write Lexical Analysis
- Semantic Parsing




Its because you're missing the declaration %type <...> expression in the first part of your grammar, where ... is some type declared in your %union statement. Without this, you can't access $$ in any expression action. Also, if you set $$ in ANY action for a non-terminal, you need to set it in all actions for that non-terminal.

In general, you need to decide for all non-terminals whether they produce a value that can be used in rules that use that non-terminal or not. If they do produce such a value, they need a %type declaration and every action needs to set $$ to something. If they do not, then no action can use $1 (or whatever) to access the non-existent value.

You need the same for all terminals, except for terminals, you use %token instead of %type, and you need to set yylval in your lexer, as that's the equivalent of $$.

In your particular example, you've dealt with the terminals but ignored the non-terminals. Depending on exactly what you're trying to do, you probably want a %type for both expression and term, but may not want one for query. This means that every term and expression rule needs an action that sets $$



References:
(1) https://www.gnu.org/software/bison/manual/bison.html#Language-and-Grammar
(2) https://gnuu.org/2009/09/18/writing-your-own-toy-compiler/
(3) https://keleshev.com/abstract-syntax-tree-an-example-in-c/
(4) https://clang.llvm.org/doxygen/classclang_1_1Stmt.html
