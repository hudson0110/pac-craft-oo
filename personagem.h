#ifndef personagem_H
#define personagem_H


#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <math.h>
#include<iostream>
#include <vector>

using namespace std;

class personagem
{
public:
	personagem();
	~personagem();
	float get_tuada();
	int get_personagem_size();
	float get_pesonagemX();
	float get_pesonagemY();
	void set_pesonagemX(float);
	void set_pesonagemY(float);
	void checa_movimento(vector < vector < char >> &mapa, int direcao_pac);
	bool checar_posicao_pra_cima(vector < vector < char >> &mapa);
	bool checar_posicao_pra_baixo(vector < vector < char >> &mapa);
	bool checar_posicao_pra_esquerda(vector < vector < char >> &mapa);
	bool checar_posicao_pra_direita(vector < vector < char >> &mapa);
	void conversao();
	void move_personagem(vector < vector < char >> &mapa);
	int posicao_convertida_x();
	int posicao_convertida_y();

protected:
	ALLEGRO_BITMAP* steve;                                                 //cria o steve
	int PERSONAGEM_SIZE;                                                   //tamanho de personagem
	float tuada;                                                           //velocidade do grande steve
	float personagem_X;//SCREEN_W / 2.0 - steve_SIZE / 2.0;                     //nascimento do grande steve em x
	float personagem_Y;//SCREEN_H / 2.0 - steve_SIZE / 2.0;                     //nascimento do grande steve em y

	bool movendo_cima;
	bool movendo_baixo;
	bool movendo_esquerda;
	bool movendo_direita;

	int personagemYConvertido;
	int personagemXConvertido;
	int colYCollisionUp;
	int colXCollisionUp;
	int colYCollisionLeft;
	int colXCollisionLeft;
	int colYCollisionRight;
	int colXCollisionRight;
	int colYCollisionBottom;
	int colXCollisionBottom;

	int colYCollisionUpNext;
	int colXCollisionUpNext;

	int colYCollisionLeftNext;
	int colXCollisionLeftNext;

	int colYCollisionRightNext;
	int colXCollisionRightNext;	

	int colYCollisionBottomNext;
	int colXCollisionBottomNext;



};



#endif // !STEVE_H

