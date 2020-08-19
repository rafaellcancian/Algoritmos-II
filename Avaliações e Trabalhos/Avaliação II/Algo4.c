#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Armazenar(int vetorA[11], int vetorB[11]),Exibir(int vetorA[11], int vetorB[11], int vetorC[11]);

void Armazenar(int vetorA[11], int vetorB[11]) {
	int i,vetorC[11];
	
	for (i = 1; i < 11; i++) {
		vetorC[i] = vetorA[i] + vetorB[i];
	}
	
	Exibir(vetorA,vetorB,vetorC);
}

void Exibir(int vetorA[11], int vetorB[11], int vetorC[11]) {
	int i;
	
	system("cls");
	printf("Resultados:\n\n");
	
	for (i = 1; i < 11; i++) {
		printf("%d + %d = %d\n", vetorA[i], vetorB[i], vetorC[i]);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int i,vetorA[11],vetorB[11];
	
	for (i = 1; i < 11; i++) {
		printf("VETOR A: Insira o %dº valor: ", i);
		scanf("%d", &vetorA[i]);
	}
	
	printf("\n");
	
	for (i = 1; i < 11; i++) {
		printf("VETOR B: Insira o %dº valor: ", i);
		scanf("%d", &vetorB[i]);
	}
	
	Armazenar(vetorA,vetorB);
	
	return 0;
}
