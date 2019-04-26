#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Assets/Sprite_Sheets/Characters/Haohmaru/Haohmaru.png");

	// Explosion particle
	tornado.anim.PushBack({22, 400, 49, 26});
	tornado.anim.PushBack({75, 385, 41, 41 });
	tornado.anim.PushBack({117, 349, 84, 77 });
	tornado.anim.PushBack({202, 348, 93, 78});
	tornado.anim.PushBack({295, 356, 92, 70});
	tornado.anim.PushBack({388, 361, 93, 65});
	tornado.anim.PushBack({482, 367, 93, 59 });
	tornado.anim.PushBack({576, 368, 88, 58 });
	tornado.anim.PushBack({665, 368, 88, 65 });
	tornado.anim.PushBack({ 754, 361, 81, 65 });
	tornado.anim.PushBack({ 836, 355, 57, 71 });
	tornado.anim.PushBack({ 894, 351, 48, 75 });
	tornado.anim.PushBack({ 943, 351, 49, 75 });
	tornado.anim.PushBack({ 993, 349, 69, 77 });
	tornado.anim.PushBack({ 1062, 349, 63, 77 });
	tornado.anim.PushBack({ 1045, 257, 81, 77 });

	tornado.anim.loop = false;
	tornado.anim.speed = 0.06f;

	tornado.speed.x = 3;
	tornado.life = 6000;
	tornado.anim.First = 2.0f;

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
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


update_status ModuleParticles::Update()
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()), 1.0f, false);
			if(p->fx_played == false)
			{
				p->fx_played = true;
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if(collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider(p->anim.GetCurrentFrame(), collider_type, this);
			active[i] = p;
			break;
		}
	}
}


void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		// Always destroy particles that collide
		if(active[i] != nullptr && active[i]->collider == c1)
		{
			delete active[i];
			active[i] = nullptr;
			break;
		}
	}
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

Particle::~Particle()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

bool Particle::Update()
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

