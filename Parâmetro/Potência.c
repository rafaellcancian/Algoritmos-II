#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Calcular(int calcularbase, int calcularpot);

int Calcular(int calcularbase, int calcularpot) {
	int i,resultado=calcularbase;
	
	for (i = 1; i < calcularpot; i++) {
		resultado = resultado * calcularbase;
	}
	
	return resultado;
}



int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int base,pot;
	
	printf("Digite a base: ");
	scanf("%d", &base);
	printf("Digite a potência: ");
	scanf("%d", &pot);
	
	printf("\nO número %d elevado ao %d é: %d\n", base,pot,Calcular(base, pot));
	
	return 0;
}
