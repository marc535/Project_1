#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleGen.h"

ModuleGen::ModuleGen()
{
	position.x = 50;
	position.y = 220;

	// idle animation
	idle.PushBack({ 1722,555,68,122 });
	idle.PushBack({ 1818,564,81,113 });
	idle.PushBack({ 1917,553,82,124 });
	idle.PushBack({ 1726,694,84,117 });
	idle.PushBack({ 1822,685,80,126 });
	idle.PushBack({ 1915,687,84,124 });
	idle.speed = 0.14f;

	// walk forward animation 
	forward.PushBack({ 9,1699,57,84 });
	forward.PushBack({ 71,1700,58,80 });
	forward.PushBack({ 132,1702,61,80 });
	forward.PushBack({ 196,1697,55,86 });
	forward.speed = 0.14f;

	// walk backward animation 
	backward.PushBack({ 9,1699,57,84 });
	backward.PushBack({ 71,1700,58,80 });
	backward.PushBack({ 132,1702,61,80 });
	backward.PushBack({ 196,1697,55,86 });
	backward.speed = 0.14f;

	// jump animation
	jump.PushBack({ 261,1687,67,105 });
	jump.PushBack({ 330,1715,62,72 });
	jump.speed = 0.07f;

	// kick animation
	kick.PushBack({ 305,141,66,95 });
	kick.PushBack({ 372,138,86,98 });
	kick.PushBack({ 305,141,66,95 });
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

	sAttack.speed = 0.3f;

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

	JumpForward.PushBack({ 392,1695,61,105 });
	JumpForward.PushBack({ 453,1680,61,120 });
	JumpForward.PushBack({ 529,1718,62,72 });
	JumpForward.loop = false;

	// jump backward

	JumpBackward.PushBack({ 604,1696,66,105 });
	JumpBackward.PushBack({ 677,1700,66,88 });
	JumpBackward.PushBack({ 746,1708,62,72 });
	JumpBackward.loop = false;

	// crouch sword attack 

	sCrouch.PushBack({ 22,832,88,75 });
	sCrouch.PushBack({ 137,838,83,69 });
	sCrouch.PushBack({ 245,838,83,69 });
	sCrouch.PushBack({ 361,838,126,68 });
	sCrouch.PushBack({ 513,838,126,68 });
	sCrouch.PushBack({ 677,839,126,68 });
	sCrouch.PushBack({ 830 ,838,125,78 });
	sCrouch.PushBack({ 988,840,124,68 });
	sCrouch.PushBack({ 1164 ,839,126,68 });
	sCrouch.PushBack({ 568,739,85,68 });
	sCrouch.PushBack({ 692 ,739,85,68 });
	sCrouch.PushBack({ 820,739,85,68 });
	sCrouch.PushBack({ 944,739,81,68 });
	sCrouch.PushBack({ 1070,739,81,68 });
	sCrouch.PushBack({ 1182,738,83,69 });
	sCrouch.speed = 0.3f;
	sCrouch.loop = false;

	// coruch kick anim
	
	kcrouch.PushBack({ 22,927,73 ,76 });
	kcrouch.PushBack({ 114,925,73 ,76 });
	kcrouch.PushBack({ 213,923,78 ,80 });
	kcrouch.PushBack({ 310,923,78 ,80 });
	kcrouch.PushBack({ 406,932,98 ,71 });
	kcrouch.PushBack({ 524,932,98 ,71 });
	kcrouch.PushBack({ 654,921,80,78 });
	kcrouch.PushBack({ 761,921,80,78 });

	//get hit anim

	hit.PushBack({ 1364,133,109,83 });
	hit.PushBack({ 1364,133,109,83 });
	hit.PushBack({ 1364,133,109,83 });

	hit.loop = false;
	hit.speed = 0.14f;

	// death animation

	death.PushBack({1126,120,98,89});
	death.PushBack({793,140,106,69});
	death.PushBack({900,155,108,54 });
	death.PushBack({1009,167,116,42});

	death.speed = 0.2f;

	//dead anim
	dead.PushBack({ 1009,167,116,42 });
}

ModuleGen::~ModuleGen()
{}

