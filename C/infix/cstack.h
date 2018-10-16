#define MAX 16
typedef struct cstack{
	char a[MAX];
	int i;
}cstack;
/* User to call init before calling other functions.
 * User to check isempty() before calling pop()
 * User to check isfull() before calling push()
 */
void cinit(cstack *s);
void cpush(cstack *s, char no);
char cpop(cstack *s);
int cisempty(cstack *s);
int cisfull(cstack *s);
