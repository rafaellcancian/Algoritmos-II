/*/
7. Ler um vetor de inteiros com 20 elementos. Desenvolver uma fun��o que encontra o maior elemento do
vetor e retorne o ponteiro para o maior elemento. A fun��o main deve exibir o maior elemento do vetor.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Maior(int elementos[21], int *ponteiro);

void Maior(int elementos[21], int *ponteiro) {
	int i;

	for (i = 1; i < 21; i++) {
		if (elementos[i] > *ponteiro) {
			*ponteiro = elementos[i];
		}
	}

	printf("\nO maior n�mero que foi encontrado no vetor �: %d\n\n\n", *ponteiro);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i,elementos[21],maior=0;
	int *ponteiro;

	for (i = 1; i < 21; i++) {
		printf("Digite o %d� elemento: ", i);
		scanf("%d", &elementos[i]);
	}

	ponteiro = &maior;

	Maior(elementos,ponteiro);

	system("pause");
	return 0;
}