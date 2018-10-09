/* This program removes vowels from a file. It takes "vowels.txt" as input and stores the output in "wvowels.txt". */
%{
  #include<stdio.h>
  FILE *vow,*wvow;
%}
vowels a|e|i|o|u|A|E|I|O|U
%%
{vowels} {fprintf(wvow,"");}
. {fprintf(wvow,"%s",yytext);}
%%
int yywrap(){}
int main()
{
  vow=fopen("vowels.txt","r");
  yyin=vow;
  wvow=fopen("wvowels.txt","w+");
  yyout=wvow;
  yylex();
  return 0;
}
