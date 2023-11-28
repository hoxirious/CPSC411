#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *ID_S = "ID";
static const char *TYPE = "Type";
static int INDENT_COUNT = 0;
#define HASH_TABLE_SIZE 100 // Adjust the size as needed

typedef enum {
  SYMBOL_LOCAL,
  SYMBOL_GLOBAL,
  SYMBOL_PARAM,
} symbol_t;

typedef enum {
  SYMBOL_INT,
  SYMBOL_VOID,
  SYMBOL_ARRAY,
  SYMBOL_FUNCTION,
  SYMBOL_ID,
} symbol_type;

struct Symbol {
  const char *name;
  symbol_t kind;
  symbol_type type;
  int which;
};

struct SymbolTable {
  struct Symbol *hashTable[HASH_TABLE_SIZE];
};

struct SymbolTableNode {
  struct SymbolTable *table;
  struct SymbolTableNode *next;
};

struct SymbolTableStack {
  struct SymbolTable *stack[HASH_TABLE_SIZE];
  int top;
};

// This function causes a new hash table to be pushed on the top of
// the stack, representing a new scope.
void scope_enter(struct SymbolTableStack *st);

// This function causes the topmost hash table to be removed.
void scope_exit(struct SymbolTableStack *st);

// This function eturns the number of hash tables in the current
// (*st). (This is helpful to know whether we are at the global scope or not.)
int scope_level(struct SymbolTableStack *st);

// This function adds an entry to the topmost hash table
// of the stack, mapping name to the symbol structure sym.
void scope_bind(struct SymbolTableStack *st, const char *name,
                struct Symbol *sym);

// This function searches the stack of hash tables from top to
// bottom, looking for the first entry that matches name exactly. If no
// match is found, it returns null.
struct Symbol *scope_lookup(struct SymbolTableStack *st, const char *name);

// This function works like scope lookup except
// that it only searches the topmost table. This is used to determine
// whether a symbol has already been defined in the current scope.
struct Symbol *scope_lookup_current(struct SymbolTableStack *st,
                                    const char *name);

struct Symbol *lookup_helper(struct SymbolTableStack *st, char *id);
void decl_resolve(struct SymbolTableStack *st, struct decl *d);
void stmt_resolve(struct SymbolTableStack *st, struct stmt *s);
void expr_resolve(struct SymbolTableStack *st, struct expr *e);
void param_list_resolve(struct SymbolTableStack *st, struct param *p);

// Function to create a new symbol
struct Symbol *symbol_create(const char *name, symbol_t kind, symbol_type type,
                             int which);

// Function to create a new symbol table
struct SymbolTable *symbol_table_create();

// Function to add a symbol to the symbol table
void add_to_symbol_table(struct SymbolTable *table, struct Symbol *symbol);

// Function to find a symbol in the symbol table
struct Symbol *find_in_symbol_table(struct SymbolTable *table, const char *id);

typedef enum {
  ADD_EXPR,
  MINUS_EXPR,
  SUB_EXPR,
  MULT_EXPR,
  DIV_EXPR,
  NUM_EXPR,
  LESSER_EXPR,
  GREATER_EXPR,
  LESSER_EQ_EXPR,
  GREATER_EQ_EXPR,
  NOT_EQ_EXPR,
  EQ_EXPR,
  ASSIGN_EXPR,
  CALL_EXPR,
  ARG_EXPR,
  VAR_EXPR,
} expr_type;

typedef enum {
  INT_TYPE,
  VOID_TYPE,
} typeKind;

typedef enum {
  EXPR_STMT,
  SELECT_STMT,
  RETURN_STMT,
  ITER_STMT,
  COMPOUND_STMT,
} stmtKind;

struct stmt {
  stmtKind kind;
  struct decl *decl;
  struct expr *expr;
  struct stmt *body;
  struct stmt *else_body;
  struct stmt *next;
  int line_num;
};

char *getIndent(int indent_count);

void printEle(const char *key, char *value, int indent_count, int line_num) {
  char *indent = getIndent(indent_count);
  printf("%s%s [%s] @line %d", indent, key, value, line_num);
}

struct stmt *createStmt(stmtKind kind, struct decl *decl, struct expr *expr,
                        struct stmt *body, struct stmt *else_body,
                        struct stmt *next, int line_num) {
  struct stmt *newStmt = malloc(sizeof *newStmt);
  newStmt->kind = kind;
  newStmt->decl = decl;
  newStmt->expr = expr;
  newStmt->body = body;
  newStmt->else_body = else_body;
  newStmt->next = next;
  newStmt->line_num = line_num;
}

