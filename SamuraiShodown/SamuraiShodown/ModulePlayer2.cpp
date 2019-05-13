#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "Animation.h"
#include "ModuleParticles2.h"
#include <stdlib.h>  
#include <time.h> 

ModulePlayer2::ModulePlayer2()
{
	position.x = 200;
	position.y = 210;

	// idle animation
	idle.PushBack({22, 0, 73, 118});
	idle.PushBack({96, 0, 73, 118});
	idle.PushBack({169, 0, 72, 118});
	idle.PushBack({241, 0, 72, 118});
	idle.PushBack({169, 0, 72, 118 });
	idle.PushBack({96, 0, 73, 118 });
	idle.speed = 0.14f;

	// walk forward animation 
	forward.PushBack({313, 0, 68, 118});
	forward.PushBack({446, 0, 58, 118});
	forward.PushBack({576, 0, 56, 118});
	forward.PushBack({701, 0, 61, 118});
	forward.PushBack({823, 0, 69, 118});
	forward.PushBack({946, 0, 75, 118});
	forward.speed = 0.14f;

	// walk backward animation 
	backward.PushBack({ 1023, 0, 82, 118 });
	backward.PushBack({ 1109, 0, 74, 118 });
	backward.PushBack({ 1187, 0, 68, 118 });
	backward.PushBack({ 1259, 0, 64, 118 });
	backward.PushBack({ 1326, 0, 69, 118 });
	backward.PushBack({ 1399, 0, 74, 118 });
	backward.PushBack({ 1326, 0, 69, 118 });
	backward.PushBack({ 1259, 0, 64, 118 });
	backward.PushBack({ 1187, 0, 68, 118 });
	backward.PushBack({ 1109, 0, 74, 118 });
	backward.speed = 0.14f;

	// jump animation
	jump.PushBack({ 22,124,59,112 }); 
	jump.PushBack({ 83,145,75,91 });
	jump.PushBack({ 158,153,76,84 });
	jump.PushBack({ 235,126,68,110 });
	jump.speed = 0.07f;

	// kick animation
	kick.PushBack({ 305,141,66, 95 });
	kick.PushBack({ 372,138,86, 98 });
	kick.PushBack({ 305,141,66, 95 });
	//kick.PushBack({22, 0, 73, 118});
	kick.speed = 0.14f;

	// tornado move animation
	tornadoMove.PushBack({ 22, 247, 102, 102 });
	tornadoMove.PushBack({ 124, 247, 81, 101 });
	tornadoMove.PushBack({ 206, 253, 82, 101 });
	tornadoMove.PushBack({ 289, 244, 66, 105 });
	tornadoMove.PushBack({ 356, 237, 107, 102 });
	tornadoMove.PushBack({ 480, 174, 72, 174 });
	tornadoMove.PushBack({ 566, 236, 111, 112 });
	tornadoMove.PushBack({ 681, 244, 111, 104 });
	tornadoMove.PushBack({ 793, 244, 118, 104 });
	tornadoMove.PushBack({ 912, 244, 104, 102 });

	tornadoMove.speed = 0.2f;

	// sword attack
	sAttack.PushBack({ 22, 1004, 67, 127 });
	sAttack.PushBack({ 90, 1035, 78, 96 });
	sAttack.PushBack({ 169, 1038, 130, 93 });
	sAttack.PushBack({ 300, 1038, 130, 93 });
	sAttack.PushBack({ 431, 1049, 129, 82 });
	sAttack.PushBack({ 561, 1049, 127, 82 });
	sAttack.PushBack({ 689, 1049, 119, 82 });
	sAttack.PushBack({ 809, 1046, 130, 85 });

	// crouch 
	crouchD.PushBack({ 22, 432, 68, 110 });
	crouchD.PushBack({ 101, 432, 68, 110 });
	crouchD.PushBack({ 187, 432, 68, 110 });
	crouchD.PushBack({ 304, 467, 89, 75 });
	crouchD.PushBack({ 434, 467, 89, 75 });
	crouchD.PushBack({ 560, 467, 89, 75 });
	crouchD.speed = 0.3f;
	crouchD.loop = false;

	// jump forward

	JumpForward.PushBack({ 22,592, 62, 128 });
	JumpForward.PushBack({ 90,592, 62, 128 });
	JumpForward.PushBack({ 158,592, 62, 128 });
	JumpForward.PushBack({ 231,592, 74, 91 });
	JumpForward.PushBack({ 314,592, 74, 91 });
	JumpForward.PushBack({ 398,592, 74, 91 });
	JumpForward.PushBack({ 485,589, 61, 82 });
	JumpForward.PushBack({ 566,589, 61, 82 });
	JumpForward.PushBack({ 638,589, 61, 82 });
	JumpForward.PushBack({ 713,592 ,82 ,61 });
	JumpForward.PushBack({ 805,592 ,82 ,61 });
	JumpForward.PushBack({ 895,592 ,82 ,61 });
	JumpForward.PushBack({ 988,592 ,61 ,81 });
	JumpForward.PushBack({ 1073,592 ,61 ,81 });
	JumpForward.PushBack({ 1158,592 ,61 ,81 });
	JumpForward.PushBack({ 1229,592 ,82 ,61 });
	JumpForward.PushBack({ 1318,592 ,82 ,61 });
	JumpForward.PushBack({ 1410,592 ,82 ,61 });
	JumpForward.PushBack({ 1213,462 ,76 ,83 });
	JumpForward.PushBack({ 1299,462 ,76 ,83 });
	JumpForward.PushBack({ 1387,462 ,76 ,83 });
	JumpForward.loop = false;

	// jump bakward

	JumpBackward.PushBack({ 22, 720, 60, 112 });
	JumpBackward.PushBack({ 89, 720, 60, 112 });
	JumpBackward.PushBack({ 157, 720, 60, 112 });
	JumpBackward.PushBack({ 231,592, 74, 91 });
	JumpBackward.PushBack({ 314,592, 74, 91 });
	JumpBackward.PushBack({ 398,592, 74, 91 });
	JumpBackward.PushBack({ 1229,592 ,82 ,61 });
	JumpBackward.PushBack({ 1318,592 ,82 ,61 });
	JumpBackward.PushBack({ 1410,592 ,82 ,61 });
	JumpBackward.PushBack({ 988,592 ,61 ,81 });
	JumpBackward.PushBack({ 1073,592 ,61 ,81 });
	JumpBackward.PushBack({ 1158,592 ,61 ,81 });
	JumpBackward.PushBack({ 713,592 ,82 ,61 });
	JumpBackward.PushBack({ 805,592 ,82 ,61 });
	JumpBackward.PushBack({ 895,592 ,82 ,61 });
	JumpBackward.PushBack({ 485,589, 61, 82 });
	JumpBackward.PushBack({ 566,589, 61, 82 });
	JumpBackward.PushBack({ 638,589, 61, 82 });
	JumpBackward.PushBack({ 1213,462 ,76 ,83 });
	JumpBackward.PushBack({ 1299,462 ,76 ,83 });
	JumpBackward.PushBack({ 1387,462 ,76 ,83 });
	JumpBackward.loop = false;

	sAttack.speed = 0.3f;
	
	//get hit anim

	hit.PushBack({ 1364,133,109,83 });
	hit.PushBack({ 1364,133,109,83 });
	hit.PushBack({ 1364,133,109,83 });

	hit.loop = false;
	hit.speed = 0.14f;

	// death animation

	death.PushBack({ 1126,120,98,89 });
	death.PushBack({ 793,140,106,69 });
	death.PushBack({ 900,155,108,54 });
	death.PushBack({ 1009,167,116,42 });

	death.speed = 0.2f;

	//dead anim
	dead.PushBack({ 1009,167,116,42 });

	srand(time(NULL));
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player2 textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/Haohmaru.png");
	
	App->audio->effects[2] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/HaomaruKick.wav");
	hp = 8000;

	p2Collider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_ENEMY, this);
	return ret;
}

