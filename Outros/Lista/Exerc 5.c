/*/
5. Ler	um	vetor	com	10	elementos	inteiros	e	um	valor	inteiro.	Usar	uma	função	para	contar	o	número	de	vezes	
que	o	valor	aparece	no	vetor.	A	função	main deve	mostrar	este	valor.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Contar(int elementos[11], int valor);

void Contar(int elementos[11], int valor) {
	int i,contador=0;

	for (i = 1; i < 11; i++) {
		if (elementos[i] == valor) {
			contador++;
		}
	}

	printf("\nO número de vezes que o valor \"%d\" aparece é: %d\n\n\n", valor, contador);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i,elementos[11],valor;

	for (i = 1; i < 11; i++) {
		printf("Digite o %dº elemento: ", i);
		scanf("%d", &elementos[i]);
	}

	printf("\nDigite um valor: ");
	scanf("%d", &valor);

	Contar(elementos,valor);

	system("pause");
	return 0;
}