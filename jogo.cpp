#include <iostream>
#include <time.h>
#include "jogo.h"

using namespace std;

// Construtor
Jogo::Jogo() {
	int i, j;

	for (i=0; i<3; i++)
		for(j=0; j<3; j++)
			tabuleiro[i][j] = ' ';
	jogadas = 0;
	srand(time(NULL));		// inicializa semente para sorteio
	if (rand() % 2 == 0)	jogador = 'X';
	else	jogador = 'O';
}

// Função: verificar se o jogo terminou
bool Jogo::terminou() {
	if (jogadas < 9 && verifica_vencedor() == ' ')
		return false;
	else
		return true;
}

// Função: verificar o vencedor
char Jogo::verifica_vencedor() {

	// verifica as linhas
	if(tabuleiro[0][0] == jogador && tabuleiro[0][1] == jogador && tabuleiro[0][2] == jogador) return jogador;
	else if(tabuleiro[1][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[1][2] == jogador) return jogador;
	else if(tabuleiro[2][0] == jogador && tabuleiro[2][1] == jogador && tabuleiro[2][2] == jogador) return jogador;
	// verifica as colunas
	else if(tabuleiro[0][0] == jogador && tabuleiro[1][0] == jogador && tabuleiro[2][0] == jogador) return jogador;
	else if(tabuleiro[0][1] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][1] == jogador) return jogador;
	else if(tabuleiro[0][2] == jogador && tabuleiro[1][2] == jogador && tabuleiro[2][2] == jogador) return jogador;
	// verifica a diagonal principal
	else if(tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) return jogador;
	// verifica a diagonal secundária
	else if(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) return jogador;
	else return ' ';
}

// Função: verificar se a jogada é válida
bool Jogo::posiciona_peca(int x, int y) {
	if (x>=0 && x<3 && y>=0 && y<3 && tabuleiro[x][y] == ' ') {
		tabuleiro[x][y] = jogador;
		jogadas++;
		return true;
	} else {
		cout << "Jogada Invalida. Jogue novamente.";
		return false;	
	}
}

// Função: lógica do jogo
void Jogo::jogar() {
		int i, posX, posY;

		while(terminou() == false) {
			do {
				cout << "Jogada: " << jogadas+1 << endl << endl;
				desenha_tabuleiro();
				cout << endl << endl;

				cout << "Jogador: " << jogador << endl;
				cout << "Linha: ";
				cin >> posX;
				cout << "Coluna: ";
				cin >> posY;
				cout << endl << endl;
			} while(posiciona_peca(posX, posY) == false);

			// caso não haja vencedor, é a vez do outro jogador
			if (terminou() == false) {
				troca_jogador();
				system("pause");
				limpa_tela();
			}
		}

		// anuncio do vencedor
		cout << endl << endl;
		desenha_tabuleiro();
		cout << endl << endl;
		cout << "Vencedor: " << verifica_vencedor() << endl << endl;

}


// Função: limpar a tela
void Jogo::limpa_tela() {
	system("cls");
}

// Função: trocar o jogador
void Jogo::troca_jogador() {
	if (jogador == 'X') {
		jogador = 'O';
	}
	else jogador = 'X';
}

// Função: desenhar o tabuleiro
void Jogo::desenha_tabuleiro() {
			cout << "  " << tabuleiro[0][0] << " | " << tabuleiro[0][1] << " | " << tabuleiro[0][2] << "\n";
			cout << " -----------\n";
			cout << "  " << tabuleiro[1][0] << " | " << tabuleiro[1][1] << " | " << tabuleiro[1][2] << "\n";
			cout << " -----------\n";
			cout << "  " << tabuleiro[2][0] << " | " << tabuleiro[2][1] << " | " << tabuleiro[2][2] << "\n";
}
