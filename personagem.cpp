#include"personagem.h"

using namespace std;

personagem::personagem()
{
	PERSONAGEM_SIZE = 32;                                                   //tamanho de steve

	tuada = 2.0;                                                             //maximo 8 se nao buga
	personagem_X = 0;                                                           //nascimento do grande steve em x
	personagem_Y = 0;                                                           //nascimento do grande steve em y
    movendo_cima = false;
    movendo_baixo = false;
    movendo_esquerda = false;
    movendo_direita = false;
    
    personagemYConvertido = 0;
    personagemXConvertido = 0;

    colYCollisionUp = 0;
    colXCollisionUp = 0;
   

    colYCollisionLeft = 0;
    colXCollisionLeft = 0;
 

    colYCollisionRight = 0;
    colXCollisionRight = 0;
   

    colYCollisionBottom = 0;
    colXCollisionBottom = 0;

    colYCollisionUpNext = 0;
    colXCollisionUpNext = 0;

    colYCollisionLeftNext = 0;
    colXCollisionLeftNext = 0;

    colYCollisionRightNext = 0;
    colXCollisionRightNext = 0;

    colYCollisionBottomNext = 0;
    colXCollisionBottomNext = 0;
   
}

personagem::~personagem()
{
	al_destroy_bitmap(steve);
}

float personagem::get_tuada() {
	return tuada;
}

int personagem::get_personagem_size() {
	return PERSONAGEM_SIZE;
}

float personagem::get_pesonagemX()
{
	return personagem_X;
}

float personagem::get_pesonagemY()
{
	return personagem_Y;
}

void personagem::set_pesonagemX(float eixoX)
{
	personagem_X = eixoX;
}

void personagem::set_pesonagemY(float eixoY)
{
	personagem_Y = eixoY;
}

void personagem::checa_movimento(vector < vector < char >>& mapa, int direcao_pac)
{
    if (direcao_pac == ALLEGRO_KEY_A && checar_posicao_pra_esquerda(mapa)) {
         movendo_cima=false;
         movendo_baixo=false;
         movendo_esquerda  = true;
         movendo_direita=false;
    }
    if (direcao_pac == ALLEGRO_KEY_D && checar_posicao_pra_direita(mapa)) {
        movendo_cima = false;
        movendo_baixo = false;
        movendo_esquerda =false;
        movendo_direita = true;
    }
    if (direcao_pac == ALLEGRO_KEY_W && checar_posicao_pra_cima(mapa)) {
        movendo_cima = true;
        movendo_baixo = false;
        movendo_esquerda = false;
        movendo_direita = false;
    }
    if (direcao_pac == ALLEGRO_KEY_S && checar_posicao_pra_baixo(mapa)) {
        movendo_cima = false;
        movendo_baixo = true;
        movendo_esquerda = false;
        movendo_direita = false;
    }
}

bool personagem::checar_posicao_pra_cima(vector < vector < char >> &mapa)
{
    return mapa[colYCollisionUp - 1][colXCollisionUp] != '1' && mapa[colYCollisionUp - 1][colXCollisionUp] != '3' && mapa[colYCollisionUp - 1][colXCollisionUp] != '4' && mapa[colYCollisionUpNext - 1][colXCollisionUpNext] != '1' && mapa[colYCollisionUpNext - 1][colXCollisionUpNext] != '3' && mapa[colYCollisionUpNext - 1][colXCollisionUpNext] != '4';
}

bool personagem::checar_posicao_pra_baixo(vector < vector < char >> &mapa)
{
    return mapa[colYCollisionBottom + 1][colXCollisionBottom] != '1' && mapa[colYCollisionBottom + 1][colXCollisionBottom] != '3' && mapa[colYCollisionBottom + 1][colXCollisionBottom] != '4' && mapa[colYCollisionBottomNext + 1][colXCollisionBottomNext] != '1' && mapa[colYCollisionBottomNext + 1][colXCollisionBottomNext] != '3' && mapa[colYCollisionBottomNext + 1][colXCollisionBottomNext] != '4';
}

