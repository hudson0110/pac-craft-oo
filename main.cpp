#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro5.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "personagem.h"
#include "diamante.h"
#include "tabua.h"
#include "grama.h"
#include "Mobs.h"
#include "madeira.h"
#include "madeiradelado.h"
#include "funcoes.h"
#include "enderman.h"
#include "creeper.h"
#include "steve.h"
#include "zumbi.h"
#include "esqueleto.h"


using namespace std;

const float FPS = 60;                                                  //velocidade do jogo.
const int SCREEN_W = 1280;                                             //largura da tela
const int SCREEN_H = 928;                                              //altura da tela


int main(){

	al_init();                                                                  //inicializa a fun�ao allegro 
	al_init_image_addon();                                                      //inicializa a fun�ao das imagens do allegro  
	al_install_keyboard();                                                      //inicializa a fun�ao do teclado
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();                                                         //inicia a fun�ao de audio
	al_init_acodec_addon();


	/*variaveis*/
	int pontuacao = -1;
	int mante = 0;
	int matrizY = 29, matrizX = 29;
	bool keys[255] = { false };                                                 //teclas
	bool IMPRIME = true;                                                        //controle de impress�o
	bool doexit = false;                                                        //controle de funcionando
	ALLEGRO_SAMPLE* sample = NULL;// * sample2 = NULL;                          //estrutura da musica
	ALLEGRO_SAMPLE_INSTANCE* instance = NULL;// *instance2  = NULL;             //estrutura da instancia da musica

	int proximo_movimento = 0;



	ALLEGRO_DISPLAY* display = NULL;                                            //cria o display
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;                                    //cria a fila de eventos
	ALLEGRO_TIMER* timer = NULL;                                                //cria a estrutura do tempo
	ALLEGRO_BITMAP* olho = NULL;                                                //cria o olho
	ALLEGRO_FONT* fonte = NULL;
	ALLEGRO_BITMAP* creeperSprite = NULL;
	ALLEGRO_BITMAP* endermanSprite = NULL;
	ALLEGRO_BITMAP* zumbiSprite = NULL;
	ALLEGRO_BITMAP* steveSprite = NULL;
	ALLEGRO_BITMAP* esqueletoSprite = NULL;


	creeperSprite = al_load_bitmap("imagens/creeper.jpg");
	endermanSprite = al_load_bitmap("imagens/enderman.jpg");
	esqueletoSprite = al_load_bitmap("imagens/zumbi.jpg");
	zumbiSprite = al_load_bitmap("imagens/zumbi.jpg");
	steveSprite = al_load_bitmap("imagens/steve.png");                             // pega as imagems  na pasta 

	fonte = al_load_font("fonte_mine_trincada.ttf",32,0);


	timer = al_create_timer(1.0 / FPS);                                         //calcula o tempo pela fun�ao com base no fps

	                                                    //inicia a playlist de audios //caso tenha mais de uma
	 al_reserve_samples(2);                                                      //Quantidade de Audios
	 sample = al_load_sample("tema_musica.wav");                                 //carrega a musica na variavel sample

     instance = al_create_sample_instance(sample);                               //cria a instancia da musica

	 al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

	 al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);             //inicia a musica junto com o jogo




	display = al_create_display(SCREEN_W, SCREEN_H);                            //cria o display na resulo�ao acima colocada


	Grama gramaobj;
	Madeira madeira;
	Madeiradelado madeiradelado;
	Tabua tabua;
	Diamante diamante;
	Steve steveobj;
	Enderman endermanobj;
	Creeper creeperobj;
	zumbi zumbiobj;
	esqueleto esqueletoobj;

	al_set_target_bitmap(al_get_backbuffer(display));                           // meche com a tela kkk

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());


	al_flip_display();                                                          //atualiza a imagem do display

	al_start_timer(timer);                                                      //come�a o tempo

	//int** matriz;
	// linha, coluna, i, j;

	vector < vector < char >> mapa;
	carregar_mapa("matriz_mapa.txt", mapa);


//	imprime_matrix(linha, coluna, matriz);                                                                                                                                        // imprime a matriz no cmd


	while (!doexit)                                                                  //lista de eventos
	{
		ALLEGRO_EVENT ev;                                                            //inicia a estrutura de eventos
		al_wait_for_event(event_queue, &ev);
		
		steveobj.conversao();
		steveobj.colisao_pilula(mapa);
		creeperobj.conversao();
		esqueletoobj.conversao();
		endermanobj.conversao();
		zumbiobj.conversao();
		if (ev.type == ALLEGRO_EVENT_TIMER) {          

			if (keys[ALLEGRO_KEY_W]) {
				proximo_movimento = ALLEGRO_KEY_W;
			}
			if (keys[ALLEGRO_KEY_S]) {
				proximo_movimento = ALLEGRO_KEY_S;
			}
			if (keys[ALLEGRO_KEY_A]) {
				proximo_movimento = ALLEGRO_KEY_A;
			}
			if (keys[ALLEGRO_KEY_D]) {
				proximo_movimento = ALLEGRO_KEY_D;
			}
			steveobj.checa_movimento(mapa, proximo_movimento);
			steveobj.move_personagem(mapa);
			endermanobj.movimento_aleatorio(mapa);
			creeperobj.movimento_perseguidor(mapa,steveobj.get_pesonagemX(),steveobj.get_pesonagemY());
			esqueletoobj.movimento_aleatorio(mapa);
			zumbiobj.movimento_aleatorio(mapa);
			IMPRIME = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			keys[ev.keyboard.keycode] = true;
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			keys[ev.keyboard.keycode] = false;
		}

		if (IMPRIME && al_is_event_queue_empty(event_queue)) {                  //o controle de impresao junto com a lista de eventos tem q tar verdadeiro

			IMPRIME = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));                            //cor do fundo

			imprime_mapa_overword(mapa);
			steveobj.imprime_steve(steveSprite);
			endermanobj.imprime_enderman(endermanSprite);
			esqueletoobj.imprime_esqueleto(esqueletoSprite);
			creeperobj.imprime_creeper(creeperSprite);
			zumbiobj.imprime_zumbi(zumbiSprite);
			
			
			al_draw_textf(fonte, al_map_rgb(255, 255, 255), 1000, 50, 0, "Diamantes:%d", steveobj.get_pontuacao());
			
			if (steveobj.get_pontuacao() >= 436)   {                                              //436
				al_draw_textf(fonte, al_map_rgb(255, 255, 255), 1050, 150, 0, "VITORIA !!!", steveobj.get_pontuacao());	
		
			}
			al_flip_display();

		}
		
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			doexit = true;
		}
		if (steveobj.colisao_inimigo(creeperobj, endermanobj,zumbiobj,esqueletoobj )) {
			al_rest(3);	
			doexit = true;
		}

	}
	al_destroy_timer(timer);
	al_destroy_bitmap(steveSprite);
	al_destroy_bitmap(endermanSprite);
	al_destroy_bitmap(creeperSprite);
	al_destroy_bitmap(zumbiSprite);
	al_destroy_bitmap(esqueletoSprite);
	al_destroy_display(display);                                                //destroi tudo 
	al_destroy_sample(sample);
	al_destroy_event_queue(event_queue);

	return 0;

}
