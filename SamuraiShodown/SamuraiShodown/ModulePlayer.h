#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:

	SDL_Texture* graphics = nullptr;

	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation kick;

	iPoint position;

	bool jumped = false;
	bool airborne = false;
	bool action = false;
	bool kicked = false;

	int var1 = 0;
	
};

#endif