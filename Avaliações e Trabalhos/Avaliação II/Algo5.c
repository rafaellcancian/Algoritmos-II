#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE *arquivo;

int Contar();

int Contar() {
	int contador=0;
	char c;
	
	arquivo = fopen("Texto.txt", "r");
	
	do {
		c = fgetc(arquivo);
		
		if ((c == 'A') || (c == 'a')) {
			contador++;
		}
	} while (c != EOF);
	
	fclose(arquivo);
	
	return contador;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char texto[100];
	
	printf("Digite um texto: ");
	scanf("%[^\n]s", texto);

	arquivo = fopen("Texto.txt", "w");
	
	fputs(texto, arquivo);
	
	fclose(arquivo);
	
	printf("\nO número de vezes que os caracteres \"A\" e \"a\" aparecem no arquivo é: %d\n\n", Contar());

	return 0;
}
