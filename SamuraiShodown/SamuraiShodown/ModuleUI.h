#ifndef __ModuleUIInGame_H__
#define __ModuleUIInGame_H__

#define TOTAL_HP 100
#define LOW_HP 50
#define LOW2_HP 20

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleUI : public Module
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

	bool damaged_1;
	bool damaged_2;

	void damage_to_1(int damage);
	void damage_to_2(int damage);

	SDL_Texture * graphics = nullptr;
	SDL_Rect health_animation_1;
	SDL_Rect health_animation_2;
	SDL_Rect hp_pull_1;
	SDL_Rect hp_pull_2;
	Animation healthy_1;
	Animation medium_health_1;
	Animation low_health_1;
	Animation healthy_2;
	Animation medium_health_2;
	Animation low_health_2;

	int HP1 = TOTAL_HP;
	int HP2 = TOTAL_HP;
	int minus1 = 0;
	int minus2 = 0;
};

#endif