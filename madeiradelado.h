#ifndef madeiradelado_h
#define madeiradelado_h

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <iostream>

class Madeiradelado
{
public:
	Madeiradelado();
	~Madeiradelado();
	ALLEGRO_BITMAP* get_madeiradelado();
	void imprime_madeiradelado(float, float);


private:
	ALLEGRO_BITMAP* madeiradelado;
	int madeiradelado_size;
};




#endif // !madeiradelado_h
