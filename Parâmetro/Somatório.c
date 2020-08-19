#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Solicitar(int i);
int Somatorio(int valores[6]);

int Solicitar(int i) {
	int solicitarvalor;
	
	printf("Digite o %dº valor: ", i);
	scanf("%d", &solicitarvalor);
	
	return solicitarvalor;
}

int Somatorio(int valores[6]) {
	int j,resultsomatorio=0;
	
	for (j = 1; j <= 5; j++) {
		resultsomatorio = resultsomatorio + valores[j];
	}
	
	return resultsomatorio;
}




int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int i,valores[6],resultado;
	
	for (i = 1; i <= 5; i++) {
		valores[i] = Solicitar(i);
	}
	
	resultado = Somatorio(valores);
	
	printf("\nO somatório é: %d\n", resultado);
	
	return 0;
}
