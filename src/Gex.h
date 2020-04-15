#ifndef GEX_H
#define GEX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


class Gex {
private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

public:
	Gex();
	~Gex();

	bool IsRunning() const;

	void Initialize(int width, int height);
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();

};


#endif
