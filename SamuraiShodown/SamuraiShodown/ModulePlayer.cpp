#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

ModulePlayer::ModulePlayer()
{
	position.x = 50;
	position.y = 220;

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
	sAttack.PushBack({ 22, 446, 67, 127 });
	sAttack.PushBack({ 90, 477, 78, 96 });	
	sAttack.PushBack({ 169, 480, 130, 93 });
	sAttack.PushBack({ 300, 480, 130, 93 });
	sAttack.PushBack({ 431, 491, 129, 82 });
	sAttack.PushBack({ 561, 491, 127, 82 });
	sAttack.PushBack({ 689, 491, 119, 82 });
	sAttack.PushBack({ 809, 488, 130, 85 });

	sAttack.speed = 0.3f;

	// crouch 
	crouchD.PushBack({ 22, 432, 68, 110 });
	crouchD.PushBack({ 101, 432, 68, 110 });
	crouchD.PushBack({ 187, 432, 68, 110 });
	crouchD.PushBack({ 304, 467, 89, 75 });
	crouchD.PushBack({ 434, 467, 89, 75 });
	crouchD.PushBack({ 560, 467, 89, 75 });
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
	JumpForward.PushBack({ 1229,592 ,82 ,61});
	JumpForward.PushBack({ 1318,592 ,82 ,61 });
	JumpForward.PushBack({ 1410,592 ,82 ,61 });
	JumpForward.PushBack({ 1213,462 ,76 ,83});
	JumpForward.PushBack({ 1299,462 ,76 ,83 });
	JumpForward.PushBack({ 1387,462 ,76 ,83 });

	// jump bakward

	JumpBackward.PushBack({ 22, 720, 60, 112 });
	JumpBackward.PushBack({ 89, 720, 60, 112 });
	JumpBackward.PushBack({ 157, 720, 60, 112 });
	JumpForward.PushBack({ 231,592, 74, 91 });
	JumpForward.PushBack({ 314,592, 74, 91 });
	JumpForward.PushBack({ 398,592, 74, 91 });
	JumpForward.PushBack({ 1229,592 ,82 ,61 });
	JumpForward.PushBack({ 1318,592 ,82 ,61 });
	JumpForward.PushBack({ 1410,592 ,82 ,61 });
	JumpForward.PushBack({ 988,592 ,61 ,81 });
	JumpForward.PushBack({ 1073,592 ,61 ,81 });
	JumpForward.PushBack({ 1158,592 ,61 ,81 });
	JumpForward.PushBack({ 713,592 ,82 ,61 });
	JumpForward.PushBack({ 805,592 ,82 ,61 });
	JumpForward.PushBack({ 895,592 ,82 ,61 });
	JumpForward.PushBack({ 485,589, 61, 82 });
	JumpForward.PushBack({ 566,589, 61, 82 });
	JumpForward.PushBack({ 638,589, 61, 82 });
	JumpForward.PushBack({ 1213,462 ,76 ,83 });
	JumpForward.PushBack({ 1299,462 ,76 ,83 });
	JumpForward.PushBack({ 1387,462 ,76 ,83 });

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
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/Haohmaru.png");
	
	App->audio->effects[2] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/HaomaruKick.wav");
	App->audio->effects[3] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/HaohmaruTornado.wav");
	App->audio->effects[4] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/TornadoFX.wav");
	App->audio->effects[6] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/Slash.wav");
	
	p1Collider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_PLAYER, this);
	current_state = ST_IDLE;
	return ret;
}

