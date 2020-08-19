#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Temperatura();
void Emergencia();

struct Temperatura {
	int valor;
}temperatura;

int Temperatura() {
	temperatura.valor=rand() % 100;
	
	printf("Temperatura atual: %d°C\n", temperatura.valor);
	
	return temperatura.valor;
}

void Emergencia() {
	int menu;

	printf("\n\nA temperatura ultrapassou 80°C\n\n\nDigite 1 para desativar o alarme.\n\nResposta: ");
	scanf("%d", &menu);
	
	switch (menu) {
		case 1: {
			system("cls");
			main();
			break;
		}
		default: {
			system("cls");
			printf("AVISO: O valor inserido é inválido.\n");
			Emergencia();		
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	for(;;) {
		int temperatura = Temperatura();
		
		if (temperatura >= 80) {
			Emergencia();
		}
	}
	
	return 0;
}
