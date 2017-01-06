/*
 * Name:gtree.h
 * Author:Hades
 * Last_modified:2016-10-31
 * Function:
*/
#ifndef GTREE_H
#define GTREE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>

extern int yylineno;
extern char* yytext;
typedef enum symkind{VAR,CON,FUN,ARR,STR}KIND;
typedef struct ast{
    int line;
    char * name;
    char *content;
    KIND tag;
    struct ast *left;
    struct ast *right;
    union{
        int valuei;
        float valuef;
    };
    int number;
}AST;
/*初始化一个新节点*/
AST *initast(void);
/*语法分析树建立函数*/
AST *newast(char *name,int num,...);
/*语法分析树遍历函数*/
void DepthT(AST *,int level);
/*错误处理函数*/
void yyerror(const char *s,...);
/*注释函数*/
void comment(void);

typedef struct fieldlist STRCT;
typedef struct type  Type;
typedef enum define{UND,DEF}DFND;

typedef struct array{
    int size;
    Type *elem;//数组成员类型
}ARRAY;
struct fieldlist{
    char *name;//成员名字
    Type *type;//成员类型
    struct fieldlist *next;//下一个成员
};
struct type{
    KIND kind;
    union{
        char *pvar;
        ARRAY *parr;
        STRCT *pstr;  
    };
};
typedef struct symbol{
    int num;
    int vname;
    char *name;//符号标示符
    int line;//标示符所在的行号
    int vis;
    DFND Ndx;
    Type *type;
    union{
        int valuei;
        float valuef;
    };
    int size;
    void *addr;
    int level;
    struct symbol *next;//符号表下一结点
    struct symbol *bind;//作用域钩链
    struct symbol *pap;//参数表钩链
}SYMBOL;


int pnum;
SYMBOL *symhead,*symtail;
SYMBOL *ph,*pt;//参数表
SYMBOL *initsym();
void newsym(DFND,KIND,int,...);
SYMBOL *findsym(AST *astp);
void print();//打印符号表
void eval(AST *,int level);//

//**************************//
void eval_c(AST *);
void extdeclist(AST *,AST *);
void fundec(AST *,AST *);
void specstrctdef(AST *);
void strctdef(AST *);
void varORarray(AST *,AST *);
void gstrctsym(AST *,AST *);
void myerror(AST * astp,int index,SYMBOL *p);
void autoname(AST *);


STRCT *ghpstr,*gtpstr;
char *gpvar;
void deflist(AST *,int);
void nmember(AST *,AST *);
void smember(AST *,AST *);
void newsfield(KIND,AST *,AST *);
void nparas(AST *);
void newvardec(AST *,AST *,int);
void compst(AST *);
void ncompdec(AST *,AST *);
void scompdec(AST *,AST *);
void stmt(AST *);
int  findmem(STRCT *,AST *);
void expression(AST *);
void expcheck(AST *,int);
void checkrtype(AST *);
void real(SYMBOL *,AST *);
void strctfield(AST *);
void matcharr(AST *,AST *);
void delbindsym();

//**************************//
ARRAY *initarray();
STRCT *initstrct();

void ptype(Type *,FILE *,int);


#endif
