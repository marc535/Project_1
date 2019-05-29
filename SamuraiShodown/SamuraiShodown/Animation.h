#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 48


class Animation
{
public:
	bool loop = true;
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];
	float First = 0.0f;

private:
	float current_frame;
	int last_frame = 0;
	int loops = 0;
	bool Finish = false;

public:

	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}

	SDL_Rect& GetCurrentFrame()
	{
		current_frame += speed;
		if (current_frame >= last_frame) {
			current_frame = (loop) ? First : last_frame - 1;
			Finish = true;
			loops++;
		}

		return frames[(int)current_frame];
	}

	bool Finished() const
	{
		return loops > 0;
	}

	void Reset()
	{
		current_frame = 0;
		Finish = false;
	}

	int SeeCurrentFrame() {
		return (int)current_frame;
	}

	bool FinishedAnimation() {
		return Finish;
	}
	void finishingAnimation(bool end) {
		Finish = end;
	}
	SDL_Rect GetCurrentRect() {
		return frames[(int)current_frame];
	}


};

#endif