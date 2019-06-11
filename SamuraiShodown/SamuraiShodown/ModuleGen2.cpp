#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleGen.h"
#include "ModuleGen2.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"


ModuleGen2::ModuleGen2()
{
	position.x = 200;
	position.y = 210;

	// light attack crouch

	lightattackc.PushBack({ 42,2087,88,56 });
	lightattackc.PushBack({ 132,2087,88,56 });
	lightattackc.PushBack({ 220,2087,103,56 });
	lightattackc.PushBack({ 326,2087,103,56 });
	lightattackc.PushBack({ 434,2085,158,54 });
	lightattackc.PushBack({ 607,2085,158,54 });
	lightattackc.PushBack({ 775,2086,170,55 });
	lightattackc.PushBack({ 945,2086,170,55 });
	lightattackc.PushBack({ 1118,2086,169,55 });
	lightattackc.PushBack({ 1290,2086,169,55 });
	lightattackc.PushBack({ 1461,2086,169,55 });
	lightattackc.PushBack({ 1633,2086,169,55 });

	lightattackc.speed = 0.5f;
	lightattackc.loop = true;

	// idle animation
	idle.PushBack({ 1722,555,68,122 });
	idle.PushBack({ 1818,564,81,113 });
	idle.PushBack({ 1917,553,82,124 });
	idle.PushBack({ 1726,694,84,117 });
	idle.PushBack({ 1822,685,80,126 });
	idle.PushBack({ 1915,687,84,124 });
	idle.speed = 0.14f;

	// walk forward animation 
	forward.PushBack({ 1174,388,88,117 });
	forward.PushBack({ 1262,388,84,117 });
	forward.PushBack({ 1346,382,83,123 });
	forward.PushBack({ 1429,383,68,122 });

	forward.speed = 0.14f;
	forward.loop = true;

	// walk backward animation 
	backward.PushBack({ 1174,388,88,117 });
	backward.PushBack({ 1262,388,84,117 });
	backward.PushBack({ 1346,382,83,123 });
	backward.PushBack({ 1429,383,68,122 });

	backward.speed = 0.14f;
	backward.loop = true;

	// jump animation
	jump.PushBack({ 634,628,80,103 });
	jump.PushBack({ 720,628,97,86 });
	jump.PushBack({ 832,647,105,64 });

	jump.speed = 0.07f;
	jump.loop = true;

	kick.PushBack({ 45,2450,82,124 });
	kick.PushBack({ 45,2450,82,124 });
	kick.PushBack({ 220,2450,85,118 });
	kick.PushBack({ 220,2450,85,118 });
	kick.PushBack({ 398,2450,72,109 });
	kick.PushBack({ 398,2450,72,109 });
	kick.PushBack({ 556,2450,82,109 });
	kick.PushBack({ 556,2450,82,109 });
	kick.PushBack({ 398,2450,72,109 });
	kick.PushBack({ 398,2450,72,109 });
	kick.PushBack({ 220,2450,85,118 });
	kick.PushBack({ 220,2450,85,118 });
	kick.PushBack({ 45,2450,82,124 });
	kick.PushBack({ 45,2450,82,124 });

	kick.speed = 0.5f;
	kick.loop = true;

	poison.PushBack({ 835,2465,97,72 });
	poison.PushBack({ 945,2464,75,75 });
	poison.PushBack({ 945,2464,75,75 });
	poison.PushBack({ 835,2465,97,72 });
	poison.PushBack({ 1172,2471,103,60 });
	poison.PushBack({ 1307,2470,127,60 });
	poison.PushBack({ 1455,2470,145,62 });
	poison.PushBack({ 1455,2470,145,62 });
	poison.PushBack({ 1620,2465,162,72 });
	poison.PushBack({ 65,2583,178,89 });
	poison.PushBack({ 257,2583,178,89 });
	poison.PushBack({ 453,2583,178,89 });
	poison.PushBack({ 453,2583,178,89 });
	poison.PushBack({ 1029,2579,182,93 });
	poison.PushBack({ 1212,2579,228,93 });
	poison.PushBack({ 1212,2579,228,93 });
	poison.PushBack({ 1212,2579,228,93 });
	poison.PushBack({ 1794,2578,229,102 });
	//poison.PushBack({ 1794,2578,229,102 });
	poison.PushBack({ 1794,2578,229,102 });
	//poison.PushBack({ 512,2701,227,98 });
	poison.PushBack({ 512,2701,227,98 });

	//poison.PushBack({ 1191,2701,232,98 });

	poison.PushBack({ 1191,2701,232,98 });
	//poison.PushBack({ 538,2834,227,92 });
	poison.PushBack({ 538,2834,227,92 });

	poison.PushBack({ 1239,2845,174,73 });

	poison.speed = 0.25f;
	poison.loop = true;


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

	crouch.PushBack({ 257,1612,88,56 });

	mediumattack.PushBack({ 42,2299,96,70 });
	mediumattack.PushBack({ 139,2299,96,70 });
	mediumattack.PushBack({ 238,2300,150,69 });
	mediumattack.PushBack({ 389,2300,150,69 });
	mediumattack.PushBack({ 542,2300,166,69 });
	mediumattack.PushBack({ 711,2300,166,69 });
	mediumattack.PushBack({ 878,2300,166,69 });
	mediumattack.PushBack({ 1045,2300,166,69 });
	mediumattack.PushBack({ 1212,2300,166,69 });
	mediumattack.PushBack({ 1379,2300,166,69 });
	mediumattack.PushBack({ 1547,2275,94,70 });
	mediumattack.PushBack({ 1647,2275,94,70 });
	mediumattack.PushBack({ 1747,2287,89,82 });
	mediumattack.PushBack({ 1837,2287,89,82 });
	mediumattack.PushBack({ 1928,2297,83,72 });
	mediumattack.PushBack({ 1761,2203,83,72 });
	mediumattack.PushBack({ 1857,2203,88,72 });
	mediumattack.PushBack({ 1953,2203,88,72 });

	mediumattack.speed = 0.4f;
	mediumattack.loop = true;

	// crouch 
	crouchD.PushBack({ 22, 432, 68, 110 });
	crouchD.PushBack({ 101, 432, 68, 110 });
	crouchD.PushBack({ 187, 432, 68, 110 });
	crouchD.PushBack({ 304, 467, 89, 75 });
	crouchD.PushBack({ 434, 467, 89, 75 });
	crouchD.PushBack({ 560, 467, 89, 75 });
	crouchD.speed = 0.3f;
	crouchD.loop = true;

	// jump forward

	JumpForward.PushBack({ 650,387,96,153 });
	JumpForward.PushBack({ 744,387,98,175 });
	JumpForward.PushBack({ 858,387,96,128 });

	JumpForward.speed = 0.14f;
	JumpForward.loop = false;

	// jump backward

	JumpBackward.PushBack({ 650,387,96,153 });
	JumpBackward.PushBack({ 744,387,98,175 });
	JumpBackward.PushBack({ 858,387,96,128 });

	JumpBackward.speed = 0.14f;
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

ModuleGen2::~ModuleGen2()
{}

// Load assets
bool ModuleGen2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Gen-An/22.png");
	
	action = false;
	hp = 8000;

	flipPlayer = true;
	
	App->audio->effects[13] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Common/attackgen.wav");
	App->audio->effects[14] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Common/SLASHGEN.wav");
	App->audio->effects[15] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/GenAn/POISONCLOUD.wav");
	App->audio->effects[6] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/Slash.wav");
	App->audio->effects[7] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/hit.wav");
	App->audio->effects[8] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersSounds/Haohmaru/hit2.wav");


	Gen2Collider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_ENEMY, this);
	Ginputs.Clear();

	current_state = STG_2IDLE;
	return ret;
}

