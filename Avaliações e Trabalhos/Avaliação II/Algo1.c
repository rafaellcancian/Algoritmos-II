#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Estudante {
	char nome[100];
	int idade,matricula;
}estudante;

int main() {
	setlocale(LC_ALL, "Portuguese");

	printf("Insira abaixo os dados do estudante:");
	
	printf("\n\nNome: ");
	scanf("%[^\n]s", estudante.nome);
	fflush(stdin);
	
	printf("Idade: ");
	scanf("%d", &estudante.idade);
	
	printf("Matrícula: ");
	scanf("%d", &estudante.matricula);
	
	system("cls");
	
	printf("Dados do estudante:\n\nNome: %s\nIdade: %d\nMatrícula: %d\n\n", estudante.nome, estudante.idade, estudante.matricula);

	return 0;
}
