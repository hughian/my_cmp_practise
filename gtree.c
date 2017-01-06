/*
 * Name:gtree.c
 * Author:Hades
 * Last_modified:2016-10-31
 * Function:
*/
#include"gtree.h"
#include"midcode.h"
extern void yyrestart(FILE *f);
extern int yyparse();
static int num=0;
static int vcount=0;
static int bind=0;
static int strsize=0;
FILE *pf;


AST *initast(void)
{
    AST *a=(AST *)malloc(sizeof(AST));
    if(!a){
        yyerror("Overflow");
        exit(0);
    }
    a->line=-1;
    a->name=0;
    a->left=0;
    a->right=0;
    a->content=0;
    a->number=-1;
    return a;
}

int stoi(char *s)
{
    int r=0;
    int i;
    if(s[0]=='0'){
        if(s[1]=='x'|| s[1]=='X'){
            for(i=2;i<(int)strlen(s);i++)
            {
                if(s[i]<='f' && s[i]>='a')
                    r = r*16 + (s[i]-'a'+10);
                else if(s[i]<='F' && s[i]>='A')
                    r = r*16 + (s[i]-'A'+10);
                else
                    r = r*16 + (s[i]-'0');
            }
        }
        else{
            for(i=1;i<(int)strlen(s);i++)
            {
                r = r*8 + (s[i]-'0');
            }
        }
    }
    else
        r=atoi(s);

    return r;
}

AST *newast(char * name,int num,...)
{
    int i;
    va_list valist;
    AST *tmp;
    AST *a;
    //AST *a=(AST *)malloc(sizeof(AST));
    //if(!a)
    //{
    //    yyerror("Overflow");
    //    exit(0);
    //}
    ///*初始化结构体内的指针，防止野指针出现*/
    //a->left=0;
    //a->right=0;
    a=initast();

    a->name=name;
    va_start(valist,num);

    if(num>0)
    {
        tmp=va_arg(valist,AST *);
        a->left=tmp;
        a->line=tmp->line;

        if(num>=2){   //智障 >= 2
            for(i=0;i<num-1;i++)
            {
                tmp->right=va_arg(valist,AST *);
                tmp=tmp->right;
            }
        }
    }
    else
    {
        int line=va_arg(valist,int);
        a->line=line;
        a->content=(char *)malloc(sizeof(char)*40);
        if(!strcmp(a->name,"INT"))
        {
            a->valuei=stoi(yytext);
            a->tag=CON;
            strcpy(a->content,"int");
        }
        else if(!strcmp(a->name,"FLOAT"))
        {
            a->valuef=atof(yytext);
            a->tag=CON;
            strcpy(a->content,"float");
        }
        else{ //非数值,标示符或者运算符
            strcpy(a->content,yytext);
        }
    }
    return a;
}

void DepthT(AST *a,int level)
{
    int i;
    if(a!=0)
    {
        if(a->line != -1) //空结点不打印
        {
            for(i=0;i<level;i++)
                printf("  ");
            printf("%s ",a->name);
            if(!strcmp(a->name,"IDENTIFIER") || !strcmp(a->name,"TYPE"))
                printf(":>%s",a->content);
            else if(!strcmp(a->name,"INT"))
                printf(":>%d",a->valuei);
            else if(!strcmp(a->name,"FLOAT"))
                printf(":>%f",a->valuef);
            else
                printf("(%d)",a->line);
            printf("\n");
        }
        

        DepthT(a->left,level+1);
        DepthT(a->right,level);
    }
}

void eval_c(AST *a)
{
    AST *pl,*pr;
    a=a->left;//ext_def_list
    int flg=0;
    while(a->line != -1){
        pl=a->left->left;  //sepcifier
        pr=pl->right; //
        if(!strcmp(pr->name,"ext_dec_list"))
            extdeclist(pl,pr);
        else if(!strcmp(pr->name,"fun_dec")){
            fundec(pl,pr);
            if(!flg)
            {
                Tgvdec(symhead->next);
                flg=1;
            }
            Tfunc(pr);
            bind++;
            compst(pr->right);
            Tvdef(bind);
            Tcompst(pr->right);
            delbindsym();
            bind--;
        }
        else
            specstrctdef(pl);

        a=a->left->right;
    }
}

void extdeclist(AST *pl,AST *pr)
{
    pl=pl->left;//TYPE or structspecifier

    if(!strcmp(pl->name,"TYPE"))
        varORarray(pl,pr);
    else
        gstrctsym(pl,pr);

}

void varORarray(AST *pl,AST *pr)
{
    //pl->content 为类型名
    //pr->name 为ext_dec_list or dec_list
    SYMBOL *p;
    AST *tmp;
    while(1){
        pr=pr->left;//var_dec or dec
        if(!strcmp(pr->name,"dec"))
            pr=pr->left;//dec的left var_dec
        if(pr->tag==VAR){
            if(!(p=findsym(pr->left)))
                newsym(DEF,VAR,bind,pl,pr->left);
            else if(p->type->kind==VAR)
                myerror(pr,301,p);//Redefined variable.
            else
                myerror(pr,303,p);//Duplicated name.
        }
        else{
            tmp=pr;
            while(tmp->left){
                tmp=tmp->left;  //找到数组名
            }
            if(!(p=findsym(tmp)))
                newsym(DEF,ARR,bind,tmp,pl,pr);//tmp=>ID,pl->content,pr=>var_dec
            else if(p->type->kind==ARR)
                myerror(tmp,302,p);//Redefined array.
            else
                myerror(tmp,303,p);//Dupicated name.
        }

        if(!pr->right)
            break;
        else
            pr=pr->right->right;//next ext_dec_list or dec_list.
    }
}

