#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneHaohmaru.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"


ModuleSceneHaohmaru::ModuleSceneHaohmaru()
{

	for (int i = 0; i < 6; i++)
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


ModuleSceneHaohmaru::~ModuleSceneHaohmaru()
{}

// Load assets
bool ModuleSceneHaohmaru::Start()
{
	Enable();
	App->collision->Enable();
	App->UI->Enable();
	LOG("UI Enabled");
	App->player->hp = 100;
	App->player->position.x = 50;
	App->player->isDead = false;

	App->player2->hp = 100;
	App->player2->position.x = 200;
	App->player2->isDead = false;

    LOG("Loading Haohmaru scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Characters/Haohmaru.ogg");

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Map_Stages/Haohmaru_Stage/Haohmaru_Stage_Sprites.png");
		graphics = App->textures->Load("Assets/Map_Stages/Haohmaru_Stage/ProvaRes.png");	
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	App->collision->AddCollider({ -10, 0, 13, 500 }, COLLIDER_WALL);
	App->collision->AddCollider({ 317, 0, 3, 500 }, COLLIDER_WALL);
	
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	if (App->player->position.x <= -15) { App->player->position.x = -15; }
	if (App->player->position.x + 60 >= 325) { App->player->position.x = 265; }
	if (App->player2->position.x <= -15) { App->player2->position.x = -15; }
	if (App->player2->position.x + 60 >= 325) { App->player2->position.x = 265; }

	Animation * current_animation = &stageAnimation;

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &stageAnimation.GetCurrentFrame(), 0.1f, false); //Haohmaru Image
	App->player->Enable();
	App->player2->Enable();
	App->UI->Enable();


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		
		
		App->fade->FadeToBlack((Module*)App->scene_haohmaru, (Module*)App->scene_ending, 2.0f);
		Mix_FadeOutMusic(2000);

	}
	if (App->player->isDead == true) {

		App->fade->FadeToBlack((Module*)App->scene_haohmaru, (Module*)App->scene_ending, 2.0f);
	}
	if (App->player2->isDead == true) {

		App->fade->FadeToBlack((Module*)App->scene_haohmaru, (Module*)App->scene_ending, 2.0f);
	}

	return UPDATE_CONTINUE;
}

// UnLoad assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru scene");

	App->player->Disable();
	App->player2->Disable();
	App->UI->Disable();
	App->textures->Unload(graphics);
	App->collision->Disable();

	
	App->audio->CleanUp();

	return true;
}

