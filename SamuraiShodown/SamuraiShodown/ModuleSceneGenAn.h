
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneGenAn : public Module
{
public:
	ModuleSceneGenAn();
	~ModuleSceneGenAn();

	bool Start();
	update_status Update();
	bool CleanUp();

	bool timeUp();

public:
	int winsgen = 0;
	int winsgen2 = 0;
	int p1win = 0;
	int p2win = 0;
	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	
	Collider *left_wall = nullptr;
	Collider *right_wall = nullptr;

	Animation stageAnimation;
};

