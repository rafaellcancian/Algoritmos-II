#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float solicitarValor();
float somar(float v1, float v2);
void exibirResultado(float resultado);

float solicitarValor() {
	float valor;
	printf("Digite um valor: ");
	scanf("%f", &valor);
	
	return valor;
}

float somar(float v1, float v2) {
	float resultado = v1 + v2;
	
	return resultado;
}

void exibirResultado(float resultado) {
	printf("\nO resultado é: %.0f\n", resultado);
}



int main() {
	setlocale(LC_ALL, "Portuguese");
	
	float v1 = solicitarValor();
	float v2 = solicitarValor();
	float result = somar(v1, v2);
	exibirResultado(result);
	
	
	return 0;
}
