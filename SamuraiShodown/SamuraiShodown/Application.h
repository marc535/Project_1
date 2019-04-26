
#include "Globals.h"

#define NUM_MODULES 15

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleSceneWelcome;
class ModuleSceneNeoGeo;
class ModuleSceneCharacterSelection;
class ModuleSceneEnding;
class ModuleSceneHaohmaru;
class ModulePlayer;
class ModulePlayer2;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleCollision;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleSceneWelcome* scene_welcome;
	ModuleSceneNeoGeo* scene_neogeo;
	ModuleSceneCharacterSelection* scene_charSelect;
	ModuleSceneEnding* scene_ending;
	ModuleSceneHaohmaru * scene_haohmaru;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleAudio* audio;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;
