#ifndef __ModuleGen_H__
#define __ModuleGen_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum Gen_states
{
	STG_UNKNOWN,

	STG_IDLE,
	STG_WALK_FORWARD,
	STG_WALK_BACKWARD,
	STG_JUMP_NEUTRAL,
	STG_JUMP_FORWARD,
	STG_JUMP_BACKWARD,
	STG_CROUCH,
	STG_SLASH_STANDING,
	STG_SLASH_NEUTRAL_JUMP,
	STG_SLASH_FORWARD_JUMP,
	STG_SLASH_BACKWARD_JUMP,
	STG_SLASH_CROUCH,
	STG_KICK_STANDING,
	STG_SPECIAL,
	STG_DEAD,
	STG_VICTORY,
};

enum Gen_inputs
{
	ING_LEFT_DOWN,
	ING_LEFT_UP,
	ING_RIGHT_DOWN,
	ING_RIGHT_UP,
	ING_LEFT_AND_RIGHT,
	ING_JUMP,
	ING_CROUCH_UP,
	ING_CROUCH_DOWN,
	ING_JUMP_AND_CROUCH,
	ING_SLASH,
	ING_KICK,
	ING_SPECIAL,
	ING_JUMP_FINISH,
	ING_KICK_FINISH,
	ING_SLASH_FINISH,
	ING_SPECIAL_FINISH
};

class ModuleGen : public Module
{
public:
	ModuleGen();
	~ModuleGen();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing(ModuleGen2* p2);

	bool external_input(p2Qeue<Gen_inputs>& Ginputs);
	Gen_states process_fsm(p2Qeue<Gen_inputs>& Ginputs);

public:
	p2Qeue<Gen_inputs> Ginputs;
	Gen_states current_state = STG_UNKNOWN;

	SDL_Texture* graphics = nullptr;

	Collider* GenCollider = nullptr;
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
	Animation JumpForward;
	Animation JumpBackward;
	Animation sCrouch;
	Animation kcrouch;
	Animation hit;
	Animation death;
	Animation dead;
	iPoint position;

	bool jumped = false;
	bool jumpedF = false;
	bool jumpedB = false;
	bool grounded = false;
	bool action = true;
	bool kicked = false;
	bool tornadoMov = false;
	bool attacking = false;
	bool crouched = false;
	bool sCrouched = false;
	bool sJump = false;
	bool sJumpF = false;
	bool sJumpB = false;
	bool getsHit = false;
	
	
	bool flipPlayer = false;
	bool godMode = false;
	bool isDead = false;
	

	int var1 = 0;
	int var2 = 0;

	int hp = 8000;
	
	Mix_Chunk* kicks;
	Mix_Chunk* tornados;

};

#endif