bool ModuleGen2::CleanUp(){

	LOG("Unloading Character");
	App->textures->Unload(graphics);

	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleGen2::Update()
{
	Animation* current_animation = &idle;
	

	int speed = 2;
	float yVelocity = 15.1f;
	float yAcceleration = 0.87f;
	

	if (external_input(Ginputs))
	{
		
		Gen2_states state = process_fsm(Ginputs);

		if (!action) {
			switch (state)
			{
			case STG_2IDLE:
				LOG("IDLE\n");
				current_animation = &idle;
				break;
			case STG_2WALK_FORWARD:
				LOG("FORWARD >>>\n");
				current_animation = &forward;			
				if (!action && !flipPlayer) { position.x += speed; }
				if (!action && flipPlayer) { position.x -= speed; }
				
				break;
			case STG_2WALK_BACKWARD:
				LOG("BACKWARD <<<\n");
				current_animation = &backward;
				if (!action && !flipPlayer) { position.x -= speed; }
				if (!action && flipPlayer) { position.x += speed; }
				break;
			case STG_2JUMP_NEUTRAL:
				LOG("jumped NEUTRAL ^^^^\n");
				jumped = true; action = true;
				break;
			case STG_2JUMP_FORWARD:
				LOG("jumped FORWARD ^^>>\n");
				jumpedF = true; action = true;
				break;
			case STG_2JUMP_BACKWARD:
				LOG("jumped BACKWARD ^^<<\n");
				jumpedB = true; action = true;
				break;
			case STG_2CROUCH:
				LOG("CROUCHING ****\n");
				crouched = true; action = true;
				break;
			case STG_2SLASH_CROUCH:
				LOG("SLASH CROUCHING **++\n");
				sCrouched = true; action = true;
			
				break;
			case STG_2SLASH_STANDING:
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
			case STG_2KICK_STANDING:
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
			case STG_2SLASH_NEUTRAL_JUMP:
				LOG("SLASH JUMP NEUTRAL ^^++\n");
				sJump = true; action = true;
				break;
			case STG_2SLASH_FORWARD_JUMP:
				LOG("SLASH JUMP FORWARD ^>>+\n");
				sJumpF = true; action = true;
				break;
			case STG_2SLASH_BACKWARD_JUMP:
				LOG("SLASH JUMP BACKWARD ^<<+\n");
				sJumpB = true; action = true;
				break;
			case STG_2SPECIAL:
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

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov && !action && !getsHit)
	{
		if (!action && !flipPlayer) { current_animation = &forward; }
		if (!action && flipPlayer) { current_animation = &backward; }
		position.x += speed;
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && !action)
		{
			if (!action && !flipPlayer) { current_animation = &JumpBackward; }
			if (!action && flipPlayer) { current_animation = &JumpForward; }

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
			if (!action && !flipPlayer) { current_animation = &JumpBackward; }
			if (!action && flipPlayer) { current_animation = &JumpForward; }
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
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov && !action && !getsHit)
		{
			crouchedD = true;
			action = true;
			if (!action && !flipPlayer) { current_animation = &forward; }
			if (!action && flipPlayer) { current_animation = &backward; }
			position.x += speed;

		}

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov && !action && !getsHit)
		{
			crouchedD = true;
			action = true;
			if (!action && !flipPlayer) { current_animation = &forward; }
			if (!action && flipPlayer) { current_animation = &backward; }
			position.x -= speed;

		}
	}
	if (App->input->keyboard[SDL_SCANCODE_KP_2] == KEY_STATE::KEY_REPEAT && !action && !jumped)
	{
		Mix_PlayChannel(-1, App->audio->effects[2], 0);
		Mattack = true; action = true;
		if (!flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
			attack->SetPos(position.x + 30, position.y - 50);
		}
		if (flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
			attack->SetPos(position.x - 25, position.y - 50);
		}

	}
	
	if (App->input->keyboard[SDL_SCANCODE_KP_1] == KEY_STATE::KEY_REPEAT && !action)
	{
		Mix_PlayChannel(-1, App->audio->effects[13], 0);
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

	if (App->input->keyboard[SDL_SCANCODE_KP_4] == KEY_STATE::KEY_REPEAT && !action && !jumped)
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

	if (App->input->keyboard[SDL_SCANCODE_KP_3] == KEY_STATE::KEY_DOWN && !action && !jumped)
	{
		Mix_PlayChannel(-1, App->audio->effects[2], 0);
		poisonA = true; action = true;
		if (!flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
			attack->SetPos(position.x + 30, position.y - 50);
		}
		if (flipPlayer) {

			attack = App->collision->AddCollider({ position.x, position.y, 70, 35 }, COLLIDER_ENEMY_ATTACK, this);
			attack->SetPos(position.x - 25, position.y - 50);
		}

	}

	

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
			Gen2Collider->to_delete = true;
		}

		if (!godMode) {
			Gen2Collider = App->collision->AddCollider({ position.x, position.y - 70, 40, 70 }, COLLIDER_PLAYER, this);
		}
	}


	if (action) {

		if (jumped) {

			current_animation = &jump;

			position.y =  210 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			grounded = true;


			if (position.y >  210 && grounded == true)	//end of the jump
			{
				Ginputs.Push(ING2_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumped = false;
				position.y =  210;
				action = false;


			}
			var1++;

		}

		if (jumpedF) {

			current_animation = &JumpForward;

			position.y =  210 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			position.x += 4;
			grounded = true;


			if (position.y >  210 && grounded == true)	//end of the jump
			{
				Ginputs.Push(ING2_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumpedF = false;
				position.y =  210;
				action = false;
				JumpForward.Reset();
				JumpBackward.Reset();


			}
			var1++;


		}
		if (jumpedB) {

			current_animation = &JumpBackward;

			position.y =  210 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			position.x -= 4;
			grounded = true;


			if (position.y >  210 && grounded == true)	//end of the jump
			{
				Ginputs.Push(ING2_JUMP_FINISH);
				var1 = 0;
				grounded = false;
				jumpedB = false;
				position.y =  210;
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
				Ginputs.Push(ING2_KICK_FINISH);

				kick.finishingAnimation(false);
			}

		}


		if (poisonA) {

			current_animation = &poison;

			if (poison.FinishedAnimation() == true) {

				poisonA = false;
				action = false;
				attack->to_delete = true;
				Ginputs.Push(ING2_KICK_FINISH);

				poison.finishingAnimation(false);
			}

		}


		if (tornadoMov) {

			current_animation = &tornadoMove;
			if (tornadoMove.FinishedAnimation() == true) {

				tornadoMov = false;
				action = false;
				Ginputs.Push(ING2_SPECIAL_FINISH);

				tornadoMove.finishingAnimation(false);
			}

		}
		if (attacking) {

			current_animation = &lightattackc;
			if (lightattackc.FinishedAnimation() == true) {

				attacking = false;
				action = false;
				attack->to_delete = true;
				Ginputs.Push(ING2_SLASH_FINISH);

				lightattackc.finishingAnimation(false);
			}

		}

		if (Mattack) {

			current_animation = &mediumattack;
			if (mediumattack.FinishedAnimation() == true) {

				Mattack = false;
				action = false;
				attack->to_delete = true;
				Ginputs.Push(ING2_SLASH_FINISH);

				mediumattack.finishingAnimation(false);
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

			current_animation = &crouch;
			if (crouch.FinishedAnimation() == true) {

				crouched = false;
				action = false;

				crouch.finishingAnimation(false);
			}

		}

		if (crouchedD) {

			current_animation = &crouchD;
			if (crouchD.FinishedAnimation() == true) {

				crouchedD = false;
				action = false;

				crouchD.finishingAnimation(false);
			}

		}

		if (isDead) {

			current_animation = &death;
			Gen2Collider->to_delete = true;
			if (death.FinishedAnimation() == true) {
				current_animation = &dead;
				}
			}
		}
	}
	
	if (hp <= 0) { isDead = true; action = true; }

	
	if (App->gen->isDead == true) {

		current_state = STG_2VICTORY;
	}
	if (getsHit) {

		action = true;
		current_animation = &hit;
		if (hit.Finished() == true) {
			action = false;
			getsHit = false;
			current_state = STG_2IDLE;

		}

	}

	if (!flipPlayer) {

		Gen2Collider->SetPos(position.x + 20, position.y - 80);
		
	}
	if (flipPlayer) {

			Gen2Collider->SetPos(position.x + 10, position.y - 80);	
	}
	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	OnPassing2(App->gen);
	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, flipPlayer);

	
	return UPDATE_CONTINUE;
}



void ModuleGen2::OnCollision(Collider* c1, Collider* c2) {
	
	switch (c2->type) {

	case COLLIDER_PLAYER_ATTACK:
		if (c2->to_delete == false) { c2->to_delete = true; }
		hp -= 10;
		getsHit = true;
		LOG("HURT 10")
		Mix_PlayChannel(-1, App->audio->effects[7], 0);
	case COLLIDER_PLAYER_SHOT:
		if (c2->to_delete == false) { c2->to_delete = true; }
		getsHit = true;
		hp -= 20;
		Mix_PlayChannel(-1, App->audio->effects[8], 0);
	}
}


void ModuleGen2::OnPassing2(ModuleGen* p1) {

	if (flipPlayer) {
		
			if ((this->position.x + 60) < p1->position.x) {
				flipPlayer = false;
				LOG("Player1 flip = false")
				if (current_state == STG_2WALK_FORWARD) { current_state = STG_2WALK_BACKWARD; }

		}
	}
	if (!flipPlayer) {

		
		if (this->position.x > (p1->position.x + 60)) {
				flipPlayer = true;
				LOG("Player1 flip = true")	
				if (current_state == STG_2WALK_FORWARD) { current_state = STG_2WALK_BACKWARD; }
		}
	}

	
}


bool ModuleGen2::external_input(p2Qeue<Gen2_inputs>& inputs)
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
					inputs.Push(ING2_CROUCH_UP);
					down = false;
					break;
				case SDLK_w:
					up = false;
					break;
				case SDLK_a:
					inputs.Push(ING2_LEFT_UP);
					left = false;
					break;
				case SDLK_d:
					inputs.Push(ING2_RIGHT_UP);
					right = false;
					break;
				}
			}
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_q:
					inputs.Push(ING2_SLASH);
					break;
				case SDLK_e:
					inputs.Push(ING2_KICK);
					break;
				case SDLK_r:
					inputs.Push(ING2_SPECIAL);
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
			inputs.Push(ING2_LEFT_AND_RIGHT);
		{
			if (left)
				inputs.Push(ING2_LEFT_DOWN);
			if (right)
				inputs.Push(ING2_RIGHT_DOWN);
		}

		if (up && down)
			inputs.Push(ING2_JUMP_AND_CROUCH);
		else
		{
			if (down)
				inputs.Push(ING2_CROUCH_DOWN);
			else
				inputs.Push(ING2_CROUCH_UP);
			if (up)
				inputs.Push(ING2_JUMP);
		}

		return true;
	}
}

