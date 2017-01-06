%{
#include<stdio.h>
#include"lex.yy.c"
#include"gtree.h"    
#include"midcode.h"
//void yyerror(const char *s);
%}
%error-verbose
%locations
%union{struct ast *a;double d;}
%token <a> INT FLOAT IDENTIFIER SEMI COMMA ASSIGNOP RELOP ADD SUB MUL DIV AND
%token <a> OR DOT NOT TYPE LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE

%type <a> program ext_def_list ext_def ext_dec_list specifier struct_specifier
%type <a> opt_tag tag var_dec var_list fun_dec param_dec comp_st stmt_list stmt
%type <a> def_list def dec_list dec exp args
%start program
/*left 为左结合，right右结合 
 *优先级与书写顺序有关，先写的优先级低，后写的优先级高。
 */
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left ADD SUB
%left MUL DIV
%right NOT
%left LP RP LB RB DOT
%nonassoc ELSE
%%
 /*high-level definitions*/
program
    :ext_def_list   
        {
            $$=newast("program",1,$1);
            $$->number=1101;
            if(!g_i){
                //printf("Type syntax tree:>\n");
                //DepthT($$,0);
                //printf("<Finish\n");
                eval_c($$);
                //eval($$,0);
                //print();
            }
        }
    ;

ext_def_list
    :ext_def ext_def_list   {$$=newast("ext_def_list",2,$1,$2);$$->number=1201;}
    |   {$$=newast("ext_def_list",0,-1);$$->number=1202;}
    ;

ext_def
    :specifier ext_dec_list SEMI    {$$=newast("ext_def",3,$1,$2,$3);$$->number=1301;}
    |specifier SEMI                 {$$=newast("ext_def",2,$1,$2);$$->number=1302;}
    |specifier error SEMI           {g_i=1;}
    |specifier fun_dec comp_st      {$$=newast("ext_def",3,$1,$2,$3);$$->number=1303;}
    ;

ext_dec_list
    :var_dec                        {$$=newast("ext_dec_list",1,$1);$$->number=1401;}
    |var_dec COMMA ext_dec_list     {$$=newast("ext_dec_list",3,$1,$2,$3);$$->number=1402;}
    ;

 /*specifiers*/
specifier
    :TYPE                           {$$=newast("specifier",1,$1);$$->number=2101;}
    |struct_specifier               {$$=newast("specifier",1,$1);$$->number=2102;}
    ;

struct_specifier
    :STRUCT opt_tag LC def_list RC  {$$=newast("struct_specifier",5,$1,$2,$3,$4,$5);$$->number=2201;}
    |STRUCT opt_tag LC def_list error RC    {g_i=1;}
    |STRUCT tag                     {$$=newast("struct_specifier",2,$1,$2);$$->number=2202;}
    ;

opt_tag
    :IDENTIFIER     {$$=newast("opt_tag",1,$1);$$->number=2301;}
    |               {$$=newast("opt_tag",0,-1);$$->number=2302;}
    ;

tag
    :IDENTIFIER     {$$=newast("tag",1,$1);$$->number=2401;}

 /*declarations*/
var_dec
    :IDENTIFIER         {$$=newast("var_dec",1,$1);$$->tag=VAR;/*普通变量*/$$->number=3101;}
    |var_dec LB INT RB  {$$=newast("var_dec",4,$1,$2,$3,$4);$$->tag=ARR;/*数组*/$$->number=3102;}
    ;

fun_dec
    :IDENTIFIER LP var_list RP  {$$=newast("fun_dec",4,$1,$2,$3,$4);$$->number=3201;}
    |IDENTIFIER LP RP           {$$=newast("fun_dec",3,$1,$2,$3);$$->number=3202;}
    ;

var_list
    :param_dec COMMA var_list   {$$=newast("var_list",3,$1,$2,$3);$$->number=3301;}
    |param_dec                  {$$=newast("var_list",1,$1);$$->number=3302;}
    ;

param_dec
    :specifier var_dec          {$$=newast("param_dec",2,$1,$2);pnum++;$$->number=3401;}
    ;

 /*statements*/
