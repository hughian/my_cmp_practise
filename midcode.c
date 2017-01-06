#include"gtree.h"
#include"midcode.h"


void initcode()
{
    codehead=(CODE *)malloc(sizeof(CODE));
    codetail=(CODE *)malloc(sizeof(CODE));

    codehead->next=codetail;
    codehead->prio=codetail;
    codetail->next=codehead;
    codetail->prio=codehead;
}

int mklabel(char *t)
{
    static int n=0;
    n++;
    sprintf(t,"LABEL label%d :",n);
    return n;
}

void Tfunc(AST *tmp)
{
    SYMBOL *p,*pt;
    char rs[10],rt[10];
    p=findsym(tmp->left);
    sprintf(mbuf,"FUNCTION %s :",p->name);
    newcode(mbuf,"010",NULL,NULL);
    p->vis=0;
    if(p->pap)
    {
        pt=p->pap;
        while(pt){
            sprintf(rs,"v%d",pt->vname);
            sprintf(rt,"%d",pt->size);
            newcode("PARAM","000",rs,rt);
            
            pt->vis=0;
            
            pt=pt->pap;
        }
    }
}


/**************************************/
/**************************************/
void newcode(const char *rd,const char *op,const char *rs,const char *rt)
{
    static int line = 0;
    CODE *a=(CODE *)malloc(sizeof(CODE));
    a->line = line++;
    if(rd)  strcpy(a->rd,rd);
    if(op)  strcpy(a->op,op);
    if(rs)  strcpy(a->rs,rs);
    if(rt)  strcpy(a->rt,rt);

    codetail->prio->next=a;
    a->prio=codetail->prio;
    codetail->prio=a;
    a->next=codetail;
}

void pcode()
{
    FILE *f;
    if(!(f=fopen("codes","w")))
    {
        perror("codes");
        exit(0);
    }
    CODE *p=codehead->next;
    while(p != codetail)
    {
        if(!strcmp(p->op,"000"))
            fprintf(f,"%s %s %s\n",p->rd,p->rs,p->rt);
        else if(!strcmp(p->op,"001"))
            fprintf(f,"%s := %s\n",p->rd,p->rs);
        else if(!strcmp(p->op,"010"))
            fprintf(f,"\n%s\n",p->rd);
        else if(!strcmp(p->op,"011"))
            fprintf(f,"%s\n",p->rd);
        else if(!strcmp(p->op,"100"))
            fprintf(f,"%s := %s %s\n",p->rd,p->rs,p->rt);
        else
            fprintf(f,"%s := %s %s %s\n",p->rd,p->rs,p->op,p->rt);

        p=p->next;
    }
    fclose(f);
}
char *newtemp()
{
    static int number=0;
    char *t=(char *)malloc(sizeof(char)*10);
    sprintf(t,"t%d",number++);
    return t;
}

void Tgvdec(SYMBOL *p)
{
    char rs[10],rt[10];
    while(p){
        if(p->level==0 && p->vis==1 && p->type->kind != FUN && p->type->kind != STR)
        {
            sprintf(rs,"gv%d",p->vname);
            sprintf(rt,"%d",p->size);
            newcode("DEC","000",rs,rt);
            p->vis=0;
        }
        p=p->next;
    }
}

void Tvdef(int bind)
{
    char rs[10],rt[10];
    SYMBOL *p=symhead->next;
    while(p){
        if(p->level==bind && p->vis==1)
        {
            sprintf(rs,"v%d",p->vname);
            sprintf(rt,"%d",p->size);
            newcode("DEC","000",rs,rt);
            p->vis=0;
        }
        p=p->next;
    }
}
void Tcompst(AST *tmp)
{
    AST *pr;
    pr=tmp->left->right->right;
    while(pr->line != -1)
    {
        Tstmt(pr->left);
        pr=pr->left->right;
    }
}

