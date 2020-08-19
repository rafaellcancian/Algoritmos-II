#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Menu(),Final();
float OperacoesBasicas();
int Fatorial();

void Menu() {
	int menu;
	
	printf("=== In�cio ===\n\n");
	
	printf("Escolha uma das op��es abaixo:\n1- Opera��es B�sicas\n2- Fatorial\n3- Sair \n\nValor: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: {
			system("cls");
			printf("O resultado �: %.2f\n\n\n", OperacoesBasicas()); 
			break;
		}
		case 2: {
			system("cls");
			printf("O resultado �: %d\n\n\n", Fatorial()); 
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos s�o inv�lidos.\n\n");
			Menu();
			break;
		}
	}
}

float OperacoesBasicas() {
	int menu;
	float valor1,valor2,resultado;
	
	printf("=== In�cio > Opera��es B�sicas ===\n\n");
	
	printf("Digite o primeiro valor: ");
	scanf("%f", &valor1);
	printf("\nDigite o segundo valor: ");
	scanf("%f", &valor2);
	
	printf("\n\nEscolha uma das opera��es abaixo:\n1- Somar\n2- Subtrair\n3- Multiplicar\n4- Dividir\n\nValor: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: {
			system("cls"); 
			printf("=== In�cio > Opera��es B�sicas > Resultado da Soma ===\n\n"); 
			resultado = valor1 + valor2; 
			break;
		}
		case 2: {
			system("cls"); 
			printf("=== In�cio > Opera��es B�sicas > Resultado da Subtra��o ===\n\n"); 
			resultado = valor1 - valor2; 
			break;
		}
		case 3: {
			system("cls"); 
			printf("=== In�cio > Opera��es B�sicas > Resultado da Multipli��o ===\n\n"); 
			resultado = valor1 * valor2; 
			break;
		}
		case 4: {
			system("cls"); 
			printf("=== In�cio > Opera��es B�sicas > Resultado da Divis�o ===\n\n"); 
			resultado = valor1 / valor2; 
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: Os valores inseridos s�o inv�lidos.\n\n");
			OperacoesBasicas();
			break;
		}
	}
	
	return resultado;
}

int Fatorial() {
	int i,fat=1;
	
	printf("=== In�cio > Fatorial ===\n\n");
	
	printf("Insira um valor para calcular seu fatorial: ");
	scanf("%d", &i);
	
	while (i >= 1) {
		fat = fat * i;
		
		i--;
	}
	
	system("cls");
	printf("=== In�cio > Fatorial > Resultado ===\n\n");
	
	return fat;
}

void Final() {
	int resposta;
		
	printf("Voc� quer?\n1- Voltar ao in�cio\n2- Sair\n\nResposta: ");
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
			printf("AVISO: Os valores inseridos s�o inv�lidos.\n\n");
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
