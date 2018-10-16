#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "cstack.h"
#include "stack.h"

#define OPERAND	100
#define OPERATOR 200
#define END	300
#define ERR 400

typedef struct token {
	int type; // OPERAND, OPERATOR or END
	int val; // will be used if type==OPERAND
	char op; // will e used if type == OPERATOR
}token;
enum state { NUMBER, OP, FINISH, ERROR, SPC };
token gettoken(char *expr, int *reset) {
	static int i = 0;
unsigned int no;
	char currchar;
	static enum state currstate = SPC;
	enum state nextstate;
	token t;
	if(*reset == 1) {
		currstate = SPC;
		*reset = 0;
		i = 0;
	}
	while(1) {
		currchar = expr[i];
		//printf("currstate: %s currchar: %c\n", states[currstate], currchar);
		switch(currstate) {
			case NUMBER:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						nextstate = NUMBER;
						no = no * 10 + (currchar - '0');
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%':
						nextstate = OP;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						i++;
						return t;
						break;
					default: // anything else
						nextstate = ERROR;
						t.type = OPERAND;
						t.val = no;
						currstate = nextstate;
						return t;
						break;
				}
				break;
			case OP:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						no = currchar - '0';
						t.type = OPERATOR;
						t.op = expr[i - 1];
						nextstate = NUMBER;
						currstate = nextstate;
						i++;
						return t;
						break;
					case '+': case '-': case '*': case '/': case '%':
						nextstate = OP;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					case '\0':
						nextstate = FINISH;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
						break;
					case ' ':
						nextstate = SPC;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						i++;
						return t;
						break;
					default: // anything else
						nextstate = ERROR;
						t.type = OPERATOR;
						t.op = expr[i - 1];
						currstate = nextstate;
						return t;
					 	break;
				}
				break;
			case FINISH:
				t.type = END;
				return t;
				break;
			case ERROR:
				t.type = ERR;
				return t;
				break;
			case SPC:
				switch(currchar) {
					case '0':case '1':case '2': case '3':
					case '4':case '5':case '6': case '7':
					case '8':case '9':
						no = currchar - '0';
						nextstate = NUMBER;
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%':
						nextstate = OP;
						i++;
						break;
					case '\0':
						nextstate = FINISH;
						break;
					case ' ':
						nextstate = SPC;
						i++;
						break;
					default: // anything else
						nextstate = ERROR;
						break;
				}
				currstate = nextstate;
				break;
		}
	}
}
// 12 123  214 + -\0
int postfix(char *expr) {
	token t;
	int x, y, z, reset = 1;
	stack s;
	init(&s);
	while(1) {
		t = gettoken(expr, &reset);
		if(t.type == OPERAND) 
			if(!isfull(&s))
				push(&s, t.val);
			else {
				fprintf(stderr, "Expression too big\n");
				return INT_MIN;
			}
		else if(t.type == OPERATOR)  {
			if(!isempty(&s))
				x = pop(&s);
			else {
				fprintf(stderr, "Less operands\n");
				return INT_MIN;
			}
			if(!isempty(&s))
				y = pop(&s);
			else {
				fprintf(stderr, "Less operands\n");
				return INT_MIN;
			}
			switch(t.op) {
				case '+':
					z = y + x;
					break;
				case '*':
					z = y * x;
					break;
				case '-':
					z = y - x;
					break;
				case '/':
					z = y / x;
					break;
				case '%':
					z = y % x;
					break;
				default:
					return INT_MIN;		
			}
			if(!isfull(&s))
				push(&s, z);
			else {
				fprintf(stderr, "Expression too big\n");
				return INT_MIN;
			}
		} else if(t.type == END) {
			if(!isempty(&s))
				y = pop(&s);
			else {
				fprintf(stderr, "Less operands\n");
				return INT_MIN;
			}
			if(!isempty(&s)) {
				fprintf(stderr, "Less operators\n");
				return INT_MIN;
			} else
				return y;
		} else if(t.type == ERR) {
			fprintf(stderr, "Error in expression\n");
			return INT_MIN;
		}
	}
}
int readline(char *line, int len) {
	int i;
	char ch;
	i = 0;
	while(i < len - 1) {
		ch = getchar();
		if(ch == '\n') {
			line[i++] = '\0';
			return i - 1;
		}
		else
			line[i++] = ch;
	}
	line[len - 1] = '\0';
	return len - 1;
}
char ctop(cstack *cs) {
	char ch;
	ch = cpop(cs);
	cpush(cs, ch);
	return ch;
}
int precedence(char op) {
	switch(op) {
		case '+': case '-':
			return 1;
			break;	
		case '*': case '/':
			return 2;
			break;	
		case '%': 
			return 3;
			break;	
		default:
			return 4;
			break;
	}
	return 4;
}
char *infixtopostfix(char *infix) {
	token t;
	cstack cs;
	int reset = 1;
	char *postfix = malloc(strlen(infix) + 1), prevop, currop;
	char str[16];
	if(!postfix)
		return NULL;
	strcpy(postfix, "");	
	cinit(&cs);
	while(1) {
		t = gettoken(infix, &reset);
		if(t.type == OPERAND) {
			sprintf(str, "%d", t.val);
			strcat(postfix, str);
			strcat(postfix, " ");
		} else if(t.type == OPERATOR) {
			if(!cisempty(&cs)) {
				currop = t.op;
				prevop = ctop(&cs);
				while (precedence(prevop) >= precedence(currop)) {
					prevop = cpop(&cs);
					str[0] = prevop;
					str[1] = '\0';
					strcat(postfix, str);
					if(!cisempty(&cs))
						prevop = ctop(&cs);
					else
						break;
				}
			}
			if(!cisfull(&cs))
				cpush(&cs, t.op);
			else {
				free(postfix);
				return NULL;
			}
		} else if(t.type == END) {
			while (!cisempty(&cs)) { 
				prevop = cpop(&cs);
				str[0] = prevop;
				str[1] = '\0';
				strcat(postfix, str);
			}
			break;
		} else if(t.type == ERR) {
			free(postfix);
			return NULL;	
		}
	}
	return postfix;
}
int main(int argc, char *argv[]) {
	char line[32];
	int r;
	char *p;
	while(readline(line, 32)) {
		p = infixtopostfix(line);
		if(!p) {
			fprintf(stderr, "Bad infix expression or malloc failed\n");
			continue;
		}
		printf("postfix: %s\n", p);
		r = postfix(p);
		free(p);
		if(r != INT_MIN)
			printf("%d\n", r); 
		else
			fprintf(stderr, "Error in postfix expr\n");
	}
	return 0;
}
