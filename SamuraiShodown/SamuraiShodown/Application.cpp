#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleSceneWelcome.h"
#include "ModuleSceneNeoGeo.h"
#include "ModuleSceneCharacterSelection.h"
#include "ModuleSceneEnding.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleUI.h"
#include "ModuleParticles.h"
#include "ModuleParticles2.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();

	modules[i++] = audio = new ModuleAudio();

	modules[i++] = scene_neogeo = new ModuleSceneNeoGeo();
	modules[i++] = scene_welcome = new ModuleSceneWelcome();
	modules[i++] = scene_charSelect = new ModuleSceneCharacterSelection();
	modules[i++] = scene_ending = new ModuleSceneEnding();
	modules[i++] = scene_haohmaru = new ModuleSceneHaohmaru();
	modules[i++] = fade = new ModuleFadeToBlack();
	modules[i++] = UI = new ModuleUI();

	modules[i++] = player = new ModulePlayer();
	modules[i++] = player2 = new ModulePlayer2();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = particles2 = new ModuleParticles2();
	modules[i++] = collision = new ModuleCollision();
	

}

Application::~Application()
{
	for (int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Deactivate modules here ----
	player->Disable();
	player2->Disable();
	UI->Disable();
	//collision->Disable();
	


	scene_welcome->Disable();
	scene_charSelect->Disable();
	scene_ending->Disable();
	scene_haohmaru->Disable();

	// ----------------------------

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for (int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for (int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for (int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}