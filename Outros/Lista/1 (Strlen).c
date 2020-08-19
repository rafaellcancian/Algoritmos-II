#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i;
	char palavra[100];

	printf("Digite uma palavra: ");
	scanf("%[^\n]s", palavra);

	printf("\n");

	for (i = 0; i < strlen(palavra); i++) {
		printf("%c\n", palavra[i]);
	}

	printf("\n\n");

	system("pause");
	return 0;
}