/*/
9. Criar um arquivo “texto” que armazena um texto digitado pelo usuário. Posteriormente, apresente ao
usuário o número de vezes que os caracteres “A” e “a” aparecem no arquivo.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE *arquivo;

void Criar(),Ler();

void Criar() {
	char texto[100];

	printf("Digite uma frase: ");
	scanf("%[^\n]s", texto);
	fflush(stdin);

	arquivo = fopen("Texto.txt", "w");

	fputs(texto, arquivo);

	fclose(arquivo);

	Ler();
}

void Ler() {
	int contador=0;
	char exibir;

	arquivo = fopen("Texto.txt", "r");

	do {
		exibir = fgetc(arquivo);
		
		if ((exibir == 'A') || (exibir == 'a')) {
			contador++;
		}
	} while (exibir != EOF);

	fclose(arquivo);

	printf("\nO número de vezes que os caracteres \"A\" e \"a\" apareceram no arquivo é: %d\n\n\n", contador);
	system("pause");
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	Criar();

	return 0;
}