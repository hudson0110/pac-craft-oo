#include"madeira.h"

using namespace std;


Madeira::Madeira(){
	madeira_size = 32;
	madeira = al_load_bitmap("imagens/madeiradecima.png");

}

Madeira::~Madeira(){
	
	al_destroy_bitmap(madeira);
}
ALLEGRO_BITMAP* Madeira::get_madeira()
{
	return madeira;
}
void Madeira::imprime_madeira(float linha, float coluna)
{
	al_draw_bitmap(madeira, linha * 32, coluna * 32, 0);
}
