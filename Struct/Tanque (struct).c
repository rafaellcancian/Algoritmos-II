#include <stdio.h>
#include <locale.h>

struct Agua {
	char litros[100],temperatura[100],ph[100];
};

struct Tanque {
	char limite[100],material[100],formato[100];
	
	struct Agua agua;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	struct Tanque tanque;
	
	printf("Registro de informações de um tanque para armazenar água\n\nQuantos litros o tanque suporta?\nResposta[L]: ");
	scanf("%[^\n]s", tanque.limite);
	fflush(stdin);
	printf("\nQual o material do tanque?\nResposta: ");
	scanf("%[^\n]s", tanque.material);
	fflush(stdin);
	printf("\nQual o formato do tanque?\nResposta: ");
	scanf("%[^\n]s", tanque.formato);
	fflush(stdin);
	printf("\nQuantos litros tem o tanque?\nResposta[L]: ");
	scanf("%[^\n]s", tanque.agua.litros);
	fflush(stdin);	
	printf("\nQual a temperatura da água do tanque?\nResposta[°C]: ");
	scanf("%[^\n]s", tanque.agua.temperatura);
	fflush(stdin);
	printf("\nQual o ph da água do tanque?\nResposta[pH]: ");
	scanf("%[^\n]s", tanque.agua.ph);
	fflush(stdin);
	
	system("cls");
	printf("O tanque possui um limite de %sL, o material é %s, tem um formato %s, possui %sL de água, com uma de temperatura de %s°C e um pH de %s.\n", tanque.limite,tanque.material,tanque.formato,tanque.agua.litros,tanque.agua.temperatura,tanque.agua.ph);
	
	
	
	return 0;
}
