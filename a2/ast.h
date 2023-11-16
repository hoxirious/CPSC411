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
} stmtKind;

struct stmt {
  stmtKind kind;
  struct expr *init_expr;
  struct expr *expr;
  struct expr *next_expr;
  struct stmt *body;
  struct stmt *else_body;
  struct stmt *next;
};

void createStmt(stmtKind kind, struct expr *init_expr,
                struct expr *expr, struct expr *next_expr, struct stmt *body,
                struct stmt *else_body, struct stmt *next) {
  struct stmt *newStmt = malloc(sizeof *newStmt);
  newStmt->kind = kind;
  newStmt->init_expr = init_expr;
  newStmt->expr = expr;
  newStmt->next_expr = next_expr;
  newStmt->body = body;
  newStmt->else_body = else_body;
  newStmt->next = next;
}

typedef enum {
  SIMPLE_DECL,
  ARRAY_DECL,
  FUNCTION_DECL,
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
  ARRAY_PARAM,
} paramKind;

struct param {
  paramKind kind;
  struct type *type;
  char *id;
  struct param *next;
};

void createParam(paramKind kind, struct type *type, char *id,
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

struct arg_list {
  struct expr *expr;
  struct arg_list *next;
};

struct call {
  char *id;
  struct arg_list *args;
};

struct expr {
  expr_type exprType;
  struct expr *left;
  struct expr *right;
  int value;
};

struct expr *createExpr(expr_type exprType, struct expr *left,
                        struct expr *right, int value) {
  struct expr *newExpr = (expr *)malloc(sizeof *newExpr);
  newExpr->exprType = exprType;
  newExpr->left = left;
  newExpr->right = right;
  newExpr->value = value;

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
    printf("Number: { %d ", expr->value);
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
    printf("Equal: {");
    break;
  case ASSIGN_EXPR:
    printf("Assignment: {");
    break;
  case CALL_EXPR:
    printf("Call: {");
    break;
  case ARG_EXPR:
    printf("Argument: {");
    break;
  default:
    break;
  }

  if (expr->left) {
    printf("left: {");
    printExpr(expr->left);
  }
  if (expr->right) {
    printf("right: {");
    printExpr(expr->right);
  }

  printf("}}");
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

  char *typeString = getType(param->type);

  if (param->kind == array_param)
    printf("PARAM_ARRAY: { ID: %s, Type: %s", param->id, typeString);
  else
    printf("PARAM: { ID: %s, Type: %s", param->id, typeString);

  printParam(param->next);
}

void printStmt(struct stmt *stmt) {

  if (!stmt) {
    return;
  }

  switch (stmt->kind) {
  case EXPR_STMT:
    printf("EXPR_STMT: {");
    printExpr(stmt->expr);
    break;
  case SELECT_STMT:
    printf("SELECT_STMT: { IF: ");
    printExpr(stmt->expr);
    printf("THEN: ");
    printStmt(stmt->body);
    printf("ELSE: ");
    printStmt(stmt->else_body);
    break;
  case RETURN_STMT:
    printf("RETURN_STMT: {");
    printExpr(stmt->expr);
    break;
  case ITER_STMT:
    printf("ITER_STMT: { WHILE: ");
    printExpr(stmt->expr);
    printf("BODY: ");
    printStmt(stmt->body);
    break;
  default:
    break;
  }
  printf("}");
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
    printf("DECLARATION: { ID: %s, Type: %s, PARAMS: {", decl->id, typeString);
    printParam(decl->param);
    printStmt(decl->compound_stmt);
  } else
    printf("DECLARATION: { ID: %s, Type: %s", decl->id, typeString);

  printf("}");
  printDecl(decl->next);
}
