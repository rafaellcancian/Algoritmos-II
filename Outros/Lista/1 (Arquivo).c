#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *arquivo;

	int i;
	char string[100],exibir;

	arquivo = fopen("Temp.txt", "w");

	printf("Digite o nome: ");
	scanf("%[^\n]s", string);
	fputs(string,arquivo);
	printf("\n");
	
	fclose(arquivo);

	arquivo = fopen("Temp.txt", "r");

	do {
		exibir = fgetc(arquivo);
		
		if (exibir != EOF) {
			printf("%c\n", exibir);
		}
	} while (exibir != EOF);

	fclose(arquivo);

	printf("\n\n");

	system("pause");
	return 0;
}