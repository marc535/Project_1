#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneHaohmaru.h"
//#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneHaohmaru::ModuleSceneHaohmaru()
{
	background.w = 320;
	background.h = 224;
	background.x = 0;
	background.y = 0;

}

ModuleSceneHaohmaru::~ModuleSceneHaohmaru()
{}

// Load assets
bool ModuleSceneHaohmaru::Start()
{
	Enable();
	

	/*LOG("Loading Haohmaru scene");

	App->audio->music[2] = Mix_LoadMUS("Assets/audio/Pregame/Title.ogg");

	if (!App->audio->music[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {*/
		graphics = App->textures->Load("Assets/Map_Stages/Haohmaru_Stage/Haohmaru_Stage.png");
		/*Mix_PlayMusic(App->audio->music[2], 2);
	}*/

	
	
	return true;
}

// UnLoad assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru scene");

	App->textures->Unload(graphics);
	
	//App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background, 0.1f); //NeoGeo Image
	

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_haohmaru, (Module*)App->scene_ending, 2.0f);
		Mix_FadeOutMusic(2000);
		
	}

	return UPDATE_CONTINUE;
}