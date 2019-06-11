#ifndef __ModuleGen2_H__
#define __ModuleGen2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum Gen2_states
{
	STG_2UNKNOWN,

	STG_2IDLE,
	STG_2WALK_FORWARD,
	STG_2WALK_BACKWARD,
	STG_2JUMP_NEUTRAL,
	STG_2JUMP_FORWARD,
	STG_2JUMP_BACKWARD,
	STG_2CROUCH,
	STG_2SLASH_STANDING,
	STG_2SLASH_NEUTRAL_JUMP,
	STG_2SLASH_FORWARD_JUMP,
	STG_2SLASH_BACKWARD_JUMP,
	STG_2SLASH_CROUCH,
	STG_2KICK_STANDING,
	STG_2SPECIAL,
	STG_2DEAD,
	STG_2VICTORY,
};

enum Gen2_inputs
{
	ING2_LEFT_DOWN,
	ING2_LEFT_UP,
	ING2_RIGHT_DOWN,
	ING2_RIGHT_UP,
	ING2_LEFT_AND_RIGHT,
	ING2_JUMP,
	ING2_CROUCH_UP,
	ING2_CROUCH_DOWN,
	ING2_JUMP_AND_CROUCH,
	ING2_SLASH,
	ING2_KICK,
	ING2_SPECIAL,
	ING2_JUMP_FINISH,
	ING2_KICK_FINISH,
	ING2_SLASH_FINISH,
	ING2_MATTACK_FINISH,
	ING2_SPECIAL_FINISH
};

class ModuleGen2 : public Module
{
public:
	ModuleGen2();
	~ModuleGen2();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing2(ModuleGen* p1);

	bool external_input(p2Qeue<Gen2_inputs>& Ginputs);
	Gen2_states process_fsm(p2Qeue<Gen2_inputs>& Ginputs);

public:
	p2Qeue<Gen2_inputs> Ginputs;
	Gen2_states current_state = STG_2UNKNOWN;

	SDL_Texture* graphics = nullptr;

	Collider* Gen2Collider = nullptr;
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
	Animation lightattackc;
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