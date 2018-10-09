#include "stack.h"
void init(stack *s) {
	s->i = 0;
}
void push(stack *s, int no) {
	s->a[s->i++] = no;
}
int pop(stack *s) {
	int t;
	t = s->a[s->i - 1];
	s->i--;
	return t;
}
int isempty(stack *s) {
	return s->i == 0;
}
int isfull(stack *s) {
	return s->i == MAX;
}
