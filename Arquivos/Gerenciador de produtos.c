#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void Menu(),Cadastrar(),Exibir(),Final();

FILE *produtos;

void Menu() {
	int menu;
	
	printf("=== Menu principal\n\nVocê quer?\n\n[1] Cadastrar produto(s)\n[2] Consultar produtos cadastrados\n[3] Sair\n\nResposta: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: system("cls"); Cadastrar(); break;
		case 2: system("cls"); Exibir(); break;
		case 3: exit(0); break;
		default: {
			system("cls"); 
			printf("ERRO: O valor inserido é inválido.\n\n");
			Menu();
			break;
		}
	}
}

void Cadastrar() {
	int numprodutos,erro,i;
	char codigodebarras[100],nome[100],nomedoarquivo[100];

	do {
		printf("=== Cadastrar produto(s)\n\nQuantos produtos você quer cadastrar?\n\n[0] Voltar\n\nResposta: ");
		scanf("%d", &numprodutos);
		fflush(stdin);
		system("cls");

		if (numprodutos < 0) {
			erro = 1;
			system("cls");
			printf("ERRO: O número de produtos é inválido.\n\n");
		}
		else if (numprodutos == 0) {
			erro = 0;
			system("cls");
			Menu();
		}
		else {
			erro = 0;
		}
	} while (erro == 1);

	for (i = 1; i <= numprodutos; i++) {
		printf("=== Cadastrar produtos(s)\n\nPara realizar o cadastro do %dº produto preencha os campos abaixo:\n\n", i);
		printf("Código de barras: ");
		scanf("%[^\n]s", nomedoarquivo);

		strcpy(codigodebarras, nomedoarquivo);
		strcat(nomedoarquivo, ".txt");

		produtos = fopen(nomedoarquivo, "a");

		if (produtos == NULL) {
			printf("ERRO: O arquivo não foi criado.\n\n");
			Menu();
		}

		fprintf(produtos, "==================================================\n\nDados armazenados de \"%s\":\n\nCódigo de barras: %s\n", codigodebarras, codigodebarras);
		fflush(stdin);

		printf("Nome do produto: ");
		scanf("%[^\n]s", nome);
		fprintf(produtos, "Nome do produto: %s\n\n==================================================\n\n", nome);
		fflush(stdin);

		system("cls");

		fclose(produtos);
	}

	printf("AVISO: O cadastro foi realizado com sucesso.\n\n");
	Menu();
}

void Exibir() {
	char nomedoarquivo[100],exibir;

	fflush(stdin);
	printf("=== Consultar produtos cadastrados\n\nPara pesquisar um produto digite o código de barras abaixo:\n\nCódigo de barras: ");
	scanf("%[^\n]s", nomedoarquivo);
	system("cls");

	strcat(nomedoarquivo, ".txt");
	
	produtos = fopen(nomedoarquivo, "r");

	if (produtos == NULL) {
		printf("ERRO: O produto não existe.\n\n");
		Menu();
	}
	
	printf("=== Exibir produtos cadastrados\n\n");
	
	do {
		exibir = fgetc(produtos);
		
		if (exibir != EOF) {
			printf("%c", exibir);
		}
	} while (exibir != EOF);
	
	fclose(produtos);

	Final();
}

void Final() {
	int resposta;

	printf("Você quer?\n\n[1] Consultar novamente\n[2] Voltar para o menu\n[3] Sair\n\nResposta: ");
	scanf("%d", &resposta);
	
	switch (resposta) {
		case 1: {
			system("cls");
			Exibir(); 
			break;
		}
		case 2: {
			system("cls");
			Menu(); 
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		default: {
			system("cls"); 
			printf("ERRO: O valor inserido é inválido.\n\n");
			Final();
			break;
		}
	}	
}	

int main() {
	setlocale(LC_ALL, "Portuguese");

	Menu();

	return 0;
}