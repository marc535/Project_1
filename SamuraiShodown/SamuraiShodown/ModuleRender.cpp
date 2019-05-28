#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleCollision.h"
#include "SDL/include/SDL.h"
#include "p2Point.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleGen.h"
#include "ModuleGen2.h"
#include "ModuleSceneHaohmaru.h"
#include "ModuleSceneGenAn.h"
#include "ModuleUI.h"
#include <cstdlib>
#include <time.h>

ModuleRender::ModuleRender() : Module()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	//SDL_RenderSetLogicalSize(renderer, App->window->width, App->window->height);
	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	SDL_RenderClear(renderer);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::Update()
{
	//move camera	

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if (renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool flip)
{
	bool ret = true;
	SDL_Rect rect;

	rect.x = (int)(-(camera.x + camera_offset.x) * speed) + x * SCREEN_SIZE;
	rect.y = (int)(-(camera.y + camera_offset.y) * speed) + y * SCREEN_SIZE;
	


	if (section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}

	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}


	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (flip == true) {

		if (SDL_RenderCopyEx(renderer, texture, section, &rect, NULL, NULL, SDL_FLIP_HORIZONTAL) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}
	}
	else {

		if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}
	}

	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

void ModuleRender::MoveCamera()
{
	if (App->scene_genan->IsEnabled() == true) {

		iPoint player_1 = App->gen->position;
		iPoint player_2 = App->gen2->position;

		if (App->gen->flipPlayer == false) {

			if (((player_1.x + 50) - player_2.x) > 250) {

				spaced = true;

			}
			else {

				spaced = false;
			}
		}
		else {

			if (((player_2.x + 50) - player_1.x) > 250) {

				spaced = true;
			}
			else {

				spaced = false;
			}

		}

		if (!spaced) {
			if ((player_1.x < left->rect.x + left->rect.w)) {
				if (player_2.x + 50 < right->rect.x) {
					right->rect.x -= 2 * SCREEN_SIZE;
					left->rect.x -= 2 * SCREEN_SIZE;
					camera.x += 2 * SCREEN_SIZE;
					

				}
			}
			else if ((player_2.x > right->rect.x - 48)) {
				if (player_1.x > left->rect.x + left->rect.w) {
					right->rect.x += 2 * SCREEN_SIZE;
					left->rect.x += 2 * SCREEN_SIZE;
					camera.x -= 2 * SCREEN_SIZE;
					
				}
			}
			if ((player_2.x < left->rect.x + left->rect.w)) {
				if (player_1.x + 50 < right->rect.x) {
					right->rect.x -= 2 * SCREEN_SIZE;
					left->rect.x -= 2 * SCREEN_SIZE;
					camera.x += 2 * SCREEN_SIZE;
					
				}
			}
			else if ((player_1.x > right->rect.x - 50)) {
				if (player_2.x > left->rect.x + left->rect.w) {
					right->rect.x += 2 * SCREEN_SIZE;
					left->rect.x += 2 * SCREEN_SIZE;
					camera.x -= 2 * SCREEN_SIZE;
					
					
				}
			}

			if (camera.x + SCREEN_WIDTH > App->scene_genan->right_wall->rect.x + 150)
			{
				camera.x--;
				left->rect.x--;
			}
			if (camera.x < App->scene_genan->left_wall->rect.x - 150)
			{
				camera.x++;
				right->rect.x++;
			}


		}
	}
	else if (App->scene_haohmaru->IsEnabled() == true) {


		iPoint player_1 = App->player->position;
		iPoint player_2 = App->player2->position;

		if (camera.x + SCREEN_WIDTH > App->scene_haohmaru->right_wall->rect.x + 150)
		{
			camera.x--;
			left->rect.x--;
		}
		if (camera.x < App->scene_haohmaru->left_wall->rect.x - 150)
		{
			camera.x++;
			right->rect.x++;
		}

		if (App->player->flipPlayer == false) {

			if (((player_1.x + 50) - player_2.x) > 250) {

				spaced = true;

			}
			else {

				spaced = false;
			}
		}
		else {

			if (((player_2.x + 50) - player_1.x) > 250) {

				spaced = true;
			}
			else {

				spaced = false;
			}

		}

		if (!spaced) {

			iPoint player_1 = App->player->position;
			iPoint player_2 = App->player2->position;

			if ((player_1.x < left->rect.x + left->rect.w)) {
				if (player_2.x + 50 < right->rect.x) {
					right->rect.x -= App->player->speed;
					left->rect.x -= App->player->speed;
					camera.x -= App->player->speed * SCREEN_SIZE;
				}
			}
			else if ((player_2.x > right->rect.x - 48)) {
				if (player_1.x > left->rect.x + left->rect.w) {
					right->rect.x += App->player->speed;
					left->rect.x += App->player->speed;
					camera.x += App->player->speed * SCREEN_SIZE;
				}
			}
			if ((player_2.x < left->rect.x + left->rect.w)) {
				if (player_1.x + 50 < right->rect.x) {
					right->rect.x -= App->player->speed;
					left->rect.x -= App->player->speed;
					camera.x -= App->player->speed * SCREEN_SIZE;
				}
			}
			else if ((player_1.x > right->rect.x - 50)) {
				if (player_2.x > left->rect.x + left->rect.w) {
					right->rect.x += App->player->speed;
					left->rect.x += App->player->speed;
					camera.x += App->player->speed * SCREEN_SIZE;
				}
			}
		}

	}
}

void ModuleRender::SetCamera()
{
	if ((!left) && (!right))
	{
		left = App->collision->AddCollider({ -50, 0, 50, SCREEN_HEIGHT }, COLLIDER_WALL);
		right = App->collision->AddCollider({ SCREEN_WIDTH, 0, 50, SCREEN_HEIGHT }, COLLIDER_WALL);
	}
	left->SetPos(-50, 0);
	right->SetPos(SCREEN_WIDTH, 0);
}

void ModuleRender::StartCameraShake(int duration, float magnitude)
{
	shaking = true;
	shake_duration = duration; 
	shake_magnitude = magnitude; 
	shake_timer = 0.0f;
}

void ModuleRender::UpdateCameraShake()
{
	if (shake_timer < shake_duration) {

		camera_offset.x = ((rand() % 2) - 1) * shake_magnitude;
		camera_offset.y = ((rand() % 2) - 1) * shake_magnitude;
		shake_timer++;
	}

}