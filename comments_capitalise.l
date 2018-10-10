/* This flex program capitalises the comments. Input file is "comments.txt" and output file is "capcom.txt". */
%{
  #include<stdio.h>
%}

%%
"/*"([a-zA-Z0-9 ]*[\n]*)*"*/" {
  int l=yyleng;
  int i=0;
  fprintf(yyout,"%c",yytext[0]);
  for(i=1;i<l;i++)
  {
    if(yytext[i-1]==32  || yytext[i-1]==9 || yytext[i-1]==10)
    {
        fprintf(yyout,"%c",toupper(yytext[i]));
    }
    else
      fprintf(yyout,"%c",yytext[i]);
  }
}

"//".* {
  int l=yyleng;
  int i=0;
  fprintf(yyout,"%c",yytext[0]);
  for(i=1;i<l;i++)
  {
    if(yytext[i-1]==32  || yytext[i-1]==9 || yytext[i-1]==10)
    {
        fprintf(yyout,"%c",toupper(yytext[i]));
    }
    else
      fprintf(yyout,"%c",yytext[i]);
  }
}
. {fprintf(yyout,"%s",yytext);}
%%
int main()
{
  yyin=fopen("comments.txt","r");
  yyout=fopen("capcom.txt","w+");
  yylex();
  return 0;
}
