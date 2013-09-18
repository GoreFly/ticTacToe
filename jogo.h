class Jogo {
private:
	char tabuleiro[3][3];		// armazena jogadores
	int jogadas;		// controle total de jogadas
	char jogador;		// controla de quem é a vez
public:
	Jogo();								// inicializa o jogo
	bool terminou();					// jogo terminou?
	char verifica_vencedor();			// quem venceu?
	bool posiciona_peca(int, int);		// posicionar peça
	void jogar();						// inicia o jogo
	void limpa_tela();					// limpa a tela
	void troca_jogador();				// troca jogador
	void desenha_tabuleiro();			// desenha tabuleiro
};