void gstrctsym(AST *pl,AST *pr)
{
    //pl struct_specifier
    //pr ext_dec_list
    SYMBOL *p;
    if(pl->left->right->right){
        strctdef(pl->left);//匿名结构将自动生成名字
        varORarray(pl->left->right->left,pr);
    }
    else{
        if(!(p=findsym(pl->left->right->left)))
            myerror(pl->left->right->left,1701,NULL);//undefined structure
        else if(p->type->kind != STR)
            myerror(pl->left->right->left,1702,p); //no a structure
        else
            varORarray(pl->left->right->left,pr);
    }
}

void specstrctdef(AST *pl)
{
    //pl specifier
    if(!strcmp(pl->left->name,"TYPE"))
        myerror(pl,1,NULL); //warning1:no meaning sentence
    else if(!(pl->left->left->right->right))
        myerror(pl,1,NULL); //warning1:no meaning sentence
    else{
        if(pl->left->left->right->line != -1) //opt_tag 不为空，非匿名结构
            strctdef(pl->left->left);
        else
            myerror(pl,2,NULL);//warning2:anonymous struct and undefined variabls
    }
}

void strctdef(AST *pl)
{
    //pl STRUCT
    SYMBOL *p;
    if(pl->right->line==-1)
        autoname(pl); //给匿名生成名字，新建树节点
    if(!(p=findsym(pl->right->left)))
        newsym(DEF,STR,bind,pl->right->left,pl->right->right->right);/////def_list need to be dealt with
    else if(p->type->kind==STR)
        myerror(pl,1601,p); //redefined structure
    else
        myerror(pl,303,p);
}

void nrtype(AST *pl)
{
    //pl specifier
    SYMBOL *p;
    pl=pl->left;
    if(!strcmp(pl->name,"TYPE")){
        gpvar=pl->content;
    }
    else{
        if(pl->left->right->right){//结构类型定义
            strctdef(pl->left);//pl->left STRUCT
            gpvar=pl->left->right->left->content;
        }
        else{//结构引用
            if(!(p=findsym(pl->left->right->left))){ //tag
                myerror(pl->left->right->left,1701,NULL);//Undefined structure
                gpvar=0;
            }
            else
                gpvar=pl->left->right->left->content;

        }
    }
}

void fundec(AST *pl,AST *pr)
{
    //pl specifier
    //pr fun_dec
    AST *tmp=pr->left;//ID
    SYMBOL *p;
    if(!(p=findsym(tmp)))
        newsym(DEF,FUN,bind,pl,pr,pr->right);
    else if(p->type->kind==FUN)
        myerror(tmp,401,p);//Redefined function.
    else
        myerror(tmp,303,p);//Duplicated name.
}


void ntype(AST *pl,AST *pr)//pl指向结点specifier,pr指向结点dec_list|ext_dec_list
{
    STRCT *ps;
    ARRAY *parr,*p;
    AST *tmp;
    if(!strcmp(pl->left->name,"TYPE"))//普通类型
    {
        do{
            pr=pr->left;//dec
            ps=initstrct();

            if(pr->left->tag==ARR){    //普通类型的数组
                parr=initarray();
                parr->elem->kind=VAR;
                parr->elem->pvar=pl->left->content;

                parr->size=pr->left->left->right->right->valuei;

                tmp=pr->left->left->left;
                while(tmp->right){
                    p=initarray();
                    p->size=tmp->right->right->valuei;
                    p->elem->kind=ARR;

                    p->elem->parr=parr;
                    parr=p;
                    
                    tmp=tmp->left;
                }
                ps->name=tmp->left->content;
                ps->type->kind=ARR;
                ps->type->parr=parr;
            }
            else //普通类型变量
            {
                ps->name=pr->left->left->content;
                ps->type->kind=VAR;
                ps->type->pvar=pl->left->content;
            }
        }while(pr->left->right);

    }
    else //结构类型
    {
        ;
    }
}

void autoname(AST *astp)
{
    static int count=0;
    AST *a;
    int line=astp->line;
    char *content=(char *)malloc(sizeof(char)*10);
    char *name=(char *)malloc(sizeof(char)*20);
    sprintf(content,"%03danony",count++);
    sprintf(name,"IDENTIFIER");
    a=initast();
    a->name=name;
    a->content=content;
    a->line=line;
    astp->right->line=line;
    astp->right->left=a;
}


ARRAY *initarray()
{
    ARRAY *a=(ARRAY *)malloc(sizeof(ARRAY));
    if(!a){
        printf("Overflow.");
        exit(0);
    }
    a->elem=(Type *)malloc(sizeof(Type));
    if(!a->elem){
        printf("Overflow.");
        exit(0);
    }
    a->size=0;
    a->elem->pvar=0;
    return a;
}

STRCT *initstrct()
{
    STRCT *a=(STRCT *)malloc(sizeof(STRCT));
    if(!a){
        printf("Overflow.");
        exit(0);
    }
    a->name=0;
    a->type=(Type *)malloc(sizeof(Type));
    if(!a->type){
        printf("Overflow.");
        exit(0);
    }
    a->type->pvar=0;
    a->next=0;//??
    return a;
}

