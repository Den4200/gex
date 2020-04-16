#include <iostream>

#include "../lib/glm/glm.hpp"
#include "./components/SpriteComponent.h"
#include "./components/TransformComponent.h"
#include "./AssetManager.h"
#include "./Constants.h"
#include "./Gex.h"

EntityManager manager;
AssetManager* Gex::assetManager = new AssetManager(&manager);
SDL_Renderer* Gex::renderer;

Gex::Gex() {
    this->isRunning = false;
}

Gex::~Gex() {}

bool Gex::IsRunning() const {
    return this->isRunning;
}

void Gex::Initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL." << std::endl;
        return;
    }

    window = SDL_CreateWindow(
        "Gex",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        std::cerr << "Error creating SDL window." << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cerr << "Error creating SDL renderer." << std::endl;
        return;
    }

    LoadLevel(0);

    isRunning = true;
    return;
}

void Gex::LoadLevel(int levelNumber) {
    std::string textureFilePath = "./assets/images/tank-big-right.png";
    assetManager->AddTexture("tank-image", textureFilePath.c_str());

    Entity& entityOne(manager.AddEntity("tank"));
    entityOne.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
    entityOne.AddComponent<SpriteComponent>("tank-image");
}

void Gex::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT: {
            isRunning = false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false;
            }
        }
        default: {
            break;
        }
    }
}

void Gex::Update() {
    // Wait until FRAME_TARGET_TIME is reached if PC is too fast
    int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME) {
        SDL_Delay(timeToWait);
    }

    // Delta time for PCs with different speeds
    float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;
    deltaTime = (deltaTime > 0.05) ? 0.05 : deltaTime;

    ticksLastFrame = SDL_GetTicks();


    manager.Update(deltaTime);
}

void Gex::Render() {
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
    SDL_RenderClear(renderer);

    if (manager.HasNoEntities()) {
        return;
    }

    manager.Render();

    SDL_RenderPresent(renderer);
}

void Gex::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
