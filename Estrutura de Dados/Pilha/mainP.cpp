#include "Pilha.h"

int main (int argc, char *argv[])
{
	system ("cls");
	setlocale (LC_ALL, "Portuguese");
	struct Pilha pilha;
	int capacidade, op, elemento, elemento_desemp;
	printf ("\n\nEste Programa Manipula Pilhas!");
	printf ("\n\nInforme a capacidade da 1� pilha: ");
	scanf ("%d", &capacidade);
	
	//chamada da fun��o criar_pilha()
	criar_pilha(&pilha, capacidade);
	system ("cls");
	
	while (1) {
		printf ("\n\n\tMENU");
		printf ("\n\n0 - Sair");
		printf ("\n\n1 - Empilhar"); //push
		printf ("\n\n2 - Desempilhar"); //POP
		printf ("\n\n3 - Exibir Pilha");
		printf ("\n\n4 - Mostrar o topo da pilha");
		//Inserir as outra op��es de menu
		printf ("\n\n\nInforme a op��o desejada: ");
		scanf ("%d", &op);
		
		printf ("\n\n\n");
		system ("Pause");
		system ("cls");
		
		switch (op) {
			case 1:
				printf ("\n\nEmpilhando elementos na pilha!");
				if (pilha_cheia(&pilha) == 1)
					printf ("\n\nPilha cheia! N�o � poss�vel realizar novo empilhamento!");
				else {
					printf ("\n\nInforme o novo elemento para empilhamento: ");
					scanf ("%d", &elemento);
					empilhar(&pilha, elemento);
				}
				printf ("\n\n\n");
				system ("Pause");
				system ("cls");
				break;
			
			case 2:
				system ("cls");
				printf ("\n\nDesempilhando elementos na pilha!");
				if (pilha_vazia(&pilha) == 1)
					printf ("\n\nPilha vazia! N�o � poss�vel desempilhar!");
				else {
					elemento_desemp = desempilhar(&pilha);
					printf ("\n\nElemento desempilhado: %d", elemento_desemp);
				}
				printf ("\n\n\n");
				system ("Pause");
				system ("cls");
				break;
				
			case 3: 
				system ("cls");
				printf ("\n\nExibindo elementos na pilha!");
				if (pilha_vazia(&pilha) == 1)
					printf ("\n\nPilha vazia! N�o h� elementos!");
				else {
					exibir_pilha (&pilha);
				}
				printf ("\n\n\n");
				system ("Pause");
				system ("cls");
				break;
				
			case 4:
				system ("cls");
				retornar_topo_pilha (&pilha);
				printf ("\n\n\n");
				system ("Pause");
				system ("cls");
				break;	
						
			default:
				system ("cls");
				printf ("\n\nObrigado por utilizar nosso programa!\n\n");
				system ("Pause");
				exit(0);
		}	
	}
	return 0;
}