SYMBOL* initsym()
{
    SYMBOL *a=(SYMBOL *)malloc(sizeof(SYMBOL));
    if(!a){
        printf("Overflow.");
        exit(0);
    }
    a->type=(Type *)malloc(sizeof(Type));
    if(!a->type){
        printf("Overflow.");
        exit(0);
    }
    
    a->name=0;
    a->num=num++;
    a->vis=1;
    a->line=0;
    a->size=0;
    a->valuei=0;
    a->next=0;
    a->pap=0;
    a->addr=0;
    a->bind=0;
    a->level=-1;
    a->vname=0;
    return a;
}
void newsym(DFND ndx,KIND kind,int level,...)
{
    SYMBOL *a,*tr;
    AST *tmp;
    int k=1;
    va_list valist;
    va_start(valist,level);
    a=initsym();
    ARRAY *parr,*p;
    a->Ndx=ndx;
    a->type->kind=kind;
    a->level=level;
    switch(kind){
        case VAR:
            a->vname=vcount++;
            tmp=va_arg(valist,AST*);
            a->type->pvar=tmp->content;
            if(!strcmp(tmp->content,"int") || !strcmp(tmp->content,"float"))
                a->size=4;
            else
            {
                tr=findsym(tmp);
                a->size=tr->size;
            }
            tmp=va_arg(valist,AST*);
            a->name=tmp->content;
            a->line=tmp->line;
            break;
        case FUN:
            
            /*返回类型*/
            tmp=va_arg(valist,AST*);
            nrtype(tmp);
            a->type->pvar=gpvar;
            /*函数头*/
            tmp=va_arg(valist,AST*);
            a->name = tmp->left->content;
            a->line = tmp->left->line;
            nparas(tmp->left->right);//LP
            a->pap=ph->pap;
            a->valuei=pnum;  //函数表项的值valuei存参数个数。
            /*函数体*/
            //tmp=va_arg(valist,AST *);
            //compst(tmp);//作用域
            a->size=-1;
            pt=ph;
            pt->pap=0;
            pnum=0;
            break;
        case CON:
            a->size=0;//常量不分配空间
            break;
        case ARR:
            a->vname=vcount++;
            tmp=va_arg(valist,AST *);
            a->name = tmp->content;
            a->line = tmp->line;

            tmp=va_arg(valist,AST *);
            parr=initarray();
            parr->elem->kind=VAR;
            parr->elem->pvar=tmp->content;
            
            a->valuei=4;  // 同下
            if(!strcmp(tmp->content,"int") || !strcmp(tmp->content,"float"))
                k *= 4;
            else
            {
                tr=findsym(tmp);
                k *= tr->size;
                a->valuei=k; //数组表项的值valuei存基本类型的大下。
            }

            tmp=va_arg(valist,AST *);
            parr->size=tmp->left->right->right->valuei;
            k *= parr->size;
            tmp = tmp->left->left;
            while(tmp->right){
                p=initarray();
                p->size=tmp->right->right->valuei;
                p->elem->kind=ARR;
                
                k= k * p->size;

                p->elem->parr=parr;
                parr=p;

                tmp=tmp->left;
            }
            a->size=k;
            a->type->parr=parr;
            break;
        case STR:
            tmp=va_arg(valist,AST *);
            a->name=tmp->content;
            a->line=tmp->line;
            tmp=va_arg(valist,AST*);
            //AST *pl,*pr,*pm;
            //STRCT *pstr,*ps;
            gtpstr=initstrct();
            ghpstr=gtpstr;
            strsize=0;
            deflist(tmp,0);
            a->size=strsize;
            a->type->pstr=ghpstr->next;
            break;
        default:
            break;
    }
    symhead->valuei++;
    symtail->next=a;
    symtail=a;
    fprintf(pf,"new:%d  %s  %d\n",a->num,a->name,a->level);
}

void deflist(AST *tmp,int op){
    //op 用来表示是结构中的dec_list(0) 还是 comp_st中的dec_list(1)
    //tmp def_list
    AST *pl,*pr;
    while(tmp->line != -1){
        pl=tmp->left->left;//specifier
        pr=pl->right; //dec_list
        if(!strcmp(pl->left->name,"TYPE")){
            if(!op)
                nmember(pl->left,pr);  //普通类型成员
            else
                ncompdec(pl->left,pr);
        }
        else{
            if(!op)
                smember(pl->left,pr);
            else
                scompdec(pl->left,pr);
        }
        tmp=tmp->left->right; //下一个def_list
    }
}

void nmember(AST *pl,AST *pr)
{
    //pl TYPE
    //pr dec_list
    AST *tmp;
    while(1){
        if(pr->left->left->right)
            myerror(pr->left->left,1501,NULL);//assignment in declaration of strcut;
        if(pr->left->left->tag==ARR){
            tmp=pr->left->left;//var_dec
            while(tmp->left){ tmp=tmp->left; }
            if(findmem(ghpstr,tmp))
                myerror(tmp,1502,NULL);//Duplicate member.
            else
                newsfield(ARR,pl,pr->left->left);
        }
        else{
            if(findmem(ghpstr,pr->left->left->left))
                myerror(pr->left->left->left,1502,NULL);//Duplicate member.
            else
                newsfield(VAR,pl,pr->left->left->left);
        }

        if(pr->left->right==0)
            break;
        else
            pr=pr->left->right->right;
    }
}

