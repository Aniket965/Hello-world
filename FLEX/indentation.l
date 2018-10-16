%{
int k = 0;
int b = 1;
int len = 0;
%}

%%

[ ]* {
	if(b == 1)
	{
		len = strlen(yytext);
		if(len > k)
		{
			k = len;
		    b = 0;
		}
	}
}

\n {
	b = 1;
}

. {}

%%

int main()
{
	yyin = fopen("text.c", "r");
	yylex();
	printf("Maximum Indentation = %d\n", k);
	return 0;
}