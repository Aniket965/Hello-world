/* This program counts the maximum level of indentation in a file */
%{
  #include<stdio.h>
  int glob=0,cur=0;
%}

%%
"\t" {
  cur++;
}
"\n" {
  if(cur>glob)
  {
    glob=cur;
  }
  cur=0;
}
%%

int main()
{
  FILE *fp;
  fp=fopen("indent.txt","r");
  yyin=fp;
  yylex();
  printf("Maximum indentation is = %d\n",glob);
  return 0;
}
