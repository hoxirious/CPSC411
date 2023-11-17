#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
};

struct stmt *createStmt(stmtKind kind, struct decl *decl, struct expr *expr,
                        struct stmt *body, struct stmt *else_body,
                        struct stmt *next) {
  struct stmt *newStmt = malloc(sizeof *newStmt);
  newStmt->kind = kind;
  newStmt->decl = decl;
  newStmt->expr = expr;
  newStmt->body = body;
  newStmt->else_body = else_body;
  newStmt->next = next;
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
  struct type *type;
  struct param *param;
  struct stmt *compound_stmt;
  struct decl *next;
};

struct decl *createDecl(declKind kind, char *id, int *NUM, struct type *type,
                        struct param *param, struct stmt *compound_stmt,
                        struct decl *next) {
  struct decl *newdecl = malloc(sizeof *newdecl);
  newdecl->kind = kind;
  newdecl->id = id;
  newdecl->NUM = NUM;
  newdecl->type = type;
  newdecl->param = param;
  newdecl->compound_stmt = compound_stmt;
  newdecl->next = next;
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
};

struct param *createParam(paramKind kind, struct type *type, char *id,
                          struct param *next) {
  struct param *newParam = malloc(sizeof *newParam);
  newParam->kind = kind;
  newParam->type = type;
  newParam->id = id;
  newParam->next = next;
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
};

struct expr *createExpr(expr_type exprType, struct expr *left,
                        struct expr *right, int value, char *id) {
  struct expr *newExpr = malloc(sizeof *newExpr);
  newExpr->exprType = exprType;
  newExpr->left = left;
  newExpr->right = right;
  newExpr->value = value;
  newExpr->id = id;
  return newExpr;
}

void printExpr(struct expr *expr) {
  if (!expr) {
    return;
  }
  switch (expr->exprType) {
  case ADD_EXPR:
    printf("Addition: {");
    break;
  case SUB_EXPR:
    printf("Subtraction: {");
    break;
  case DIV_EXPR:
    printf("Division: {");
    break;
  case MULT_EXPR:
    printf("Multiplication: {");
    break;
  case NUM_EXPR:
    printf("Number: { %d } ", expr->value);
    break;
  case LESSER_EXPR:
    printf("Lesser: {");
    break;
  case GREATER_EXPR:
    printf("Greater: {");
    break;
  case LESSER_EQ_EXPR:
    printf("Lesser or Equal: {");
    break;
  case GREATER_EQ_EXPR:
    printf("Greater or Equal: {");
    break;
  case NOT_EQ_EXPR:
    printf("Not Equal: {");
    break;
  case EQ_EXPR:
    printf("Equal: ");
    break;
  case ASSIGN_EXPR:
    printf("Assignment: {");
    break;
  case CALL_EXPR:
    printf("Call: { ID: %s, ", expr->id);
    break;
  case ARG_EXPR:
    printf("Argument: {");
    break;
  case VAR_EXPR:
    printf("Variable: { ID: %s } ", expr->id);
    break;
  default:
    break;
  }

  if (expr->left) {
    printf("left: {");
    printExpr(expr->left);
    printf("} ");
  }
  if (expr->right) {
    printf("right: {");
    printExpr(expr->right);
    printf("} ");
  }

  if (expr->exprType != NUM_EXPR && expr->exprType != VAR_EXPR){
      printf("} ");
  }
}

void printArg(struct arg_list *arg) {
  if (!arg) {
    return;
  }
  printf("ARG: {");
  printExpr(arg->expr);
  printf("} ");
  printArg(arg->next);
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

void printParam(struct param *param) {
  if (!param) {
    return;
  }

  if (param->kind == ARRAY_PARAM)
    printf("PARAM_ARRAY: { ID: %s, Type: %s", param->id, getType(param->type));
  else if (param->kind == VOID_PARAM) {
    printf("\t{PARAM_VOID");
  } else
    printf("\tPARAM: { ID: %s, Type: %s", param->id, getType(param->type));

  printf("}\n");
  printParam(param->next);
}
void printStmt(struct stmt *stmt) {

  if (!stmt) {
    return;
  }
  printf("\n");

  switch (stmt->kind) {
  case EXPR_STMT:
    printf("EXPR_STMT: \n\t");
    printExpr(stmt->expr);
    break;
  case SELECT_STMT:
    printf("SELECT_STMT: \n\tIF: ");
    printExpr(stmt->expr);
    printf("\n\tTHEN: ");
    printStmt(stmt->body);
    printf("\n\tELSE: ");
    printStmt(stmt->else_body);
    break;
  case RETURN_STMT:
    printf("RETURN_STMT: \n\t");
    printExpr(stmt->expr);
    break;
  case ITER_STMT:
    printf("ITER_STMT: \n\tWHILE: ");
    printExpr(stmt->expr);
    printf("\n\tBODY: ");
    printStmt(stmt->body);
    break;
  case COMPOUND_STMT: {
    struct decl *tmp = stmt->decl;
    printf("LOCAL_DECL: \n");
    while (tmp) {
      printf("\tID: %s, Type: %s\n", tmp->id, getType(tmp->type));
      tmp = tmp->next;
    }
    break;
  }
  default:
    break;
  }
  printStmt(stmt->next);
}
void printDecl(struct decl *decl) {
  if (!decl) {
    return;
  }

  char *typeString = getType(decl->type);

  if (decl->kind == ARRAY_DECL)
    printf("DECLARATION: { ID: %s, Type: %s, Size: %d", decl->id, typeString,
           *(decl->NUM));
  else if (decl->kind == FUNCTION_DECL) {
    printf("DECLARATION: { ID: %s, Type: %s, PARAMS: \n", decl->id,
           typeString);
    if (decl->param) {
      printParam(decl->param);
    }
    printStmt(decl->compound_stmt);
  } else
    printf("DECLARATION: { ID: %s, Type: %s", decl->id, typeString);

  printf("\n}\n\n");
  printDecl(decl->next);
}
