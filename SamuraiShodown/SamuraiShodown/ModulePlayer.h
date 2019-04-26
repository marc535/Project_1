#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleAudio.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing(ModulePlayer2* p2);

public:

	SDL_Texture* graphics = nullptr;

	Collider* p1Collider = nullptr;
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

	bool flipPlayer = false;
	bool godMode = false;

	int var1 = 0;
	
	Mix_Chunk* kicks;

};

#endif