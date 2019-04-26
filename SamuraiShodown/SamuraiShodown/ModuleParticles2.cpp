#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles2.h"
#include "ModulePlayer2.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles2::ModuleParticles2()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles2::~ModuleParticles2()
{}

// Load assets
bool ModuleParticles2::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/Haohmaru.png");

	// Tornado particle
	tornado.anim.PushBack({ 22, 349, 49, 77 });
	tornado.anim.PushBack({ 22, 349, 49, 77 });
	tornado.anim.PushBack({ 75, 349, 41, 77 });
	tornado.anim.PushBack({ 75, 349, 41, 77 });
	tornado.anim.PushBack({ 117, 349, 84, 77 });
	tornado.anim.PushBack({ 202, 348, 93, 78 });
	tornado.anim.PushBack({ 295, 349, 92, 77 });
	tornado.anim.PushBack({ 388, 349, 93, 77 });
	tornado.anim.PushBack({ 482, 349, 93, 77 });
	tornado.anim.PushBack({ 576, 349, 88, 77 });
	tornado.anim.PushBack({ 665, 349, 88, 77 });
	tornado.anim.PushBack({ 754, 349, 81, 77 });
	tornado.anim.PushBack({ 836, 355, 57, 71 });
	tornado.anim.PushBack({ 894, 351, 48, 75 });
	tornado.anim.PushBack({ 943, 351, 49, 75 });
	tornado.anim.PushBack({ 993, 349, 69, 77 });
	tornado.anim.PushBack({ 1062, 349, 63, 77 });
	tornado.anim.PushBack({ 1045, 257, 81, 77 });

	tornado.anim.loop = false;
	tornado.anim.speed = 0.2f;

	tornado.speed.x = 3;
	tornado.life = 6000;
	tornado.anim.First = 2.0f;

	tornadoHit.anim.PushBack({1140, 249, 50, 177});
	tornadoHit.anim.PushBack({ 1191, 248, 61, 176 });
	tornadoHit.anim.PushBack({ 1254, 245, 52, 177 });
	tornadoHit.anim.PushBack({ 1191, 248, 61, 176 });
	tornadoHit.anim.PushBack({ 1254, 245, 52, 177 });

	tornadoHit.anim.loop = true;
	tornadoHit.anim.speed = 0.3f;
	tornadoHit.life = 1125;
	tornadoHit.anim.First = 1.0f;

	return true;
}

// Unload assets
bool ModuleParticles2::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}


update_status ModuleParticles2::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle2* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			if (App->player2->flipPlayer == true) { App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()), 1.0f, true); }
			else { App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()), 1.0f, false); }

			if(p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles2::AddParticle2(const Particle2& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle2* p = new Particle2(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			LOG("TORNADO 2 CREATED");
			active[i] = p;
			break;
		}
	}
}


void ModuleParticles2::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if (active[i] != nullptr && active[i]->collider == c1 && c2->type == COLLIDER_PLAYER)
		{
			AddParticle2(tornadoHit, active[i]->position.x, active[i]->position.y - 100, COLLIDER_NONE);
			if (c1->type == COLLIDER_ENEMY) { LOG("c1 - Colliding with enemy") }
			if (c2->type == COLLIDER_ENEMY) { LOG("c2 - Colliding with enemy") }
			LOG("big TORNADO 2 CREATED");
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------2------------

Particle2::Particle2()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle2::Particle2(const Particle2& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle2::~Particle2()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle2::Update()
{
	bool ret = true;

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	return ret;
}

