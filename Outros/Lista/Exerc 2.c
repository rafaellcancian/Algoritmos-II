/*/
2. Ler	uma	string	e	chamar	uma	função	para realizar	a	sua	inversão dentro	da	mesma	string.		Mostrar	a	string	
invertida.
/*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void Inverter();

void Inverter(char palavra[100]) {
	int i;

	printf("\n");

	for (i = strlen(palavra) - 1; i >= 0; i--) {
		printf("%c", palavra[i]);
	}

	printf("\n\n\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	char palavra[100];

	printf("Digite uma palavra: ");
	scanf("%[^\n]s", palavra);

	Inverter(palavra);

	system("pause");
	return 0;
}