#include <iostream>
#include "jogo.h"

using namespace std;

int main() {
	// declaração de variáveis
	char jogar;

	// execução do programa
	do {
		// criação de uma nova instância do jogo
		Jogo ticTacToe;

		// execução da lógica do jogo
		ticTacToe.jogar();
		
		// verificação de se o jogador deseja jogar novamente
		cout << "  Deseja jogar novamente? (Y/N) " << endl;
		cout << " --> ";
		cin >> jogar;

		ticTacToe.limpa_tela();
	} while(jogar == 'Y' || jogar == 'y');

	system("pause");
	EXIT_SUCCESS;
}
