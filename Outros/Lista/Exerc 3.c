/*/
3. Ler	duas	palavras	e	usar	uma	 função	para	compará-las.	A	main	deve	informar	se	as	palavras	são	iguais ou	
diferentes.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void Comparar(char palavra1[100], char palavra2[100]);

void Comparar(char palavra1[100], char palavra2[100]) {
	int estado;

	estado = strcmp(palavra1,palavra2);

	if (estado == 0) {
		printf("\nAs palavras são iguais.\n\n\n");
	}
	else {
		printf("\n\n");
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	char palavra1[100],palavra2[100];

	printf("Digite a primeira palavra: ");
	scanf("%[^\n]s", palavra1);
	fflush(stdin);
	printf("Digite a segunda palavra: ");
	scanf("%[^\n]s", palavra2);

	Comparar(palavra1,palavra2);

	system("pause");
	return 0;
}