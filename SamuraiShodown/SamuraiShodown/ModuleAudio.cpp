#include "Globals.h"
#include "ModuleAudio.h"

ModuleAudio::ModuleAudio() : Module()
{
	for (int i = 0; i < MAX_SOUNDTRACK; i++)
	{
		songs[i] = nullptr;
	}

	for (int j = 0; j < MAX_EFFECTS; j++)
	{
		fxs[j] = nullptr;
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
	if ((initted) & (flags != flags)) {
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
		if (songs[i] != nullptr) {
			Mix_FreeMusic(songs[i]);
			songs[i] = nullptr;
		}
			
	}

	for (int j = 0; j < MAX_EFFECTS; j++)
	{
		if (fxs[j] != nullptr) {
			Mix_FreeChunk(fxs[j]);
			fxs[j] = nullptr;
		}			
	}


	Mix_Quit();

	return true;
}

Mix_Music* ModuleAudio::LoadMusic(const char* path) {
	Mix_Music* song;
	song = Mix_LoadMUS(path);
	if (!song)
	{
		LOG("Mix_LoadMUS(\"%s\"): %s\n", path, Mix_GetError());
	}
	for (int i = 0; i < MAX_SOUNDTRACK; i++)
	{
		if (songs[i] == nullptr)
		{
			songs[i] = song;
			break;
		}
	}
	return song;
}

Mix_Chunk* ModuleAudio::LoadEffects(const char* path) {
	Mix_Chunk* fx;
	fx = Mix_LoadWAV(path);
	if (!fx)
	{
		LOG("Mix_LoadWAV: %s\n", Mix_GetError());
	}
	for (int i = 0; i < MAX_EFFECTS; i++)
	{
		if (fxs[i] == nullptr)
		{
			fxs[i] = fx;
			break;
		}
	}
	return fx;
}

bool ModuleAudio::PlayMusic(Mix_Music* song, int times) {
	if (times == NULL)
	{
		times = -1;
	}
	if (Mix_FadeInMusic(song, times, 1250) == -1)
	{
		LOG("Mix_PlayMusic: %s\n", Mix_GetError());
		return false;
	}
	return true;
}

bool ModuleAudio::PlayEffects(Mix_Chunk* fx) {
	if (Mix_PlayChannel(-1, fx, 0) == -1)
	{
		LOG("Mix_PlayChannel: %s\n", Mix_GetError());
		return false;
	}
	return true;
}

bool ModuleAudio::UnLoadMusic(Mix_Music * mus)
{
	for (int i = 0; i < MAX_SOUNDTRACK; ++i) {
		if (songs[i] == mus) {
			Mix_FreeMusic(mus);
			songs[i] = nullptr;
			mus = nullptr;
			break;
		}
	}
	return true;
}

bool ModuleAudio::UnLoadEffects(Mix_Chunk * chunk)
{
	for (int i = 0; i < MAX_EFFECTS; ++i) {
		if (fxs[i] == chunk) {
			Mix_FreeChunk(chunk);
			fxs[i] = nullptr;
			chunk = nullptr;
			break;
		}
	}
	return true;
}