bool ModulePlayer::CleanUp(){

	LOG("Unloading Character");
	App->textures->Unload(graphics);

	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;
	
	int speed = 2;
	float yVelocity = 15.1f;
	float yAcceleration = 0.87f;
	

	if (external_input(inputs))
	{
		
		player_states state = process_fsm(inputs);

		if (!action) {
			switch (state)
			{
			case ST_IDLE:
				LOG("IDLE\n");
				current_animation = &idle;
				break;
			case ST_WALK_FORWARD:
				LOG("FORWARD >>>\n");
				current_animation = &forward;			
				if (!action && !flipPlayer) { position.x += speed; }
				if (!action && flipPlayer) { position.x -= speed; }
				
				break;
			case ST_WALK_BACKWARD:
				LOG("BACKWARD <<<\n");
				current_animation = &backward;
				if (!action && !flipPlayer) { position.x -= speed; }
				if (!action && flipPlayer) { position.x += speed; }
				break;
			case ST_JUMP_NEUTRAL:
				LOG("jumped NEUTRAL ^^^^\n");
				jumped = true; action = true;
				break;
			case ST_JUMP_FORWARD:
				LOG("jumped FORWARD ^^>>\n");
				jumped = true; action = true;
				break;
			case ST_JUMP_BACKWARD:
				LOG("jumped BACKWARD ^^<<\n");
				jumped = true; action = true;
				break;
			case ST_CROUCH:
				LOG("CROUCHING ****\n");
				crouched = true; action = true;
				break;
			case ST_SLASH_CROUCH:
				LOG("SLASH CROUCHING **++\n");
				sCrouch = true; action = true;
				break;
			case ST_SLASH_STANDING:
				LOG("SLASH STANDING ++++\n");
				attacking = true; action = true;
				if (!flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_PLAYER_ATTACK, (Module*)App->player2);
					attack->SetPos(position.x + 60, position.y - 50);
				}
				if (flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 67, 30 }, COLLIDER_PLAYER_ATTACK, (Module*)App->player2);
					attack->SetPos(position.x - 55, position.y - 50);
				}
				break;
			case ST_KICK_STANDING:
				LOG("KICK STANDING ----\n");
				kicked = true; action = true;
				if (!flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_PLAYER_ATTACK, this);
					attack->SetPos(position.x + 30, position.y - 50);
				}
				if (flipPlayer) {

					attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_PLAYER_ATTACK, this);
					attack->SetPos(position.x - 25, position.y - 50);
				}
				break;
			case ST_SLASH_NEUTRAL_JUMP:
				LOG("SLASH JUMP NEUTRAL ^^++\n");
				sJump = true; action = true;
				break;
			case ST_SLASH_FORWARD_JUMP:
				LOG("SLASH JUMP FORWARD ^>>+\n");
				sJumpF = true; action = true;
				break;
			case ST_SLASH_BACKWARD_JUMP:
				LOG("SLASH JUMP BACKWARD ^<<+\n");
				sJumpB = true; action = true;
				break;
			case ST_SPECIAL:
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
		}
		current_state = state;
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
			p1Collider->to_delete = true;
		}

		if (!godMode) {
			p1Collider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_PLAYER, this);
		}
	}


	if(action){
	
		if (jumped) {

			current_animation = &jump;

			position.y = 220 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			grounded = true;

			
			if (position.y > 220 && grounded == true)	//end of the jump
			{
				inputs.Push(IN_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumped = false;
				position.y = 220;
				action = false;

			}
			var1++;

		}

		if (kicked) {
			
			current_animation = &kick;
			
			if (kick.FinishedAnimation() == true) {
			
				kicked = false; 
				action = false;
				attack->to_delete = true;
				inputs.Push(IN_KICK_FINISH);

				kick.finishingAnimation(false); 
			}
		
		}
		if (tornadoMov) {

			current_animation = &tornadoMove;
			if (tornadoMove.FinishedAnimation() == true) {

				tornadoMov = false;
				action = false;
				inputs.Push(IN_SPECIAL_FINISH);

				tornadoMove.finishingAnimation(false);
			}

		}
		if (attacking) {

			current_animation = &sAttack;
			if (sAttack.FinishedAnimation() == true) {

				attacking = false;
				action = false;
				attack->to_delete = true;
				inputs.Push(IN_SLASH_FINISH);

				sAttack.finishingAnimation(false);
			}

		}
		if (crouched) {

			current_animation = &crouchD;


		}
	
	
	}

	if (!flipPlayer) {
		p1Collider->SetPos(position.x + 20, position.y - 80);
	}
	else {
		p1Collider->SetPos(position.x + 10, position.y - 80);
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	OnPassing(App->player2);
	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, flipPlayer);

	
	return UPDATE_CONTINUE;
}



void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {
	
	switch (c2->type) {

	case COLLIDER_ENEMY_ATTACK:
		App->player2->attack->to_delete = true;
		hp -= 10;
	case COLLIDER_ENEMY_SHOT:
		
		hp -= 20;
	}
}