comp_st
    :LC def_list stmt_list RC   {$$=newast("comp_st",4,$1,$2,$3,$4);$$->number=4101;}
    |LC def_list stmt_list error RC {g_i=1;}
    ;

stmt_list
    :stmt stmt_list             {$$=newast("stmt_list",2,$1,$2);$$->number=4201;}
    |                           {$$=newast("stmt_list",0,-1);$$->number=4202;}
    ;

stmt
    :exp SEMI                   {$$=newast("stmt",2,$1,$2);$$->number=4301;}
    |exp error SEMI             {g_i=1;}
    |comp_st                    {$$=newast("stmt",1,$1);$$->number=4302;}
    |RETURN exp SEMI            {$$=newast("stmt",3,$1,$2,$3);$$->number=4303;}
    |RETURN exp error SEMI      {g_i=1;}
    |IF LP exp RP stmt          {$$=newast("stmt",5,$1,$2,$3,$4,$5);$$->number=4304;}
    |IF LP exp RP stmt ELSE stmt{$$=newast("stmt",7,$1,$2,$3,$4,$5,$6,$7);$$->number=4305;}
    |WHILE LP exp RP stmt       {$$=newast("stmt",5,$1,$2,$3,$4,$5);$$->number=4306;}
    ;

 /*local definitions*/
def_list
    :def def_list               {$$=newast("def_list",2,$1,$2);$$->number=5101;}
    |                           {$$=newast("def_list",0,-1);$$->number=5102;}
    ;

def
    :specifier dec_list SEMI    {$$=newast("def",3,$1,$2,$3);$$->number=5201;}
    |specifier dec_list error SEMI  {g_i=1;}
    ;

dec_list
    :dec                        {$$=newast("dec_list",1,$1);$$->number=5301;}
    |dec COMMA dec_list         {$$=newast("dec_list",3,$1,$2,$3);$$->number=5302;}
    ;

dec
    :var_dec                {$$=newast("dec",1,$1);$$->number=5401;}
    |var_dec ASSIGNOP exp   {$$=newast("dec",3,$1,$2,$3);$$->number=5402;}
    ;

 /*expressions*/
exp
    :exp ASSIGNOP exp       {$$=newast("exp",3,$1,$2,$3);$$->number=6101;}
    |exp AND exp            {$$=newast("exp",3,$1,$2,$3);$$->number=6102;}
    |exp OR exp             {$$=newast("exp",3,$1,$2,$3);$$->number=6103;}
    |exp RELOP exp          {$$=newast("exp",3,$1,$2,$3);$$->number=6104;}
    |exp ADD exp            {$$=newast("exp",3,$1,$2,$3);$$->number=6105;}
    |exp SUB exp            {$$=newast("exp",3,$1,$2,$3);$$->number=6106;}
    |exp MUL exp            {$$=newast("exp",3,$1,$2,$3);$$->number=6107;}
    |exp DIV exp            {$$=newast("exp",3,$1,$2,$3);$$->number=6108;}
    |LP exp RP              {$$=newast("exp",3,$1,$2,$3);$$->number=6109;}
    |SUB exp                {$$=newast("exp",2,$1,$2);   $$->number=6110;}
    |NOT exp                {$$=newast("exp",2,$1,$2);   $$->number=6111;}
    |IDENTIFIER LP args RP  {$$=newast("exp",4,$1,$2,$3,$4);$$->number=6112;}
    |IDENTIFIER LP RP       {$$=newast("exp",3,$1,$2,$3);$$->number=6113;}
    |exp LB exp RB          {$$=newast("exp",4,$1,$2,$3,$4);$$->number=6114;}
    |exp DOT IDENTIFIER     {$$=newast("exp",3,$1,$2,$3);$$->number=6115;}
    |IDENTIFIER             {$$=newast("exp",1,$1);      $$->number=6116;}
    |INT                    {$$=newast("exp",1,$1);      $$->number=6117;}
    |FLOAT                  {$$=newast("exp",1,$1);      $$->number=6118;}
    ;

args
    :exp COMMA args         {$$=newast("args",3,$1,$2,$3);$$->number=6201;}
    |exp                    {$$=newast("args",1,$1);$$->number=6202;}
    ;

%%

