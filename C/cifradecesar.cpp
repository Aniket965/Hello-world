#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void codifica (char texto[], int senha){

int i;

  for (i=0;i<strlen(texto);i++){
    texto[i] = texto [i] + senha;
          }


}
void decodifica (char texto[], int senha){

int i;

  for (i=0;i<strlen(texto);i++){
    texto[i] = texto [i] - senha;
          }

}

int main(){

char mensagem[30];
int senha;
char fim[] = {'f','i','m'};

        do{

        printf("Insira a mensagem de no max 30 caracteres\n");
        fflush(stdin);
          scanf(" %29[^\n]s",mensagem);

        printf("Insira a senha para codificacao\n");
          fflush(stdin);
        scanf("%d",&senha);

    printf("%s\n",mensagem);


codifica(mensagem, senha);

 printf("Mensagem codificada: %s\n",mensagem);

decodifica(mensagem, senha);

 printf("Mensagem decodificada: %s\n",mensagem);

        }while(strcmp(mensagem,fim) == 0);



 return 0;
 }


