
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneHaohmaru : public Module
{
public:
	ModuleSceneHaohmaru();
	~ModuleSceneHaohmaru();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;

	Animation stageAnimation;
};

