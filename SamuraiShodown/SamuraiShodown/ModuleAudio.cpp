#include "Globals.h"
#include "ModuleAudio.h"

ModuleAudio::ModuleAudio() : Module()
{
	for (int i = 0; i < MAX_SOUNDTRACK; i++)
	{
		soundtracks[i] = nullptr;
	}

	for (int z = 0; z < MAX_EFFECTS; z++)
	{
		effects[z] = nullptr;
	}
}

// Destructor
ModuleAudio::~ModuleAudio() {};

// Called before render is available
bool ModuleAudio::Init()
{
	LOG("Init Audio library");


	SDL_Init(SDL_INIT_AUDIO);

	// load support for the OGG sample/music formats



	int flags = MIX_INIT_OGG | MIX_INIT_MOD;
	int initted = Mix_Init(flags);
	if (initted & flags != flags) {
		LOG("Mix_Init: Failed to init required ogg and mod support!\n");
		LOG("Mix_Init: %s\n", Mix_GetError());
		// handle error
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
		if (soundtracks[i] != nullptr) {
			Mix_FreeMusic(soundtracks[i]);
			soundtracks[i] = nullptr;
		}

	}

	for (int z = 0; z < MAX_EFFECTS; z++)
	{
		if (effects[z] != nullptr) {
			Mix_FreeChunk(effects[z]);
			effects[z] = nullptr;
		}
	}


	Mix_Quit();

	return true;
}