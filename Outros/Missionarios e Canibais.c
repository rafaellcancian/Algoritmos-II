#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Separador(),Esquerda(),Direita(),Condicoes(),Final();
int main(),Exibir();

struct Missionarios {
	int esquerda,direita;
}missionarios;

struct Canibais {
	int esquerda,direita;
}canibais;

struct Barco {
	int missionarios,canibais,total;
	char *posicao;
}barco;

int bloqueador=0,contador,mincontador=0;

void Separador() {
	int i;
	
	for (i = 1;i <= 50; i++) {
		printf("=");
	}
}

int Exibir() {	
	int menu;
	
	Separador();
	printf("\nLado esquerdo:\t\tLado direito:\n\nMission�rios: %d\t\tMission�rios: %d\nCanibais: %d\t\tCanibais: %d\n\n", missionarios.esquerda,missionarios.direita,canibais.esquerda,canibais.direita);
	Separador();
	printf("\nBarco:\n\nMission�rios: %d\nCanibais: %d\n\nPosi��o do barco: %s\n\nMovimentos: %d\n", barco.missionarios,barco.canibais,barco.posicao,contador);
	if (mincontador != 0) {
		printf("Recorde: %d\n", mincontador);
	}
	printf("\n");
	Separador();
	printf("\nVoc� quer mover um?\n[1] Mission�rio\n[2] Canibal\n\n[3] Mover\n\nResposta: ");
	scanf("%d", &menu);
	
	return menu;
}

void Esquerda(int menu) {
	switch (menu) {
		case 1: {
			if (barco.total < 2) {
				if (missionarios.esquerda > 0) {
					missionarios.esquerda--;
					barco.missionarios++;
				}
				else {
					system("cls");
					printf("AVISO: N�o h� mais mission�rios na esquerda.\n\n");
					main();
				}
			}
			else {
				system("cls");
				printf("AVISO: O barco est� cheio.\n\n");
				main();
			}
			break;
		}
		case 2: {
			if (barco.total < 2) {
				if (canibais.esquerda > 0) {
					canibais.esquerda--;
					barco.canibais++;
				}
				else {
					system("cls");
					printf("AVISO: N�o h� mais canibais na esquerda.\n\n");
					main();
				}
			}
			else {
				system("cls");
				printf("AVISO: O barco est� cheio.\n\n");
				main();
			}
			break;
		}
		case 3: {
			if (barco.total != 0) {
				if ((barco.missionarios == 1) && (barco.canibais == 1)) {
					missionarios.direita++;
					canibais.direita++;
				}
				else if (barco.missionarios == 2) {
					missionarios.direita = missionarios.direita + 2;
				}
				else if (barco.canibais == 2) {
					canibais.direita = canibais.direita + 2;
				}
				else if (barco.missionarios == 1) {
					missionarios.direita++;
				}
				else if (barco.canibais == 1) {
					canibais.direita++;
				}
				barco.missionarios=0,barco.canibais=0,barco.total=0;
				barco.posicao="Direita";
			}
			else {
				system("cls");
				printf("AVISO: N�o h� ningu�m no barco.\n\n");
				main();
			}
			contador++;
			Condicoes();
			break;
		}
		default: {
			system("cls");
			printf("AVISO: O valor inserido � inv�lido.\n\n");
			main();		
			break;
		}
	}

	barco.total = barco.missionarios + barco.canibais;
	
	system("cls");
	main();
}

