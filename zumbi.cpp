#include "zumbi.h"

zumbi::zumbi()
{
	personagem_X = 448;
	personagem_Y = 448;
}

zumbi::~zumbi()
{
}

void zumbi::imprime_zumbi(ALLEGRO_BITMAP* img)
{
	al_draw_bitmap(img, get_pesonagemX(), get_pesonagemY(), 0);
}
void zumbi::move_zumbi(vector < vector < char >>& mapa) {


}