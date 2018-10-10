/* Problem
 * Solve postfix expression. E.g. 
 * 11 22 33 44 + -* 3 4+ -
 * The user input will have integer operands and operators + - * / % 
 * The operands and operators may be separated by zero or more spaces
 * The operators may be separated by zero or more spaces
 * The operands are separted from each other by 1 or more spaces.
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OPERAND 1
#define OPERATOR 2
#define END 3
#define ERROR 4
typedef struct token {
	int type;  // OPERAND or OPERATOR or END
	int val; // if type == OPERAND
	char op; // if type == OPERATOR
}token;
enum states { NUM, OPR, SPC, FINISH, ERR};
token gettoken(char *expr, int *reset) {
	token t;
	int no;
	static int i = 0;
	static enum states currstate = SPC;
	char currchar;
	if(*reset == 1) {
		*reset = 0;
		i = 0;
		currstate = SPC;
	}
	while(1) {
		currchar = expr[i];
		// depending on currstate, and currchar, change state, and take action.
		switch(currstate) {
			case NUM:
				switch(currchar) {
					case '0': case '1': case '2': case '3':
					case '4': case '5': case '6': case '7':
					case '8': case '9':
						no = no * 10 + currchar - '0';
						currstate = NUM;
						i++;
						break;
					case '+': case '-': case '*': case '/': case '%':
						t.type = OPERAND;
						t.val = no;
						currstate = OPR;
						i++;
						return t;	
						break;
					case ' ':
						t.type = OPERAND;
						t.val = no;
						currstate = SPC;
						i++;
						return t;
						break;
					case '\0':
						t.type = OPERAND;
						t.val = no;
						currstate = FINISH;
						i++;
						return t;
						break;
					default:
						t.type = OPERAND;
						t.val = no;
						currstate = ERR;
						i++;
						return t;
						break;
				}
				break;
			case OPR:
				t.type = OPERATOR;
				t.op = expr[i - 1]; 
				i++;
				switch(currchar) {
					case '0': case '1': case '2': case '3':
					case '4': case '5': case '6': case '7':
					case '8': case '9':
						currstate = NUM;
						break;
					case '+': case '-': case '*': case '/': case '%':
						currstate = OPR;
						break;
					case ' ':
						currstate = SPC;
						break;
					case '\0':
						currstate = FINISH;
						break;
					default:
						currstate = ERR;
						break;
				}
				return t;
				break;
			case SPC:
				switch(currchar) {
					case '0': case '1': case '2': case '3':
					case '4': case '5': case '6': case '7':
					case '8': case '9':
						no = currchar - '0';
						currstate = NUM;
						break;
					case '+': case '-': case '*': case '/': case '%':
						currstate = OPR;
						break;
					case ' ':
						currstate = SPC;
						break;
					case '\0':
						currstate = FINISH;
						break;
					default:
						currstate = ERR;
						break;
				}
				i++;
				break;
			case FINISH:
				t.type = END;
				return t;
				break;
			case ERR:
				t.type = ERROR;
				return t;
				break;
		}
	}
	return t;
}
int postfix(char *expr) {
	token t;
	int a[16];
	int i = 0, x, y, z, reset = 1;
	while(1) {
		t = gettoken(expr, &reset);
		if(t.type == OPERAND) {
			a[i++] = t.val;
		} else if(t.type == OPERATOR) {
			x = a[i - 1];
			y = a[i - 2];
			switch(t.op) {
				case '+':
					z = y + x;
					break;
				case '-':
					z = y - x;
					break;
				case '*':
					z = y * x;
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
			a[i - 2]= z;
			i--;
		} else if(t.type == END) {
			return a[0];
		} else if(t.type == ERROR) {
			return INT_MIN;
		}
	}
}
int readline(char *line, int len) {
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n' && i < len - 1) 
		line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main() {
	char line[128];	
	int r;
	while(readline(line, 128)) {
		r = postfix(line);
		if(r != INT_MIN)
			printf("%d\n", r);
		else 
			fprintf(stderr, "Wrong Expression\n");
	}
	return 0;
}