// Load assets
bool ModuleGen::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/Haohmaru.png");
	
	action = false;

	
	App->audio->effects[2] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/HaomaruKick.wav");
	App->audio->effects[3] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/HaohmaruTornado.wav");
	App->audio->effects[4] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/TornadoFX.wav");
	App->audio->effects[6] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/Slash.wav");
	App->audio->effects[7] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/hit.wav");
	App->audio->effects[8] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/hit2.wav");


	GenCollider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_PLAYER, this);
	Ginputs.Clear();
	
	current_state = STG_IDLE;
	return ret;
}

bool ModuleGen::CleanUp(){

	LOG("Unloading Character");
	App->textures->Unload(graphics);

	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleGen::Update()
{
	Animation* current_animation = &idle;
	
	int speed = 2;
	float yVelocity = 15.1f;
	float yAcceleration = 0.87f;
	

	if (external_input(Ginputs))
	{
		
		Gen_states state = process_fsm(Ginputs);

		if (!action) {
			switch (state)
			{
			case STG_IDLE:
				LOG("IDLE\n");
				current_animation = &idle;
				break;
			case STG_WALK_FORWARD:
				LOG("FORWARD >>>\n");
				current_animation = &forward;			
				if (!action && !flipPlayer) { position.x += speed; }
				if (!action && flipPlayer) { position.x -= speed; }
				
				break;
			case STG_WALK_BACKWARD:
				LOG("BACKWARD <<<\n");
				current_animation = &backward;
				if (!action && !flipPlayer) { position.x -= speed; }
				if (!action && flipPlayer) { position.x += speed; }
				break;
			case STG_JUMP_NEUTRAL:
				LOG("jumped NEUTRAL ^^^^\n");
				jumped = true; action = true;
				break;
			case STG_JUMP_FORWARD:
				LOG("jumped FORWARD ^^>>\n");
				jumpedF = true; action = true;
				break;
			case STG_JUMP_BACKWARD:
				LOG("jumped BACKWARD ^^<<\n");
				jumpedB = true; action = true;
				break;
			case STG_CROUCH:
				LOG("CROUCHING ****\n");
				crouched = true; action = true;
				break;
			case STG_SLASH_CROUCH:
				LOG("SLASH CROUCHING **++\n");
				sCrouched = true; action = true;
			
				break;
			case STG_SLASH_STANDING:
				LOG("SLASH STANDING ++++\n");
				attacking = true; action = true;
				Mix_PlayChannel(-1, App->audio->effects[6], 0);
				if (!flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_PLAYER_ATTACK, (Module*)App->player2);
					attack->SetPos(position.x + 60, position.y - 50);
				}
				if (flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_PLAYER_ATTACK, (Module*)App->player2);
					attack->SetPos(position.x - 55, position.y - 50);
				}
				break;
			case STG_KICK_STANDING:
				LOG("KICK STANDING ----\n");
				kicked = true; action = true;
				if (!flipPlayer) {
					Mix_PlayChannel(-1, App->audio->effects[2], 0);
					attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_PLAYER_ATTACK, this);
					attack->SetPos(position.x + 30, position.y - 50);
				}
				if (flipPlayer) {
					Mix_PlayChannel(-1, App->audio->effects[2], 0);
					attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_PLAYER_ATTACK, this);
					attack->SetPos(position.x - 25, position.y - 50);
				}
				break;
			case STG_SLASH_NEUTRAL_JUMP:
				LOG("SLASH JUMP NEUTRAL ^^++\n");
				sJump = true; action = true;
				break;
			case STG_SLASH_FORWARD_JUMP:
				LOG("SLASH JUMP FORWARD ^>>+\n");
				sJumpF = true; action = true;
				break;
			case STG_SLASH_BACKWARD_JUMP:
				LOG("SLASH JUMP BACKWARD ^<<+\n");
				sJumpB = true; action = true;
				break;
			case STG_SPECIAL:
				LOG("TORNADO\n");
				tornadoMov = true; action = true;
				Mix_PlayChannel(-1, App->audio->effects[3], 0);
				Mix_PlayChannel(-1, App->audio->effects[4], 0);
				tornadoMov = true;
				action = true;
				if (!flipPlayer) {
					App->particles->tornado.speed.x = +3;
					App->particles->AddParticle(App->particles->tornado, position.x + 20, position.y - 77, COLLIDER_PLAYER_SHOT);
				}
				else {
					App->particles->tornado.speed.x = -3;
					App->particles->AddParticle(App->particles->tornado, position.x - 20, position.y - 77, COLLIDER_PLAYER_SHOT);

				}
				break;
			
		}
		//current_state = state;
	}

	/*if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov)
	{
		if (!action && !flipPlayer) { current_animation = &forward; }
		if (!action && flipPlayer) { current_animation = &backward; }
		position.x += speed;
	
	}
		
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov)
	{
		if (!action && !flipPlayer) { current_animation = &backward; }
		if (!action && flipPlayer) { current_animation = &forward; }
		position.x -= speed;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT && !action)
	{

		jumped = true;
		action = true;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_REPEAT && !action && !jumped)
	{
        Mix_PlayChannel(-1, App->audio->effects[2], 0);
		kicked = true;
		action = true;

	}
	if (App->input->keyboard[SDL_SCANCODE_R] == KEY_STATE::KEY_REPEAT && !action && !jumped) {

		Mix_PlayChannel(-1, App->audio->effects[3], 0);
		Mix_PlayChannel(-1, App->audio->effects[4], 0);
		tornadoMov = true;
		action = true;
		if (!flipPlayer) {
			App->particles->tornado.speed.x = +3;
			App->particles->AddParticle(App->particles->tornado, position.x + 20, position.y - 77, COLLIDER_PLAYER_SHOT);
		}
		else {
			App->particles->tornado.speed.x = -3;
			App->particles->AddParticle(App->particles->tornado, position.x - 20, position.y - 77, COLLIDER_PLAYER_SHOT);
			
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_REPEAT && !action)
	{
		Mix_PlayChannel(-1, App->audio->effects[6], 0);
		attacking = true;
		action = true;

	}*/

	

	//GOD MODE
	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
	{
		if (godMode)
			godMode = false;
		else
			godMode = true;

	}
	else if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_UP) {
		if (godMode) {
			GenCollider->to_delete = true;
		}

		if (!godMode) {
			GenCollider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_PLAYER, this);
		}
	}


	if (action) {

		if (jumped) {

			current_animation = &jump;

			position.y = 220 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			grounded = true;


			if (position.y > 220 && grounded == true)	//end of the jump
			{
				Ginputs.Push(ING_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumped = false;
				position.y = 220;
				action = false;


			}
			var1++;

		}
		if (jumpedF) {

			current_animation = &JumpForward;

			position.y = 220 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			position.x += 4;
			grounded = true;


			if (position.y > 220 && grounded == true)	//end of the jump
			{
				Ginputs.Push(ING_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumpedF = false;
				position.y = 220;
				action = false;
				JumpForward.Reset();
				JumpBackward.Reset();


			}
			var1++;


		}
		if (jumpedB) {

			current_animation = &JumpBackward;

			position.y = 220 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			position.x -= 4;
			grounded = true;


			if (position.y > 220 && grounded == true)	//end of the jump
			{
				Ginputs.Push(ING_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumpedB = false;
				position.y = 220;
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
				Ginputs.Push(ING_KICK_FINISH);

				kick.finishingAnimation(false);
			}

		}
		if (tornadoMov) {

			current_animation = &tornadoMove;
			if (tornadoMove.FinishedAnimation() == true) {

				tornadoMov = false;
				action = false;
				Ginputs.Push(ING_SPECIAL_FINISH);

				tornadoMove.finishingAnimation(false);
			}

		}
		if (attacking) {

			current_animation = &sAttack;
			if (sAttack.FinishedAnimation() == true) {

				attacking = false;
				action = false;
				attack->to_delete = true;
				Ginputs.Push(ING_SLASH_FINISH);

				sAttack.finishingAnimation(false);
			}

		}
		/*if (sCrouched) {

			current_animation = &sCrouch;
			if (sCrouch.FinishedAnimation() == true) {

				sCrouched = false;
				action = false;
				attack->to_delete = true;
				inputs.Push(IN_SLASH_FINISH);

				sCrouch.finishingAnimation(false);
			}

		}*/
		if (crouched) {

			current_animation = &crouchD;
			if (crouchD.FinishedAnimation() == true) {

				crouched = false;
				action = false;

				crouchD.finishingAnimation(false);
			}

		}
		if (isDead) {

			current_animation = &death;
			GenCollider->to_delete = true;
			if (death.FinishedAnimation() == true) {
				current_animation = &dead;
				}
			}
		}
	}
	
	if (hp <= 0) { isDead = true; action = true; }

	
	if (App->player2->isDead == true) {

		current_state = STG_VICTORY;
	}
	if (getsHit) {

		action = true;
		current_animation = &hit;
		if (hit.Finished() == true) {
			action = false;
			getsHit = false;
			current_state = STG_IDLE;

		}

	}

	if (!flipPlayer) {

		GenCollider->SetPos(position.x + 20, position.y - 80);
		
	}
	if (flipPlayer) {

			GenCollider->SetPos(position.x + 10, position.y - 80);	
	}
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	//OnPassing(App->player2);
	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, flipPlayer);

	
	return UPDATE_CONTINUE;
}



