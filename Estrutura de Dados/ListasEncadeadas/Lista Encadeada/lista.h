#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
// struct lista
struct lista {
	int id;
	char nome[80];
	float peso;
	struct lista* prox;
	int tam;
};
// fim da struct lista

//Tipando a estrutura Lista do tipo lista
typedef struct lista Lista;

// fun��o criar_lista ()
Lista* criar_lista(){
	return NULL;
} //fim da fun��o criar_lista ()

// fun��o inserir lista
Lista* inserir_lista(Lista* l, int novo_id, char* novo_nome, float novo_peso){
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->id = novo_id;
	strcpy(novo->nome, novo_nome);
	novo->peso=novo_peso;
	novo->prox = l;
	novo->tam++;
	return novo;
}
// fim da fun��o lista

//fun��o imprimir lista
void Exibir(Lista* l){
	Lista* p = l;
		for(p = l; p != NULL; p = p->prox){
			printf("\n\nId do cadastro: %d",p->id);
			printf("\n\nNome da pessoa: %s",p->nome);
			printf("\n\nPeso da pessoa (kg): %2.f",p->peso);
			printf ("\n\n\n");
		}
} // fim da fun��o imprimir lista

//fun��o imprimir_elemento_lista
void imprimir_elemento_lista (Lista *l, int codigo_busca){
	Lista* p;
	int cod = 0;
	for(p = l; p != NULL; p = p->prox){
		if(p->id == codigo_busca){
			cod = 1;
			printf("\n\nElemento localizado na lista!\n\n");
			printf("\n\nId do cadastro: %d",p->id);
			printf("\n\nNome da pessoa: %s",p->nome);
			printf("\n\nPeso da pessoa (kg): %2.f",p->peso);
		}
	}
	if (cod == 0){
		printf ("\n\nElemento n�o localizado na lista!\n\n");
	}
	//fun��o imprimir_lista()-busca bin�ria
	//fun��o pra ordenar a lista com base no id de cadastro
	//printf("\n\n\nObrigado por utilizar nosso programa!\n\n");
	printf ("\n\n");
}

//fun��o busca_elemento
Lista* busca_elemento (Lista* l, int codigo_busca) {
	Lista* p;
	for (p = l; p != NULL; p = p->prox) {
		if (p->id == codigo_busca) {
			printf("\n\nElemento localizado na lista!\n\n");
			printf("\n\nId do cadastro: %d",p->id);
			printf("\n\nNome da pessoa: %s",p->nome);
			printf("\n\nPeso da pessoa (kg): %2.f",p->peso);
			return p;
		}
	}
	printf("Elemento n�o localizado!");
	return NULL;
} //Fun��o busca_elemento ()

//fun��o lista_vazia()
int lista_vazia (Lista* l) {
	if (l == NULL)
		return 1;
	return 0;
}//fun��o lista_vazia ()

//fun��o para remover_elemento ()
Lista* remover_elemento_lista (Lista* l, int codigo_busca) {
	Lista* ant = NULL;
	Lista* p = l;
	while (p != NULL && p->id != codigo_busca) {
		ant = p;
		p = p->prox;
	}
	
	//Se n�o testa lista vazia:
	//Lista vazia- ? ou elemento n�o localizado
	if (p == NULL)  
		return l;
	
	if (ant == NULL) //Localizou no primeiro elemento da lista
		l = p->prox;
	else //Localizou no "meio" da lista
		ant->prox = p->prox;
	
	free (p);
	return l;		
} //fim da fun��o remover_elemento_lista ()

//fun��o liberar_lista ()
Lista* liberar_lista (Lista* l) {
	Lista* p = l;
	while (p != NULL) {
		Lista* t = p->prox; //t � um ponteiro auxiliar
		free(p);
		p = t;
	}
	return p;
}//fim da fun��o liberar_lista()

//Ideia da Alice: duas listas iguais
//fun��o listas_iguais ()
int listas_iguais (Lista* l1, Lista* l2) {
	//dois ponteiros auxiliares
	Lista* p1 = l1;
	Lista* p2 = l2;
	while (p1 != NULL && p2 != NULL) {
		if (p1->id != p2->id)
			return 0;
		
		p1 = p1->prox;
		p2 = p2->prox;
	}
	return p1 == p2; //NULL == NULL retornar� 1
}

//fun��o busca_elemento -> repeti�ao id
int busca_elemento_repeticao (Lista* l, int codigo_busca) {
	Lista* p;
	int cont = 0;
	for (p = l; p != NULL; p = p->prox) {
		if (p->id == codigo_busca) {
			cont++;
		}
	}
	return cont;
} //Fun��o busca_elemento_repeticao ()

//Procedimento ordenar_lista() 
void ordenar_lista (Lista *l) {
	Lista* pi; 
	Lista* pj;
	Lista* pfim = NULL;
	int aux;
	
	int cont = 0;
	for (pi = l; pi->prox != NULL; pi = pi->prox) {
		for (pj = l; pj->prox != NULL; pj = pj->prox) {
			if (pj->id > pj->prox->id) {
				aux = pj->id;
				pj->id = pj->prox->id;
				pj->prox->id = aux;
			}
		}
	}
} //Fim do procedimento ordenar_lista()

//Fun��o buscaBinaria()
int buscaBinaria (int busca_id, Lista *l) 
{
	//ordenar_lista (l);
	Lista* p;
	int esquerda = -1, direita = p->tam;
	while (esquerda < direita - 1) {
		int medio = (esquerda + direita)/2;
		if (p->id = medio < busca_id)
			esquerda = medio;
		else
			direita = medio;
	}
	return direita;
	
	printf("\n\nElemento localizado na lista!\n\n");
	printf("\n\nId do cadastro: %d",p->id);
	printf("\n\nNome da pessoa: %s",p->nome);
	printf("\n\nPeso da pessoa (kg): %2.f",p->peso);
	
} //Fim da fun��o buscaBinaria

//Tarefinha
//1 - Implementar fun��o para verificar elementos iguais em uma lista
//2 - Crias todas as buscas com buscas bin�rias
//3 - Criar fun��o de ordena��o com base no id
//4 - fun��o elementos_iguais_lista () - id
