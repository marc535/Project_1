#include "Globals.h"
#include "ModuleAudio.h"

ModuleAudio::ModuleAudio() : Module()
{
	for (int i = 0; i < MAX_SOUNDTRACK; i++)
	{
		music[i] = nullptr;
	}

	for (int p = 0; p < MAX_EFFECTS; p++)
	{
		fx[p] = nullptr;
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

	/*	MIX FORMATS
	AUDIO_U8
	Unsigned 8-bit samples
	AUDIO_S8
	Signed 8-bit samples
	AUDIO_U16LSB
	Unsigned 16-bit samples, in little-endian byte order
	AUDIO_S16LSB
	Signed 16-bit samples, in little-endian byte order
	AUDIO_U16MSB
	Unsigned 16-bit samples, in big-endian byte order
	AUDIO_S16MSB
	Signed 16-bit samples, in big-endian byte order
	AUDIO_U16
	same as AUDIO_U16LSB (for backwards compatability probably)
	AUDIO_S16
	same as AUDIO_S16LSB (for backwards compatability probably)
	AUDIO_U16SYS
	Unsigned 16-bit samples, in system byte order
	AUDIO_S16SYS
	Signed 16-bit samples, in system byte order
	*/


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

	for (int z = 0; z < MAX_EFFECTS; z++)
	{
		if (fx[z] != nullptr) {
			Mix_FreeChunk(fx[z]);
			fx[z] = nullptr;
		}			
	}


	Mix_Quit();

	return true;
}