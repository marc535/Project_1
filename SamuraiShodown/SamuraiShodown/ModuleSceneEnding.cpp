#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneEnding.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneEnding::ModuleSceneEnding()
{
	background.w = 320;
	background.h = 224;
	background.x = 0;
	background.y = 0;

}

ModuleSceneEnding::~ModuleSceneEnding()
{}

// Load assets
bool ModuleSceneEnding::Start()
{
	Enable();
	

	LOG("Loading Welcome scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Endings/Peace.ogg");

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/EndingHaohmaru.png");

	player = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/EndingHaohmaru1.png");
	player2 = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/EndingHaohmaru2.png");
	Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	
	
	return true;
}

// UnLoad assets
bool ModuleSceneEnding::CleanUp()
{
	LOG("Unloading Ending scene");

	App->textures->Unload(graphics);
	
	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneEnding::Update()
{

	// Draw everything --------------------------------------	
	if (App->player->isDead) { App->render->Blit(player2, 0, 0, &background, 0.1f, false); }

	if (App->player2->isDead) { App->render->Blit(player, 0, 0, &background, 0.1f, false); }
	 //Ending Image
	

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_ending, (Module*)App->scene_genan, 2.0f);
		Mix_FadeOutMusic(2000);
	}
	if (App->input->keyboard[SDL_SCANCODE_F2] == 1) {

		App->fade->FadeToBlack((Module*)App->scene_ending, (Module*)App->scene_haohmaru, 2.0f);
	}
	return UPDATE_CONTINUE;
}