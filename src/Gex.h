#ifndef GEX_H
#define GEX_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "./Component.h"
#include "./Entity.h"
#include "./EntityManager.h"

class Gex {
private:
    bool isRunning;
    SDL_Window *window;

public:
    Gex();
    ~Gex();

    int ticksLastFrame;

    static SDL_Renderer *renderer;

    void LoadLevel(int levelNumber);

    bool IsRunning() const;
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();
    void Destroy();

};


#endif
