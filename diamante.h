#ifndef diamante_h
#define diamante_h

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <iostream>

class Diamante
{
public:
	Diamante();
	~Diamante();
	ALLEGRO_BITMAP* get_diamante();
	void imprime_diamante(float, float);

private:
	ALLEGRO_BITMAP* diamante;                                            //cria o diamante (pilula)
	int diamante_size;

};

#endif

