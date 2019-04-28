#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"
#include "ModuleAudio.h"

struct SDL_Texture;

enum PlayerStates2 {


	ST2_UNKNOWN,

	ST2_IDLE,
	ST2_WALK_FORWARD,
	ST2_WALK_BACKWARD,
	ST2_JUMP_NEUTRAL,
	ST2_JUMP_FORWARD,
	ST2_JUMP_BACKWARD,
	ST2_CROUCH_UP,
	ST2_CROUCH_DOWN,
	ST2_SLASH_STANDING,
	ST2_SLASH_NEUTRAL_JUMP,
	ST2_SLASH_FORWARD_JUMP,
	ST2_SLASH_BACKWARD_JUMP,
	ST2_SLASH_CROUCH,
	ST2_KICK_CROUCH,
	ST2_KICK_STANDING,
	ST2_SPECIAL,

	HIT2,
	DEATH2,
	WIN2
};


struct PlayerInput2 {
	bool pressing_left;
	bool pressing_right;
	bool pressing_down;
	bool pressing_up;
	bool pressing_1;//J
	bool pressing_2;//K
	bool pressing_3;//L
	bool pressing_F5;
};
class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status PreUpdate();
	update_status Update();

	void OnCollision(Collider* c1, Collider* c2);
	void OnPassing(ModulePlayer* p1);

	PlayerInput2 player2_input;

public:

	p2Qeue<PlayerInput2> inputs;
	PlayerStates2 current_state2 = ST2_UNKNOWN;

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

	iPoint position;

	bool jumped = false;
	bool airborne = false;
	bool action = false;
	bool kicked = false;
	bool tornadoMov = false;
	bool attacking = false;
	bool crouched = false;
	bool sCrouch = false;
	bool sJump = false;
	bool sJumpF = false;
	bool sJumpB = false;

	bool flipPlayer = true;


	int var1 = 0;

	int hp = 100;

	Mix_Chunk* kicks;

};

#endif