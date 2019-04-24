#include "Globals.h"
#include "ModuleAudio.h"

ModuleAudio::ModuleAudio() : Module()
{
	for (int i = 0; i < MAX_SOUNDTRACK; i++)
	{
		music[i] = nullptr;
	}

	for (int j = 0; j < MAX_EFFECTS; j++)
	{
		fx[j] = nullptr;
	}
}

// Destructor
ModuleAudio::~ModuleAudio() {};

// Called before render is available
bool ModuleAudio::Init()
{
	LOG("Init Audio library");

	SDL_Init(SDL_INIT_AUDIO);


	int flags = MIX_INIT_OGG | MIX_INIT_MOD;
	int initted = Mix_Init(flags);
	if (initted & flags != flags) {
		//check errors
		LOG("Mix_Init: Failed to init required ogg and mod support!\n");
		LOG("Mix_Init: %s\n", Mix_GetError());
		
	}

	Mix_OpenAudio(48000, AUDIO_U8, 2, 1024);

	Mix_VolumeMusic(MUSIC_VOLUME);
	

	return true;
}


// Called before quitting
bool ModuleAudio::CleanUp()
{

	for (int i = 0; i < MAX_SOUNDTRACK; i++)
	{
		if (music[i] != nullptr) {
			Mix_FreeMusic(music[i]);
			music[i] = nullptr;
		}
			
	}

	for (int j = 0; j < MAX_EFFECTS; j++)
	{
		if (fx[j] != nullptr) {
			Mix_FreeChunk(fx[j]);
			fx[j] = nullptr;
		}			
	}


	Mix_Quit();

	return true;
}