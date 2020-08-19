/*/
1. Ler	uma	string	e	chamar	uma	função	para	contar	quantos	caracteres	possui. A	main	deve	exibir	a	quantidade	
de	caracteres.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void Contar();

void Contar(char palavra[100]) {
	printf("\nA palavra \"%s\" contém %d caracteres.\n\n\n", palavra, strlen(palavra));
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	char palavra[100];

	printf("Digite uma palavra: ");
	scanf("%[^\n]s", palavra);

	Contar(palavra);

	system("pause");
	return 0;
}