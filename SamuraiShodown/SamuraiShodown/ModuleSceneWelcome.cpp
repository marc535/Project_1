#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneWelcome.h"
//#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneWelcome::ModuleSceneWelcome()
{
	background.w = 320;
	background.h = 224;
	background.x = 0;
	background.y = 0;

}

ModuleSceneWelcome::~ModuleSceneWelcome()
{}

// Load assets
bool ModuleSceneWelcome::Start()
{

	/*LOG("Loading Welcome scene");

	App->audio->music[2] = Mix_LoadMUS("Assets/audio/Pregame/Title.ogg");

	if (!App->audio->music[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {*/
		graphics = App->textures->Load("Assets/Sprite_Sheets/UI/title.png");
		/*Mix_PlayMusic(App->audio->music[2], 2);
	}*/

	
	
	return true;
}

// UnLoad assets
bool ModuleSceneWelcome::CleanUp()
{
	LOG("Unloading Welcome scene");

	App->textures->Unload(graphics);
	
	//App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneWelcome::Update()
{

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background, 0.1f); //Welcome Image
	

	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		Mix_FadeOutMusic(2000);
		
	}

	return UPDATE_CONTINUE;
}