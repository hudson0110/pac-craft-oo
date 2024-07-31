#ifndef grama_h
#define grama_h

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <iostream>

class Grama
{
public:
	Grama();
	~Grama();
	ALLEGRO_BITMAP* get_grama();
	void imprime_grama(float, float);

private:
	ALLEGRO_BITMAP* grama;               //cria a grama
	int grama_size;


};


#endif // !grama_h

