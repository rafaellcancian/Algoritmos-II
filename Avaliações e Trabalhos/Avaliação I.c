#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

float sensorCintoSeguranca();
void exibirMediaConsumo(float kmPercorridos, float litrosConsumidos);

typedef struct {
	char marca[30];
	int anoFabricacao;
}Veiculo;

float sensorCintoSeguranca() {
	float estado = rand() % 2;
	
	return estado;
}

void exibirMediaConsumo(float kmPercorridos, float litrosConsumidos) {
	float consumoCombustivel;
	
	consumoCombustivel = kmPercorridos / litrosConsumidos;
	
	printf("\n\nConsumo de combustível (em km/L): %.1f\n", consumoCombustivel);
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");

	Veiculo veiculo;
	
	printf("Digite a marca do veículo: ");
	scanf("%s", veiculo.marca);
	fflush(stdin);
	printf("\nDigite o ano de fabricação do veículo: ");
	scanf("%d", &veiculo.anoFabricacao);
	fflush(stdin);
	
	printf("\n\nInformações inseridas:\n\nMarca: %s\nAno de fabricação: %d", veiculo.marca,veiculo.anoFabricacao);
	
	if (sensorCintoSeguranca() == 0) {
		printf("\n\nATENÇÃO: O cinto de segurança precisa ser engatado.");
	}
	
	float kmPercorridos=180,litrosConsumidos=10;
	
	exibirMediaConsumo(kmPercorridos,litrosConsumidos);
	

	return 0;
}
