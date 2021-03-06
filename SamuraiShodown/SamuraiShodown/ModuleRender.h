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

	void StartCameraShake(int duration, float magnitude);
	void UpdateCameraShake();

	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera;
	Collider* left = nullptr;
	Collider* right = nullptr;

	bool spaced = false;
	
	bool shaking = false;

	float shake_duration = 1.0f;
	float shake_timer = 0.0f;
	float shake_magnitude = 1.0f;

	SDL_Point camera_offset;

};

#endif //__ModuleRenderer_H__