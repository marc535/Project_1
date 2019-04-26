
#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 100

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle2
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;
	bool flipPlayer = false;

	Particle2();
	Particle2(const Particle2& p);
	~Particle2();
	bool Update();
};

class ModuleParticles2 : public Module
{
private:

	SDL_Texture* graphics = nullptr;
	Particle2* active[MAX_ACTIVE_PARTICLES];

public:

	ModuleParticles2();
	~ModuleParticles2();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle2& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

	Particle2 tornado;
	Particle2 tornadoHit;



};