void ModulePlayer::OnPassing(ModulePlayer2* p2) {

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

bool ModulePlayer::external_input(p2Qeue<player_inputs>& inputs)
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
					inputs.Push(IN_CROUCH_UP);
					down = false;
					break;
				case SDLK_w:
					up = false;
					break;
				case SDLK_a:
					inputs.Push(IN_LEFT_UP);
					left = false;
					break;
				case SDLK_d:
					inputs.Push(IN_RIGHT_UP);
					right = false;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_q:
					inputs.Push(IN_SLASH);
					break;
				case SDLK_e:
					inputs.Push(IN_KICK);
					break;
				case SDLK_r:
					inputs.Push(IN_SPECIAL);
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
			inputs.Push(IN_LEFT_AND_RIGHT);
		{
			if (left)
				inputs.Push(IN_LEFT_DOWN);
			if (right)
				inputs.Push(IN_RIGHT_DOWN);
		}

		if (up && down)
			inputs.Push(IN_JUMP_AND_CROUCH);
		else
		{
			if (down)
				inputs.Push(IN_CROUCH_DOWN);
			else
				inputs.Push(IN_CROUCH_UP);
			if (up)
				inputs.Push(IN_JUMP);
		}

		return true;
	}
}

player_states ModulePlayer::process_fsm(p2Qeue<player_inputs>& inputs)
{
	static player_states state = ST_IDLE;
	player_inputs laST_input;

	while (inputs.Pop(laST_input))
	{
		switch (state)
		{
		case ST_IDLE:
		{
			switch (laST_input)
			{
			case IN_RIGHT_DOWN: if (!flipPlayer) { state = ST_WALK_FORWARD; break; }
								if(flipPlayer) { state = ST_WALK_BACKWARD; break; }
			case IN_LEFT_DOWN: if (!flipPlayer) { state = ST_WALK_BACKWARD; break;	}
							   if (flipPlayer) { state = ST_WALK_FORWARD; break;	}
			case IN_JUMP: state = ST_JUMP_NEUTRAL;  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_SLASH: state = ST_SLASH_STANDING; break;
			case IN_KICK: state = ST_KICK_STANDING; break;
			case IN_SPECIAL: state = ST_SPECIAL; break;

			}
		}
		break;

		case ST_WALK_FORWARD:
		{
			switch (laST_input)
			{
			if (flipPlayer) { case IN_LEFT_UP: state = ST_IDLE; break; }
			if (!flipPlayer) { case IN_RIGHT_UP: state = ST_IDLE; break; }
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_FORWARD;  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			}
		}
		break;

		case ST_WALK_BACKWARD:
		{
			switch (laST_input)
			{
			if (!flipPlayer) {case IN_LEFT_UP: state = ST_IDLE; break;}
			if (flipPlayer) { case IN_RIGHT_UP: state = ST_IDLE; break; }
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_BACKWARD; break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			}
		}
		break;

		case ST_JUMP_NEUTRAL:
		{
			switch (laST_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			case IN_SLASH: state = ST_SLASH_NEUTRAL_JUMP; break;
			}
		}
		break;

		case ST_JUMP_FORWARD:
		{
			switch (laST_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			case IN_SLASH: state = ST_SLASH_FORWARD_JUMP; break;
			}
		}
		break;

		case ST_JUMP_BACKWARD:
		{
			switch (laST_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			case IN_SLASH: state = ST_SLASH_BACKWARD_JUMP; break;
			}
		}
		break;

		case ST_SLASH_NEUTRAL_JUMP:
		{
			switch (laST_input)
			{
			case IN_SLASH_FINISH: state = ST_IDLE; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_SLASH_FORWARD_JUMP:
		{
			switch (laST_input)
			{
			case IN_SLASH_FINISH: state = ST_IDLE; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_SLASH_BACKWARD_JUMP:
		{
			switch (laST_input)
			{
			case IN_SLASH_FINISH: state = ST_IDLE; break;
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_SLASH_STANDING:
		{
			switch (laST_input)
			{
			case IN_SLASH_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_CROUCH:
		{
			switch (laST_input)
			{
			case IN_CROUCH_UP: state = ST_IDLE; break;
			case IN_SLASH: state = ST_SLASH_CROUCH; break;
			}
		}
		break;
		case ST_SLASH_CROUCH:
		{
			switch (laST_input)
			{
			case IN_CROUCH_UP && IN_SLASH_FINISH: state = ST_IDLE; break;
			case IN_SLASH_FINISH: state = ST_CROUCH; break;
			}
		}
		case ST_KICK_STANDING:
		{
			switch (laST_input)
			{
			case IN_KICK_FINISH: state = ST_IDLE; break;
			}
		}
		case ST_SPECIAL:
		{
			switch (laST_input)
			{
			case IN_SPECIAL_FINISH: state = ST_IDLE; break;
			}
		}
		break;
		}
	}
	return state;
}