bool personagem::checar_posicao_pra_esquerda(vector < vector < char >> &mapa)
{
	return mapa[colYCollisionLeft ][colXCollisionLeft - 1] != '1' && mapa[colYCollisionLeft ][colXCollisionLeft - 1] != '3' && mapa[colYCollisionLeft][colXCollisionLeft - 1] != '4' && mapa[colYCollisionLeftNext][colXCollisionLeftNext - 1] != '1' && mapa[colYCollisionLeftNext][colXCollisionLeftNext - 1] != '3' && mapa[colYCollisionLeftNext][colXCollisionLeftNext - 1] != '4';
}

bool personagem::checar_posicao_pra_direita(vector < vector < char >> &mapa)
{
    return  mapa[colYCollisionRight][colXCollisionRight + 1] != '1' && mapa[colYCollisionRight][colXCollisionRight + 1] != '3' && mapa[colYCollisionRight][colXCollisionRight + 1] != '4' && mapa[colYCollisionRightNext][colXCollisionRightNext + 1] != '1' && mapa[colYCollisionRightNext][colXCollisionRightNext + 1] != '3' && mapa[colYCollisionRightNext][colXCollisionRightNext + 1] != '4';
}

void personagem::conversao()
{
    personagemYConvertido = get_pesonagemY() / PERSONAGEM_SIZE;
    personagemXConvertido = get_pesonagemX() / PERSONAGEM_SIZE;

    colYCollisionUp = ceil(get_pesonagemY() / PERSONAGEM_SIZE);
    colXCollisionUp = get_pesonagemX() / PERSONAGEM_SIZE;
    colYCollisionUpNext = ceil(get_pesonagemY() / PERSONAGEM_SIZE);
    colXCollisionUpNext = ceil(get_pesonagemX() / PERSONAGEM_SIZE);

    colYCollisionLeft = ceil(get_pesonagemY() / PERSONAGEM_SIZE);
    colXCollisionLeft = ceil(get_pesonagemX() / PERSONAGEM_SIZE);
    colYCollisionLeftNext = get_pesonagemY() / PERSONAGEM_SIZE;
    colXCollisionLeftNext = ceil(get_pesonagemX() / PERSONAGEM_SIZE);

    colYCollisionRight = ceil(get_pesonagemY() / PERSONAGEM_SIZE);
    colXCollisionRight = get_pesonagemX() / PERSONAGEM_SIZE;
    colYCollisionRightNext = get_pesonagemY() / PERSONAGEM_SIZE;
    colXCollisionRightNext = get_pesonagemX() / PERSONAGEM_SIZE;

    colYCollisionBottom = get_pesonagemY() / PERSONAGEM_SIZE;
    colXCollisionBottom = ceil(get_pesonagemX() / PERSONAGEM_SIZE);
    colYCollisionBottomNext = get_pesonagemY() / PERSONAGEM_SIZE;
    colXCollisionBottomNext = get_pesonagemX() / PERSONAGEM_SIZE;
}

void personagem::move_personagem(vector < vector < char >> &mapa)
{
    if(movendo_cima && checar_posicao_pra_cima(mapa)){
        set_pesonagemY( get_pesonagemY() -  get_tuada());
    }
    else {
        movendo_cima = false;
    }
    if (movendo_baixo && checar_posicao_pra_baixo(mapa)) {
         set_pesonagemY( get_pesonagemY() +  get_tuada());
    }
    else {
        movendo_baixo = false;
    }
    if (movendo_direita && checar_posicao_pra_direita(mapa)) {
         set_pesonagemX( get_pesonagemX() +  get_tuada());
    }
    else {
        movendo_direita = false;
    }
    if (movendo_esquerda && checar_posicao_pra_esquerda(mapa)) {
         set_pesonagemX( get_pesonagemX() -  get_tuada());
    }
    else {
        movendo_esquerda = false;
    }
    conversao();
}

int personagem::posicao_convertida_x()
{
    return personagemXConvertido;
}

int personagem::posicao_convertida_y()
{
    return personagemYConvertido;
}

