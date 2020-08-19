/*/
4. Ler	uma	palavra	e	uma letra	qualquer.	Usar	uma	função	para	mostrar	a	palavra	cortada	na	primeira	posição	
em	que	a	letra	informada for	encontrada	na	palavra.	A	função	main	deve	exibir	a	nova	string.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Cortar(char palavra[100], char letra);

void Cortar(char palavra[100], char letra) {
	int i;

	printf("\n");

	for (i = 0; palavra[i] != letra; i++) {
		printf("%c", palavra[i]);
	}

	printf("\n\n\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	char palavra[100],letra;

	printf("Digite uma palavra: ");
	scanf("%[^\n]s", palavra);
	fflush(stdin);
	printf("Digite uma letra: ");
	scanf("%c", &letra);

	Cortar(palavra,letra);

	system("pause");
	return 0;
}