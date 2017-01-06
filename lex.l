%{
#include"syn.tab.h"
#include"gtree.h"
int g_i=0;
//extern void yyerror(const char *);
int yycolumn = 1;
#define YY_USER_ACTION  \
    yylloc.first_line = yylloc.last_line = yylineno -1;  \
    yylloc.first_column = yycolumn;  \
    yylloc.last_column = yycolumn + yyleng -1; \
    yycolumn += yyleng;
%}
%x COMMENT
%option yylineno
O   [0-7]
D   [0-9]
H   [a-fA-F0-9]
NZ  [1-9]
L   [_a-zA-Z]
A   [_a-zA-Z0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
Fs  (f|F|l|L)
Is  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\b\f]
Num {D}+
ID {L}({D}|{L}){0,32}
blank [;\t\n\x0B\f\r\x20]+
%%

"/*"    {comment();}
"//".*  {/*comment();*/}
";"     {yylval.a=newast("SEMI",0,yylineno);return (SEMI);}
","     {yylval.a=newast("COMMA",0,yylineno);return (COMMA);}
"="     {yylval.a=newast("ASSIGNOP",0,yylineno);return (ASSIGNOP);}

(">"|"<"|">="|"<="|"=="|"!=")  {yylval.a=newast("RELOP",0,yylineno);return (RELOP);}
"+"     {yylval.a=newast("ADD",0,yylineno);return (ADD);}
"-"     {yylval.a=newast("SUB",0,yylineno);return (SUB);}
"*"     {yylval.a=newast("MUL",0,yylineno);return (MUL);}
"/"     {yylval.a=newast("DIV",0,yylineno);return (DIV);}
"&&"    {yylval.a=newast("AND",0,yylineno);return (AND);}
"||"    {yylval.a=newast("OR",0,yylineno);return (OR);}
"."     {yylval.a=newast("DOT",0,yylineno);return (DOT);}
"!"     {yylval.a=newast("NOT",0,yylineno);return (NOT);}
("int"|"float")   {yylval.a=newast("TYPE",0,yylineno);return (TYPE);} 
"("     {yylval.a=newast("LP",0,yylineno);return (LP);}
")"     {yylval.a=newast("RP",0,yylineno);return (RP);}
"["     {yylval.a=newast("LB",0,yylineno);return (LB);}
"]"     {yylval.a=newast("RB",0,yylineno);return (RB);}
"{"     {yylval.a=newast("LC",0,yylineno);return (LC);}
"}"     {yylval.a=newast("RC",0,yylineno);return (RC);}
"struct" {yylval.a=newast("STRUCT",0,yylineno);return (STRUCT);}
"return" {yylval.a=newast("RETURN",0,yylineno);return (RETURN);}
"if"     {yylval.a=newast("IF",0,yylineno);return (IF);}
"else"   {yylval.a=newast("ELSE",0,yylineno);return (ELSE);}
"while"  {yylval.a=newast("WHILE",0,yylineno);return (WHILE);}

{L}{A}*  {yylval.a=newast("IDENTIFIER",0,yylineno);return (IDENTIFIER);}

{HP}{H}+{Is}?   {yylval.a=newast("INT",0,yylineno);return INT;}
{NZ}{D}*{Is}?   {yylval.a=newast("INT",0,yylineno);return INT;}
"0"{O}*{Is}?    {yylval.a=newast("INT",0,yylineno);return INT;}
{CP}?"'"([^'\\\n]|{ES})+"'" {yylval.a=newast("INT",0,yylineno);return INT;}

{D}+{E}{Fs}?            {yylval.a=newast("FLOAT",0,yylineno);return FLOAT;}
{D}*"."{D}+{E}?{Fs}?    {yylval.a=newast("FLOAT",0,yylineno);return FLOAT;}
{D}+"."{E}?{Fs}?        {yylval.a=newast("FLOAT",0,yylineno);return FLOAT;}
{HP}{H}+{P}{Fs}?        {yylval.a=newast("FLOAT",0,yylineno);return FLOAT;}
{HP}{H}*"."{H}+{P}{Fs}? {yylval.a=newast("FLOAT",0,yylineno);return FLOAT;}
{HP}{H}+"."{P}{Fs}?     {yylval.a=newast("FLOAT",0,yylineno);return FLOAT;}

{WS}+ {/*whitespace separates tokens*/}
\n    {yycolumn = 1;}
. {yyerror("%s \"%s\"","Mysterious character",yytext);g_i=1;}
%%
int yywrap(void){return 1;}
/*int main(int argc,char *argv[])
{
    FILE * f;
    if(argc>1){
        if(!(f=fopen(argv[1],"r"))){
            perror(argv[1]);
            return 1;
        }
    }
    yylex();
    return 0;
}*/
void comment()
{
    int c;
    while((c=input())!=-1)
    {
        if(c=='*')
        {
            while((c=input())=='*')
                ;
            if(c=='/')
                return ;
        }
    }
    yyerror("%s","Unterminated comment");
}