void ModuleGen::OnCollision(Collider* c1, Collider* c2) {
	
	switch (c2->type) {

	case COLLIDER_ENEMY_ATTACK:
		if (c2->to_delete == false) { c2->to_delete = true; }
		hp -= 10;
		getsHit = true;
		LOG("HURT 10")
		Mix_PlayChannel(-1, App->audio->effects[7], 0);
	case COLLIDER_ENEMY_SHOT:
		if (c2->to_delete == false) { c2->to_delete = true; }
		getsHit = true;
		hp -= 20;
		Mix_PlayChannel(-1, App->audio->effects[8], 0);
	}
}

/*
void ModuleGen::OnPassing(ModulePlayer2* p2) {

	if (flipPlayer) {
		
			if ((this->position.x + 60) < p2->position.x) {
				flipPlayer = false;
				LOG("Player1 flip = false")
				if (current_state == ST_WALK_FORWARD) { current_state = ST_WALK_BACKWARD; }

		}
	}
	if (!flipPlayer) {

		
		if (this->position.x > (p2->position.x + 60)) {
				flipPlayer = true;
				LOG("Player1 flip = true")	
				if (current_state == ST_WALK_FORWARD) { current_state = ST_WALK_BACKWARD; }
		}
	}

	
}
*/

bool ModuleGen::external_input(p2Qeue<Gen_inputs>& inputs)
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
				case SDLK_s:
					inputs.Push(ING_CROUCH_UP);
					down = false;
					break;
				case SDLK_w:
					up = false;
					break;
				case SDLK_a:
					inputs.Push(ING_LEFT_UP);
					left = false;
					break;
				case SDLK_d:
					inputs.Push(ING_RIGHT_UP);
					right = false;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_q:
					inputs.Push(ING_SLASH);
					break;
				case SDLK_e:
					inputs.Push(ING_KICK);
					break;
				case SDLK_r:
					inputs.Push(ING_SPECIAL);
					break;
				case SDLK_w:
					up = true;
					break;
				case SDLK_s:
					down = true;
					break;
				case SDLK_a:
					left = true;
					break;
				case SDLK_d:
					right = true;
					break;
				}
			}
		}

		if (left && right)
			inputs.Push(ING_LEFT_AND_RIGHT);
		{
			if (left)
				inputs.Push(ING_LEFT_DOWN);
			if (right)
				inputs.Push(ING_RIGHT_DOWN);
		}

		if (up && down)
			inputs.Push(ING_JUMP_AND_CROUCH);
		else
		{
			if (down)
				inputs.Push(ING_CROUCH_DOWN);
			else
				inputs.Push(ING_CROUCH_UP);
			if (up)
				inputs.Push(ING_JUMP);
		}

		return true;
	}
}