void Direita(int menu) {
	switch (menu) {
		case 1: {
			if (barco.total < 2) {
				if (missionarios.direita > 0) {
					missionarios.direita--;
					barco.missionarios++;
				}
				else {
					system("cls");
					printf("AVISO: N�o h� mais mission�rios na direita.\n\n");
					main();
				}
			}
			else {
				system("cls");
				printf("AVISO: O barco est� cheio.\n\n");
				main();
			}
			break;
		}
		case 2: {
			if (barco.total < 2) {
				if (canibais.direita > 0) {
					canibais.direita--;
					barco.canibais++;
				}
				else {
					system("cls");
					printf("AVISO: N�o h� mais canibais na direita.\n\n");
					main();
				}
			}
			else {
				system("cls");
				printf("AVISO: O barco est� cheio.\n\n");
				main();
			}
			break;
		}
		case 3: {
			if (barco.total != 0) {
				if ((barco.missionarios == 1) && (barco.canibais == 1)) {
					missionarios.esquerda++;
					canibais.esquerda++;
				}
				else if (barco.missionarios == 2) {
					missionarios.esquerda = missionarios.esquerda + 2;
				}
				else if (barco.canibais == 2) {
					canibais.esquerda = canibais.esquerda + 2;
				}
				else if (barco.missionarios == 1) {
					missionarios.esquerda++;
				}
				else if (barco.canibais == 1) {
					canibais.esquerda++;
				}
				barco.missionarios=0,barco.canibais=0,barco.total=0;
				barco.posicao="Esquerda";
			}
			else {
				system("cls");
				printf("AVISO: N�o h� ningu�m no barco.\n\n");
				main();			
			}
			contador++;
			Condicoes();
			break;
		}
		default: {
			system("cls");
			printf("AVISO: O valor inserido � inv�lido.\n\n");
			main();		
			break;
		}
	}

	barco.total = barco.missionarios + barco.canibais;
	
	system("cls");
	main();
}

void Condicoes() {
	if ((missionarios.direita == 3) && (canibais.direita == 3)) {
		system("cls");
		printf("Parab�ns, voc� ganhou!\n\nMovimentos: %d\n\n", contador);
		
		if (mincontador == 0) {
			mincontador = contador;
		}
		else if (contador < mincontador) {
			mincontador = contador;
		}
		Separador();
		Final();
	}
	if ((missionarios.direita != 0) && (canibais.direita != 0)) {
		if (missionarios.direita < canibais.direita) {
			system("cls");
			printf("Infelizmente voc� perdeu.\n\nMovimentos: %d\n\n", contador);
			Separador();
			Final();
		}
	}
	if ((missionarios.esquerda != 0) && (canibais.esquerda != 0)) {
		if (missionarios.esquerda < canibais.esquerda) {
			system("cls");
			printf("Infelizmente voc� perdeu.\n\nMovimentos: %d\n\n", contador);
			Separador();
			Final();
		}
	}
	system("cls");
	main();
}

void Final() {
	int resposta;
	
	printf("\nVoc� quer?\n[1] Jogar novamente\n[2] Sair\n\nResposta: ");
	scanf("%d", &resposta);
	
	switch (resposta) {
		case 1: {
			system("cls");
			bloqueador=0;
			main(); 
			break;
		}
		case 2: {
			exit(0);
			break;
		}
		default: {
			system("cls"); 
			printf("AVISO: O valor inserido � inv�lido.\n\n");
			Final();
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int menu;
	
	if (bloqueador == 0) {
		Separador();
		printf("\nTrabalho de Algoritmos II\n\nJogo desenvolvido por: Rafael Londero Cancian\n\n\nComo jogar Mission�rios e Canibais?\n\nOs mission�rios n�o podem ficar em menor n�mero, em qualquer uma das margens, ou os canibais os devorar�o.\n\n");
		Separador();
		printf("\n\n");
		system("pause");
		system("cls");
		
		missionarios.esquerda=3,missionarios.direita=0;
		canibais.esquerda=3,canibais.direita=0;
		barco.missionarios=0,barco.canibais=0,barco.total=0;
		barco.posicao="Esquerda";
		contador=0;
		
		bloqueador++;
	}

	menu = Exibir();
	
	if (barco.posicao == "Esquerda") {
		Esquerda(menu);
	}
	else {
		Direita(menu);
	}

	return 0;
}
