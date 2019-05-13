
#include "Globals.h"

#define NUM_MODULES 20

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleParticles;
class ModuleParticles2;
class ModuleSceneWelcome;
class ModuleSceneNeoGeo;
class ModuleSceneCharacterSelection;
class ModuleSceneEnding;
class ModuleSceneHaohmaru;
class ModuleSceneGenAn;
class ModulePlayer;
class ModulePlayer2;
class ModuleAudio;
class ModuleFadeToBlack;
class ModuleCollision;
class Module;
class ModuleUI;
class ModuleGen;
class ModuleFonts;

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
	ModuleSceneGenAn * scene_genan;
	ModuleCollision* collision;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleParticles* particles;
	ModuleParticles2* particles2;
	ModuleAudio* audio;
	ModuleUI* UI;
	ModuleGen* gen;
	ModuleFonts* fonts;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;