Gen_states ModuleGen::process_fsm(p2Qeue<Gen_inputs>& inputs)
{
	static Gen_states state = STG_IDLE;
	Gen_inputs last_input;

	while (inputs.Pop(last_input))
	{
		switch (state)
		{
		case ST_IDLE:
		{
			switch (last_input)
			{
			case ING_RIGHT_DOWN: if (!flipPlayer) { state = STG_WALK_FORWARD; break; }
								if(flipPlayer) { state = STG_WALK_BACKWARD; break; }
			case ING_LEFT_DOWN: if (!flipPlayer) { state = STG_WALK_BACKWARD; break;	}
							   if (flipPlayer) { state = STG_WALK_FORWARD; break;	}
			case ING_JUMP: state = STG_JUMP_NEUTRAL;  break;
			case ING_CROUCH_DOWN: state = STG_CROUCH; break;
			case ING_SLASH: state = STG_SLASH_STANDING; break;
			case ING_KICK: state = STG_KICK_STANDING; break;
			case ING_SPECIAL: state = STG_SPECIAL; break;

			}
		}
		break;

		case STG_WALK_FORWARD:
		{
			switch (last_input)
			{
			if (flipPlayer) { case ING_LEFT_UP: state = STG_IDLE; break; }
			if (!flipPlayer) { case ING_RIGHT_UP: state = STG_IDLE; break; }
			case ING_LEFT_AND_RIGHT: state = STG_IDLE; break;
			case ING_JUMP: 
				if (!flipPlayer) { state = STG_JUMP_FORWARD; }
				if (flipPlayer) { state = STG_JUMP_BACKWARD; }
				break;
			case ING_CROUCH_DOWN: state = STG_CROUCH; break;
			}
		}
		break;

		case STG_WALK_BACKWARD:
		{
			switch (last_input)
			{
			if (!flipPlayer) {case ING_LEFT_UP: state = STG_IDLE; break;}
			if (flipPlayer) { case ING_RIGHT_UP: state = STG_IDLE; break; }
			case ING_LEFT_AND_RIGHT: state = STG_IDLE; break;
			case ING_JUMP: 
				if (!flipPlayer) { state = STG_JUMP_BACKWARD; }
				if (flipPlayer) { state = STG_JUMP_FORWARD; }
				break;
			case IN_CROUCH_DOWN: state = STG_CROUCH; break;
			}
		}
		break;

		case STG_JUMP_NEUTRAL:
		{
			switch (last_input)
			{
			case ING_JUMP_FINISH: state = STG_IDLE; break;
			case ING_SLASH: state = STG_SLASH_NEUTRAL_JUMP; break;
			}
		}
		break;

		case STG_JUMP_FORWARD:
		{
			switch (last_input)
			{
			case ING_JUMP_FINISH: state = STG_IDLE; break;
			case ING_SLASH: state = STG_SLASH_FORWARD_JUMP; break;
			}
		}
		break;

		case STG_JUMP_BACKWARD:
		{
			switch (last_input)
			{
			case ING_JUMP_FINISH: state = STG_IDLE; break;
			case ING_SLASH: state = STG_SLASH_BACKWARD_JUMP; break;
			}
		}
		break;

		case STG_SLASH_NEUTRAL_JUMP:
		{
			switch (last_input)
			{
			case ING_SLASH_FINISH: state = STG_IDLE; break;
			case ING_JUMP_FINISH: state = STG_IDLE; break;
			}
		}
		break;

		case STG_SLASH_FORWARD_JUMP:
		{
			switch (last_input)
			{
			case ING_SLASH_FINISH: state = STG_IDLE; break;
			case ING_JUMP_FINISH: state = STG_IDLE; break;
			}
		}
		break;

		case STG_SLASH_BACKWARD_JUMP:
		{
			switch (last_input)
			{
			case ING_SLASH_FINISH: state = STG_IDLE; break;
			case ING_JUMP_FINISH: state = STG_IDLE; break;
			}
		}
		break;

		case STG_SLASH_STANDING:
		{
			switch (last_input)
			{
			case ING_SLASH_FINISH: state = STG_IDLE; break;
			}
		}
		break;

		case STG_CROUCH:
		{
			switch (last_input)
			{
			case ING_CROUCH_UP: state = STG_IDLE; break;
			case ING_SLASH: state = STG_SLASH_CROUCH; break;
			}
		}
		break;
		case STG_SLASH_CROUCH:
		{
			switch (last_input)
			{
			case ING_CROUCH_UP && IN_SLASH_FINISH: state = STG_IDLE; break;
			case ING_SLASH_FINISH: state = STG_CROUCH; break;
			}
		}
		case STG_KICK_STANDING:
		{
			switch (last_input)
			{
			case ING_KICK_FINISH: 
				state = STG_IDLE;

				break;
			}
		}
		case STG_SPECIAL:
		{
			switch (last_input)
			{
			case ING_SPECIAL_FINISH: state = STG_IDLE; break;
			}
		}
		break;
		}
	}
	return state;
}