#ifndef creeper_h
#define creeper_h
#include "Mobs.h"

class Creeper : public mobs
{
public:
	Creeper();
	~Creeper();
	void imprime_creeper(ALLEGRO_BITMAP* img);
	void movimento_perseguidor(vector < vector < char >>& mapa, float,float);
	void set_tuado_do_persequidor(int);
	int get_tuado_do_persequidor();

private:
	int caminho;
	int tuado_do_persequidor;
};

#endif // !creeper_h