void newsfield(KIND kind,AST *pl,AST *pr)
{
    STRCT *p;
    AST *tmp;
    ARRAY *parr,*arr;
    int k=1;
    p=initstrct();
    p->type->kind=kind;
    switch(kind){
        case VAR:
            strsize += 4;
            p->name=pr->content;
            p->type->pvar=pl->content;
            break;
        case ARR:
            
            parr=initarray();
            parr->elem->kind=VAR;
            parr->elem->pvar=pl->content;
            parr->size=pr->left->right->right->valuei;
            k = 4*parr->size;
            tmp=pr->left->left;
            while(tmp->right){
                arr=initarray();
                arr->size=tmp->right->right->valuei;
                arr->elem->kind=ARR;
                
                k *= arr->size;

                arr->elem->parr=parr;
                parr=arr;

                tmp=tmp->left;
            }
            strsize += k;
            p->name=tmp->content;
            p->type->parr=parr;
            break;
        case STR:
            break;
        default:
            break;
    }
    gtpstr->next=p;
    gtpstr=p;
}

void smember(AST *pl,AST *pr)
{
    pl=pr;//这句是乱写的
    myerror(pl,3,NULL); //结构里面定义结构
}

int findmem(STRCT *pstr,AST *pr)
{
    STRCT *p=pstr->next;
    while(p){
        if(!strcmp(p->name,pr->content))
            return 1;
        p=p->next;
    }
    return 0;
}


void nparas(AST *tmp)
{
    //tmp LP右部为var_list or RP
    //ph=pt 参数表链
    AST *pl,*pr;
    SYMBOL *p;
    if(!strcmp(tmp->right->name,"var_list")){
        tmp=tmp->right;//var_dec
        while(1){
            pl=tmp->left->left;//spcifier
            pr=pl->right;//var_dec
            if(!strcmp(pl->left->name,"TYPE"))
                newvardec(pl->left,pr,0);
            else{
                if(pl->left->left->right->right){ //结构类型定义
                    strctdef(pl->left->left);
                    newvardec(pl->left->left->right->left,pr,0);
                }
                else{ //结构类型引用
                    if(!(p=findsym(pl->left->left->right->left)))
                        myerror(pl->left->left->right->left,1701,NULL); //undefined structure.
                    else if(p->type->kind != STR)
                        myerror(pl->left->left->right->left,1702,p); //not a structure.
                    else
                        newvardec(pl->left->left->right->left,pr,0);
                }
            }
            if(tmp->left->right)
                tmp=tmp->left->right->right;
            else
                break;
        }
    }
    else
        ph->next=0;//no param
    
}
void newvardec(AST *pl,AST *pr,int op)
{
    //pl->content 为类型名
    //pr为第一个var_dec(VAR or ARR)
    //op 表示形参(0) 还是与前面作用域不同的同名变量(1)
    AST *tmp;
    SYMBOL *a,*p,*tr;
    ARRAY *parr,*arr;
    int flg=0;
    int k=1;
    if(pr->tag==ARR){
        tmp=pr->left;
        while(tmp->left){   tmp=tmp->left;  }
    }
    else
        tmp=pr->left;
    
    p=symhead;
    while(p){
        if(p->next != 0 && !strcmp(p->next->name,tmp->content))
        {   flg=1;break;    }
        p=p->next;
    }
    a=initsym();
    if(pr->tag==ARR){
        a->vname=vcount++;
        a->name=tmp->content;
        a->line=tmp->line;
        a->type->kind=ARR;

        parr=initarray();
        parr->elem->kind=VAR;
        parr->elem->pvar=pl->content;
        if(!strcmp(pl->content,"int") || !strcmp(pl->content,"float"))
            k *= 4;
        else
        {
            tr=findsym(pl);
            k *= tr->size;
        }
        parr->size=pr->left->right->right->valuei;
        k *= parr->size;
        pr=pr->left->left;
        while(pr->right){
            arr=initarray();
            arr->size=pr->right->right->valuei;
            arr->elem->kind=ARR;
            
            k *= arr->size;

            arr->elem->parr=parr;
            parr=arr;

            pr=pr->left;
        }
        a->size=k;
        a->type->parr=parr;
    }
    else{
        if(!strcmp(pl->content,"int") || !strcmp(pl->content,"float"))
            a->size=4;
        else
        {
            tr=findsym(pl);
            a->size=tr->size;
        }
        a->type->kind=VAR;
        a->type->pvar=pl->content;
        a->name=pr->left->content;
        a->vname=vcount++;
        a->line=pr->left->line;
    }
    a->Ndx=DEF;
    a->level=bind;
    /*勾连参数链*/
    if(!op){
        pnum++;
        a->level=bind+1;
        pt->pap=a;
        pt=a;
    }

    if(flg){
        a->next=p->next->next;
        a->bind=p->next;
        p->next=a;
        //p->next->next=0;//????????需不需要??????
    }
    else{
        symtail->next=a;
        symtail=a;
    }
    symhead->valuei++;
    fprintf(pf,"new:%d  %s  %d  \n",a->num,a->name,a->level);
}

