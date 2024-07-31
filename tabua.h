#ifndef tabua_h
#define tabua_h

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <iostream>

class Tabua
{
public:
	Tabua();
	~Tabua();
	ALLEGRO_BITMAP* get_tabua();
	void imprime_tabua(float, float);

private:
	ALLEGRO_BITMAP* tabua;     //cria a tabua de madeira
	int tabua_size;


};




#endif