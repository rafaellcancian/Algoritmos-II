#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void Menu(),Cadastrar(),Exibir(),Final();

FILE *contatos;

void Menu() {
	int menu;
	
	printf("=== Menu principal\n\nVocê quer?\n\n[1] Cadastrar contato(s)\n[2] Pesquisar contatos cadastrados\n[3] Sair\n\nResposta: ");
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
	int numcontatos,erro,i;
	char nome[100],email[100],telefone[100],nomedoarquivo[100];

	do {
		printf("=== Cadastrar contato(s)\n\nQuantos contatos você quer cadastrar?\n\n[0] Voltar\n\nResposta: ");
		scanf("%d", &numcontatos);
		fflush(stdin);
		system("cls");

		if (numcontatos < 0) {
			erro = 1;
			system("cls");
			printf("ERRO: O número de contatos é inválido.\n\n");
		}
		else if (numcontatos == 0) {
			erro = 0;
			system("cls");
			Menu();
		}
		else {
			erro = 0;
		}
	} while (erro == 1);

	for (i = 1; i <= numcontatos; i++) {
		printf("=== Cadastrar contato(s)\n\nPara realizar o cadastro do %dº contato preencha os campos abaixo:\n\n", i);
		printf("Nome: ");
		scanf("%[^\n]s", nomedoarquivo);

		strcpy(nome, nomedoarquivo);
		strcat(nomedoarquivo, ".txt");

		contatos = fopen(nomedoarquivo, "a");

		if (contatos == NULL) {
			printf("ERRO: O arquivo não foi criado.\n\n");
			Menu();
		}

		fprintf(contatos, "==================================================\n\nDados armazenados de \"%s\":\n\nNome: %s\n", nome, nome);
		fflush(stdin);

		printf("Email: ");
		scanf("%[^\n]s", email);
		fprintf(contatos, "Email: %s\n", email);
		fflush(stdin);

		printf("Telefone: ");
		scanf("%[^\n]s", telefone);
		fprintf(contatos, "Telefone: %s\n\n==================================================\n\n", telefone);
		fflush(stdin);

		system("cls");

		fclose(contatos);
	}

    printf("AVISO: O cadastro foi realizado com sucesso.\n\n");
	Menu();
}

void Exibir() {
	char nomedoarquivo[100],exibir;

	fflush(stdin);
	printf("=== Exibir contatos cadastrados\n\nPara pesquisar o cadastro do contato digite o nome abaixo:\n\nNome: ");
	scanf("%[^\n]s", nomedoarquivo);
	system("cls");

	strcat(nomedoarquivo, ".txt");
	
	contatos = fopen(nomedoarquivo, "r");

	if (contatos == NULL) {
		printf("ERRO: O contato não existe.\n\n");
		Menu();
	}
	
	printf("=== Exibir contatos cadastrados\n\n");
	
	do {
		exibir = fgetc(contatos);
		
		if (exibir != EOF) {
			printf("%c", exibir);
		}
	} while (exibir != EOF);
	
	fclose(contatos);

	Final();
}

void Final() {
	int resposta;

	printf("Você quer?\n\n[1] Pesquisar novamente\n[2] Voltar para o menu\n[3] Sair\n\nResposta: ");
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