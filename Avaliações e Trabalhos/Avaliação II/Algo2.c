#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Solicitar(),Calcular(int anos, int meses),Exibir(int resultado);

void Solicitar() {
	int anos,meses;
	
	printf("Insira abaixo quanto tempo você já viveu (em anos e meses):");
	
	printf("\n\nAnos: ");
	scanf("%d", &anos);
	
	printf("Meses: ");
	scanf("%d", &meses);
	
	Calcular(anos,meses);
}

void Calcular(int anos, int meses) {
	int resultado;
	
	resultado = (anos * 365) + (meses * 30);
	
	Exibir(resultado);
}

void Exibir(int resultado) {
	printf("\nA sua idade em dias é: %d\n\n", resultado);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	Solicitar();

	return 0;
}
