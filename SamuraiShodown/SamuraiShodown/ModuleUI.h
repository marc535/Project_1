#ifndef _MODULE_UI
#define _MODULE_UI
#include "Module.h"
#include "Animation.h"
#include "SDL/include/SDL_rect.h"
#include "ModuleAudio.h"
struct SDL_Texture;

class ModuleUI : public Module
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

	void UpdateBars();
	//void VictorySprite();


public:
	SDL_Texture * ui_png = nullptr;

	

	//BARS
	int maxHP = 0;
	int max_width = 128;

	//player1
	int target_hp1 = 0;
	int current_hp1 = 0;
	int currentW_player1 = 0;
	bool decrease_player1 = false;
	SDL_Rect hpBar1{ 8,32,128,9 };

	//player2
	int target_hp2 = 0;
	int current_hp2 = 0;
	int currentW_player2 = 0;
	bool decrease_player2 = false;
	SDL_Rect hpBar2{ 8,32,128,9 };

	//timer
	int font_time = -1;
	char time_text[10];
	int actualtime = 99;
	int startingtime = 0;
	
	int puntuacion1;
	char puntuation1[10];
	char puntuation2[10];

	//el resto de fuentes
	int font_name = -1;
	int font_menu = -1;
	
	
	//KO

	bool animKO;
	
	
	
	bool show_ui = false;
	bool is_draw = false;
	
	Animation draw_anim;
	Animation time_up_anim;
	Animation KO;
	
	



};

#endif // !_MODULE_UI

