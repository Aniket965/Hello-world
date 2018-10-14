#include <stdio.h>

union test
{
int x,y;


};
int main()
{
union test t;
t.x =2;


printf("%d %d\n",t.x,t.y);
t.y=10;
printf("%d, %d\n",t.x,t.y);


return 0;
}
