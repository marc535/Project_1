#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneEnding.h"
//#include "ModulePlayer.h"
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
	

	/*LOG("Loading Welcome scene");

	App->audio->music[2] = Mix_LoadMUS("Assets/audio/Pregame/Title.ogg");

	if (!App->audio->music[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {*/
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/EndingHaohmaru.png");
		/*Mix_PlayMusic(App->audio->music[2], 2);
	}*/

	
	
	return true;
}

// UnLoad assets
bool ModuleSceneEnding::CleanUp()
{
	LOG("Unloading Ending scene");

	App->textures->Unload(graphics);
	
	//App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneEnding::Update()
{

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background, 0.1f); //Ending Image
	

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_ending, (Module*)App->scene_welcome, 2.0f);
		Mix_FadeOutMusic(2000);
		
	}

	return UPDATE_CONTINUE;
}