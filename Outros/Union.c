#include <stdio.h>
#include <locale.h>

union Pessoa {
	char cpf[15],cnpj[19];
}pessoa;

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	printf("Tamanho da union: %li\n\n", sizeof(pessoa));
	
	printf("Digite o CPF: ");
	scanf("%s", pessoa.cpf);
	printf("Digite o CNPJ: ");
	scanf("%s", pessoa.cnpj);
	
	printf("\nCPF: %s\nCNPJ: %s\n", pessoa.cpf, pessoa.cnpj);
	
	return 0;
}
