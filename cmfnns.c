#include<stdio.h>

int main(){

	float x, y;
	char op;
	
	printf("Digite o primeiro numero: ");
	scanf("%f",&x);
	printf("Digite o segundo numero: ");
	scanf("%f",&y);
	printf("\nEscolha uma operacao:");
	printf("\n+ (adicao)");
	printf("\n- (subtracao)");
	printf("\n* (multiplicacao)");
	printf("\n/ (divisao)\n\n");
	scanf("%s",&op);
	
	switch(op){
		case '+': 
			printf("\n%.2f + %.2f: %.2f", x, y, x+y);
			break;
		case '-': 
			printf("\n%.2f - %.2f: %.2f", x, y, x-y);
			break;
		case '*': 
			printf("\n%.2f * %.2f: %.2f", x, y, x*y);
			break;
		case '/': 
			printf("\n%.2f / %.2f: %.2f", x, y, x/y);
			break;
		default:
			printf("Operacao invalida.");
	}
}