update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;

	int speed = 2;
	float yVelocity = 15.1f;
	float yAcceleration = 0.87f;

//	if (!jumped && !jumpedB && !jumpedF) { position.y = 210; }
	if (external_input2(inputs))
	{
		player2_states state = process_fsm2(inputs);

		if (!action) {
			switch (state)
			{
			case ST2_IDLE:
				LOG("IDLE\n");
				current_animation = &idle;
				break;
			case ST2_WALK_FORWARD:
				LOG("FORWARD >>>\n");
				current_animation = &forward;
				if (!action && !flipPlayer) { position.x += speed; }
				if (!action && flipPlayer) { position.x -= speed; }

				break;
			case ST2_WALK_BACKWARD:
				LOG("BACKWARD <<<\n");
				current_animation = &backward;
				if (!action && !flipPlayer) { position.x -= speed; }
				if (!action && flipPlayer) { position.x += speed; }
				break;
			case ST2_JUMP_NEUTRAL:
				LOG("jumped NEUTRAL ^^^^\n");
				jumped = true; action = true;
				break;
			case ST2_JUMP_FORWARD:
				LOG("jumped FORWARD ^^>>\n");
				jumpedF = true; action = true;
				break;
			case ST2_JUMP_BACKWARD:
				LOG("jumped BACKWARD ^^<<\n");
				jumpedB = true; action = true;
				break;
			case ST2_CROUCH:
				LOG("CROUCHING ****\n");
				crouched = true; action = true;
				break;
			case ST2_SLASH_CROUCH:
				LOG("SLASH CROUCHING **++\n");
				sCrouched = true; //action = true;
				break;
			case ST2_SLASH_STANDING:
				LOG("SLASH STANDING ++++\n");
				attacking = true; action = true;
				if (!flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_ENEMY_ATTACK, (Module*)App->player2);
					attack->SetPos(position.x + 60, position.y - 50);
				}
				if (flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_ENEMY_ATTACK, (Module*)App->player2);
					attack->SetPos(position.x - 55, position.y - 50);
				}
				break;
			case ST2_KICK_STANDING:
				LOG("KICK STANDING ----\n");
				kicked = true; action = true;
				if (!flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
					attack->SetPos(position.x + 30, position.y - 50);
				}
				if (flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
					attack->SetPos(position.x - 25, position.y - 50);
				}
				break;
			case ST2_SLASH_NEUTRAL_JUMP:
				LOG("SLASH JUMP NEUTRAL ^^++\n");
				sJump = true; action = true;
				break;
			case ST2_SLASH_FORWARD_JUMP:
				LOG("SLASH JUMP FORWARD ^>>+\n");
				sJumpF = true; action = true;
				break;
			case ST2_SLASH_BACKWARD_JUMP:
				LOG("SLASH JUMP BACKWARD ^<<+\n");
				sJumpB = true; action = true;
				break;
			case ST2_SPECIAL:
				LOG("TORNADO\n");
				tornadoMov = true; action = true;
				Mix_PlayChannel(-1, App->audio->effects[3], 0);
				Mix_PlayChannel(-1, App->audio->effects[4], 0);
				tornadoMov = true;
				action = true;
				if (!flipPlayer) {
					App->particles2->tornado.speed.x = +3;
					App->particles2->AddParticle2(App->particles2->tornado, position.x + 20, position.y - 77, COLLIDER_PLAYER_SHOT);
				}
				else {
					App->particles2->tornado.speed.x = -3;
					App->particles2->AddParticle2(App->particles2->tornado, position.x - 20, position.y - 77, COLLIDER_PLAYER_SHOT);

				}
				break;

			}
		}
		current_state2 = state;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov && !action && !getsHit)
	{
		if (!action && !flipPlayer) { current_animation = &forward; }
		if (!action && flipPlayer) { current_animation = &backward; }
		position.x += speed;
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && !action)
		{
			if (!action && !flipPlayer) { current_animation = &JumpBackward;}
			if (!action && flipPlayer) { current_animation = &JumpForward;}

			jumpedF = true;
			action = true;

		}

	}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov && !action && !getsHit)
	{
		if (!action && !flipPlayer) { current_animation = &backward; }
		if (!action && flipPlayer) { current_animation = &forward; }
		position.x -= speed;
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && !action)
		{
			if (!action && !flipPlayer) { current_animation = &JumpBackward;}
			if (!action && flipPlayer) { current_animation = &JumpForward;}
			jumpedB = true;
			action = true;

		}

	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && !action)
	{

		jumped = true;
		action = true;

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT && !action)
	{

		crouched = true;
		action = true;

	}
	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_STATE::KEY_REPEAT && !action && !jumped)
	{
		Mix_PlayChannel(-1, App->audio->effects[2], 0);
		kicked = true; action = true;
		if (!flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
			attack->SetPos(position.x + 30, position.y - 50);
		}
		if (flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
			attack->SetPos(position.x - 25, position.y - 50);
		}

	}
	if (App->input->keyboard[SDL_SCANCODE_KP_3] == KEY_STATE::KEY_REPEAT && !action && !jumped) {

		Mix_PlayChannel(-1, App->audio->effects[3], 0);
		Mix_PlayChannel(-1, App->audio->effects[4], 0);
		tornadoMov = true;
		action = true;
		if (!flipPlayer) {
			App->particles2->tornado.speed.x = +3;
			App->particles2->AddParticle2(App->particles2->tornado, position.x + 20, position.y - 77, COLLIDER_ENEMY_SHOT);
		}
		else {
			App->particles2->tornado.speed.x = -3;
			App->particles2->AddParticle2(App->particles2->tornado, position.x - 20, position.y - 77, COLLIDER_ENEMY_SHOT);

		}
	}
	if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_STATE::KEY_REPEAT && !action)
	{
		Mix_PlayChannel(-1, App->audio->effects[6], 0);
		attacking = true; action = true;
		if (!flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_ENEMY_ATTACK, (Module*)App->player2);
			attack->SetPos(position.x + 60, position.y - 50);
		}
		if (flipPlayer) {
			attacking = true; action = true;

			attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_ENEMY_ATTACK, (Module*)App->player2);
			attack->SetPos(position.x - 55, position.y - 50);
		}

	}


	if (action) {

		if (jumped) {

			current_animation = &jump;

			position.y = 210 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			grounded = true;


			if (position.y > 210 && grounded == true)	//end of the jump
			{
				inputs.Push(IN2_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumped = false;
				position.y = 210;
				action = false;

			}
			var1++;

		}

		if (jumpedF) {

			current_animation = &JumpForward;

			position.y = 210 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			position.x += 4;
			grounded = true;


			if (position.y > 210 && grounded == true)	//end of the jump
			{
				inputs.Push(IN2_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumpedF = false;
				position.y = 210;
				action = false;
				JumpForward.Reset();
				JumpBackward.Reset();


			}
			var1++;


		}
		if (jumpedB) {

			current_animation = &JumpBackward;

			position.y = 210 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			position.x -= 4;
			grounded = true;


			if (position.y > 210 && grounded == true)	//end of the jump
			{
				inputs.Push(IN2_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumpedB = false;
				position.y = 210;
				action = false;
				JumpBackward.Reset();


			}
			var1++;


		}

		if (kicked) {

			current_animation = &kick;

			if (kick.FinishedAnimation() == true) {

				kicked = false;
				action = false;
				attack->to_delete = true;
				inputs.Push(IN2_KICK_FINISH);

				kick.finishingAnimation(false);
			}

		}
		if (tornadoMov) {

			current_animation = &tornadoMove;
			if (tornadoMove.FinishedAnimation() == true) {

				tornadoMov = false;
				action = false;
				inputs.Push(IN2_SPECIAL_FINISH);

				tornadoMove.finishingAnimation(false);
			}

		}
		if (attacking) {

			current_animation = &sAttack;
			if (sAttack.FinishedAnimation() == true) {

				attacking = false;
				action = false;
				attack->to_delete = true;
				inputs.Push(IN2_SLASH_FINISH);

				sAttack.finishingAnimation(false);
			}

		}
		if (crouched) {

			current_animation = &crouchD;
			action = true;

			if (crouchD.FinishedAnimation() == true && App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP) {
				inputs.Push(IN2_CROUCH_UP);
				var1 = 0;
				crouched = false;
				position.y = 210;
				action = false;
			}
		}
	}

	if (isDead) {

		current_animation = &death;
		p2Collider->to_delete = true;

		if (death.FinishedAnimation() == true) {current_animation = &dead;}
	}
	if (getsHit) {

		action = true;
		current_animation = &hit;
		if (hit.Finished() == true) {
			action = false;
			getsHit = false;
			current_state2 = ST2_IDLE;
			position.y = 210;
		}

	}

	if (hp <= 0) { isDead = true; action = true; }

	if (isDead) {

		current_state2 = ST2_DEAD;

	}
	if (App->player2->isDead == true) {

		current_state2 = ST2_VICTORY;
	}

	if (!flipPlayer) {
		p2Collider->SetPos(position.x + 20, position.y - 80);
	}
	else {
		p2Collider->SetPos(position.x + 10, position.y - 80);
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	OnPassing(App->player);
	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, flipPlayer);


	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	switch (c2->type) {

	case COLLIDER_PLAYER_ATTACK:

		if (c2->to_delete == false) { c2->to_delete = true; }
		hp -= 550 + (rand() % 150);
		getsHit = true;
		Mix_PlayChannel(-1, App->audio->effects[7], 0);

	case COLLIDER_PLAYER_SHOT:

		if (c2->to_delete == false) { c2->to_delete = true; }
		hp -= 20;
		getsHit = true;
		position.y = 210;
		Mix_PlayChannel(-1, App->audio->effects[8], 0);
	}
	
}

void ModulePlayer2::OnPassing(ModulePlayer* p1) {

	if (flipPlayer) {

		if ((this->position.x + 60) < p1->position.x) {
			flipPlayer = false;
			LOG("Player1 flip = false")

		}
	}
	if (!flipPlayer) {


		if (this->position.x > (p1->position.x + 60)) {
			flipPlayer = true;
			LOG("Player1 flip = true")
		}
	}
}

bool ModulePlayer2::external_input2(p2Qeue<player2_inputs>& inputs)
{
	static bool left = false;
	static bool right = false;
	static bool down = false;
	static bool up = false;

	SDL_Event event;

	if (this->IsEnabled() == true) {

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_KEYUP && event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					return false;
					break;
				case SDLK_DOWN:
					inputs.Push(IN2_CROUCH_UP);
					down = false;
					break;
				case SDLK_UP:
					up = false;
					break;
				case SDLK_LEFT:
					inputs.Push(IN2_LEFT_UP);
					left = false;
					break;
				case SDLK_RIGHT:
					inputs.Push(IN2_RIGHT_UP);
					right = false;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_KP_1:
					inputs.Push(IN2_SLASH);
					break;
				case SDLK_KP_2:
					inputs.Push(IN2_KICK);
					break;
				case SDLK_KP_3:
					inputs.Push(IN2_SPECIAL);
					break;
				case SDLK_UP:
					up = true;
					break;
				case SDLK_DOWN:
					down = true;
					break;
				case SDLK_LEFT:
					left = true;
					break;
				case SDLK_RIGHT:
					right = true;
					break;
				}
			}
		}

		if (left && right)
			inputs.Push(IN2_LEFT_AND_RIGHT);
		{
			if (left)
				inputs.Push(IN2_LEFT_DOWN);
			if (right)
				inputs.Push(IN2_RIGHT_DOWN);
		}

		if (up && down)
			inputs.Push(IN2_JUMP_AND_CROUCH);
		else
		{
			if (down)
				inputs.Push(IN2_CROUCH_DOWN);
			else
				inputs.Push(IN2_CROUCH_UP);
			if (up)
				inputs.Push(IN2_JUMP);
		}

		return true;
	}
}