typedef enum {
  SIMPLE_DECL,
  ARRAY_DECL,
  FUNCTION_DECL,
  LOCAL_DECL,
} declKind;

struct decl {
  declKind kind;
  char *id;
  int *NUM;
  int line_num;
  struct type *type;
  struct param *param;
  struct stmt *compound_stmt;
  struct decl *next;
  struct Symbol *symbol;
};

struct decl *createDecl(declKind kind, char *id, int *NUM, struct type *type,
                        struct param *param, struct stmt *compound_stmt,
                        struct decl *next, int line_num) {
  struct decl *newdecl = malloc(sizeof *newdecl);
  newdecl->kind = kind;
  newdecl->id = id;
  newdecl->NUM = NUM;
  newdecl->type = type;
  newdecl->param = param;
  newdecl->compound_stmt = compound_stmt;
  newdecl->next = next;
  newdecl->line_num = line_num;
  // decl_resolve(st, newdecl);
}

typedef enum {
  SIMPLE_PARAM,
  VOID_PARAM,
  ARRAY_PARAM,
} paramKind;

struct param {
  paramKind kind;
  struct type *type;
  char *id;
  struct param *next;
  int line_num;
  struct Symbol *symbol;
};

struct param *createParam(paramKind kind, struct type *type, char *id,
                          struct param *next, int line_num) {
  struct param *newParam = malloc(sizeof *newParam);
  newParam->kind = kind;
  newParam->type = type;
  newParam->id = id;
  newParam->next = next;
  newParam->line_num = line_num;
}

struct type {
  typeKind kind;
  struct type *subtype;
  struct param *param;
};

struct type *createType(typeKind kind, struct type *subtype,
                        struct param *param) {
  struct type *newType = malloc(sizeof *newType);
  newType->kind = kind;
  newType->subtype = subtype;
  newType->param = param;

  return newType;
}

struct var {
  char *id;
  struct expr *expr;
};

struct var *createVar(char *id, struct expr *expr) {
  struct var *newVar = malloc(sizeof *newVar);
  newVar->id = id;
  newVar->expr = expr;
}

struct arg_list {
  struct expr *expr;
  struct arg_list *next;
};

struct expr {
  expr_type exprType;
  struct expr *left;
  struct expr *right;
  int value;
  char *id;
  int line_num;
  struct Symbol *symbol;
};

struct expr *createExpr(expr_type exprType, struct expr *left,
                        struct expr *right, int value, char *id, int line_num) {
  struct expr *newExpr = malloc(sizeof *newExpr);
  newExpr->exprType = exprType;
  newExpr->left = left;
  newExpr->right = right;
  newExpr->value = value;
  newExpr->id = id;
  newExpr->line_num = line_num;
  return newExpr;
}

void printExpr(struct expr *expr, int indent_count) {
  char *indent = getIndent(indent_count);
  char *next_indent = getIndent(indent_count + 1);
  if (!expr) {
    return;
  }
  printf("%s", indent);
  switch (expr->exprType) {
  case ADD_EXPR:
    printf("+ @line %d", expr->line_num);
    break;
  case SUB_EXPR:
    printf("- @line %d", expr->line_num);
    break;
  case DIV_EXPR:
    printf("/ @line %d", expr->line_num);
    break;
  case MULT_EXPR:
    printf("* @line %d", expr->line_num);
    break;
  case NUM_EXPR:
    printf("\tNUM: [%d] @line %d", expr->value, expr->line_num);
    break;
  case LESSER_EXPR:
    printf("< @line %d", expr->line_num);
    break;
  case GREATER_EXPR:
    printf("> @line %d", expr->line_num);
    break;
  case LESSER_EQ_EXPR:
    printf("<= @line %d", expr->line_num);
    break;
  case GREATER_EQ_EXPR:
    printf(">= @line %d", expr->line_num);
    break;
  case NOT_EQ_EXPR:
    printf("!= @line %d", expr->line_num);
    break;
  case EQ_EXPR:
    printf("== @line %d", expr->line_num);
    break;
  case ASSIGN_EXPR:
    printf("= @line %d", expr->line_num);
    break;
  case CALL_EXPR:
    printf("CALL @line %d", expr->line_num);
    printEle(ID_S, expr->id, indent_count + 1, expr->line_num);
    break;
  case ARG_EXPR:
    printf("\tARG @line %d", expr->line_num);
    break;
  case VAR_EXPR:
    printf("\tVAR [%s] @line %d", expr->id, expr->line_num);
    break;
  default:
    break;
  }

  if (expr->left) {
    if (expr->exprType == ARG_EXPR) {
      printExpr(expr->left, indent_count + 1);
    } else
      printExpr(expr->left, indent_count);
  }
  if (expr->right) {
    if (expr->right->exprType == ARG_EXPR) {
      printExpr(expr->right, indent_count - 1);
    } else
      printExpr(expr->right, indent_count);
  }
}