void compst(AST *tmp)
{
    //tmp comp_st
    AST *pl,*pr;
    pl=tmp->left->right; //def_list
    pr=pl->right; //stmt_list
    //bind++;
    deflist(pl,1);
    while(pr->line != -1){
        stmt(pr->left);//pr->left stmt
        pr=pr->left->right;//下一个stmt_list
    }
    /*删除当前作用域下的符号表项*/
    //delbindsym();
    //bind--;
}
void ncompdec(AST *pl,AST *pr)
{
    //pl TYPE
    //pr dec_list
    SYMBOL *p;
    AST *tmp;
    int flg=0;
    while(1){
        if(pr->left->left->tag==ARR){
            flg=1;
            tmp=pr->left->left;//var_dec
            while(tmp->left){   tmp=tmp->left;  }
        }
        else
            tmp=pr->left->left->left;
        
        if(!(p=findsym(tmp))){
            if(flg)
                newsym(DEF,ARR,bind,tmp,pl,pr->left->left);
            else
                newsym(DEF,VAR,bind,pl,pr->left->left->left);
        }
        else if(p->level < bind){
            newvardec(pl,pr->left->left,1);
        }
        else
            myerror(tmp,301,p);//Redefined variable;
        /*循环控制*/
        if(pr->left->right==0)
            break;
        else
            pr=pr->left->right->right;//下一个dec_list
    }
}
void scompdec(AST *pl,AST *pr)
{
    //pl structspcifier
    //pr dec_list
    SYMBOL *p;
    if(pl->left->right->right){
        strctdef(pl->left);
        ncompdec(pl->left->right->left,pr);//定义完结构类型，变量列表为普通变量
    }
    else{
        if(!(p=findsym(pl->left->right->left)))
            myerror(pl->left->right->left,1701,NULL);//undefined structure
        else if(p->type->kind != STR)
            myerror(pl->left->right->left,1702,p);//not a structure
        else
            ncompdec(pl->left->right->left,pr);
    }
}
void stmt(AST *tmp)
{
    //tmp stmt
    if(tmp->number==4301)  //stmt=>exp SEMI
        expression(tmp->left);
    else if(tmp->number==4302) //stmt=>comp_st
        compst(tmp->left);
    else if(tmp->number==4303) //stmt=>RETURN exp SEMI
        checkrtype(tmp->left);
    else if(tmp->number==4304){
        expression(tmp->left->right->right);
        stmt(tmp->left->right->right->right->right);
    }
    else if(tmp->number==4305){
        expression(tmp->left->right->right);
        stmt(tmp->left->right->right->right->right);
        stmt(tmp->left->right->right->right->right->right->right);
    }
    else{ //tmp->number==4306
        expression(tmp->left->right->right);
        stmt(tmp->left->right->right->right->right);
    }
}
void expression(AST *tmp)
{
    //tmp exp;
    AST *pl,*pr;
    SYMBOL *p;
    ARRAY *parr;
    int flg=0;
    int n=0,i=0;
    switch(tmp->number){
        case 6101:      //exp=>exp ASSIGNOP exp
            expression(tmp->left);
            expression(tmp->left->right->right);
            if(tmp->left->tag==CON)
                myerror(tmp->left,601,NULL);
            else if(tmp->left->tag==ARR)
                expcheck(tmp,502);
            else
                expcheck(tmp,501);
            break;
        case 6102:      //exp=>exp AND exp
            expression(tmp->left);
            expression(tmp->left->right->right);

            break;
        case 6103:      //exp=>exp OR exp
            expression(tmp->left);
            expression(tmp->left->right->right);

            break;
        case 6104:      //exp=>exp RELOP exp
            expression(tmp->left);
            expression(tmp->left->right->right);

            break;
        case 6105:      //exp=>exp ADD exp
            expression(tmp->left);
            expression(tmp->left->right->right);
            expcheck(tmp,701);
            break;
        case 6106:      //exp=>exp SUB exp
            expression(tmp->left);
            expression(tmp->left->right->right);
            expcheck(tmp,702);
            break;
        case 6107:      //exp=>exp MUL exp
            expression(tmp->left);
            expression(tmp->left->right->right);
            expcheck(tmp,703);
            break;
        case 6108:      //exp=>exp DIV exp
            expression(tmp->left);
            expression(tmp->left->right->right);
            expcheck(tmp,704);
            break;
        case 6109:      //exp=>LP exp RP
            expression(tmp->left->right);
            tmp->content=tmp->left->right->content;
            tmp->tag=tmp->left->right->tag;
            break;
        case 6110:      //exp=>SUB exp
            expression(tmp->left->right);
            tmp->content=tmp->left->right->content;
            tmp->tag=tmp->left->right->tag;
            //?????
            break;
        case 6111:      //exp=>NOT exp
            expression(tmp->left->right);
            if(tmp->left->right->tag==ARR)
                myerror(tmp,705,NULL);
            else if((p=findsym(tmp->left->right)) && p->type->kind==STR)
                myerror(tmp,705,NULL);
            else{
                tmp->content=(char *)malloc(sizeof(char)*10);
                strcpy(tmp->content,"int");
                tmp->tag=VAR;
                tmp->valuei=!(tmp->left->right->valuei);
            }
            break;
        case 6112:      //exp=>ID LP args RP
            if(!(p=findsym(tmp->left)))
                myerror(tmp->left,201,NULL); //undefined function
            else if(p->type->kind != FUN)
                myerror(tmp->left,1101,p);    //not a function
            else{
                real(p,tmp->left);//符号表项，函数ID->right->right为参数表
                tmp->content=p->type->pvar;
                tmp->tag=VAR;
            }
            break;
        case 6113:      //exp=>ID LP RP
            if(!(p=findsym(tmp->left)))
                myerror(tmp->left,201,NULL); //undefined function
            else if(p->type->kind != FUN)
                myerror(tmp->left,201,NULL); //undefined function
            else{
                real(p,tmp->left);//函数名，无实参
                tmp->content=p->type->pvar;
                tmp->tag=VAR;
            }
            break;
        case 6114:      //exp=>exp LB exp RB
            flg=0;
            if(tmp->right==0 || strcmp(tmp->right->name,"LB"))
            {
                pl=tmp->left; //左exp
                while(pl->left){ //找到ID,并检查数组下标
                    pr=pl->right->right;
                    expression(pr);
                    if(strcmp(pr->content,"int")) //检查数组下标是否都为整数
                        flg=1;
                    n++;
                    pl=pl->left;
                }
                if(!(p=findsym(pl))){
                    myerror(pl,102,NULL);//undefined array;
                    if(flg)
                        myerror(pl,1201,NULL);
                }
                else if(p->type->kind != ARR){
                    myerror(pl,1001,p);//not an array;
                    if(flg)
                        myerror(pl,1201,p);
                }
                else{
                    if(flg)
                        myerror(pl,1201,p);
                    //tmp->tag=VAR;
                    parr=p->type->parr;
                    i=1;
                    while(parr->elem->kind==ARR){
                        parr=parr->elem->parr;
                        i++;
                    }
                    tmp->content=parr->elem->pvar;
                    if(i==n)
                        tmp->tag=VAR;
                    else
                        tmp->tag=ARR;
                }
            }
            break;
        case 6115:      //exp=>exp DOT ID
            expression(tmp->left);
            if(tmp->left->content !=0 &&(!strcmp(tmp->left->content,"int") || !strcmp(tmp->left->content,"float")))
                myerror(tmp->left,1301,NULL);//not a structure
            else
                strctfield(tmp);
            break;
        case 6116:      //exp=>ID 递归到的id都是VAR,因为ARR在6114中遍历处理
            if(!(p=findsym(tmp->left))){
                //newsym(UND,UNK,bind,NULL,NULL);
                myerror(tmp->left,101,NULL);//Undefine variable
                tmp->content=0;
            }
            else{
                if(p->type->kind==VAR){
                    tmp->content=p->type->pvar;
                    tmp->tag=VAR;
                }
                else if(p->type->kind==ARR){
                    tmp->tag=ARR;
                    tmp->content=p->type->pvar;//
                }
                else{
                    printf("something went wrong.");
                }
            }
            break;
        case 6117:      //exp=>INT
            tmp->content=tmp->left->content;
            tmp->tag=tmp->left->tag;
            tmp->valuei=tmp->left->valuei;
            break;
        case 6118:      //exp=>FLOAT
            tmp->content=tmp->left->content;
            tmp->tag=tmp->left->tag;
            tmp->valuef=tmp->left->valuef;
            break;
        default:
            printf("something went wrong.");
            break;
    }
}