void Tstmt(AST *tmp)
{
    //tmp stmt
    char *tn,*tt,*ltrue,*lfalse,*lmid;
    AST *pl,*pr;
    int nt,nf,nm;
    switch(tmp->number)
    {
        case 4301:  //exp;
            tn=newtemp();
            Texp(tmp->left,tn);
            break;
        case 4302:  //nothing need to be done
            Tcompst(tmp->left);
            break;
        case 4303:  //return
            tn=newtemp();
            pl=tmp->left->right;
            Texp(pl,tn);
            if(pl->number==6114){
                tt=newtemp();
                sprintf(mbuf,"*%s",tn);
                newcode(tt,"001",mbuf,NULL);
                sprintf(mbuf,"RETURN %s",tt);
            }
            else
                sprintf(mbuf,"RETURN %s",tn);
            newcode(mbuf,"011",NULL,NULL);
            break;
        case 4304:  //if
            tn=newtemp();
            pl=tmp->left->right->right;
            pr=pl->right->right;
            Texp(pl,tn);
            ltrue=(char *)malloc(sizeof(char)*20);
            lfalse=(char *)malloc(sizeof(char)*20);
            nt=mklabel(ltrue);
            nf=mklabel(lfalse);
            sprintf(mbuf,"%slabel%d",mbuf,nt);
            newcode(mbuf,"011",NULL,NULL);
            sprintf(mbuf,"GOTO label%d",nf);
            newcode(mbuf,"011",NULL,NULL);
            newcode(ltrue,"011",NULL,NULL);
            Tstmt(pr);
            newcode(lfalse,"011",NULL,NULL);
            break;       
        case 4305:  //if-else
            tn=newtemp();
            pl=tmp->left->right->right;
            pr=pl->right->right;
            Texp(pl,tn);    //条件表达式翻译
            ltrue=(char *)malloc(sizeof(char)*20);
            lfalse=(char *)malloc(sizeof(char)*20);
            lmid=(char *)malloc(sizeof(char)*20);
            nt=mklabel(ltrue);
            nm=mklabel(lmid);
            nf=mklabel(lfalse);
            sprintf(mbuf,"%slabel%d",mbuf,nt);
            newcode(mbuf,"011",NULL,NULL);
            sprintf(mbuf,"GOTO label%d",nm);
            newcode(mbuf,"011",NULL,NULL);
            newcode(ltrue,"011",NULL,NULL);
            Tstmt(pr);
            sprintf(mbuf,"GOTO label%d",nf);
            newcode(mbuf,"011",NULL,NULL);
            newcode(lmid,"011",NULL,NULL);
            Tstmt(pr->right->right);
            newcode(lfalse,"011",NULL,NULL);
            break;
        case 4306:  //while
            tn=newtemp();
            pl=tmp->left->right->right;
            pr=pl->right->right;
            Texp(pl,tn);
            ltrue=(char *)malloc(sizeof(char)*20);
            lfalse=(char *)malloc(sizeof(char)*20);
            lmid=(char *)malloc(sizeof(char)*20);
            nm=mklabel(lmid);
            nt=mklabel(ltrue);
            nf=mklabel(lfalse);
            newcode(lmid,"011",NULL,NULL);
            sprintf(mbuf,"%slabel%d",mbuf,nt);
            newcode(mbuf,"011",NULL,NULL);
            sprintf(mbuf,"GOTO label%d",nf);
            newcode(mbuf,"011",NULL,NULL);
            newcode(ltrue,"011",NULL,NULL);
            Tstmt(pr);
            sprintf(mbuf,"GOTO label%d",nm);
            newcode(mbuf,"011",NULL,NULL);
            newcode(lfalse,"011",NULL,NULL);
            break;
    }
}

void twoexp(AST *tmp,char *tvar,const char *op,int la)
{
    //la  逻辑运算或算数运算
    AST *pl,*pr;
    char *ts,*tt;
    pl=tmp->left;
    pr=pl->right->right;

    if(la==0){
        tt=newtemp();
        ts=newtemp();
        Texp(pr,tt);
        Texp(pl,ts);
        if(pl->number==6114){
            sprintf(mbuf,"*%s",ts);
            sprintf(ts,"%s",mbuf);
        }
        if(pr->number==6114){
            sprintf(mbuf,"*%s",tt);
            sprintf(tt,"%s",mbuf);
        }
        newcode(tvar,op,ts,tt);
    }
    else{   //条件表达式，多语句嵌套时有问题
        tt=newtemp();
        Texp(pr,tt);
        Texp(pl,tvar);
        sprintf(mbuf,"IF %s %s %s GOTO ",tvar,op,tt);
    }

}

