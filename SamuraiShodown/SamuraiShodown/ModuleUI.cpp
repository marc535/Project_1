#include "ModuleUI.h"
#include "ModuleTextures.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleGen.h"
#include "ModuleGen2.h"
#include "ModuleRender.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleSceneGenAn.h"
#include "ModuleFonts.h"
#include <iostream>

ModuleUI::ModuleUI() {
	
	KO.PushBack({ 151,  0, 26, 23 });
	KO.PushBack({ 151, 23, 26, 23 });

	KO.speed = 0.14f;
	KO.loop = true;
}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {

	startingtime = SDL_GetTicks();
	int actualtime = 99;
	is_draw = false;
	LOG("Loading UI\n");

	font_time = App->fonts->Load("Assets/Fonts/TimeTile.png", "0123456789", 1);
	font_name = App->fonts->Load("Assets/Fonts/NameTile.png", "ABCDEFGHIJKLMNOPQRSTUWYZ0123456789-= ", 1);
	font_menu = App->fonts->Load("Assets/Fonts/TextTile.png", "ABCDEFGHIJKLMNOPQRSTUVWYZ-123! ", 1);
	ui_png = App->textures->Load("Assets/Textures/in_gameUI.png");


	hpBar1 = { 8,32,128,9 };
	hpBar2 = { 8,32,128,9 };

	if (App->scene_genan->IsEnabled() == true) {

		App->gen->hp = 8000;
		App->gen2->hp = 8000;
		currentW_player1 = hpBar1.w;

		maxHP = App->gen->hp;
		currentW_player2 = hpBar2.w;
		current_hp2 = maxHP;
		current_hp1 = maxHP;
	}

	if (App->scene_haohmaru->IsEnabled() == true) {
		App->player->life = 8000;
		App->player2->hp = 8000;
		currentW_player1 = hpBar1.w;

		maxHP = App->player->life;
		currentW_player2 = hpBar2.w;
		current_hp2 = maxHP;
		current_hp1 = maxHP;
	}
	return true;
}

bool ModuleUI::CleanUp() {

	LOG("UI Unloaded\n");
	App->textures->Unload(ui_png);
	App->fonts->UnLoad(font_time);
	App->fonts->UnLoad(font_menu);
	App->fonts->UnLoad(font_name);
	return true;
}

update_status ModuleUI::Update() {
	
	UpdateBars();

	

	//player 1 bar
	App->render->Blit(ui_png, 8, 17, &rect, 1.0f, false); //
	App->render->Blit(ui_png, 10, 19, &hpBar1, 1.0f, false); //

	//player 2 bar
	App->render->Blit(ui_png, 183, 17, &rect, 1.0f, false); //
	App->render->Blit(ui_png, 185, 19, &hpBar2, 1.0f, false); //

	
	
	if (!animKO) {
		App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 12, 10, &KO.frames[0], 1.0F, false);
	}
	else {
		App->render->Blit(ui_png, SCREEN_WIDTH / 2 - 24 / 2, 10, &KO.GetCurrentFrame(), 1.0F, false);
	}

	if (App->player2->getsHit == true) {
		puntuacion1 = puntuacion1 + 100;
	}
	sprintf_s(puntuation1, 10, "%7d", puntuacion1);
	actualtime = 99 - ((SDL_GetTicks() - (startingtime )) / 1000);
	sprintf_s(time_text, 10, "%7d", actualtime);

	App->fonts->BlitText((SCREEN_WIDTH / 2) - 15, 40, 0, time_text);

	

	App->fonts->BlitText(45, 5, 1, puntuation1);

	App->fonts->BlitText(19, 6, 1, "P1=");
	App->fonts->BlitText(200, 5, 1, "P2= 0");


	App->fonts->BlitText(210, 215, 1, "CREDITS 01");
	//App->fonts->BlitText((SCREEN_WIDTH / 2) - 25, 215, 1, "LEVEL 1");
	return UPDATE_CONTINUE;
}

void ModuleUI::UpdateBars()
{
	
	if (App->scene_genan->IsEnabled() == true) {
	
		if (App->gen->hp < 2400 || App->gen2->hp < 2400) { animKO = true; }

		if (current_hp1 != App->gen->hp) {
			int new_width = currentW_player1;
			int quantity = App->gen->hp - current_hp1;
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

		if (current_hp2 != App->gen2->hp) {
			int new_width = currentW_player2;
			int quantity = App->gen2->hp - current_hp2;
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
	else if(App->scene_haohmaru->IsEnabled() == true) {
	
		if (App->player->life < 2400 || App->player2->hp < 2400) { animKO = true; }

		if (current_hp1 != App->player->life) {
			int new_width = currentW_player1;
			int quantity = App->player->life - current_hp1;
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

	
}

