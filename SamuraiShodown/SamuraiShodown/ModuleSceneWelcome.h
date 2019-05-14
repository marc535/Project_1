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
	SDL_Rect background;
	

	Animation backgroundanim;
	Animation backgroundanim2;
};

#endif // __MODULESCENEWELC_H__