char *getType(struct type *type) {
  char *arr = (char *)malloc(5);

  switch (type->kind) {
  case INT_TYPE:
    return "integer";
  case VOID_TYPE:
    return "void";
  default:
    break;
  }
}

char *getIndent(int indent_count) {
  char *indent = (char *)malloc(indent_count + 1);
  indent[0] = '\n';
  for (int i = 1; i < indent_count + 1; i++) {
    indent[i] = '\t';
  }
  return indent;
}

void printParam(struct param *param, int indent_count) {
  char *indent = getIndent(indent_count);
  char id[] = "ID";
  char type[] = "Type";
  if (!param) {
    return;
  }

  if (param->kind == ARRAY_PARAM) {
    printEle(id, param->id, indent_count, param->line_num);
    printEle(type, getType(param->type), indent_count, param->line_num);
  } else if (param->kind == VOID_PARAM) {
    printf("%sPARAM_VOID", indent);
  } else {
    printEle(id, param->id, indent_count, param->line_num);
    printEle(type, getType(param->type), indent_count, param->line_num);
  }

  printf("\n");
  printParam(param->next, indent_count);
}
void printStmt(struct stmt *stmt, int indent_count) {
  char *indent = getIndent(indent_count);
  char *next_indent = getIndent(indent_count + 1);
  if (!stmt) {
    return;
  }
  printf("%s", indent);
  switch (stmt->kind) {
  case EXPR_STMT:
    printf("EXPR_STMT:");
    printExpr(stmt->expr, indent_count + 1);
    break;
  case SELECT_STMT:
    printf("SELECT_STMT:");
    printf("%sIF: ", next_indent);
    printExpr(stmt->expr, indent_count + 1);
    printf("%sTHEN: ", next_indent);
    printStmt(stmt->body, indent_count + 1);
    printf("%sELSE: ", next_indent);
    printStmt(stmt->else_body, indent_count + 1);
    break;
  case RETURN_STMT:
    printf("RETURN_STMT:");
    printExpr(stmt->expr, indent_count + 1);
    break;
  case ITER_STMT:
    printf("ITER_STMT:");
    printf("%sWHILE: ", next_indent);
    printExpr(stmt->expr, indent_count + 1);
    printf("%sBODY: ", next_indent);
    printStmt(stmt->body, indent_count + 1);
    break;
  case COMPOUND_STMT: {
    printf("COMPOUND_STMT: %s\t", indent);
    struct decl *tmp = stmt->decl;
    printf("LOCAL_DECL:");
    while (tmp) {
      printEle(ID_S, tmp->id, indent_count + 1, tmp->line_num);
      printEle(TYPE, getType(tmp->type), indent_count + 1, tmp->line_num);
      tmp = tmp->next;
    }
    printStmt(stmt->next, indent_count + 1);
    break;
  }
  default:
    break;
  }
  if (stmt->kind != COMPOUND_STMT)
    printStmt(stmt->next, indent_count);
}

void printDecl(struct decl *decl) {
  char id[] = "ID";
  char type[] = "Type";
  if (!decl) {
    return;
  }

  char *typeString = getType(decl->type);

  if (decl->kind == ARRAY_DECL)
    printf("ARRAY DECL @line %d:\n\tID: %s\n\tType: %s\n\tSize: %d",
           decl->line_num, decl->id, typeString, *(decl->NUM));
  else if (decl->kind == FUNCTION_DECL) {
    int indent_count = 1;
    char *indent = getIndent(indent_count);
    int i = 1;
    printf("FUNC DECL @line %d:", decl->line_num);
    printEle(id, decl->id, indent_count, decl->line_num);
    printEle(type, typeString, indent_count, decl->line_num);
    printf("%sPARAMS:", indent);
    if (decl->param) {
      printParam(decl->param, indent_count + 1);
    }
    printStmt(decl->compound_stmt, indent_count + 1);
  } else
    printf("SIMPLE DECL @line %d:\n\tID: %s\n\tType: %s", decl->line_num,
           decl->id, typeString);

  printf("\n\n\n");
  printDecl(decl->next);
}
unsigned int hashFunction(const char *id) {
  unsigned int hash = 0;
  while (*id) {
    hash = (hash * 31) + *id;
    id++;
  }
  return hash % HASH_TABLE_SIZE;
}

