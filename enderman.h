#ifndef enderman_h
#define enderman_h

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

#include "Mobs.h"


using namespace std;

class Enderman:public mobs
{
public:
	Enderman();
	~Enderman();
	void imprime_enderman(ALLEGRO_BITMAP* img);
	void teleporta_enderman(vector<vector<char>>& mapa);
private:
};






#endif // !enderman_h
