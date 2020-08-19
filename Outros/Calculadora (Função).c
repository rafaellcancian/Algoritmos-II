#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Solicitar(),Operacao(),Somar(),Subtrair(),Multiplicar(),Dividir(),Final();

int valor1,valor2,resultado,menu;

void Solicitar() {
	printf("Digite o primeiro valor: ");
	scanf("%d", &valor1);
	printf("\nDigite o segundo valor: ");
	scanf("%d", &valor2);
	
	printf("\n\n");
}

void Operacao() {
	printf("Escolha uma das operações abaixo:\n1- Somar\n2- Subtrair\n3- Multiplicar\n4- Dividir\n\nValor: ");
	scanf("%d", &menu);
	

	switch (menu) {
		case 1: Somar(); break;
		case 2: Subtrair(); break;
		case 3: Multiplicar(); break;
		case 4: Dividir(); break;
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos so inválidos.\n\n");
			Operacao();
			break;
		}
	}
}

void Somar() {
	resultado = valor1 + valor2;
}

void Subtrair() {
	resultado = valor1 - valor2;
}

void Multiplicar() {
	resultado = valor1 * valor2;
}

void Dividir() {
	resultado = valor1 / valor2;
}

void Final() {
	int resposta;
	
	printf("\nO resultado é: %d\n\n\n", resultado);
	
	printf("Você deseja?\n1- Reiniciar\n2- Sair\n\nResposta: ");
	scanf("%d", &resposta);
	
	switch (resposta) {
		case 1: system("cls"); main(); break;
		case 2: exit(0); break;
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos so inválidos.\n\n");
			Final();
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Solicitar();
	Operacao();
	Final();
	
	return 0;
}
