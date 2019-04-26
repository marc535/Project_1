#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleAudio.h"

struct SDL_Texture;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing(ModulePlayer* p1);

public:

	SDL_Texture* graphics = nullptr;

	Collider* p2Collider = nullptr;
	Collider* attack = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation kick;
	Animation tornadoMove;

	iPoint position;

	bool jumped = false;
	bool airborne = false;
	bool action = false;
	bool kicked = false;
	bool tornadoMov = false;

	bool flipPlayer = true;


	int var1 = 0;
	

	Mix_Chunk* kicks;
	
};

#endif