#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Menu(),Cadastrar(),Exibir(),Limpar();

FILE *contatos;

void Menu() {
	int menu;
	
	printf("=== Menu principal\n\nVocê quer?\n\n[1] Cadastrar contato(s)\n[2] Exibir contatos cadastrados\n[3] Limpar TODA a lista de contatos\n[4] Sair\n\nResposta: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: system("cls"); Cadastrar(); break;
		case 2: system("cls"); Exibir(); break;
		case 3: system("cls"); Limpar(); break;
		case 4: exit(0); break;
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
	char nome[100],email[100],telefone[100];

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

	contatos = fopen("Contatos.txt", "a");

	if (contatos == NULL) {
    	printf("ERRO: O arquivo não foi criado.\n\n");
    	Menu();
	}

	for (i = 0; i < numcontatos; i++) {
		printf("=== Cadastrar contato(s)\n\nPara realizar o cadastro do contato preencha os campos abaixo:\n\n");
		printf("Nome: ");
		scanf("%[^\n]s", nome);
		fprintf(contatos, "Dados armazenados de \"%s\":\n\nNome: %s\n", nome, nome);
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
	}

	fclose(contatos);

    printf("AVISO: O cadastro foi realizado com sucesso.\n\n");
	Menu();
}

void Exibir() {
	char exibir;
	
	contatos = fopen("Contatos.txt", "r");
	
	printf("=== Exibir contatos cadastrados\n\n");
	
	do {
		exibir = fgetc(contatos);
		
		if (exibir != EOF) {
			printf("%c", exibir);
		}
	} while (exibir != EOF);
	
	fclose(contatos);

	printf("\n");

    printf("Pressione qualquer tecla para voltar. . . ");
    system("pause > nul");
	system("cls");
	Menu();
}

void Limpar() {
	contatos = fopen("Contatos.txt", "w");
	fclose(contatos);

	printf("AVISO: A lista de contatos foi excluída.\n\n");
	Menu();
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	Menu();

	return 0;
}