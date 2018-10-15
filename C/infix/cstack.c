#include "cstack.h"
void cinit(cstack *s) {
	s->i = 0;
}
void cpush(cstack *s, char no) {
	s->a[s->i++] = no;
}
char cpop(cstack *s) {
	char t;
	t = s->a[s->i - 1];
	s->i--;
	return t;
}
int cisempty(cstack *s) {
	return s->i == 0;
}
int cisfull(cstack *s) {
	return s->i == MAX;
}
