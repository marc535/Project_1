#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneNeoGeo.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneNeoGeo::ModuleSceneNeoGeo()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			backgroundanim.PushBack({ (320 * j), (224 * i), 320, 224 });
			LOG("j++")
		}
		LOG("i++")
	}

	backgroundanim.speed = 0.14f;
	backgroundanim.loop = false;
}

ModuleSceneNeoGeo::~ModuleSceneNeoGeo()
{}

// Load assets
bool ModuleSceneNeoGeo::Start()
{
	Enable();
	

	LOG("Loading Welcome scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Pregame/Neo Geo Logo.ogg");

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Sprite_Sheets/UI/neo_geo_anim2.png");
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	
	
	return true;
}

// Update: draw background
update_status ModuleSceneNeoGeo::Update()
{

	Animation *current_animation = &backgroundanim;

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &backgroundanim.GetCurrentFrame(), 0.1f, false); //NeoGeo Image



	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_neogeo, (Module*)App->scene_welcome, 2.0f);
		Mix_FadeOutMusic(2000);

	}
	if (App->input->keyboard[SDL_SCANCODE_F2] == 1) {

		App->fade->FadeToBlack((Module*)App->scene_neogeo, (Module*)App->scene_haohmaru, 2.0f);
		Mix_FadeOutMusic(2000);
	}
	if (App->input->keyboard[SDL_SCANCODE_1] == 1) {
		App->player2->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_neogeo, (Module*)App->scene_ending, 2.0f);
		LOG("PLAYER1 WIN")
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == 1) {
		App->player->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_neogeo, (Module*)App->scene_ending, 2.0f);
		LOG("PLAYER2 WIN")
	}

	return UPDATE_CONTINUE;

}

// UnLoad assets
bool ModuleSceneNeoGeo::CleanUp()
{
	LOG("Unloading Welcome scene");

	App->textures->Unload(graphics);
	
	App->audio->CleanUp();

	return true;
}