struct Symbol *symbol_create(const char *name, symbol_t kind, symbol_type type,
                             int which) {
  struct Symbol *symbol = malloc(sizeof(struct Symbol));
  symbol->name = strdup(name); // Make a copy of the name
  symbol->kind = kind;
  symbol->type = type;
  symbol->which = which;
  printf("Creating symbol for %s\n", name);
  return symbol;
}

struct SymbolTable *symbol_table_create() {
  struct SymbolTable *table = malloc(sizeof(struct SymbolTable));
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    table->hashTable[i] = NULL;
  }
  // Initialize other attributes or functionality as needed
  // ...
  return table;
}

void add_to_symbol_table(struct SymbolTable *table, struct Symbol *symbol) {
  // Use the hash function to determine the bucket in the hash table
  unsigned int hashValue = hashFunction(symbol->name);
  printf("Adding symbol %s to hash bucket %d\n", symbol->name, hashValue);

  // Add symbol to the beginning of the linked list in the hash bucket
  if (!table) {
    printf("Table is null\n");
  }

  table->hashTable[hashValue] = symbol;
}

struct Symbol *find_in_symbol_table(struct SymbolTable *table,
                                    const char *name) {
  // Use the hash function to determine the bucket in the hash table
  unsigned int hashValue = hashFunction(name);

  if (!table) {
    printf("Table is null\n");
    return NULL;
  }

  // Search for the symbol in the hash bucket
  return table->hashTable[hashValue];
}

// struct SymbolTableStack *symbol_table_stack_create() {
//   struct SymbolTableStack *stack = malloc(sizeof(struct SymbolTableStack));
//   (*st).top = -1;
//   return stack;
// }

void scope_enter(struct SymbolTableStack *st) {
  // Create a new symbol table and push it onto the stack

  (*st).top++;
  (*st).stack[(*st).top] = symbol_table_create();
  printf("Entering scope %d\n", (*st).top);
}

void scope_exit(struct SymbolTableStack *st) {
  // Pop the top symbol table from the stack

  free((*st).stack[(*st).top]);
  printf("Exiting scope %d\n", (*st).top);
  (*st).top--;
}

int scope_level(struct SymbolTableStack *st) {
  // Return the number of symbol tables on the stack
  struct SymbolTableStack stack = *st;
  return (*st).top + 1;
}

void scope_bind(struct SymbolTableStack *st, const char *name,
                struct Symbol *sym) {
  struct SymbolTableStack stack = *st;
  struct SymbolTable *table = (*st).stack[(*st).top];
  add_to_symbol_table(table, sym);
}

struct Symbol *scope_lookup(struct SymbolTableStack *st, const char *name) {
  struct SymbolTableStack stack = *st;
  int i = (*st).top;
  while (i >= 0) {
    struct SymbolTable *table = (*st).stack[i];
    struct Symbol *symbol = find_in_symbol_table(table, name);
    if (symbol) {
      return symbol;
    }
    i--;
  }
  return NULL;
}

struct Symbol *scope_lookup_current(struct SymbolTableStack *st,
                                    const char *name) {
  struct SymbolTableStack stack = *st;
  struct SymbolTable *table = (*st).stack[(*st).top];
  return find_in_symbol_table(table, name);
}

void decl_resolve(struct SymbolTableStack *st, struct decl *d) {
  if (!d) {
    return;
  }
  symbol_t kind = scope_level(st) > 1 ? SYMBOL_LOCAL : SYMBOL_GLOBAL;
  // todo: define which

  if (d->kind == FUNCTION_DECL) {
    d->symbol = symbol_create(d->id, kind, SYMBOL_FUNCTION, 0);
    struct Symbol *sym = scope_lookup_current(st, d->id);
    if (sym) {
      printf("Error: %s is already defined\n", d->id);
    } else {
      printf("Binding %s to symbol table\n", d->id);
      scope_bind(st, d->id, d->symbol);
    }

    // Start Param Scope
    scope_enter(st);
    param_list_resolve(st, d->param);
    scope_exit(st);
    // End Param Scope
    // Start Compound Stmt Scope
    scope_enter(st);
    stmt_resolve(st, d->compound_stmt);
    scope_exit(st);
    // End Compound Stmt Scope
  } else if (d->kind == ARRAY_DECL) {
    // TODO: save array size
    d->symbol = symbol_create(d->id, kind, SYMBOL_ARRAY, 0);
    struct Symbol *sym = lookup_helper(st, d->id);
    if (sym) {
      printf("Error: %s is already defined\n", d->id);
    } else {
      printf("Binding %s to symbol table\n", d->id);
      scope_bind(st, d->id, d->symbol);
    }
  } else if (d->kind == SIMPLE_DECL) {
    symbol_type type = d->type->kind == INT_TYPE ? SYMBOL_INT : SYMBOL_VOID;
    d->symbol = symbol_create(d->id, kind, type, 0);
    struct Symbol *sym = lookup_helper(st, d->id);
    if (sym) {
      printf("Error: %s is already defined\n", d->id);
    } else {
      printf("Binding %s to symbol table\n", d->id);
      scope_bind(st, d->id, d->symbol);
    }
  }
  // else if(d->kind == LOCAL_DECL){
  //     expr_resolve(d->expr);
  // }
}