void Texp(AST *tmp,char *tvar)
{
    //printf("%s\n",tvar);
    AST *pl,*pr;
    SYMBOL *p;
    char *ts,*tt;
    switch(tmp->number)        
    {
        case 6101:   //exp => exp = exp
            pl=tmp->left;
            pr=pl->right->right;
            if(pr->number==6114){
                //=newtemp();
                Texp(pr,tvar);//tt为地址;
                sprintf(tvar,"*%s",tvar);
            }
            else
                Texp(pr,tvar);
            if(!strcmp(tmp->left->left->name,"IDENTIFIER"))
            {
                p=findsym(tmp->left->left);
                sprintf(mbuf,"v%d",p->vname);   
                newcode(mbuf,"001",tvar,NULL);
            }
            else{
                tt=newtemp();
                Texp(pl,tt);  //计算地址
                sprintf(mbuf,"*%s",tt);
                newcode(mbuf,"001",tvar,NULL);
            }
            break;
        case 6102:   //exp => exp && exp
            twoexp(tmp,tvar,"&&",1);
            break;
        case 6103:   //exp => exp || exp
            twoexp(tmp,tvar,"||",1);
            break;
        case 6104:   //exp => exp RELOP exp
            twoexp(tmp,tvar,tmp->left->right->content,1);
            break;
        case 6105:   //exp => exp + exp
            twoexp(tmp,tvar,"+",0);
            break;
        case 6106:   //exp => exp - exp
            twoexp(tmp,tvar,"-",0);
            break;
        case 6107:   //exp => exp * exp
            twoexp(tmp,tvar,"*",0);
            break;
        case 6108:   //exp => exp / exp
            twoexp(tmp,tvar,"/",0);
            break;
        case 6109:   //exp => ( exp )
            pr=tmp->left->right;
            ts=newtemp();
            Texp(pr,ts);
            newcode(tvar,"001",ts,NULL);
            break; 
        case 6110:   //exp => - exp
            pl=tmp->left->right;
            tt=newtemp();
            Texp(pl,tt);
            newcode(tvar,"-","#0",tt);
            break;
        case 6111:   //exp => ! exp
            pl=tmp->left->right;
            tt=newtemp();
            Texp(pl,tt);
            newcode(tvar,"!","",tt);
            break;
        case 6112:   //exp => ID ( args )
            tt=newtemp();
            Targs(tmp->left->right->right,tt);
            newcode(tvar,"100","CALL",tmp->left->content);
            break;
        case 6113:   //exp => ID ( )
            newcode(tvar,"100","CALL",tmp->left->content);
            break;  
        case 6114:   //exp => exp [ exp ]
            Tarr(tmp,tvar);  //tvar为计算得到的地址
            break;
        case 6115:   //exp => exp . ID
            break;
        case 6116:   //exp => ID
            p=findsym(tmp->left);
            sprintf(mbuf,"v%d",p->vname);
            newcode(tvar,"001",mbuf,NULL);
            break;
        case 6117:   //exp => INT
            sprintf(mbuf,"#%d",tmp->left->valuei);
            newcode(tvar,"001",mbuf,NULL);
            break;
        case 6118:   //exp => FLOAT
            sprintf(mbuf,"#%lf",tmp->left->valuef);
            newcode(tvar,"001",mbuf,NULL);
            break;
        /**********************************/
    }
}

void Tarr(AST *tmp,char *tvar)
{
    int base,*a;
    int n=0;
    int i,j,offset;
    AST *pl,*pr;
    ARRAY *parr;
    SYMBOL *p;
    char *tl,*tr,buf[10];
    pl=tmp->left;
    while(pl->left){
        n++;
        pl=pl->left;
    }
    a=(int *)malloc(sizeof(int)*n);
    p=findsym(pl);

    sprintf(buf,"&v%d",p->vname);
    newcode(tvar,"001",buf,NULL);

    base=p->valuei;
    n=0;
    parr=p->type->parr;
    a[n++]=parr->size;
    while(parr->elem->kind==ARR){
        parr=parr->elem->parr;
        a[n++]=parr->size;
    }
    
    pl=tmp->left;

    pr=pl->right->right;
    tr=newtemp();
    Texp(pr,tr);
    tl=newtemp();
    sprintf(buf,"#%d",base);
    newcode(tl,"*",tr,buf);
    newcode(tvar,"+",tvar,tl);

    i=n-1;
    pl=pl->left;
    while(pl->left){
        pr=pl->right->right;
        tr=newtemp();
        Texp(pr,tr);
        tl=newtemp();
        offset=base;
        for(j=i;j<n;j++)
            offset *= a[j];
        sprintf(buf,"#%d",offset);
        newcode(tl,"*",tr,buf);
        newcode(tvar,"+",tvar,tl);
        i=i-1;
        pl=pl->left;
    }
}

void Targs(AST *tmp,char *tvar)
{
    char *tt;
    Texp(tmp->left,tvar);
    if(tmp->number==6201){
        tt=newtemp();
        Targs(tmp->left->right->right,tt);
    }
    sprintf(mbuf,"ARG %s",tvar);
    newcode(mbuf,"011",NULL,NULL);
}

