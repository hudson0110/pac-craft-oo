#include "tabua.h"

using namespace std;

Tabua::Tabua(){
	tabua_size = 32;
	tabua = al_load_bitmap("imagens/tabua.png");
}

Tabua::~Tabua()
{
	al_destroy_bitmap(tabua);
}

ALLEGRO_BITMAP* Tabua::get_tabua() {
	return tabua;
}
void Tabua::imprime_tabua(float linha, float coluna)
{
	al_draw_bitmap(tabua, linha * 32, coluna * 32, 0);
}