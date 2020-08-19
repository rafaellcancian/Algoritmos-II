#include <stdio.h>
#include <locale.h>

struct Cadastro {
	char nome[20];
	int idade;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
	struct Cadastro cadastro;
	
	printf("Trabalhando com estruturas\n\n");

	printf("Digite o nome: ");
	scanf("%s", cadastro.nome);
	fflush(stdin);
	
	printf("\nDigite a idade: ");
	scanf("%d", &cadastro.idade);
	
	printf("\n\nDados informados:\nNome: %s\nIdade: %d\n", cadastro.nome, cadastro.idade);
	
	return 0;
}
