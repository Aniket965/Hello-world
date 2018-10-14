/* This program removes special characters from a file. It takes "spchar.txt" as input and stores the output in "wspchar.txt". */
%{
  #include<stdio.h>
  FILE *sp,*wsp;
%}

%%
[a-zA-Z ] {fprintf(wsp,"%s",yytext);}
. {fprintf(wsp,"");}
%%

int main()
{
  sp=fopen("spchar.txt","r");
  wsp=fopen("wspchar.txt","w+");
  yyin=sp;
  yyout=wsp;
  yylex();
  return 0;
}
