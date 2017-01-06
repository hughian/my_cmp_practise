/*******************************************
func

1:(类型，标示符)  返回表头指针，然后个数加1
形参数目+1，记录形参表

2：(返回类型，函数名)
新增函数返回类型
return 语句

3：匹配函数的返回类型



newsym：(函数名，参数表？？？)
//没有参数表时？NULL？？？

新增符号表项，将参数表挂到addition下
*******************************************/
void eval(AST *a,int level)
{
    AST *pl,*pr,*tmp;
    SYMBOL *psym;
    if(a!=0 )
    {
        if(!strcmp(a->name,"ext_def")){
            pl=a->left->left;
            pr=a->left->right;
            if(!strcmp(pr->name,"ext_dec_list")){//全局变量定义   
                if(!strcmp(pl->name,"TYPE")){ //基本类型
                    while(pr){ //处理ext_dec_list下的var_dec
                        if(pr->left->tag==ARR){//var_dec定义的是数组
                            tmp=pr->left;//tmp为当前var_dec
                            while(tmp->left){
                                tmp=tmp->left;
                            }
                            if(!(psym=findsym(tmp)))
                                newsym(DEF,ARR,2,tmp,pl,pr->left);//需要遍历这整个var_dec分支建立类型
                            else if(psym->type->kind==ARR)
                                printf("[line %d]Error302:Redefined array '%s',first defined at line %d",tmp->line,psym->name,psym->line);
                            else
                                printf("[line %d]Error303:Duplicated name '%s',first used at line %d",tmp->line,psym->name,psym->line);
                        }
                        else{   //var_dec定义的是普通变量
                            if((psym=findsym(pr->left->left)))
                                printf("[line %d]Error301:Redefine variable '%s',first defined at line %d",pr->left->left->line,psym->name,psym->line);
                            else
                                newsym(DEF,VAR,2,pl,pr->left->left);
                        }
                        if(pr->left->right==0)
                            pr=0;
                        else if(!strcmp(pr->left->right->name,"COMMA"))
                            pr=pr->left->right->right;
                        else
                            pr=0;
                    }
                }
                else{ //pl表示struct_specifier结点
                    pl=pl->left;//pl递归到STRUCT结点
                    if(!strcmp(pl->right->name,"opt_tag")){ //结构类型定义+定义变量
                        /*判断结构类型定义是否重名*/
                        if(!(psym=findsym(pl->right->left))){
                            newsym(DEF,STR,2,pl->right,pl->right->right->right);//需要遍历构建结构成员列表
                            /*结构类型变量定义*/
                            while(pr){ //处理ext_dec_list下的var_dec
                                if(pr->left->tag==ARR){
                                    tmp=pr->left;//tmp置为当前var_dec
                                    while(tmp->left){   tmp=tmp->left;  }
                                    if(!(psym=findsym(tmp)))
                                        newsym(DEF,ARR,2,tmp,pl->right->left,pr->left);//tmp为数组名，pl->right->left为结构名即类型，pr->left是需要遍历的数组维度表
                                    else if(psym->type->kind==ARR)
                                        printf("[line %d]Error302:Redefined array '%s',first defined at line %d",tmp->line,psym->name,psym->line);
                                    else
                                        printf("[line %d]Error303:Duplicated name '%s',first used at line %d",tmp->line,psym->name,psym->line);
                                }
                                else{ //var_dec定义的是普通变量
                                    if(!(psym=findsym(pr->left->left)))
                                        newsym(DEF,VAR,2,pl->right->left,pr->left->left);
                                    else if(psym->type->kind==VAR)
                                        printf("[line %d]Error301:Redefined variable '%s',first defined at line %d",pr->left->left->line,psym->name,psym->line);
                                    else
                                        printf("[line %d]Error303:Duplicated name '%s',first used at line %d",pr->left->left->line,psym->name,psym->line);
                                }
                                if(pr->left->right==0)
                                    pr=0;
                                else if(!strcmp(pr->left->right->name,"COMMA"))
                                    pr=pr->left->right->right;
                                else
                                    pr=0;
                            }
                        }
                        else if(psym->type->kind==STR)   
                            printf("[line %d]Error304:Redefined structure '%s',first defined at line %d",pl->right->left->line,psym->name,psym->line);
                        else
                            printf("[line %d]Error303:Duplicated name '%s',first used at line %d",pl->right->left->line,psym->name,psym->line);
                    }
                    else //结构类型引用+定义变量
                        ;
                }
            }
            else if(!strcmp(pr->name,"SEMI")){ //结构类型声明
                newsym(DEF,FUN,2,pl,pr->left);
            }
            else{ //pr表示fun_dec结点，为函数定义
                ; 
            }
        }
        eval(a->left,level+1);
        eval(a->right,level);

    }
}