Gen2_states ModuleGen2::process_fsm(p2Qeue<Gen2_inputs>& inputs)
{
	static Gen2_states state = STG_2IDLE;
	Gen2_inputs laSTG_2input;

	while (inputs.Pop(laSTG_2input))
	{
		switch (state)
		{
		case STG_2IDLE:
		{
			switch (laSTG_2input)
			{
			case ING2_RIGHT_DOWN: if (!flipPlayer) { state = STG_2WALK_FORWARD; break; }
								if(flipPlayer) { state = STG_2WALK_BACKWARD; break; }
			case ING2_LEFT_DOWN: if (!flipPlayer) { state = STG_2WALK_BACKWARD; break;	}
							   if (flipPlayer) { state = STG_2WALK_FORWARD; break;	}
			case ING2_JUMP: state = STG_2JUMP_NEUTRAL;  break;
			case ING2_CROUCH_DOWN: state = STG_2CROUCH; break;
			case ING2_SLASH: state = STG_2SLASH_STANDING; break;
			case ING2_KICK: state = STG_2KICK_STANDING; break;
			case ING2_SPECIAL: state = STG_2SPECIAL; break;

			}
		}
		break;

		case STG_2WALK_FORWARD:
		{
			switch (laSTG_2input)
			{
			if (flipPlayer) { case ING2_LEFT_UP: state = STG_2IDLE; break; }
			if (!flipPlayer) { case ING2_RIGHT_UP: state = STG_2IDLE; break; }
			case ING2_LEFT_AND_RIGHT: state = STG_2IDLE; break;
			case ING2_JUMP: 
				if (!flipPlayer) { state = STG_2JUMP_FORWARD; }
				if (flipPlayer) { state = STG_2JUMP_BACKWARD; }
				break;
			case ING2_CROUCH_DOWN: state = STG_2CROUCH; break;
			}
		}
		break;

		case STG_2WALK_BACKWARD:
		{
			switch (laSTG_2input)
			{
			if (!flipPlayer) {case ING2_LEFT_UP: state = STG_2IDLE; break;}
			if (flipPlayer) { case ING2_RIGHT_UP: state = STG_2IDLE; break; }
			case ING2_LEFT_AND_RIGHT: state = STG_2IDLE; break;
			case ING2_JUMP: 
				if (!flipPlayer) { state = STG_2JUMP_BACKWARD; }
				if (flipPlayer) { state = STG_2JUMP_FORWARD; }
				break;
			case ING2_CROUCH_DOWN: state = STG_2CROUCH; break;
			}
		}
		break;

		case STG_2JUMP_NEUTRAL:
		{
			switch (laSTG_2input)
			{
			case ING2_JUMP_FINISH: state = STG_2IDLE; break;
			case ING2_SLASH: state = STG_2SLASH_NEUTRAL_JUMP; break;
			}
		}
		break;

		case STG_2JUMP_FORWARD:
		{
			switch (laSTG_2input)
			{
			case ING2_JUMP_FINISH: state = STG_2IDLE; break;
			case ING2_SLASH: state = STG_2SLASH_FORWARD_JUMP; break;
			}
		}
		break;

		case STG_2JUMP_BACKWARD:
		{
			switch (laSTG_2input)
			{
			case ING2_JUMP_FINISH: state = STG_2IDLE; break;
			case ING2_SLASH: state = STG_2SLASH_BACKWARD_JUMP; break;
			}
		}
		break;

		case STG_2SLASH_NEUTRAL_JUMP:
		{
			switch (laSTG_2input)
			{
			case ING2_SLASH_FINISH: state = STG_2IDLE; break;
			case ING2_JUMP_FINISH: state = STG_2IDLE; break;
			}
		}
		break;

		case STG_2SLASH_FORWARD_JUMP:
		{
			switch (laSTG_2input)
			{
			case ING2_SLASH_FINISH: state = STG_2IDLE; break;
			case ING2_JUMP_FINISH: state = STG_2IDLE; break;
			}
		}
		break;

		case STG_2SLASH_BACKWARD_JUMP:
		{
			switch (laSTG_2input)
			{
			case ING2_SLASH_FINISH: state = STG_2IDLE; break;
			case ING2_JUMP_FINISH: state = STG_2IDLE; break;
			}
		}
		break;

		case STG_2SLASH_STANDING:
		{
			switch (laSTG_2input)
			{
			case ING2_SLASH_FINISH: state = STG_2IDLE; break;
			}
		}
		break;

		case STG_2CROUCH:
		{
			switch (laSTG_2input)
			{
			case ING2_CROUCH_UP: state = STG_2IDLE; break;
			case ING2_SLASH: state = STG_2SLASH_CROUCH; break;
			}
		}
		break;
		case STG_2SLASH_CROUCH:
		{
			switch (laSTG_2input)
			{
			case ING2_CROUCH_UP && ING2_SLASH_FINISH: state = STG_2IDLE; break;
			case ING2_SLASH_FINISH: state = STG_2CROUCH; break;
			}
		}
		case STG_2KICK_STANDING:
		{
			switch (laSTG_2input)
			{
			case ING2_KICK_FINISH: 
				state = STG_2IDLE;

				break;
			}
		}
		case STG_2SPECIAL:
		{
			switch (laSTG_2input)
			{
			case ING2_SPECIAL_FINISH: state = STG_2IDLE; break;
			}
		}
		break;
		}
	}
	return state;
}