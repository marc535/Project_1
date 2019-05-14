#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"

struct SDL_Renderer;
struct SDL_Texture;
struct Collider;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status Update();
	update_status PreUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed, bool flip);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);
	void MoveCamera();
	void SetCamera();

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	Collider* left = nullptr;
	Collider* right = nullptr;

};

#endif //__ModuleRenderer_H__