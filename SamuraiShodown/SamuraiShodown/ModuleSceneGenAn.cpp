#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneGenAn.h"
#include "ModuleGen.h"
#include "ModuleGen2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleUI.h"
#include "ModuleFonts.h"


ModuleSceneGenAn::ModuleSceneGenAn()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stageAnimation.PushBack({ (320 * j), (224 * i), 320, 224 });
			LOG("j++")
		}
		LOG("i++")
	}

	stageAnimation.speed = 0.3f;
}


ModuleSceneGenAn::~ModuleSceneGenAn()
{}

// Load assets
bool ModuleSceneGenAn::Start()
{
	Enable();
	App->collision->Enable();
	//App->collision->debug = false;	//game starts without collision draw activated
	LOG("Collision Enabled");
	App->UI->Enable();
	LOG("UI Enabled");

	App->gen->Ginputs.Clear();
	App->gen->hp = 8000;
	App->gen->position.x = 50;
	App->gen->isDead = false;

	App->collision->debug = false;

    LOG("Loading GenAn scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Characters/GenAn.ogg");

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Map_Stages/Genan_Stage/GenAn_Stage_Sprites.png");	
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	left_wall = App->collision->AddCollider({ -10, 0, 13, 500 }, COLLIDER_WALL);
	right_wall = App->collision->AddCollider({ 317, 0, 3, 500 }, COLLIDER_WALL);

	App->gen->Enable();
	App->gen2->Enable();

	/*App->player->Enable();
	App->gen2->Enable();*/
	
	App->render->SetCamera();

	return true;
}

// Update: draw background
update_status ModuleSceneGenAn::Update()
{
	timeUp();

	/*if (App->gen->position.x <= -15) { App->gen->position.x = -15; }
	if (App->gen->position.x + 60 >= 325) { App->gen->position.x = 265; }
	if (App->gen2->position.x <= -15) { App->gen2->position.x = -15; }
	if (App->gen2->position.x + 60 >= 325) { App->gen2->position.x = 265; }
*/
	Animation * current_animation = &stageAnimation;

	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &stageAnimation.GetCurrentFrame(), 0.1f, false); //GenAn Image
	App->render->Blit(graphics, 0, 0, &background, 0.1f, false); //GenAn Image

	//App->UI->Enable();


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		
		
		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 0, 2.0f);
		Mix_FadeOutMusic(2000);

	}

	if (App->input->keyboard[SDL_SCANCODE_F2] == 1) {

		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_haohmaru, 0, 2.0f);
	}
	if (App->input->keyboard[SDL_SCANCODE_1] == 1) {
		App->gen2->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 0, 2.0f);
		LOG("PLAYER1 WIN")
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == 1) {
		App->gen->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 0, 2.0f);
		LOG("gen2 WIN")
	}
	if (App->gen->isDead == true) {

		App->gen->action = true;
		App->gen2->action = true;

		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (App->collision->colliders[i] != nullptr)
			{
				delete App->collision->colliders[i];
				App->collision->colliders[i] = nullptr;
			}
		}

		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 0, 2.0f);
	}
	if (App->gen2->isDead == true) {

		App->gen->action = true;
		App->gen2->action = true;

		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (App->collision->colliders[i] != nullptr)
			{
				delete App->collision->colliders[i];
				App->collision->colliders[i] = nullptr;
			}
		}

		App->fade->FadeToBlack((Module*)App->scene_genan, (Module*)App->scene_ending, 2.0f);
	}

	

	App->fonts->BlitText(255, 31, 1, "GEN-AN");
	App->fonts->BlitText(20, 31, 1, "GEN-AN");
	//App->render->MoveCamera();
	if (App->gen->flipPlayer == false && App->gen->position.x < App->render->camera.x) {

		App->gen->position.x = App->render->camera.x;
	}
	if (App->gen->flipPlayer == true && (App->gen->position.x + App->gen->GenCollider->rect.w) > SCREEN_WIDTH) {

		App->gen->position.x = SCREEN_WIDTH - App->gen->GenCollider->rect.w;
	}

	if (App->gen2->flipPlayer == false && App->gen2->position.x < App->render->camera.x) {

		App->gen2->position.x = App->render->camera.x;
	}
	if (App->gen2->flipPlayer == true && (App->gen2->position.x + App->gen2->Gen2Collider->rect.w) > SCREEN_WIDTH) {

		App->gen2->position.x = SCREEN_WIDTH - App->gen2->Gen2Collider->rect.w;
	}
	return UPDATE_CONTINUE;
}

// UnLoad assets
bool ModuleSceneGenAn::CleanUp()
{
	LOG("Unloading GenAn scene");

	App->gen->Disable();
	App->gen2->Disable();
	App->UI->Disable();
	App->textures->Unload(graphics);
	App->collision->Disable();

	
	App->audio->CleanUp();

	return true;
}

bool ModuleSceneGenAn::timeUp() {

	if (App->UI->actualtime == 0) {
		if (App->gen->hp == App->gen2->hp) {

			App->gen->isDead = true;
			App->gen2->isDead = true;
		}
		if (App->gen->hp > App->gen2->hp) {

			App->gen2->isDead = true;
		}
		else {

			App->gen->isDead = true;
		}
		return true;
	}
	else { return false; }
}

