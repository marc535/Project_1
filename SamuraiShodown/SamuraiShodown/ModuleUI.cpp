#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleUI.h"
#include "ModuleInput.h"

ModuleUI::ModuleUI()
{
	//health 1
	hp_pull_1.h = 15;
	hp_pull_1.w = 134;
	hp_pull_1.x = 273;
	hp_pull_1.y = 421;

	//health 2
	hp_pull_2.h = 15;
	hp_pull_2.w = 134;
	hp_pull_2.x = 273;
	hp_pull_2.y = 405;

	//healthy 1
	healthy_1.PushBack({ 273, 308, 128, 13 });
	healthy_1.PushBack({ 273, 308, 128, 13 });
	healthy_1.speed = 1.0f;

	//medium health 1
	medium_health_1.PushBack({ 277, 326, 128, 9 });
	medium_health_1.PushBack({ 277, 391, 128, 9 });
	medium_health_1.speed = 0.2f;

	//low health 1
	low_health_1.PushBack({ 277, 326, 128, 9 });
	low_health_1.PushBack({ 277, 391, 128, 9 });
	low_health_1.speed = 0.7f;

	//healthy 2
	healthy_2.PushBack({ 273, 308, 128, 13 });
	healthy_2.PushBack({ 273, 308, 128, 13 });
	healthy_2.speed = 1.0f;

	//medium health 2
	medium_health_2.PushBack({ 277, 326, 128, 9 });
	medium_health_2.PushBack({ 277, 391, 128, 9 });
	medium_health_2.speed = 0.2f;

	//low health 2
	low_health_2.PushBack({ 277, 326, 128, 9 });
	low_health_2.PushBack({ 277, 391, 128, 9 });
	low_health_2.speed = 0.7f;

}

ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start()
{
	LOG("Loading UI in-Game textures");
	graphics = App->textures->Load("Assets/Sprite_Sheets/UI/1.png");
	return true;
}

void ModuleUI::damage_to_1(int damage)
{
	HP1 -= damage;
	//damaged_1 = true;
}
void ModuleUI::damage_to_2(int damage)
{
	HP2 -= damage;
	//damaged_2 = true;
}

update_status ModuleUI::Update()
{
	Animation* health_bar_animation_1 = &healthy_1;
	Animation* health_bar_animation_2 = &healthy_2;

	if (App->input->keyboard[SDL_SCANCODE_6] == KEY_STATE::KEY_DOWN)
	{
		damage_to_1(20);
	}
	if (App->input->keyboard[SDL_SCANCODE_7] == KEY_STATE::KEY_DOWN)
	{
		damage_to_2(20);
	}

	App->render->Blit(graphics, 10, 10, &hp_pull_1, 1.0f, false);
	App->render->Blit(graphics, 148, 10, &hp_pull_2, 1.0f, false);

	if (HP1 <= LOW_HP && HP1 > LOW2_HP)
	{
		health_bar_animation_1 = &medium_health_1;
		App->render->Blit(graphics, 14, 12, &health_animation_1, 1.0f, false);
	}
	if (HP1 <= LOW2_HP)
	{
		health_bar_animation_1 = &low_health_1;
		App->render->Blit(graphics, 14, 12, &health_animation_1, 1.0f, false);
	}
	if (HP1 > LOW_HP)
	{
		App->render->Blit(graphics, 14, 10, &health_animation_1, 1.0f, false);
	}


	if (HP2 <= LOW_HP && HP2 > LOW2_HP)
	{
		health_bar_animation_2 = &medium_health_2;
		App->render->Blit(graphics, 150, 12, &health_animation_2, 1.0f, false);
	}
	if (HP2 <= LOW2_HP)
	{
		health_bar_animation_2 = &low_health_2;
		App->render->Blit(graphics, 150, 12, &health_animation_2, 1.0f, false);
	}
	if (HP2 > LOW_HP)
	{
		App->render->Blit(graphics, 150, 10, &health_animation_2, 1.0f, false);
	}

	health_animation_1 = health_bar_animation_1->GetCurrentFrame();
	health_animation_2 = health_bar_animation_2->GetCurrentFrame();

	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading Welcome scene");

	HP1 = TOTAL_HP;
	HP2 = TOTAL_HP;
	App->textures->Unload(graphics);

	return true;
}