#include "esqueleto.h"

esqueleto::esqueleto():mobs()
{
	personagem_X = 448;
	personagem_Y = 448;
}

esqueleto::~esqueleto()
{
}

void esqueleto::imprime_esqueleto(ALLEGRO_BITMAP* img)
{
	al_draw_bitmap(img, get_pesonagemX(), get_pesonagemY(), 0);
}