void expcheck(AST *tmp,int index)
{
    //tmp exp
    AST *pl,*pr;
    pl=tmp->left;//exp 左操作数
    pr=pl->right->right;//exp 右操作数
    if(pl->content==0 || pr->content == 0) //变量未定义，类型属性为空
        ;
    else if(strcmp(pl->content,pr->content))
        myerror(tmp,index,NULL);
    else{
        if(pl->tag != pr->tag){
            if(pl->tag == CON){
                tmp->content=pr->content;
                tmp->tag=pr->tag;
            }
            else if(pr->tag == CON){
                tmp->content=pr->content;
                tmp->tag=pr->tag;
            }
            else
                myerror(tmp,index,NULL);
        }
        else{
            if(pl->tag==ARR)
                myerror(pl,index,NULL);
            else{
                tmp->tag=pl->tag;
                tmp->content=pl->content;
            }
        }
    }
}
void delbindsym()
{
    SYMBOL *p,*ptemp;
    p=symhead;
    while(1){
        if( p->next && p->next->level == bind){  //当前作用域下的结点
            ptemp=p->next;
            if(symtail==p->next && p->next->bind !=0){
                symtail=p->next->bind;
                p->next->bind->next=p->next->next;
                p->next=symtail;
            }
            else if(symtail == p->next && p->next->bind ==0){
                symtail=p;
                p->next=p->next->next;
            }
            else if(symtail != p->next && p->bind != 0){
                p->next->bind->next=p->next->next;
                p->next=p->next->bind;
            }
            else{
                p->next=p->next->next;
            }
            //free(ptemp);
        }
        else{
            if(p->next) 
                p=p->next;
            else
                break;
        }
    }
}

