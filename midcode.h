
#ifndef MIDCODE_H
#define MIDCODE_H
#include "gtree.h"

typedef struct code{
    struct code *prio;
    int line;
    char rd[40];
    char op[4];
    char rs[10];
    char rt[10];
    struct code *next;
}CODE;

int Ted[100];

char mbuf[100];

CODE *codehead,*codetail;


/*******************************************/
void initcode();
int mklabel();
void twoexp(AST *tmp,char *tvar,const char *op,int la);

void Tgvdec(SYMBOL *);
void Tfunc(AST *tmp);
void Tvdef(int bind);
void Tcompst(AST *tmp);
void Tstmt(AST *tmp);
void Texp(AST *tmp,char *tvar);
void Tarr(AST *tmp,char *tvar);
void Targs(AST *tmp,char *tvar);
void Tret(AST *tmp);
char *newtemp();
void newcode(const char*,const char*,const char*,const char *);
void insert();
void pcode();


#endif
