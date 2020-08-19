#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

FILE *sensores;

void Exibir() {
	char exibir;
	
	sensores = fopen("Sensores.txt", "r");

	if (sensores == NULL) {
		printf("ERRO: O arquivo não existe.\n\n");
		Exibir();
	}
	
	printf("=== Sensores\n\n");
	
	do {
		exibir = fgetc(sensores);
		
		if (exibir != EOF) {
			printf("%c", exibir);
		}
	} while (exibir != EOF);
	
	fclose(sensores);

	sleep(1);
	system("cls");
	Exibir();
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	Exibir();

	return 0;
}