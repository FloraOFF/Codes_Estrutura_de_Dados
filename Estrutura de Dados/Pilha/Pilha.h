#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//Struct Pilha
struct Pilha {
	int topo_pilha;
	int capacidade_pilha;
	int *elemento_pilha;
}; //fim struct Pilha

//procedimento criar_pilha()
void criar_pilha(struct Pilha *pilha, int capacidade) {
	pilha->topo_pilha = -1;
	pilha->capacidade_pilha = capacidade;
	pilha->elemento_pilha = (int*)malloc(capacidade* sizeof(int));
} //fim do procedimento criar_pilha

//fun��o pilha_vazia()
int pilha_vazia(struct Pilha *pilha) {
	if (pilha->topo_pilha == -1)
		return 1; 
	else
		return 0;
}//fim da fun��o pilha_vazia()

//fun��o pilha_cheia()
int pilha_cheia(struct Pilha *pilha) {
	if (pilha->topo_pilha == pilha->capacidade_pilha - 1)
		return 1;
	else
		return 0;
}//fim da fun��o pilha_cheia()

//procedimento empilhar ()
int empilhar (struct Pilha *pilha, int novo_elemento) {
	pilha->topo_pilha++;
	pilha->elemento_pilha[pilha->topo_pilha] = novo_elemento;
	return novo_elemento;
}//fim do procedimento empilhar()

//fun��o desempilhar()
int desempilhar(struct Pilha *pilha) {
	int aux = pilha->elemento_pilha[pilha->topo_pilha];
	pilha->topo_pilha--;
	return aux;
}//fim da fun��o desempilhar()

//Fun��o exibir_pilha()
int exibir_pilha (struct Pilha *pilha) {
	int cont_capacidade, cont_topo;
	printf ("\n\nPilha: ");
	for (cont_capacidade, cont_topo = pilha->topo_pilha = 0; cont_topo < pilha->capacidade_pilha; cont_topo++) {
		printf ("\t%d", pilha->elemento_pilha[cont_capacidade++]);
		
		if (cont_capacidade == pilha->capacidade_pilha)
			cont_capacidade = 0;
	}
	printf ("\n\n\n");
	return cont_capacidade;
} //Fim da fun��o exibir_pilha()


//Fun��o retornar_topo_pilha()
int retornar_topo_pilha (struct Pilha *pilha) {	
	int topo_P = pilha->elemento_pilha[pilha->topo_pilha];
	printf("\n\nRetornando o topo da pilha: %d", topo_P);
		
	return topo_P;
} //Fim da fun��o retornar_topo_pilha()


//fun��o retornar_topo_pilha()
//fun��o retornar_base_pilha()
//fun��o buscar_elemento_pilha() - busca linear
//fun��o de ordena��o (crescente, decrescente e rand�mica) da pilha -> nova pilha -> comparar as duas pilhas
//fun��o para comparar_pilhas()
//fun��o para transformar pilha em fila e vice-versa????????
//Posso criar pilhas e filas de maneira din�mica?????????????????????????? ALICE
//Os tamanhos das pilhas e das filas podem ser din�micos??????? IGOR
//Fun��o exibir_pilha(); OK!
//Fun��o liberar_pilha();
//Fun��o liberar_elemento_pilha()
