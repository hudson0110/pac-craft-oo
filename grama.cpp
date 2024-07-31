#include "grama.h"

using namespace std;

Grama::Grama() {
	grama_size = 32;
	grama = al_load_bitmap("imagens/grama.png");
}

Grama::~Grama()
{
	al_destroy_bitmap(grama);
}

ALLEGRO_BITMAP* Grama::get_grama()
{
	return grama;
}
void Grama::imprime_grama(float linha, float coluna)
{
	al_draw_bitmap(grama, linha * 32, coluna * 32, 0);

}