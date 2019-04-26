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
	
	p1Collider = App->collision->AddCollider({ position.x, position.y - 90, 60, 90 }, COLLIDER_PLAYER, this);
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
	
	float speed = 2.0f;
	float yVelocity = 15.1f;
	float yAcceleration = 0.87f;
	

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && !kicked && !tornadoMov)
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
			p1Collider->to_delete = true;
		}

		if (!godMode) {
			p1Collider = App->collision->AddCollider({ position.x, position.y - 90, 60, 90 }, COLLIDER_PLAYER, this);
		}
	}


	if(action){
	
		if (jumped) {

			current_animation = &jump;

			position.y = 220 - (yVelocity*var1) + (0.5*(yAcceleration)*pow(var1, 2));
			airborne = true;

			
			if (position.y > 220 && airborne == true)	//end of the jump
			{
				var1 = 0;
				airborne = false;
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

				kick.finishingAnimation(false); 
			}
		
		}
		if (tornadoMov) {

			current_animation = &tornadoMove;
			if (tornadoMove.FinishedAnimation() == true) {

				tornadoMov = false;
				action = false;

				tornadoMove.finishingAnimation(false);
			}

		}
		if (attacking) {

			current_animation = &sAttack;
			if (sAttack.FinishedAnimation() == true) {

				attacking = false;
				action = false;

				sAttack.finishingAnimation(false);
			}

		}
	
	
	}

	p1Collider->SetPos(position.x, position.y - 90);

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	OnPassing(App->player2);
	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, flipPlayer);
	
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2) {

	
}

void ModulePlayer::OnPassing(ModulePlayer2* p2) {

	if (flipPlayer) {
		
			if ((this->position.x + 60) < p2->position.x) {
				flipPlayer = false;
				LOG("Player1 flip = false")
			
		}
	}
	if (!flipPlayer) {

		
		if (this->position.x > (p2->position.x + 60)) {
				flipPlayer = true;
				LOG("Player1 flip = true")	
		}
	}
}
