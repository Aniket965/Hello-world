// This algorithm solves a crossword using backtracking.
// Comments are in portuguese.
/*
Sample input
  4 3
  0 0 -1
  0 0 0 
  -1 0 0
  0 0 0
  5
  key
  car
  or
  as
  rry
  saoe
*/

#include<stdio.h>
#include<stdlib.h>

// Estrutura utilizada para coordenar e aramazenar os vertices
typedef struct {
	int i;
	int j;
	int tamPal[2]; // [0] - coluna S / [1] - linha L
	int idxPal[2]; // Index da palavra em determinado ponto
}vertice;

// Estrututa utilizada na pilha
typedef struct{
	int vertice;
	int lado; // 'Ponto cadeal'
}par;

// Funçao para contar tamanho da palavra
int TamanhoPalavra(char *str){
	int tamanho = 0;
		while (str[tamanho] != '\0'){
			tamanho++;
		}
	return tamanho;
}

void setarTamanhos(vertice *ver, char **tab, int m, int n){
	/*
	Funçao que determina o numero de letras que as palavras alocadas em 
	determinado local podem assumir. Recebe um 'vertice' e percorre todos
	os seus quatro pontos cardeiais e realaciona cada um com um tamanho.
	*/

	int t = 0;	
	int di = ver->i;
	while (++di < m){
		if (tab[di][ver->j] == '*') break;
		t++;
	}
	ver->tamPal[0] = t;

	t = 0;
	int dj = ver->j;
	while (++dj < n){
		if (tab[ver->i][dj] == '*') break; 
		t++;
	}
	ver->tamPal[1] = t;
}

void montarTabuleiro(vertice *ver, char **tab, char **pal, int nVer, int m, int n){
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (tab[i][j] != '*') 
				tab[i][j] = '#'; // Reinicializando tabuleiro

	for (int i = 0; i < nVer; i++){	// Percorrendo todos vertices
		for (int j = 0; j < 4; j++){ // Percorrendo pontos posiveis dentro do vertice
			int auxTam = ver[i].tamPal[j]; // Variaveis que auxilian na posiçao
			int auxIdx = ver[i].idxPal[j];

			if (auxIdx >= 0){ // Se existe palavra idexada a aquela posicao
				char *auxPal = pal[auxIdx];
				if (j == 0){ // Caso ela esteja numa coluna no sul
					int auxI = ver[i].i + 1;
					int auxJ = ver[i].j;

					for (int k = 0; k < auxTam; k++){
						tab[auxI][auxJ] = auxPal[k]; // Passando a palvra para o tabuleiro
						auxI++;
					}
				}
				if (j == 1){ // Caso ela esteja numa linha no leste
					int auxI = ver[i].i;
					int auxJ = ver[i].j + 1;

					for (int k = 0; k < auxTam; k++){
						tab[auxI][auxJ] = auxPal[k]; 
						auxJ++;
					}
				}
			}
		}
	}
}

int checaEspacoVazio(char **tab, int m, int n){
	// Checa se existe alguma posiçao vazia no tabuleiro
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			if (tab[i][j] == '#') return 1; // Tem espaço vazio;
		}
	}
	return 0;
}

int vaiDar(char **tab, char *pal, int i, int j, int ori){
	/*
	Funçao que, dado o tabuleiro, uma palavra, uma posiçao e uma orintaçao,
	checa se sera possivel colocar aquela palavra no local, ou seja, se ela
	nao vai colodir com alguma palavra ja colocada no tabuleiro, em termos de
	letras diferentes.
	*/
	int n = TamanhoPalavra(pal);
	for (int k = 1; k <= n; k++){
		if (ori == 0){ // Caso a palavra tenha que caber em uma coluna
			// Caso aquela posicao ja esteja com outra letra e nao seja vazia
			if (tab[i+k][j] != pal[k-1] && tab[i+k][j] != '#') return 0;
		}
		else if (ori == 1){
			if (tab[i][j+k] != pal[k-1] && tab[i][j+k] != '#') return 0;
		}
	}
	return 1; // #VaiDarCerto
}

