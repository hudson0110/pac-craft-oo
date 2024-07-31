#include "enderman.h"

using namespace std;

Enderman::Enderman() :mobs()
{
	PERSONAGEM_SIZE = 32;
	personagem_X = 448;
	personagem_Y = 448;
}
Enderman::~Enderman()
{

}
void Enderman::imprime_enderman(ALLEGRO_BITMAP* enderman)
{
	al_draw_bitmap(enderman, get_pesonagemX(), get_pesonagemY(), 0);
}


/*   testes    


void Enderman::teleporta_enderman(vector<vector<char>>& mapa)
{
	if () {

	}

}

 */


