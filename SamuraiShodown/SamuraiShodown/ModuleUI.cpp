#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleUI.h"
#include "ModuleInput.h"

ModuleUI::ModuleUI()
{
	hp_pull.h = 15;
	hp_pull.w = 134;
	hp_pull.x = 273;
	hp_pull.y = 421;

	//healthy
	healthy.PushBack({ 273, 308, 134 - hp_graph, 15 });
	healthy.PushBack({ 273, 308, 134 - hp_graph, 15 });
	healthy.speed = 1.0f;

	//not healthy 1
	not_healthy1.PushBack({ 273, 324, 134 - hp_graph, 15 });
	not_healthy1.PushBack({ 273, 389, 134 - hp_graph, 15 });
	not_healthy1.speed = 0.2f;

	//not healthy 2
	not_healthy2.PushBack({ 273, 324, 134 - hp_graph, 15 });
	not_healthy2.PushBack({ 273, 389, 134 - hp_graph, 15 });
	not_healthy2.speed = 0.5f;

	//damage taken
	damage_taken.PushBack({ 273, 310, 134 - hp_graph, 9 });
	damage_taken.PushBack({ 273, 310, 134 - hp_graph, 9 });
	damage_taken.speed = 1.0f;
}

ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start()
{
	LOG("Loading UI in-Game textures");
	graphics = App->textures->Load("Assets/Sprite_Sheets/UI/1.png");
	return true;
}

void ModuleUI::damage(int damage)
{
	damaged = true;
	hp_graph += (1.34f * damage);
	HP -= damage;
}

update_status ModuleUI::Update()
{
	Animation* current_animation = &healthy;

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
	{
		damage(20);
	}
	if (HP <= LOW_HP)
	{
		if (damaged)
		{
			current_animation = &damage_taken;
			damaged = false;
		}
		else
		{
			current_animation = &not_healthy1;
		}
	}
	else if (HP <= LOW2_HP)
	{
		if (damaged)
		{
			current_animation = &damage_taken;
			damaged = false;
		}
		else
		{
			current_animation = &not_healthy2;
		}
	}

	animation = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, 10, 10, &hp_pull, 1.0f, false);
	App->render->Blit(graphics, 10, 10, &damage_animation, 1.0f, false);
	if (HP > LOW_HP)
	{
		App->render->Blit(graphics, 14, 10, &animation, 0.1f, false);
	}
	else
	{
		if (damaged)
		{
			App->render->Blit(graphics, 14, 12, &animation, 0.1f, false);
		}
		else
		{
			App->render->Blit(graphics, 10, 10, &animation, 0.1f, false);
		}
	}
	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp()
{
	LOG("Unloading Welcome scene");

	HP = TOTAL_HP;
	hp_graph = 134;
	App->textures->Unload(graphics);

	return true;
}