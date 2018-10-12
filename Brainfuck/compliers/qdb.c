/*  qdb.c -- quick and dirty brainfuck interpreter.
    Version 1.0, 12/19/04
    Daniel B Cristofani
    email cristofdathevanetdotcom
    http://www.hevanet.com/cristofd/brainfuck/  */

/*Make any use you like of this software. I can't stop you anyway. :)*/

/*  This interpreter uses byte cells, wraps around on overflow or
    underflow, has unpredictable misbehavior if the pointer is moved
    outside the array, and interprets '#' as a command to output the
    first sixteen cells of the array, plus a '^' for the pointer. It
    should be fairly fast, but no match for a decent compiler or even
    for a really clever interpreter.  */

#include <stdio.h>

#define S 65536

int t[S];
char a[S], p[S], bf[256];
int b, c, d, g, h, i, j, k, m, n, x;
FILE *prog;

int main(int argc, char **argv){
  if (!(prog=fopen(argv[1], "r"))){
    fprintf(stderr, "can't open the file \"%s\".\n", argv[1]);
    exit(1);
  }
  g=fread(p, 1, S, prog);
  fclose(prog);
  bf['<']=bf['>']=bf['+']=bf['-']=bf[',']=bf['.']=bf['[']=bf[']']=bf['#']=1;
  m=S;
  while (i<g){
    c=1;
    while((d=p[i++])==b && ++c || i<=g && !bf[d]);
    switch (b){
      case '+': if (c<=4) p[j++]='a'-1+c; else p[j]='+', t[j++]=c; break;
      case '-': if (c<=4) p[j++]='d'+c; else p[j]='-', t[j++]=c; break;
      case '>': if (c<=4) p[j++]='h'+c; else p[j]='>', t[j++]=c; break;
      case '<': if (c<=4) p[j++]='l'+c; else p[j]='<', t[j++]=c; break;
      case ',': while (c--) p[j++]=','; break;
      case '.': while (c--) p[j++]='.'; break;
      case '[': while (c--) t[--m]=j; p[j++]='['; break;
      case ']': if (m+c>S)fprintf(stderr, "unbalanced ].\n"), exit(1);
            t[j]=t[m]+1; while (c--) t[t[m++]]=j+1; p[j++]=']';break;
      case '#': while (c--) p[j++]='#'; break;
    }
    b=d;
  }   
  p[j]=0;
  if (m!=S) fprintf(stderr, "unbalanced [.\n"), exit(1);
  j=0;
  while(1){
    switch (p[j]){
      case '+': a[x]+=t[j++]; break;
      case '-': a[x]-=t[j++]; break;
      case '>': x+=t[j++]; break;
      case '<': x-=t[j++]; break;
      case '[': if (!a[x]) j=t[j]; else j++; break;
      case ']': if (a[x]) j=t[j]; else j++; break;
#if '\n' == 10
      case ',': if ((c=getchar())!=EOF) a[x]=c; j++; break;
      case '.': putchar(a[x]); j++; break;
#else
      case ',': if ((c=getchar())!=EOF)a[x]=c=='\n'?10:c; j++; break;
      case '.': putchar(a[x]==10?'\n':a[x]); j++; break;
#endif
      case 'a': a[x]++; j++; break;
      case 'b': a[x]+=2; j++; break;
      case 'c': a[x]+=3; j++; break;
      case 'd': a[x]+=4; j++; break;
      case 'e': a[x]--; j++; break;
      case 'f': a[x]-=2; j++; break;
      case 'g': a[x]-=3; j++; break;
      case 'h': a[x]-=4; j++; break;
      case 'i': x++; j++; break;
      case 'j': x+=2; j++; break;
      case 'k': x+=3; j++; break;
      case 'l': x+=4; j++; break;
      case 'm': x--; j++; break;
      case 'n': x-=2; j++; break;
      case 'o': x-=3; j++; break;
      case 'p': x-=4; j++; break;
      case '#': printf("\n%3d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n"
             "%*s\n",*a,a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],
             a[9],a[10],a[11],a[12],a[13],a[14],a[15],x*4+3,"^"); j++; break;
      case 0: exit(0); break;
    }
  }
}
