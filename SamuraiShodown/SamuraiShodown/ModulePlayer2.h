#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum player2_states
{
	ST2_UNKNOWN,

	ST2_IDLE,
	ST2_WALK_FORWARD,
	ST2_WALK_BACKWARD,
	ST2_JUMP_NEUTRAL,
	ST2_JUMP_FORWARD,
	ST2_JUMP_BACKWARD,
	ST2_CROUCH,
	ST2_SLASH_STANDING,
	ST2_SLASH_NEUTRAL_JUMP,
	ST2_SLASH_FORWARD_JUMP,
	ST2_SLASH_BACKWARD_JUMP,
	ST2_SLASH_CROUCH,
	ST2_KICK_STANDING,
	ST2_SPECIAL
};

enum player2_inputs
{
	IN2_LEFT_DOWN,
	IN2_LEFT_UP,
	IN2_RIGHT_DOWN,
	IN2_RIGHT_UP,
	IN2_LEFT_AND_RIGHT,
	IN2_JUMP,
	IN2_CROUCH_UP,
	IN2_CROUCH_DOWN,
	IN2_JUMP_AND_CROUCH,
	IN2_SLASH,
	IN2_KICK,
	IN2_SPECIAL,
	IN2_JUMP_FINISH,
	IN2_KICK_FINISH,
	IN2_SLASH_FINISH,
	IN2_SPECIAL_FINISH
};
class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing(ModulePlayer* p1);

	bool external_input2(p2Qeue<player2_inputs>& inputs);
	player2_states process_fsm2(p2Qeue<player2_inputs>& inputs);

public:

	p2Qeue<player2_inputs> inputs;
	player2_states current_state2 = ST2_UNKNOWN;

	SDL_Texture* graphics = nullptr;

	Collider* p2Collider = nullptr;
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

	iPoint position;

	bool jumped = false;
	bool grounded = false;
	bool action = false;
	bool kicked = false;
	bool tornadoMov = false;
	bool attacking = false;
	bool crouched = false;
	bool sCrouched = false;
	bool sJump = false;
	bool sJumpF = false;
	bool sJumpB = false;

	bool flipPlayer = true;


	int var1 = 0;

	int hp = 100;

	Mix_Chunk* kicks;

};

#endif