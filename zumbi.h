#pragma once
#include "Mobs.h"
class zumbi : public mobs
{
public:
	zumbi();
	~zumbi();
	void imprime_zumbi(ALLEGRO_BITMAP* img);
	void move_zumbi(vector < vector < char >>& mapa);
private:

};

