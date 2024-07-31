#include"diamante.h"

using namespace std;

Diamante::Diamante() {						 // construtor
	diamante_size = 32;								//tamanho do diamante
	diamante = al_load_bitmap("imagens/diamante2.png");
}

Diamante::~Diamante() {
	
	al_destroy_bitmap(diamante);

}

ALLEGRO_BITMAP* Diamante::get_diamante()
{
	return diamante;
}
void Diamante::imprime_diamante(float linha, float coluna)
{
	al_draw_bitmap(diamante, linha *32, coluna*32, 0);
}