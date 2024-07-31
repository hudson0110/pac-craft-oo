#include "steve.h"

Steve::Steve():personagem()
{
    steve = al_load_bitmap("imagens/steve.png");                             // pega as imagems  na pasta 
    personagem_X = 448;
    personagem_Y = 576;
}

Steve::~Steve()
{
}

void Steve::imprime_steve(ALLEGRO_BITMAP* steve) {
    al_draw_bitmap(steve, get_pesonagemX(), get_pesonagemY(), 0);

}
void Steve::colisao_pilula(vector < vector < char >>& mapa)
{
    if (mapa[posicao_convertida_y()][posicao_convertida_x()] == '0') {
        pontuacao++;
        mapa[posicao_convertida_y()][posicao_convertida_x()] = '2';
    }
}
bool Steve::colisao_inimigo(Creeper creeperobj, Enderman endermanobj,zumbi zumbiobj,esqueleto esqueletoobj)
{
    if (posicao_convertida_x() == creeperobj.posicao_convertida_x() && posicao_convertida_y() == creeperobj.posicao_convertida_y()) {
        return true;
    }
    if (posicao_convertida_x() == endermanobj.posicao_convertida_x() && posicao_convertida_y() == endermanobj.posicao_convertida_y()) {
        return true;
    }
    if (posicao_convertida_x() == zumbiobj.posicao_convertida_x() && posicao_convertida_y() == zumbiobj.posicao_convertida_y()) {
        return true;
    }
    if (posicao_convertida_x() == esqueletoobj.posicao_convertida_x() && posicao_convertida_y() == esqueletoobj.posicao_convertida_y()) {
        return true;
    }
    return false;
}
int Steve::get_pontuacao()
{
    return pontuacao;
}