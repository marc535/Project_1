#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleSceneWelcome.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"



ModuleSceneWelcome::ModuleSceneWelcome()
{

	background.w = 320;
	background.h = 224;
	background.x = 0;
	background.y = 0;

	SNK.w = 78;
	SNK.h = 21;
	SNK.x = 93;
	SNK.y = 0;

	/*backgroundanim.PushBack({ 82, 52, 55, 70 });
	backgroundanim.PushBack({ 82, 182, 55, 70 });
	backgroundanim.PushBack({ 70, 297, 67, 79 });
	backgroundanim.PushBack({ 55, 419, 82, 87 });*/

	
	for (int i = 0; i < 6; i++) {

		for (int j = 0; j < 8; j++) {

				backgroundanim.PushBack({ (242 * i), (130 * j), 242, 130 });

				if (i == 5 && j == 4) {
					break;
				}
			
		}
	}

	
	

	backgroundanim.speed = 0.35f;
	backgroundanim.loop = false;

	backgroundanim2.PushBack({759, 0, 253, 114 });
	backgroundanim2.PushBack({ 759, 0, 253, 114 });
	backgroundanim2.PushBack({ 759, 0, 253, 114 });
	backgroundanim2.PushBack({ 759, 0, 253, 114 });


	// insert coin animation
	insertcoin.PushBack({ 0,0,89,9 });
	insertcoin.PushBack({ 0,10,89,9 });

	insertcoin.speed = 0.03f;
	insertcoin.loop = true;


	for (int i = 0; i < 6; i++) {

		for (int j = 0; j < 3; j++) {

			backgroundanim2.PushBack({ (253 * j), (114 * i), 253, 114 });

		}

	}

	backgroundanim2.speed = 0.14f;
	backgroundanim2.loop = false;

}

ModuleSceneWelcome::~ModuleSceneWelcome()
{}


// Load assets
bool ModuleSceneWelcome::Start()
{
	Enable();
	//if((Module*)App->scene_neogeo->isEnabled == false) {}
	LOG("Loading Welcome scene");

	App->audio->soundtracks[2] = Mix_LoadMUS("Assets/audio/Pregame/Title.ogg");
	

	if (!App->audio->soundtracks[2]) {
		LOG("Mix_LoadMUS(\"Title.ogg\"): %s\n", Mix_GetError());
	}
	else {
		graphics = App->textures->Load("Assets/Textures/menus.png");
		anim = App->textures->Load("Assets/Textures/white_letters.png");
		redlet = App->textures->Load("Assets/Textures/3SamuraiShodownLetters.png");
		coin = App->textures->Load("Assets/Textures/extras.png");
		Mix_PlayMusic(App->audio->soundtracks[2], 2);
	}

	
	
	return true;
}

// UnLoad assets
bool ModuleSceneWelcome::CleanUp()
{
	LOG("Unloading Welcome scene");

	App->textures->Unload(graphics);
	
	App->audio->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleSceneWelcome::Update()
{

	// Draw everything --------------------------------------	
	
	App->render->Blit(graphics, 0, 0, &background, 0.1f, false); //Welcome Image
	
	
	if (backgroundanim.FinishedAnimation() == true) {
			App->render->Blit(redlet, 33, 55, &backgroundanim2.GetCurrentFrame(), 0.1f, false); 

			if (backgroundanim2.FinishedAnimation() == true) {

				App->render->Blit(coin, 115, 177, &insertcoin.GetCurrentFrame(), 0.1f, false);
				App->render->Blit(coin, 20, 193, &SNK, 0.1f, false); //SNK Image

			}
			
		}
	else{
			App->render->Blit(anim, 39, 36, &backgroundanim.GetCurrentFrame(), 0.1f, false);
			

			if (backgroundanim.FinishedAnimation() == true) {
				
				App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_welcome, 1, 0.5f);
				
			}
	}
		
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		//FadeToBlack
		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_charSelect, 0, 2.0f);

		Mix_FadeOutMusic(2000);
	}

	//if (App->input->keyboard[SDL_SCANCODE_F2] == 1) {

		//App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_haohmaru, 0, 2.0f);

	//}
	if (App->input->keyboard[SDL_SCANCODE_F3] == 1) {

		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_genan, 0, 2.0f);

	}
	if (App->input->keyboard[SDL_SCANCODE_1] == 1) {
		App->player2->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_ending, 0, 2.0f);
		LOG("PLAYER1 WIN")
	}
	if (App->input->keyboard[SDL_SCANCODE_2] == 1) {
		App->player->isDead = true;
		App->fade->FadeToBlack((Module*)App->scene_welcome, (Module*)App->scene_ending, 0, 2.0f);
		LOG("PLAYER2 WIN")
	}

	return UPDATE_CONTINUE;
}