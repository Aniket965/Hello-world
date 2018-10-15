#define MAX 16
typedef struct stack{
	int a[MAX];
	int i;;
}stack;
/* User to call init before calling other functions.
 * User to check isempty() before calling pop()
 * User to check isfull() before calling push()
 */
void init(stack *s);
void push(stack *s, int no);
int pop(stack *s);
int isempty(stack *s);
int isfull(stack *s);

