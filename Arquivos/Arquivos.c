#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Geral {
	FILE *arquivo;
	char palavra[100];
}geral;

void Gravar() {
	geral.arquivo = fopen("Teste.txt", "a");
	
	if (geral.arquivo == NULL) {
    	printf("AVISO: O arquivo não foi criado!\n\n");
	}
	
	printf("Escreva uma palavra: ");
	scanf("%s", geral.palavra);
	
	fprintf(geral.arquivo, "%s\n", geral.palavra);
	fclose(geral.arquivo);
	
	system("cls");
}

void Carregar() {
	char c;
	
	geral.arquivo = fopen("Teste.txt", "r");
	
	printf("Dados no arquivo:\n");
	
	do {
		c = getc(geral.arquivo);
		
		if (c != EOF) {
			printf("%c", c);
		}
	}
	while (c != EOF);
	
	fclose(geral.arquivo);
	
	printf("\n\n");
	
	system("pause");
	system("cls");
}

void Limpar() {
	geral.arquivo = fopen("Teste.txt", "w");
	fclose(geral.arquivo);
}

Menu() {
	int menu;
	
	printf("Você quer?\n\n1- Gravar\n2- Carregar\n3- Limpar\n4- Sair\n\nResposta: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: system("cls"); Gravar(); break;
		case 2: system("cls"); Carregar(); break;
		case 3: system("cls"); Limpar(); break;
		case 4: exit(0); break;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int i;
	
	for (;;i++) {
		Menu();
	}
	
	return 0;
}
