#include "ModuleUI.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleRender.h"
#include "ModuleSceneHaohmaru.h"
#include <iostream>

ModuleUI::ModuleUI() {
	
	KO.PushBack({151, 0, 26, 23});
	KO.PushBack({ 151, 23, 26, 23 });
}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {
	LOG("Loading UI\n");
	ui_png = App->textures->Load("Assets/Textures/in_gameUI.png");

	hpBar1 = { 8,32,128,9 };
	hpBar2 = { 8,32,128,9 };


	App->player->hp = 100;
	App->player2->hp = 100;
	currentW_player1 = hpBar1.w;
	
	maxHP = App->player->hp;
	currentW_player2 = hpBar2.w;
	current_hp2 = maxHP;
	current_hp1 = maxHP;

	return true;
}

bool ModuleUI::CleanUp() {

	LOG("UI Unloaded\n");
	App->textures->Unload(ui_png);
	
	return true;
}

update_status ModuleUI::Update() {
	
	UpdateBars();

	SDL_Rect name{ 0,0,64,8 }; // haomaru name
	App->render->Blit(ui_png, 17, 32, &name, 1.0f, false); //
	App->render->Blit(ui_png, 238, 32, &name, 1.0f, false);

	SDL_Rect rect{ 6,17,132,13 }; // bar

	//player 1 bar
	App->render->Blit(ui_png, 8, 17, &rect, 1.0f, false); //
	App->render->Blit(ui_png, 10, 19, &hpBar1, 1.0f, false); //

	//player 2 bar
	App->render->Blit(ui_png, 183, 17, &rect, 1.0f, false); //
	App->render->Blit(ui_png, 185, 19, &hpBar2, 1.0f, false); //

	
	
	return UPDATE_CONTINUE;
}

void ModuleUI::UpdateBars()
{


	if (current_hp1 != App->player->hp) {
		int new_width = currentW_player1;
		int quantity = App->player->hp - current_hp1;
		int new_quantity = (current_hp1 + quantity);
		current_hp1 += quantity;

		if (maxHP != 0)
			new_width = (new_quantity * max_width) / maxHP;

		if (current_hp1 <= 0) {
			current_hp1 = 0;
			target_hp1 = 0;
		}
		else if (current_hp1 >= maxHP) {
			current_hp1 = maxHP;
			target_hp1 = max_width;
		}
		else
			target_hp1 = new_width;

		decrease_player1 = true;
	}
	if (decrease_player1) {
		if (currentW_player1 > target_hp1) {
			currentW_player1 -= 1;
		}
		else if (currentW_player1 < target_hp1) {
			currentW_player1 += 1;
		}
		else {
			decrease_player1 = false;
		}
		hpBar1.w = currentW_player1;
	}

	if (current_hp2 != App->player2->hp) {
		int new_width = currentW_player2;
		int quantity = App->player2->hp - current_hp2;
		int new_quantity = (current_hp2 + quantity);
		current_hp2 += quantity;

		if (maxHP != 0)
			new_width = (new_quantity * max_width) / maxHP;

		if (current_hp2 <= 0) {
			current_hp2 = 0;
			target_hp2 = 0;
		}
		else if (current_hp2 >= maxHP) {
			current_hp2 = maxHP;
			target_hp2 = max_width;
		}
		else
			target_hp2 = new_width;

		decrease_player2 = true;
	}
	if (decrease_player2) {
		if (currentW_player2 > target_hp2) {
			currentW_player2 -= 1;
		}
		else if (currentW_player2 < target_hp2) {
			currentW_player2 += 1;
		}
		else {
			decrease_player2 = false;
		}
		hpBar2.w = currentW_player2;
	}
}