player2_states ModulePlayer2::process_fsm2(p2Qeue<player2_inputs>& inputs)
{
	static player2_states state = ST2_IDLE;
	player2_inputs last_input;

	while (inputs.Pop(last_input))
	{
		switch (state)
		{
		case ST2_IDLE:
		{
			switch (last_input)
			{
			case IN2_RIGHT_DOWN: if (!flipPlayer) { state = ST2_WALK_FORWARD; break; }
								if (flipPlayer) { state = ST2_WALK_BACKWARD; break; }
			case IN2_LEFT_DOWN: if (!flipPlayer) { state = ST2_WALK_BACKWARD; break; }
							   if (flipPlayer) { state = ST2_WALK_FORWARD; break; }
			case IN2_JUMP: state = ST2_JUMP_NEUTRAL;  break;
			case IN2_CROUCH_DOWN: state = ST2_CROUCH; break;
			case IN2_SLASH: state = ST2_SLASH_STANDING; break;
			case IN2_KICK: state = ST2_KICK_STANDING; break;
			case IN2_SPECIAL: state = ST2_SPECIAL; break;

			}
		}
		break;

		case ST2_WALK_FORWARD:
		{
			switch (last_input)
			{
			if (flipPlayer) { case IN2_LEFT_UP: state = ST2_IDLE; break; }
			if (!flipPlayer) { case IN2_RIGHT_UP: state = ST2_IDLE; break; }
			case IN2_LEFT_AND_RIGHT: state = ST2_IDLE; break;
			case IN2_JUMP: 
				if (!flipPlayer) { state = ST2_JUMP_FORWARD; }
				if (flipPlayer) { state = ST2_JUMP_BACKWARD; }
				break;
			case IN2_CROUCH_DOWN: state = ST2_CROUCH; break;
			}
		}
		break;

		case ST2_WALK_BACKWARD:
		{
			switch (last_input)
			{
			if (!flipPlayer) { case IN2_LEFT_UP: state = ST2_IDLE; break; }
			if (flipPlayer) { case IN2_RIGHT_UP: state = ST2_IDLE; break; }
			case IN2_LEFT_AND_RIGHT: state = ST2_IDLE; break;
			case IN2_JUMP:
				if (!flipPlayer) { state = ST2_JUMP_BACKWARD; }
				if (flipPlayer) { state = ST2_JUMP_FORWARD; }
				break;
			case IN2_CROUCH_DOWN: state = ST2_CROUCH; break;
			}
		}
		break;

		case ST2_JUMP_NEUTRAL:
		{
			switch (last_input)
			{
			case IN2_JUMP_FINISH: state = ST2_IDLE; break;
			case IN2_SLASH: state = ST2_SLASH_NEUTRAL_JUMP; break;
			}
		}
		break;

		case ST2_JUMP_FORWARD:
		{
			switch (last_input)
			{
			case IN2_JUMP_FINISH: state = ST2_IDLE; break;
			case IN2_SLASH: state = ST2_SLASH_FORWARD_JUMP; break;
			}
		}
		break;

		case ST2_JUMP_BACKWARD:
		{
			switch (last_input)
			{
			case IN2_JUMP_FINISH: state = ST2_IDLE; break;
			case IN2_SLASH: state = ST2_SLASH_BACKWARD_JUMP; break;
			}
		}
		break;

		case ST2_SLASH_NEUTRAL_JUMP:
		{
			switch (last_input)
			{
			case IN2_SLASH_FINISH: state = ST2_IDLE; break;
			case IN2_JUMP_FINISH: state = ST2_IDLE; break;
			}
		}
		break;

		case ST2_SLASH_FORWARD_JUMP:
		{
			switch (last_input)
			{
			case IN2_SLASH_FINISH: state = ST2_IDLE; break;
			case IN2_JUMP_FINISH: state = ST2_IDLE; break;
			}
		}
		break;

		case ST2_SLASH_BACKWARD_JUMP:
		{
			switch (last_input)
			{
			case IN2_SLASH_FINISH: state = ST2_IDLE; break;
			case IN2_JUMP_FINISH: state = ST2_IDLE; break;
			}
		}
		break;

		case ST2_SLASH_STANDING:
		{
			switch (last_input)
			{
			case IN2_SLASH_FINISH: state = ST2_IDLE; break;
			}
		}
		break;

		case ST2_CROUCH:
		{
			switch (last_input)
			{
			case IN2_CROUCH_UP: state = ST2_IDLE; break;
			case IN2_SLASH: state = ST2_SLASH_CROUCH; break;
			}
		}
		break;
		case ST2_SLASH_CROUCH:
		{
			switch (last_input)
			{
			case IN2_CROUCH_UP && IN2_SLASH_FINISH: state = ST2_IDLE; break;
			case IN2_SLASH_FINISH: state = ST2_CROUCH; break;
			}
		}
		case ST2_KICK_STANDING:
		{
			switch (last_input)
			{
			case IN2_KICK_FINISH: state = ST2_IDLE; break;
			}
		}
		case ST2_SPECIAL:
		{
			switch (last_input)
			{
			case IN2_SPECIAL_FINISH: state = ST2_IDLE; break;
			}
		}
		break;
		}
	}
	return state;
}