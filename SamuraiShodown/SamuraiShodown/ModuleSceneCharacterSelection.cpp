#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneCharacterSelection.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneCharacterSelection::ModuleSceneCharacterSelection()
{
	background.w = 320;
	background.h = 224;
	background.x = 0;
	background.y = 0;


}

ModuleSceneCharacterSelection::~ModuleSceneCharacterSelection()
{}


// Load assets
bool ModuleSceneCharacterSelection::Start()
{
	Enable();
	//if((Module*)App->scene_neogeo->isEnabled == false) {}
      LOG("Loading CharSelection scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Pregame/PlayerSelect.ogg");
	App->audio->effects[5] = Mix_LoadWAV("Assets/audio/FXSAMURAI/CharactersNames/Haohmaru.wav");
	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Sprite_Sheets/UI/characterselecting.png");
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
		Mix_PlayChannel(-1, App->audio->effects[5], 0);
	}
	
	return true;
}

// UnLoad assets
bool ModuleSceneCharacterSelection::CleanUp()
{
	LOG("Unloading CharSelection scene");

	App->textures->Unload(graphics);
	
	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneCharacterSelection::Update()
{

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background, 0.1f, false); //Char selection image

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_ending, (Module*)App->scene_genan, 0, 2.0f);
		Mix_FadeOutMusic(2000);
	}
	if (App->input->keyboard[SDL_SCANCODE_F2] == 1) {

		App->fade->FadeToBlack((Module*)App->scene_charSelect, (Module*)App->scene_haohmaru,0, 2.0f);
	}
	if (App->input->keyboard[SDL_SCANCODE_F3] == 1) {

		App->fade->FadeToBlack((Module*)App->scene_charSelect, (Module*)App->scene_genan, 0, 2.0f);

	}
	if (App->input->keyboard[SDL_SCANCODE_1] == 1) {
		App->player2->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_charSelect, (Module*)App->scene_ending, 0, 2.0f);
		LOG("PLAYER1 WIN")
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == 1) {
		App->player->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_charSelect, (Module*)App->scene_ending, 0, 2.0f);
		LOG("PLAYER2 WIN")
	}
	

	return UPDATE_CONTINUE;
}