// Type check
void param_list_resolve(struct SymbolTableStack *st, struct param *p) {
  if (!p) {
    return;
  }
  if (p->kind == ARRAY_PARAM) {

    p->symbol = symbol_create(p->id, SYMBOL_PARAM, SYMBOL_ARRAY, 0);
    printf("Resolve array param\n");
  } else if (p->kind == SIMPLE_PARAM) {
    printf("Resolve simple param\n");
    p->symbol = symbol_create(p->id, SYMBOL_PARAM, SYMBOL_INT, 0);
    struct Symbol *sym = scope_lookup_current(st, p->id);
    if (sym) {
      printf("Error: %s is already defined\n", p->id);
    } else {
      printf("Binding %s to symbol table\n", p->id);
      scope_bind(st, p->id, p->symbol);
    }
  } else if (p->kind == VOID_PARAM) {
    p->symbol = symbol_create(p->id, SYMBOL_PARAM, SYMBOL_VOID, 0);
    printf("Resolve void param\n");
    return;
  }
  param_list_resolve(st, p->next);
}

void stmt_resolve(struct SymbolTableStack *st, struct stmt *s) {
  if (!s) {
    return;
  }

  if (s->kind == EXPR_STMT) {
    printf("Resolving expr stmt\n");
    expr_resolve(st, s->expr);
  } else if (s->kind == SELECT_STMT) {
    printf("Resolving select stmt\n");
    expr_resolve(st, s->expr);
    stmt_resolve(st, s->body);
    stmt_resolve(st, s->else_body);
  } else if (s->kind == RETURN_STMT) {
    // TODO: check if expr is of type function
    printf("Resolving return stmt\n");
    expr_resolve(st, s->expr);
  } else if (s->kind == ITER_STMT) {
    printf("Resolving iter stmt\n");
    expr_resolve(st, s->expr);
    stmt_resolve(st, s->body);
  } else if (s->kind == COMPOUND_STMT) {
    printf("Resolving compound stmt\n");
    struct decl *tmp = s->decl;
    while (tmp) {
      decl_resolve(st, tmp);
      tmp = tmp->next;
    }
    stmt_resolve(st, s->next);
  }

  if (s->kind != COMPOUND_STMT)
    stmt_resolve(st, s->next);
}

void expr_resolve(struct SymbolTableStack *st, struct expr *e) {
  if (!e) {
    return;
  }
  if (e->exprType == VAR_EXPR) {
    printf("Resolving var expr\n");
    struct Symbol *sym = lookup_helper(st, e->id);
    if (sym) {
      printf("Found symbol %s\n", sym->name);
    } else {
      printf("Error: Symbol %s not found\n", e->id);
    }
  } else if (e->exprType == CALL_EXPR) {
    printf("Resolving call expr\n");
    struct Symbol *sym = lookup_helper(st, e->id);
    if (sym) {
      printf("Found symbol %s\n", sym->name);
    } else {
      printf("Error: Symbol %s not found\n", e->id);
    }
  } else if (e->exprType == ARG_EXPR) {
    printf("Resolving arg expr\n");
    struct expr *tmp = e;
    while (tmp->right) {
      struct Symbol *sym = scope_lookup(st, tmp->id);
      if (!sym) {
        printf("Error: Symbol %s not found\n", tmp->id);
        break;
      } else {
        printf("Found symbol %s\n", sym->name);
        tmp = tmp->right;
      }
    }
  }

  if(e->left){
    expr_resolve(st, e->left);
  }

  if(e->right){
    expr_resolve(st, e->right);
  }
}
struct Symbol *lookup_helper(struct SymbolTableStack *st, char *id) {
  struct Symbol *local_symbol = scope_lookup_current(st, id);
  if (!local_symbol) {
    struct Symbol *global_symbol = scope_lookup(st, id);
    if (!global_symbol) {
      return NULL;
    } else {
      return global_symbol;
    }
  } else {
    return local_symbol;
  }
}
