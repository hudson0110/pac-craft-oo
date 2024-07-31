#ifndef madeira_h
#define madeira_h

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <iostream>

class Madeira
{
public:
	Madeira();
	~Madeira();
	ALLEGRO_BITMAP* get_madeira();
	void imprime_madeira(float, float);



private:
	ALLEGRO_BITMAP* madeira;
	int madeira_size;
};




#endif // !madeira_h