void real(SYMBOL *p,AST *tmp)
{
    //p 符号表中的函数表项
    //tmp ID  兄弟结点中为参数表或空
    AST *pl,*pr;
    SYMBOL *pt;
    ARRAY *parr;
    if(tmp->right->right->right){ //有参数
        pt=p->pap;
        pr=tmp->right->right;//args
        while(1){
            /*形参实参类型匹配*/
            pl=pr->left;//exp;
            
            expression(pl);
            
            if(pl->tag == pt->type->kind && pl->tag ==ARR)
                ;
            else if(pl->tag == pt->type->kind && pl->tag == VAR){
                if(strcmp(pl->content,pt->type->pvar))
                    myerror(pr,901,p);
            }
            else{ //
                if(pt->type->kind==ARR){
                    parr=pt->type->parr;
                    while(parr->elem->kind==ARR)
                        parr=parr->elem->parr;
                    if(pl->tag!=CON || strcmp(pl->content,parr->elem->pvar))
                        myerror(pr,901,p);
                }
                else{
                    if(pl->tag!=CON || strcmp(pl->content,pt->type->pvar))
                        myerror(pr,901,p);
                }
            }
                

            /*查找循环控制***********/
            if(pt->pap && pr->left->right){
                pt=pt->pap; //下一个形参
                pr=pr->left->right->right;//下一个args实参
            }
            else if(!pt->pap && !pr->left->right){
                break; //all check
            }
            else{
                myerror(pr,901,p);
                break;
            }    
            /************************/
        }

    }
    else{  //无参
        if(p->pap != 0)
            myerror(tmp,901,p);
    }
}

void strctfield(AST *tmp)
{
    //tmp exp
    AST *pr;
    SYMBOL *p;
    STRCT *pstr;
    ARRAY *parr;
    pr=tmp->left->right->right;
    p=findsym(tmp->left);//找到结构类型
    pstr=p->type->pstr;
    while(pstr){
        if(!strcmp(pr->content,pstr->name))
        {
            tmp->tag=pstr->type->kind;
            if(tmp->tag==ARR){
                parr=pstr->type->parr;//////////////////
                while(parr->elem->kind==ARR)
                    parr=parr->elem->parr;
                tmp->content=pstr->type->pvar;
            }
            else
                tmp->content=pstr->type->pvar;
            return;
        }
        pstr=pstr->next;
    }
    myerror(pr,1401,p);
}

void checkrtype(AST *tmp)
{
    //tmp RETURN
    AST *pl;
    pl=tmp->right;
    expression(pl);
    if(pl->tag==CON && !strcmp(pl->content,gpvar))
        ;//check
    else if(pl->tag==VAR && !strcmp(pl->content,gpvar))
        ;//check
    else
        myerror(pl,801,NULL);
}
void ptype(Type *p,FILE *f,int level)
{
    if(p!=0){
        switch(p->kind){
            case VAR:
                fprintf(f,"type:%8s",p->pvar);
                break;
            case FUN:
                fprintf(f,"rtype:%7s",p->pvar);
                break;
            case CON:
                fprintf(f,"type:%8s",p->pvar); 
            case ARR:
                fprintf(f,"\n\t\t\tlv:%02d-size:%4d  ",level,p->parr->size);
                ptype(p->parr->elem,f,level+1);
                break;
            case STR:
                fprintf(f,"\n\t\t\t\tname:%8s ",p->pstr->name);
                ptype(p->pstr->type,f,level+1);
                break;
        }
    }
}


void print()
{
    SYMBOL *p=symhead->next,*tmp;
    FILE *f;
    STRCT *pstr;
    if(!(f=fopen("result","w")))
        perror("result");
    while(p){
        fprintf(f,"[%03d]%8s\t",p->num,p->name);
        fprintf(f,"kind:%2d  Ndx:%2d",p->type->kind,p->Ndx);
        //if(p->type->kind==ARR)
        //    fprintf(f,"  type:%p",p->type->parr);
        //else if(p->type->kind==STR)
        //    fprintf(f,"  type:%p",p->type->pstr);
        //else
        //    fprintf(f,"  type:%8s",p->type->pvar);
        fprintf(f,"  size:%6d  value:0x%x  addr:%p  ",p->size,p->valuei,p->addr);
        fprintf(f,"bind:%d",p->level);
        
        switch(p->type->kind){
            case ARR:
                ptype(p->type,f,0);
                break;
            case STR:
                pstr=p->type->pstr;
                fprintf(f,"\n\t\t\ttype:");
                while(pstr){
                    fprintf(f,"\n\t\t\t\tname:%8s  ",pstr->name);
                    ptype(pstr->type,f,0);
                    pstr=pstr->next;
                }
                break;
            default:
                fprintf(f,"\n\t\t\ttype:%8s",p->type->pvar);
                break;
        }
        fprintf(f,"[***]\n");
        
        if(p->type->kind==FUN){
            tmp=p->pap;
            while(tmp){
                fprintf(f,"\t\t\t\t\t[%03d]%s\t",tmp->num,tmp->name);
                fprintf(f,"kind:%6d\n",tmp->type->kind);
                tmp=tmp->pap;
            }
        }
        if(p->bind){
            tmp=p->bind;
            while(tmp){
                fprintf(f,"[%03d]%8s\t",tmp->num,tmp->name);
                fprintf(f,"kind:%2d  Ndx:%2d  ",tmp->type->kind,tmp->Ndx);
                fprintf(f,"size:%6d  value:0x%x  addr:%p",tmp->size,tmp->valuei,tmp->addr);
                fprintf(f,"  bind:%d",tmp->level);
                switch(tmp->type->kind){
                    case ARR:
                        ptype(tmp->type,f,0);
                        break;
                    case STR:
                        pstr=tmp->type->pstr;
                        fprintf(f,"\n\t\t\ttype:");
                        while(pstr){
                            fprintf(f,"\n\t\t\t\tname:%8s",pstr->name);
                            ptype(pstr->type,f,0);
                            pstr=pstr->next;
                        }
                        break;
                    default:
                        fprintf(f,"\n\t\t\ttype:%8s ",tmp->type->pvar);
                        break;
                }
                fprintf(f,"[***]\n");
                tmp=tmp->bind;
            }
        }
        p=p->next;
    };
    fclose(f);
}


