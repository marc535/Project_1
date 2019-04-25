#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneCharacterSelection.h"
#include "ModulePlayer.h"
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

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Sprite_Sheets/UI/characterselecting.png");
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
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
	App->render->Blit(graphics, 0, 0, &background, 0.1f); //Char selection image

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_charSelect, (Module*)App->scene_haohmaru, 2.0f);
		

		//Mix_FadeOutMusic(2000);
		
	}

	return UPDATE_CONTINUE;
}