#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneGenAn.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"


ModuleSceneGenAn::ModuleSceneGenAn()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stageAnimation.PushBack({ (320 * j), (224 * i), 320, 224 });
			LOG("j++")
		}
		LOG("i++")
	}

	stageAnimation.speed = 0.14f;
}


ModuleSceneGenAn::~ModuleSceneGenAn()
{}

// Load assets
bool ModuleSceneGenAn::Start()
{
	Enable();
	App->collision->Enable();
	//App->collision->debug = false;	//game starts without collision draw activated
	LOG("Collision Enabled");
	//App->UI->Enable();
	LOG("UI Enabled");
	App->player->inputs.Clear();
	App->player->hp = 100;
	App->player->position.x = 50;
	App->player->isDead = false;

	App->player2->inputs.Clear();
	App->player2->hp = 100;
	App->player2->position.x = 200;
	App->player2->isDead = false;

    LOG("Loading GenAn scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Characters/GenAn.ogg");

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Map_Stages/Genan_Stage/GenAn_Stage_Sprites.png");	
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	App->collision->AddCollider({ -10, 0, 13, 500 }, COLLIDER_WALL);
	App->collision->AddCollider({ 317, 0, 3, 500 }, COLLIDER_WALL);

	/*App->player->Enable();
	App->player2->Enable();*/
	
	return true;
}

// Update: draw background
update_status ModuleSceneGenAn::Update()
{
	if (App->player->position.x <= -15) { App->player->position.x = -15; }
	if (App->player->position.x + 60 >= 325) { App->player->position.x = 265; }
	if (App->player2->position.x <= -15) { App->player2->position.x = -15; }
	if (App->player2->position.x + 60 >= 325) { App->player2->position.x = 265; }

	Animation * current_animation = &stageAnimation;

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &stageAnimation.GetCurrentFrame(), 0.1f, false); //GenAn Image
	App->render->Blit(graphics, 0, 0, &background, 0.1f, false); //GenAn Image

	//App->UI->Enable();


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		
		
		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 2.0f);
		Mix_FadeOutMusic(2000);

	}

	
	if (App->input->keyboard[SDL_SCANCODE_1] == 1) {
		App->player2->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 2.0f);
		LOG("PLAYER1 WIN")
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == 1) {
		App->player->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 2.0f);
		LOG("PLAYER2 WIN")
	}
	if (App->player->isDead == true) {

		App->player->action = true;
		App->player2->action = true;

		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (App->collision->colliders[i] != nullptr)
			{
				delete App->collision->colliders[i];
				App->collision->colliders[i] = nullptr;
			}
		}

		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 2.0f);
	}
	if (App->player2->isDead == true) {

		App->player->action = true;
		App->player2->action = true;

		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (App->collision->colliders[i] != nullptr)
			{
				delete App->collision->colliders[i];
				App->collision->colliders[i] = nullptr;
			}
		}

		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 2.0f);
	}

	return UPDATE_CONTINUE;
}

// UnLoad assets
bool ModuleSceneGenAn::CleanUp()
{
	LOG("Unloading GenAn scene");

	App->player->Disable();
	App->player2->Disable();
	App->UI->Disable();
	App->textures->Unload(graphics);
	App->collision->Disable();

	
	App->audio->CleanUp();

	return true;
}

