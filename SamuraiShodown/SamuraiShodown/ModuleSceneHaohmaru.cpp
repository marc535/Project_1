#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneHaohmaru.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


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
	App->player->Enable();

	

    LOG("Loading Haohmaru scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Pregame/Title.ogg");

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Map_Stages/Haohmaru_Stage/Haohmaru_Stage_Sprites.png");
	graphics = App->textures->Load("Assets/Map_Stages/Haohmaru_Stage/ProvaRes.png");
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	
	
	return true;
}

// Update: draw background
update_status ModuleSceneHaohmaru::Update()
{
	Animation * current_animation = &stageAnimation;

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &stageAnimation.GetCurrentFrame(), 0.1f); //Haohmaru Image



	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_haohmaru, (Module*)App->scene_ending, 2.0f);
		Mix_FadeOutMusic(2000);

	}

	return UPDATE_CONTINUE;
}

// UnLoad assets
bool ModuleSceneHaohmaru::CleanUp()
{
	LOG("Unloading Haohmaru scene");

	App->player->Disable();
	App->textures->Unload(graphics);
	
	
	App->audio->CleanUp();

	return true;
}

