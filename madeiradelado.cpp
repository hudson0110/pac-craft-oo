#include"madeiradelado.h"

using namespace std;


Madeiradelado::Madeiradelado() {
	madeiradelado_size = 32;
	madeiradelado = al_load_bitmap("imagens/madeiradelado.png");

}

Madeiradelado::~Madeiradelado() {
	
	al_destroy_bitmap(madeiradelado);
}
ALLEGRO_BITMAP* Madeiradelado::get_madeiradelado()
{
	return madeiradelado;
}
void Madeiradelado::imprime_madeiradelado(float linha, float coluna)
{
	al_draw_bitmap(madeiradelado, linha * 32, coluna * 32, 0);
}