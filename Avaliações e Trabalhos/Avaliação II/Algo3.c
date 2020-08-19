#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Exibir(char palavra[100], char letra);

void Exibir(char palavra[100], char letra) {
	int i;
	
	printf("\n");
	
	for (i = 0; palavra[i] != letra; i++) {
		printf("%c", palavra[i]);
		
		if (palavra[i + 1] == letra) {
			printf("%c", palavra[i + 1]);
		}
	}
	
	printf("\n\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	char palavra[100],letra;
	
	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	fflush(stdin);
	
	printf("Digite uma letra: ");
	scanf("%c", &letra);
	
	Exibir(palavra,letra);
	
	return 0;
}
