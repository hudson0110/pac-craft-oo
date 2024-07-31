#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <fstream>
#include <vector>
#include "personagem.h"
#include "diamante.h"
#include "tabua.h"
#include "grama.h"
#include "madeira.h"
#include "madeiradelado.h"

using namespace std;


void imprime_matrix(int linha, int coluna, int** matriz) {
    int i, j;
    for (i = 0; i < linha; i++) {
        printf("\n");                                                               //e pra imprimir a matriz no cmd.
        for (j = 0; j < coluna; j++) {
            cout << " " << matriz[i][j];
        }
    }

}

/*
void imprime_mapa_overword(int linha, int coluna, int** matriz, Tabua* tabua,Grama* grama,Diamante* diamante,Madeiradelado* madeiradelado, Madeira* madeira ) {

    int contador_tabua = 0;
    int contador_diamante = 0;
    int contador_grama = 0;
    int contador_madeira = 0;
    int contador_madeiradelado = 0;
    int y, x;

    for (y = 0; y < linha; y++) {
        for (x = 0; x < coluna; x++) {
            if (matriz[y][x] == 1) {
                if (tabua[contador_tabua].get_tabua() != NULL) {
                    tabua[contador_tabua].imprime_tabua(x * 32, y * 32);

                }
                contador_tabua++;
            }
            if (matriz[y][x] == 0 || matriz[y][x] == 2 || matriz[y][x] == 5) {
                if (grama[contador_grama].get_grama() != NULL) {
                    grama[contador_grama].imprime_grama(x * 32, y * 32);

                }
                contador_grama++;
            }
            if (matriz[y][x] == 0) {
                if (diamante[contador_diamante].get_diamante() != NULL) {
                    diamante[contador_diamante].imprime_diamante(x * 32, y * 32);

                }
                contador_diamante++;
            }
            if (matriz[y][x] == 3) {
                if (madeiradelado[contador_madeiradelado].get_madeiradelado() != NULL) {
                    madeiradelado[contador_madeiradelado].imprime_madeiradelado(x * 32, y * 32);

                }
                contador_madeiradelado++;
            }
            if (matriz[y][x] == 4) {
                if (madeira[contador_madeira].get_madeira() != NULL) {
                    madeira[contador_madeira].imprime_madeira(x * 32, y * 32);

                }
                contador_madeira++;
            }

        }
    }

}
*/
void imprime_mapa_overword(vector<vector< char>>& mapa) {
    Diamante objeto_diamante;
    Grama objeto_grama;
    Tabua objeto_tabua;
    Madeira objeto_madeira;
    Madeiradelado objeto_madeiradelado;
    int i, j;
    int altura = mapa.size();
    int largura= mapa[0].size();
    
    for (i = 0; i < largura; i++) {
        for (j = 0; j < altura; j ++ ) {
            if (mapa[j][i] == '1') {
                objeto_tabua.imprime_tabua(i, j);

            }
            if (mapa[j][i] == '0' || mapa[j][i] == '2' || mapa[j][i] == '5') {
                objeto_grama.imprime_grama(i, j);

            }
            if (mapa[j][i] == '0') {
                objeto_diamante.imprime_diamante(i, j);

            }
            if (mapa[j][i] == '4') {
                objeto_madeira.imprime_madeira(i, j);

            }
            if (mapa[j][i] == '3') {
                objeto_madeiradelado.imprime_madeiradelado(i, j);

            }
        }
    }
    
}
void carregar_mapa(const char* nome_arquivo, vector < vector < char >>& mapa) {
    ifstream arquivo(nome_arquivo);
    string linha;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            vector<char> linhaMapa;
            for (char caractere : linha) {
                if (caractere != ' ') {
                    linhaMapa.push_back(caractere);
                }
            }
            mapa.push_back(linhaMapa);
        }
        arquivo.close();
    }
    else {
        cout << "Error while opening the map file." << endl;
    }
}

