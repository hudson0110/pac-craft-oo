#ifndef Mobs_h
#define Mobs_h

#include <cstdlib>
#include "personagem.h"

using namespace std;

class mobs:public personagem
{
public:
	mobs();
	~mobs();
	void sorteia_direcao(vector < vector < char >>& mapa);
	void movimento_aleatorio(vector < vector < char >>& mapa);


protected:
	int recebe_direcao;
};

#endif // !Mobs_h

