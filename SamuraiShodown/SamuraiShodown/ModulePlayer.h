#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum player_states
{
	ST_UNKNOWN,

	ST_IDLE,
	ST_WALK_FORWARD,
	ST_WALK_BACKWARD,
	ST_JUMP_NEUTRAL,
	ST_JUMP_FORWARD,
	ST_JUMP_BACKWARD,
	ST_CROUCH,
	ST_SLASH_STANDING,
	ST_SLASH_NEUTRAL_JUMP,
	ST_SLASH_FORWARD_JUMP,
	ST_SLASH_BACKWARD_JUMP,
	ST_SLASH_CROUCH,
	ST_KICK_STANDING,
	ST_SPECIAL
};

enum player_inputs
{
	IN_LEFT_DOWN,
	IN_LEFT_UP,
	IN_RIGHT_DOWN,
	IN_RIGHT_UP,
	IN_LEFT_AND_RIGHT,
	IN_JUMP,
	IN_CROUCH_UP,
	IN_CROUCH_DOWN,
	IN_JUMP_AND_CROUCH,
	IN_SLASH,
	IN_KICK,
	IN_SPECIAL,
	IN_JUMP_FINISH,
	IN_KICK_FINISH,
	IN_SLASH_FINISH,
	IN_SPECIAL_FINISH
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing(ModulePlayer2* p2);

	bool external_input(p2Qeue<player_inputs>& inputs);
	player_states process_fsm(p2Qeue<player_inputs>& inputs);

public:
	p2Qeue<player_inputs> inputs;
	player_states current_state = ST_UNKNOWN;

	SDL_Texture* graphics = nullptr;

	Collider* p1Collider = nullptr;
	Collider* attack = nullptr;
	Animation idle;
	Animation forward;
	Animation backward;
	Animation jump;
	Animation kick;
	Animation tornadoMove;
	Animation sAttack;
	Animation crouchD;
	Animation crouchU;

	iPoint position;

	bool jumped = false;
	bool grounded = false;
	bool action = false;
	bool kicked = false;
	bool tornadoMov = false;
	bool attacking = false;
	bool crouched = false;
	bool sCrouch = false;
	bool sJump = false;
	bool sJumpF = false;
	bool sJumpB = false;

	bool flipPlayer = false;
	bool godMode = false;

	int var1 = 0;

	int hp = 100;
	
	Mix_Chunk* kicks;
	Mix_Chunk* tornados;

};

#endif