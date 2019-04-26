#ifndef __ModuleUIInGame_H__
#define __ModuleUIInGame_H__

#define TOTAL_HP 100
#define LOW_HP 40
#define LOW2_HP 20

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleUIInGame : public Module
{
public:
	ModuleUIInGame();
	~ModuleUIInGame();

	bool Start();
	update_status Update();
	bool CleanUp();
	
	bool damaged;

	void damage(int damage);

	SDL_Texture * graphics = nullptr;
	SDL_Rect animation;
	SDL_Rect damage_animation;
	SDL_Rect hp_pull;
	Animation damage_taken;
	Animation healthy;
	Animation not_healthy1;
	Animation not_healthy2;

	int HP = TOTAL_HP;
	int hp_graph = 0;
};

#endif