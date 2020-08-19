#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Gerar(),Ordenar(int numGerados[60]),Exibir(int numGerados[]),Final();

void Gerar() {
	int i,j,numGerados[60],erro;

    for (i = 0; i < 60; i++) {
		do {
			numGerados[i] = rand() % 60;
			erro = 0;
			for (j = 0; j < i; j++) {
				if (numGerados[i] == numGerados[j]) {
					erro = 1;
				}
			}
		} while (erro == 1);
	}
	
	Ordenar(numGerados);
}

void Ordenar(int numGerados[60]) {
	int i,j,k,vetortemp[6],temp;

	for (i = 0; i < 60; i++) {
		vetortemp[0] = numGerados[i];
		vetortemp[1] = numGerados[i+1];
		vetortemp[2] = numGerados[i+2];
		vetortemp[3] = numGerados[i+3];
		vetortemp[4] = numGerados[i+4];
		vetortemp[5] = numGerados[i+5];

		for (j = 0; j < 6; j++) {
	    	for (k = j + 1; k < 6; k++) {
	        	if (vetortemp[j] > vetortemp[k]) {
	            	temp = vetortemp[j];
	                vetortemp[j] = vetortemp[k];
	                vetortemp[k] = temp;
				}    	
			}
		}

		numGerados[i] = vetortemp[0];
		numGerados[i+1] = vetortemp[1];
		numGerados[i+2] = vetortemp[2];
		numGerados[i+3] = vetortemp[3];
		numGerados[i+4] = vetortemp[4];
		numGerados[i+5] = vetortemp[5];

		i = i + 5;
	}

	Exibir(numGerados);
}

void Exibir(int numGerados[]) {
	int i,numCartelas,ordemCartelas=1,erro=0;

	do {
		printf("[MEGA SENA SIMULATOR]\n\nDigite o número de cartelas: ");
		scanf("%d", &numCartelas);

		if ((numCartelas < 1) || (numCartelas > 10)) {
			erro=1;
			system("cls");
			printf("AVISO: O valor inserido é inválido.\n\n");
		}
		else {
			erro=0;
			system("cls");
		}
	} while(erro == 1);

	printf("[MEGA SENA SIMULATOR]\n\nO número de cartelas solicitado está sendo exibido abaixo:\n");

	for (i = 0; i < numCartelas * 6; i++) {
		printf("\n%dª Cartela: ", ordemCartelas);
		printf("%d - %d - %d - %d - %d - %d\n", numGerados[i], numGerados[i+1], numGerados[i+2], numGerados[i+3], numGerados[i+4], numGerados[i+5]);
		i = i + 5;
		ordemCartelas++;
	}

	printf("\n\n");
	Final();
}

void Final() {
	int resposta;

	printf("Você quer?\n[1] Gerar novamente\n[2] Sair\n\nResposta: ");
	scanf("%d", &resposta);
	
	switch (resposta) {
		case 1: {
			system("cls");
			main(); 
			break;
		}
		case 2: {
			exit(0);
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: O valor inserido é inválido.\n\n");
			Final();
			break;
		}
	}	
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");

	Gerar();

	return 0;
}