/* This program identifies identifiers. */
%{
  #include<stdio.h>
%}
letters [a-zA-Z]
digits [0-9]
identifiers {letters}({letters}*{digits}*)*
nonidentifiers ({digits}{letters}*)
%%
{identifiers} {printf("%s is an identifier\n",yytext);}
{nonidentifiers} {printf("%s is not an identifier\n",yytext);}
%%
int main()
{
  yylex();
  return 0;
}
