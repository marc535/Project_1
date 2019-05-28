#ifndef __MODULESCENEWELC_H__
#define __MODULESCENEWELC_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneWelcome : public Module
{
public:
	ModuleSceneWelcome();
	~ModuleSceneWelcome();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* anim = nullptr;
	SDL_Texture* redlet = nullptr;
	SDL_Texture* coin = nullptr;
	
	SDL_Rect background;
	SDL_Rect SNK;

	
	
	

	Animation backgroundanim;
	Animation backgroundanim2;
	Animation insertcoin;
	
};

#endif // __MODULESCENEWELC_H__