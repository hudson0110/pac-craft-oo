#ifndef esqueleto_h
#define esqueleto_h
#include "Mobs.h"
class esqueleto : public mobs
{
public:
	esqueleto();
	~esqueleto();
	void imprime_esqueleto(ALLEGRO_BITMAP* img);
private:

};

#endif