#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Menu(),Final();
float OperacoesBasicas();
int Fatorial();

void Menu() {
	int menu;
	
	printf("=== Início ===\n\n");
	
	printf("Escolha uma das opções abaixo:\n1- Operações Básicas\n2- Fatorial\n3- Sair \n\nValor: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: {
			system("cls");
			printf("O resultado é: %.2f\n\n\n", OperacoesBasicas()); 
			break;
		}
		case 2: {
			system("cls");
			printf("O resultado é: %d\n\n\n", Fatorial()); 
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos são inválidos.\n\n");
			Menu();
			break;
		}
	}
}

float OperacoesBasicas() {
	int menu;
	float valor1,valor2,resultado;
	
	printf("=== Início > Operações Básicas ===\n\n");
	
	printf("Digite o primeiro valor: ");
	scanf("%f", &valor1);
	printf("\nDigite o segundo valor: ");
	scanf("%f", &valor2);
	
	printf("\n\nEscolha uma das operações abaixo:\n1- Somar\n2- Subtrair\n3- Multiplicar\n4- Dividir\n\nValor: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: {
			system("cls"); 
			printf("=== Início > Operações Básicas > Resultado da Soma ===\n\n"); 
			resultado = valor1 + valor2; 
			break;
		}
		case 2: {
			system("cls"); 
			printf("=== Início > Operações Básicas > Resultado da Subtração ===\n\n"); 
			resultado = valor1 - valor2; 
			break;
		}
		case 3: {
			system("cls"); 
			printf("=== Início > Operações Básicas > Resultado da Multiplição ===\n\n"); 
			resultado = valor1 * valor2; 
			break;
		}
		case 4: {
			system("cls"); 
			printf("=== Início > Operações Básicas > Resultado da Divisão ===\n\n"); 
			resultado = valor1 / valor2; 
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos são inválidos.\n\n");
			OperacoesBasicas();
			break;
		}
	}
	
	return resultado;
}

int Fatorial() {
	int i,fat=1;
	
	printf("=== Início > Fatorial ===\n\n");
	
	printf("Insira um valor para calcular seu fatorial: ");
	scanf("%d", &i);
	
	while (i >= 1) {
		fat = fat * i;
		
		i--;
	}
	
	system("cls");
	printf("=== Início > Fatorial > Resultado ===\n\n");
	
	return fat;
}

void Final() {
	int resposta;
		
	printf("Você quer?\n1- Voltar ao início\n2- Sair\n\nResposta: ");
	scanf("%d", &resposta);
	
	switch (resposta) {
		case 1: {
			system("cls");
			main();
			break;
		}
		case 2: {
			exit(0);
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos são inválidos.\n\n");
			Final();
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Menu();
	Final();
	
	return 0;
}
