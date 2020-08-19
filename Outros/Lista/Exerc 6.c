/*/
6. Escreva um programa que lê dois vetores de inteiros com 10 elementos e chama funções para executar as
seguintes operações:
a. Soma de vetores
b. Subtração de vetores
c. Produto escalar dos vetores
d. Use ponteiros para manipular os vetores nas funções.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Somar(int *ponteiro1, int *ponteiro2),Subtrair(int *ponteiro1, int *ponteiro2),ProdutoEscalar(int *ponteiro1, int *ponteiro2);

void Somar(int *ponteiro1, int *ponteiro2) {
	int i,resultado=0;

	for (i = 1; i < 11; i++) {
		resultado = resultado + (ponteiro1[i] + ponteiro2[i]);
	}

	printf("\n\nResultado da soma: %d\n", resultado);
}

void Subtrair(int *ponteiro1, int *ponteiro2) {
	int i,resultado=0;

	for (i = 1; i < 11; i++) {
		resultado = resultado + (ponteiro1[i] - ponteiro2[i]);
	}

	printf("Resultado da subtração: %d\n", resultado);
}

void ProdutoEscalar(int *ponteiro1, int *ponteiro2) {
	int i,resultado=0;

	for (i = 1; i < 11; i++) {
		resultado = resultado + (ponteiro1[i] * ponteiro2[i]);
	}

	printf("Resultado do produto escalar: %d\n\n\n", resultado);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i,vetor1[11],vetor2[11];
	int *ponteiro1,*ponteiro2;

	for (i = 1; i < 11; i++) {
		printf("VETOR 1: Digite o %dº elemento: ", i);
		scanf("%d", &vetor1[i]);
	}

	printf("\n");

	for (i = 1; i < 11; i++) {
		printf("VETOR 2: Digite o %dº elemento: ", i);
		scanf("%d", &vetor2[i]);
	}

	ponteiro1 = vetor1;
	ponteiro2 = vetor2;

	Somar(ponteiro1,ponteiro2);
	Subtrair(ponteiro1,ponteiro2);
	ProdutoEscalar(ponteiro1,ponteiro2);

	system("pause");
	return 0;
}