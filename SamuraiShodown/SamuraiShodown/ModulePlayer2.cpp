#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"

ModulePlayer2::ModulePlayer2()
{
	position.x = 200;
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
	kick.PushBack({ 305,141,66,118 });
	kick.PushBack({ 372,138,86,118 });
	kick.PushBack({ 305,141,66,118 });
	//kick.PushBack({22, 0, 73, 118});
	kick.speed = 0.14f;
	
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player2 textures");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/Haohmaru.png");
	
	p2Collider = App->collision->AddCollider({ position.x, position.y - 90, 60, 90 }, COLLIDER_ENEMY, this);
	return ret;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	Animation* current_animation = &idle;
	
	int speed = 1;
	float yVelocity = 15.1f;
	float yAcceleration = 0.87f;
	

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (!action && !flipPlayer) { current_animation = &forward; }
		if (!action && flipPlayer) { current_animation = &backward; }
		position.x += speed;
	}
		
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (!action && !flipPlayer) { current_animation = &backward; }
		if (!action && flipPlayer) { current_animation = &forward; }
		position.x -= speed;

	}
	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT && !action)
	{

		jumped = true;
		action = true;
		
	}
	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_STATE::KEY_REPEAT && !action)
	{

		kicked = true;
		action = true;

	}
	if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
	{
		if (flipPlayer) { flipPlayer = false; }
		else { flipPlayer = true; }
		
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
	
	
	
	}

	p2Collider->SetPos(position.x, position.y - 90);

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r, 1.0f, flipPlayer);

	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2) {

	if (!flipPlayer) {

		if (this->p2Collider == c1) {
			if (c1->rect.x > c2->rect.x) {
				flipPlayer = true;
				LOG("Player1 flip = true")
			}
		}
	}
	else {
		if (this->p2Collider == c1) {
			if (c1->rect.x < c2->rect.x) {
				flipPlayer = false;
				LOG("Player1 flip = false")
			}
		}
	}


	if (c2->type == COLLIDER_ENEMY_SHOT) {
		/*Mix_PlayChannel(-1, App->audio->effects[2], 0);
		health += 30;
		getsHit = true; doingAction = true;*/
	}
}