#include"creeper.h"

Creeper::Creeper():mobs()
{
  
	personagem_X = 448;
	personagem_Y = 448;
    movendo_cima = true;
    caminho = 2; //0 direita 1 esquerda 2 cima 3 baixo
}





Creeper::~Creeper()
{
}
void Creeper::imprime_creeper(ALLEGRO_BITMAP* creeper)
{
	al_draw_bitmap(creeper, get_pesonagemX() , get_pesonagemY(), 0);
}

void Creeper::movimento_perseguidor(vector<vector<char>>& mapa, float steveX, float steveY)




/*
Para o mob de perseguição(creeper)  criei um metodo que pega
a posição x e y do steve e a utiliza na função, ele compara os vetores para determinar qual direção o creeper deve seguir, por exemplo
se o eixo X do steve for menor que o do creeper, isso quer dizer que o steve esta a esquerda do creeper, e do contrario a direita,
e caso o eixo Y do steve for menor que o do fantsma, isso quer dizer que o pacma esta a cima do creeper, e do contrario para baixo,
sabendo onde o steve esta no mapa é hora de dar a direção para o creeper perseguidor assim que a colisão for verdadeira

na condição eu tambem proibi que ele pegasse a direção contraria, assim como os creepers aleatorios, assim ele, seguira continuamente atrás do steve
*/

{
    if (caminho == 2 && checar_posicao_pra_cima(mapa)) {
        set_pesonagemY(get_pesonagemY() - get_tuada());
    }
    else {
        movendo_cima = false;
    }
    if (caminho == 3 && checar_posicao_pra_baixo(mapa)) {
        set_pesonagemY(get_pesonagemY() + get_tuada());
    }
    else {
        movendo_baixo = false;
    }
    if (caminho == 0 && checar_posicao_pra_direita(mapa)) {
        set_pesonagemX(get_pesonagemX() + get_tuada());
    }
    else {
        movendo_direita = false;
    }
    if (caminho == 1 && checar_posicao_pra_esquerda(mapa)) {
        set_pesonagemX(get_pesonagemX() - get_tuada());
    }
    else {
        movendo_esquerda = false;
    }
    conversao();

    if (steveY < personagem_Y && caminho != 3 && checar_posicao_pra_cima(mapa) == true) { //Cima
        caminho = 2;
    }else if (steveX > personagem_X && caminho != 1 && checar_posicao_pra_direita(mapa) == true) { //Direita
        caminho = 0;
    }
    else if (steveY > personagem_Y && caminho != 2 && checar_posicao_pra_baixo(mapa) == true) { //Baixo
        caminho = 3;
    }
    else if (steveX < personagem_X && caminho != 0 && checar_posicao_pra_esquerda(mapa) == true) { //Esquerda
        caminho = 1;
    }


    /*algumas exessoes caso o creeper fique presso em algums canto*/




    if (checar_posicao_pra_esquerda(mapa) == false && steveX < personagem_X && checar_posicao_pra_baixo(mapa) == false && checar_posicao_pra_cima(mapa) == true) {
        caminho = 2;
    }
    if (checar_posicao_pra_direita(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == true && checar_posicao_pra_cima(mapa) == false) {
        caminho = 3;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX < personagem_X && checar_posicao_pra_baixo(mapa) == true && checar_posicao_pra_cima(mapa) == false) {
        caminho = 3;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == false && checar_posicao_pra_cima(mapa) == true) {
        caminho = 2;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == true && checar_posicao_pra_cima(mapa) == false) {
        caminho = 0;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == true && checar_posicao_pra_cima(mapa) == false && checar_posicao_pra_direita(mapa) == false) {
        caminho = 3;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == false && checar_posicao_pra_cima(mapa) == true) {
        caminho = 2;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == false && checar_posicao_pra_cima(mapa) == false && checar_posicao_pra_direita(mapa) == true) {
        caminho = 0;
    }
    if (checar_posicao_pra_esquerda(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == true && checar_posicao_pra_cima(mapa) == false && checar_posicao_pra_direita(mapa) == false) {
        caminho = 3;
    }
    if (checar_posicao_pra_esquerda(mapa) == true && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == false && checar_posicao_pra_cima(mapa) == false && checar_posicao_pra_direita(mapa) == false) {
        caminho = 1;
    }
    if (checar_posicao_pra_direita(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == false && checar_posicao_pra_cima(mapa) == true) {
        caminho = 2;
    }
    if (checar_posicao_pra_direita(mapa) == false && steveX > personagem_X && checar_posicao_pra_baixo(mapa) == true && checar_posicao_pra_cima(mapa) == false) {
        caminho = 1;
    }
}

void Creeper::set_tuado_do_persequidor(int x)
{
    x = tuado_do_persequidor;
}

int Creeper::get_tuado_do_persequidor()
{
    return tuado_do_persequidor;
}

