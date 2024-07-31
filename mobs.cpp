#include "Mobs.h"





mobs::mobs()
{
	tuada = 2.0;
	recebe_direcao = 0;
	PERSONAGEM_SIZE = 32;

}

mobs::~mobs()
{
}

void mobs::sorteia_direcao(vector<vector<char>>& mapa)
{
	bool pode_ir_pra_cima;
	bool pode_ir_pra_baixo;
	bool pode_ir_pra_esquerda;
	bool pode_ir_pra_direita;

	if (checar_posicao_pra_cima(mapa)) {
		pode_ir_pra_cima = true;
	}
	else {
		pode_ir_pra_cima = false;
	}
	if (checar_posicao_pra_baixo(mapa)) {
		pode_ir_pra_baixo = true;
	}
	else {
		pode_ir_pra_baixo = false;
	}
	if (checar_posicao_pra_esquerda(mapa)) {
		pode_ir_pra_esquerda = true;
	}
	else {
		pode_ir_pra_esquerda = false;
	}
	if (checar_posicao_pra_direita(mapa)) {
		pode_ir_pra_direita = true;
	}
	else {
		pode_ir_pra_direita = false;
	}

	if (pode_ir_pra_cima && !pode_ir_pra_baixo && !pode_ir_pra_direita && !pode_ir_pra_esquerda) {

		checa_movimento(mapa, ALLEGRO_KEY_W);
	}

	if (!pode_ir_pra_cima && pode_ir_pra_baixo && !pode_ir_pra_direita && !pode_ir_pra_esquerda) {

		checa_movimento(mapa, ALLEGRO_KEY_S);
	}
	if (!pode_ir_pra_cima && !pode_ir_pra_baixo && pode_ir_pra_direita && !pode_ir_pra_esquerda) {

		checa_movimento(mapa, ALLEGRO_KEY_D);
	}
	if (!pode_ir_pra_cima && !pode_ir_pra_baixo && !pode_ir_pra_direita && pode_ir_pra_esquerda) {

		checa_movimento(mapa, ALLEGRO_KEY_A);
	}

	if (pode_ir_pra_cima && pode_ir_pra_esquerda) {
		recebe_direcao = rand() % 2;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
		else {
				checa_movimento(mapa, ALLEGRO_KEY_A);
		}
	}
	if (pode_ir_pra_cima && pode_ir_pra_baixo) {
		recebe_direcao = rand() % 2;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_S);
		}
	}
	if (pode_ir_pra_cima && pode_ir_pra_direita) {
		recebe_direcao = rand() % 2;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_D);
		}
	}
	if (pode_ir_pra_baixo && pode_ir_pra_esquerda) {
		recebe_direcao = rand() % 2;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_S);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_A);
		}
	}
	if (pode_ir_pra_baixo && pode_ir_pra_direita) {
		recebe_direcao = rand() % 2;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_S);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_D);
		}
	}
	if (pode_ir_pra_esquerda && pode_ir_pra_direita) {
		recebe_direcao = rand() % 2;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_A);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_D);
		}
	}
	if (pode_ir_pra_cima && pode_ir_pra_esquerda && pode_ir_pra_direita){
		recebe_direcao = rand() % 3;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
		else if(recebe_direcao == 1) {
			checa_movimento(mapa, ALLEGRO_KEY_A);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_D);

		}
	}
	if (pode_ir_pra_cima && pode_ir_pra_esquerda && pode_ir_pra_baixo){
		recebe_direcao = rand() % 3;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
		else if (recebe_direcao == 1) {
			checa_movimento(mapa, ALLEGRO_KEY_A);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_S);

		}
	}
	if (pode_ir_pra_cima && pode_ir_pra_direita && pode_ir_pra_baixo){
		recebe_direcao = rand() % 3;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
		else if (recebe_direcao == 1) {
			checa_movimento(mapa, ALLEGRO_KEY_D);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_S);

		}
	}
	if (pode_ir_pra_baixo && pode_ir_pra_esquerda && pode_ir_pra_direita) {
		recebe_direcao = rand() % 3;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_S);
		}
		else if (recebe_direcao == 1) {
			checa_movimento(mapa, ALLEGRO_KEY_A);
		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_D);

		}
	}
	if (pode_ir_pra_baixo && pode_ir_pra_esquerda && pode_ir_pra_direita && pode_ir_pra_cima) {
		recebe_direcao = rand() % 4;
		if (recebe_direcao == 0) {
			checa_movimento(mapa, ALLEGRO_KEY_S);
		}
		else if (recebe_direcao == 1) {
			checa_movimento(mapa, ALLEGRO_KEY_A);
		}
		else if(recebe_direcao == 2) {
			checa_movimento(mapa, ALLEGRO_KEY_D);

		}
		else {
			checa_movimento(mapa, ALLEGRO_KEY_W);
		}
	}
}

void mobs::movimento_aleatorio(vector<vector<char>>& mapa)
{
	bool esta_andando;

	if (movendo_cima || movendo_baixo || movendo_direita || movendo_esquerda) {
		esta_andando = true;
	}
	else {
		esta_andando = false;
	}


	if (esta_andando && checar_posicao_pra_cima(mapa) && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_esquerda(mapa) && checar_posicao_pra_direita(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_cima(mapa) && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_esquerda(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_cima(mapa) && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_direita(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_cima(mapa) && checar_posicao_pra_direita(mapa) && checar_posicao_pra_esquerda(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_esquerda(mapa) && checar_posicao_pra_direita(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_esquerda(mapa) && checar_posicao_pra_cima(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_direita(mapa) && checar_posicao_pra_cima(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_cima(mapa) && checar_posicao_pra_esquerda(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_cima(mapa) && checar_posicao_pra_direita(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_esquerda(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando && checar_posicao_pra_baixo(mapa) && checar_posicao_pra_direita(mapa)) {
		sorteia_direcao(mapa);
	}
	if (esta_andando) {
		move_personagem(mapa);
	}
	else {
		sorteia_direcao(mapa);
	}
}