SYMBOL * findsym(AST *astp)
{
    SYMBOL *p=symhead->next;
    while(p){
        if(!strcmp(p->name,astp->content)){
                return p;
        }
        p=p->next;
    }
    return 0;
}

//void yyerror(const char *s,...)
//{
//    va_list valist;
//    va_start(valist,s);
//    fprintf(stderr,"[line %d]error:%s",yylineno,s);
//    vprintf(stderr,valist);
//    fprintf(stderr,"\n");
//}
void yyerror(const char *fmt,...)
{
    va_list ap;
    va_start(ap,fmt);
    //fprintf(stderr,"[line %d]Error:",yylineno);
    printf("[line %d]Error:",yylineno);
    vprintf(fmt,ap);
    va_end(ap);
    //fprintf(stderr,"\n");
    printf("\n");
}
void myerror(AST *astp,int index,SYMBOL *p)
{
    switch(index)
    {
        case 101:
            printf("[line %d]Error0101:Undefined variable '%s'.",astp->line,astp->content);
            break;
        case 102:
            printf("[line %d]Error0102:Undefined array '%s'.",astp->line,astp->content);
        case 201:
            printf("[line %d]Error0201:Undefined function '%s'.",astp->line,astp->content);
            break;
        case 301:
            printf("[line %d]Error0301:Redefined variable '%s',first defined at line %d.",astp->line,p->name,p->line);
            break;
        case 302:
            printf("[line %d]Error0302:Redefined array '%s',first defined at line %d.",astp->line,p->name,p->line);
            break;
        case 303:
            printf("[line %d]Error0303:Duplicated name '%s',first used at line %d.",astp->line,p->name,p->line);
            break;
        case 401:
            printf("[line %d]Error0401:Redefined function '%s',first diefined at line %d.",astp->line,p->name,p->line);
            break;
        case 501:
            printf("[line %d]Error0501:Operands type mismatched for assignment.",astp->line);
            break;
        case 502:
            printf("[line %d]Error0502:Assignment with array type.",astp->line);
            break;
        case 601:
            printf("[line %d]Error0601:The left-hand side of an assignment must be a variable.",astp->line);
            break;
        case 701:
            printf("[line %d]Error0701:Operands type mismatched for operator '+'.",astp->line);
            break;
        case 702:
            printf("[line %d]Error0702:Operands type mismatched for operator '-'.",astp->line);
            break;
        case 703:
            printf("[line %d]Error0703:Operands type mismatched for opetator '*'.",astp->line);
            break;
        case 704:
            printf("[line %d]Error0704:Operands type mismatched for operator '/'.",astp->line);
            break;
        case 705:
            printf("[line %d]Error0705:Operand can't be array or structure.",astp->line);
            break;
        case 801:
            printf("[line %d]Error0801:Type mismatched for return.",astp->line);
            break;
        case 901:
            printf("[line %d]Error0901:No matching function for call to '%s'.",astp->line,p->name);       
            break;
        case 1001:
            printf("[line %d]Error1001:'%s' is not an array.",astp->line,p->name);
            break;
        case 1101:
            printf("[line %d]Error1101:'%s' is not a function.",astp->line,p->name);
            break;
        case 1201:
            printf("[line %d]Error1201:Array subscript is not an integer.",astp->line);
            break;
        case 1301:
            printf("[line %d]Error1301:Illegal use of '.'.",astp->line);
            break;
        case 1401:
            printf("[line %d]Error1401:struct '%s' don't have any member named '%s'.",astp->line,p->name,astp->content);
            break;

        case 1501:
            printf("[line %d]Error1501:Assignment wasn't allowed in declaration of structure.",astp->line);
            break;
        case 1502:
            printf("[line %d]Error1502:Dupicate member '%s'.",astp->line,astp->content);
            break;
        case 1601:
            printf("[line %d]Error1601:Redefined structure '%s',first defined at line %d",astp->line,p->name,p->line);
            break;
        case 1701:
            printf("[line %d]Error1701:Undefined structure '%s'.",astp->line,astp->content);
            break;
        case 1702:
            printf("[line %d]Error1702:'%s' is not a structure.",astp->line,p->name);
            break;
        case 1:
            printf("[line %d]Warning01:no meaning sentence.",astp->line);
            break;
        case 2:
            printf("[line %d]Warning02:Unamed struct that defines no instance.",astp->line);
            break;
        case 3:
            printf("[line %d]Warning03:not allowed struct member",astp->line);
            break;
        default:
            break;
    }
    printf("\n");
    
}


int main(int argc,char *argv[])
{
    symtail=initsym();
    symhead=symtail;
    symhead->valuei=0;
    pt=(SYMBOL *)malloc(sizeof(SYMBOL));
    ph=pt;
    ph->next=0;
    ph->pap=0;
    initcode(); 
    FILE *f;
    pf=fopen("bug","w");
    if(argc>1){
        if((f=fopen(argv[1],"r"))==0){
            perror(argv[1]);
            exit(0);
        }
        printf("BEGIN>\n");
        yyrestart(f);
        yyparse();
        print();
        fclose(pf);

        pcode();
        printf("<END\n");
        return 0;
    }
    fclose(pf);
    return 0;
}


