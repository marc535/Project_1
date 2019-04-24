
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneNeoGeo : public Module
{
public:
	ModuleSceneNeoGeo();
	~ModuleSceneNeoGeo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;

	//Animation backgroundanim;
};

