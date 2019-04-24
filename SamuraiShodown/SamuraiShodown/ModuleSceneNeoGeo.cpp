#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneNeoGeo.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneNeoGeo::ModuleSceneNeoGeo()
{
	background.w = 320;
	background.h = 224;
	background.x = 0;
	background.y = 0;

}

ModuleSceneNeoGeo::~ModuleSceneNeoGeo()
{}

// Load assets
bool ModuleSceneNeoGeo::Start()
{
	Enable();
	

	/*LOG("Loading Welcome scene");

	App->audio->music[2] = Mix_LoadMUS("Assets/audio/Pregame/Title.ogg");

	if (!App->audio->music[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {*/
		graphics = App->textures->Load("Assets/Sprite_Sheets/UI/neogeo.png");
		/*Mix_PlayMusic(App->audio->music[2], 2);
	}*/

	
	
	return true;
}

// UnLoad assets
bool ModuleSceneNeoGeo::CleanUp()
{
	LOG("Unloading Welcome scene");

	App->textures->Unload(graphics);
	
	//App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneNeoGeo::Update()
{

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background, 0.1f); //NeoGeo Image
	

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_neogeo, (Module*)App->scene_welcome, 2.0f);
		Mix_FadeOutMusic(2000);
		
	}

	return UPDATE_CONTINUE;
}