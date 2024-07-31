#ifndef steve_h
#define steve_h
#include "personagem.h"
#include "creeper.h"
#include "enderman.h"
#include "zumbi.h"
#include "esqueleto.h"

class Steve : public personagem
{
public:
	Steve();
	~Steve();
	void imprime_steve(ALLEGRO_BITMAP* img);
	int get_pontuacao();
	void colisao_pilula(vector < vector < char >>& mapa);
	bool colisao_inimigo(Creeper creeperobj, Enderman endermanobj,zumbi zumbiobj, esqueleto esqueletoobj);


private:
	int pontuacao;

};

#endif // !steve_h
