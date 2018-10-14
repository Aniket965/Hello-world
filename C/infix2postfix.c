#define max_size 100
#include<stdio.h>
#include<stdlib.h>
struct stack{
	char arr[max_size];
	int top;
}; 
typedef struct stack STACK;
STACK s;
void push(char c){
	s.arr[++s.top] = c; 
}
char pop(){
	return s.arr[s.top--];
} 
int precedense(char c){
	return (c=='^')?3:(c=='*'||c=='/')?2:(c!='(')?1:-1;
}
int main(){
	int i, last_precedense;
	char str[max_size];
	char c, popped, choice;
	s.top = -1;
	
	printf("Use Capital Letter's as Operand\n");
	printf("'+','-','*','/','^' as Operators\n");
	printf("a. Fully Parenthesised Infix Expression\n");
	printf("b. Expression to be evaluated as per \nPresedence and Associativity\n");
	printf("Enter choice : ");
	scanf("%c", &choice);
	printf("Enter Infix Expression : ");
	scanf("%s",str);
	printf("Postfix Expression : ");
	if (choice == 'a'){
		for(i=0; str[i]!='\0'; i++){
			char c = str[i];
			if(c>=65&&c<=90)
				printf("%c",c);
			else if (c=='('||c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
				push(c);
			else if (c==')'){
				for(popped=pop(); popped!='('; popped=pop())
					printf("%c",popped);
			}
		}
	}
	else{
		for(i=0;str[i]!='\0';i++){
			c = str[i];
			if(c>=65&&c<=90)
				printf("%c",c);
			else{
				if(s.top==-1){
					push(c);
					last_precedense = precedense(c);
				}
				else if (c=='('){
					push(c);
					last_precedense = precedense(c);
				}
				else if (c==')'){
					for(popped=pop(); popped!='('; popped=pop())
						printf("%c",popped);
					if(s.top!=-1)
						last_precedense = precedense(s.arr[s.top]);
				}
				else{
					if(c=='^'){
						push(c);
						last_precedense = 3;
					}
					else if(c=='*'||c=='/'){
						if(last_precedense<2){
							push(c);
							last_precedense = 2;
						}
						else{
							while(last_precedense>=2){
								popped = pop();
								printf("%c", popped);
								if(s.top==-1)
									break;
								else
									last_precedense = precedense(s.arr[s.top]);
							}
							push(c);
							last_precedense = 2;
						}
					}
					else{
						if(last_precedense<1){
							push(c);
							last_precedense = 1;
						}
						else{
							while(last_precedense>=1){
								popped = pop();
								printf("%c", popped);
								if(s.top==-1)
									break;
								else
									last_precedense = precedense(s.arr[s.top]); 
							}
							push(c);
							last_precedense = 1;
						}
					}
				}
			}	
		}
		while(s.top!=-1)
			printf("%c",pop());
	}
	return 0;
}
