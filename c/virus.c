#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
	int i;
	int ID;
	ID = (1207274233 % 3) + 2;
	for(i = 1; i <= ID; i++){
		char buffer[12];
		srand(time(NULL)*i);
		sprintf(buffer,"%d",rand()%1000);
		strcat(buffer,".c");
  		FILE* fp;
  		fp = fopen(buffer,"w");
  		char *s1="#include <stdio.h>%c#include <stdlib.h>%c#include <time.h>%c#include <string.h>%c%cint main() {%c%cint i;%c%cint ID;%c%cID = (1207274233 % 3) + 2;%c%cfor(i = 1; i <= ID; i++){%c%c%cchar buffer[12];%c%c%csrand(time(NULL)*i);%c%c%csprintf(buffer,%c%cd%c,rand()%1000);%c%c%cstrcat(buffer,%c.c%c);%c%c%cFILE* fp;%c%c%cfp = fopen(buffer,%cw%c);%c";
  		char *s2="%c%cchar *s%c=%c%s%c;%c%c%cchar *s%c=%c%s%c;%c";
  		char *s3="%c%cchar n='%cn', q='%c', b='%c%c', t='%ct', s='%';%c";
  		char *sp="fprintf(fp,";
  		char *s4="%c%c%ss1,n,n,n,n,n,n,t,n,t,n,t,n,t,n,t,t,n,t,t,n,t,t,q,s,q,n,t,t,q,q,n,t,t,n,t,t,q,q,n);%c";
  		char *s5="%c%c%ss2,t,t,'1',q,s1,q,n,t,t,'2',q,s2,q,n);  %ss2,t,t,'3',q,s3,q,n,t,t,'p',q,sp,q,n);%c";
  		char *s6="%c%c%ss2,t,t,'4',q,s4,q,n,t,t,'5',q,s5,q,n);  %ss2,t,t,'6',q,s6,q,n,t,t,'7',q,s7,q,n);%c";
  		char *s7="%c%c%ss2,t,t,'8',q,s8,q,n,t,t,'9',q,s9,q,n);  %ss2,t,t,'0',q,s0,q,n,t,t,'x',q,sx,q,n);%c";
  		char *s8="%c%c%ss3,t,t,b,q,b,b,b,n);  %ss4,t,t,sp,n);  %ss5,t,t,sp,sp,n);%c";
  		char *s9="%c%c%ss6,t,t,sp,sp,n);  %ss7,t,t,sp,sp,n);  %ss8,t,t,sp,sp,sp,n);%c";
  		char *s0="%c%c%ss9,t,t,sp,sp,sp,n);  %ss0,t,t,sp,sp,n,t,t,n,t,n);%c%c%cfclose(fp);%c%c}%c}";
  		char *sx="--- I am the creeper, catch me if you can. ---";
  		char n='\n', q='"', b='\\', t='\t', s='%';
  		fprintf(fp,s1,n,n,n,n,n,n,t,n,t,n,t,n,t,n,t,t,n,t,t,n,t,t,q,s,q,n,t,t,q,q,n,t,t,n,t,t,q,q,n);
  		fprintf(fp,s2,t,t,'1',q,s1,q,n,t,t,'2',q,s2,q,n);  fprintf(fp,s2,t,t,'3',q,s3,q,n,t,t,'p',q,sp,q,n);
  		fprintf(fp,s2,t,t,'4',q,s4,q,n,t,t,'5',q,s5,q,n);  fprintf(fp,s2,t,t,'6',q,s6,q,n,t,t,'7',q,s7,q,n);
  		fprintf(fp,s2,t,t,'8',q,s8,q,n,t,t,'9',q,s9,q,n);  fprintf(fp,s2,t,t,'0',q,s0,q,n,t,t,'x',q,sx,q,n);
  		fprintf(fp,s3,t,t,b,q,b,b,b,n);  fprintf(fp,s4,t,t,sp,n);  fprintf(fp,s5,t,t,sp,sp,n);
  		fprintf(fp,s6,t,t,sp,sp,n);  fprintf(fp,s7,t,t,sp,sp,n);  fprintf(fp,s8,t,t,sp,sp,sp,n);
  		fprintf(fp,s9,t,t,sp,sp,sp,n);  fprintf(fp,s0,t,t,sp,sp,n,t,t,n,t,n);
  		fclose(fp);
	}
}