void imprimeTabuleiro(char **tab, int m, int n){
	/*
	Funçao auxiliar para imprimir o tabuleiro
	*/
	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			printf("%c ", tab[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int i, j, m, n, t;
	t = 1; // Contador de instancias
	while (scanf("%d %d", &m, &n) && !(m == 0 && n == 0)){
		// m - linha , n - col

		// Definindo a matrix que representara o tabuleiro, sendo que ela possui
		// 1 linha e coluna a mais (que formam uma especie de moldura).
		m += 1; n += 1;
		char **tab;
		tab = malloc(m * sizeof(char *));
		for (i = 0; i < m; i++)
			tab[i] = malloc(n * sizeof(char));

		/*
		Aqui se cria um vetor de vertices. Neste EP, a ideia de vertice se traduz
		no local de onde uma palavra pode iniciar/acabar.
		*/
		vertice *v;
		v = malloc(2 * m * n * sizeof(vertice));

		// Lendo o tabuleiro
		int ipt, nVertices = 0;
		for (i = 1; i < m; i++){
			for (j = 1; j < n; j++){
				tab[i][j] = '#'; // Inicializando tabuleiro, '#' representa vazio
				scanf("%d", &ipt);
				if (ipt == -1){
					// Inicializando um vertice
					tab[i][j] = '*';
					v[nVertices].i = i;
					v[nVertices].j = j;
					v[nVertices].idxPal[0] = -1;
					v[nVertices].idxPal[1] = -1;

					nVertices++;
				}
			}
		}

		// Criando a 'moldura de vertices' para o tabuleiro
		for (int i = 0; i < m; i++){
			tab[i][0] = '*';
			v[nVertices].i = i;
			v[nVertices].j = 0;
			v[nVertices].idxPal[0] = -1;
			v[nVertices].idxPal[1] = -1;
			nVertices++;
		}
		for (int j = 0; j < n; j++){
			tab[0][j] = '*';
			v[nVertices].i = 0;
			v[nVertices].j = j;
			v[nVertices].idxPal[0] = -1;
			v[nVertices].idxPal[1] = -1;
			nVertices++;
		}

		// Lendo a lista de palavras como uma matriz de char's
		int nPal;
		scanf("%d", &nPal);
		char **pal;
		pal = malloc(nPal * sizeof(char*));
		for (i = 0; i < nPal; i++){
			pal[i] = malloc(105 * sizeof(char));
			scanf("%s", pal[i]);
		}

		// Setando o numero maximo que uma palavra pode ter para cada vertice
		for (i = 0; i < nVertices; i++)
			setarTamanhos(&v[i], tab, m, n);

		// Criando pilha usada no backtracking
		par *pilha;
		pilha = malloc((nPal+1) * sizeof(par));
		int topoPilha = 0; 

		printf("Instancia %d\n", t);
		int palAtual = 0;

		// Inicio do backtracking
		while (palAtual <= nPal){
			if (palAtual < 0){ // Base de erro do backtracking
				printf("nao ha solucao\n\n");
				break;
			}
			else if (palAtual == nPal){ // Sucesso
				if (checaEspacoVazio(tab, m, n)){ // Nao tao sucesso assim
					printf("nao ha solucao\n\n");
					break;
				}
				montarTabuleiro(v, tab, pal, nVertices, m, n);
				imprimeTabuleiro(tab, m, n);
				printf("\n");
				break;
			}

			int verAtual = 0; // Indicador de qual vertice estou lidando
			while (verAtual <= nVertices && palAtual < nPal && palAtual >= 0){
				int lado = 0; // Indicador de qual ponto do vertice estou lidando

				if (verAtual == nVertices){ // Aqui eu faço o back do tracking
					topoPilha--; // Desempilhando
					verAtual = pilha[topoPilha].vertice; // Passando valores da pilha de volta para a execuçao
					lado = pilha[topoPilha].lado; 
					v[verAtual].idxPal[lado] = -1;
					lado++; // Dando sequencia a partir do proximo passo
					palAtual = topoPilha; // A altura da pilha representa a palavr anterior a que estou lidando					
					if (topoPilha < 0) break;
					montarTabuleiro(v, tab, pal, nVertices, m, n); // Atualiza tabuleiro, dado que retirei uma palavra
				}

				while (lado <= 2){

					if (lado == 2){ // Ja percorri todos os pontos possiveis dentro de um vertice
						verAtual++; // Vou para o proximo vertice
						break;
					}

					if (v[verAtual].tamPal[lado] == TamanhoPalavra(pal[palAtual]) && v[verAtual].idxPal[lado] == -1) 
						if (vaiDar(tab, pal[palAtual], v[verAtual].i, v[verAtual].j, lado) == 1){
							// Caso eu consiga colocar a palavra no determinado local
							pilha[topoPilha].vertice = verAtual;
							pilha[topoPilha].lado = lado;
							v[verAtual].idxPal[lado] = palAtual;
							topoPilha++; // Empilhando
							palAtual++; // Indo para proxima palavra
							verAtual = 0;
							montarTabuleiro(v, tab, pal, nVertices, m, n); // Atualiza tabuleiro com a nova palavra
							break;
						}

					lado++;
				}
			}
		}

		t++; // Incrementando instancia
		// Liberando a memoria
		free(pilha);
		free(tab);
		free(v);
		free(pal);
	}
	return 0;
}

