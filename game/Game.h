#ifndef GAME_HEADER_
#define GAME_HEADER_

#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <iostream>

class Game
{
private:
    SDL_Renderer *pGameRenderer = {nullptr};
    SDL_Window *pGameWindow = {nullptr};
    int iWindowWidth, iWindowHeight;

    void tick();
    void handleRendering();
    void handleEvents(SDL_Event *pSdlEvents);

public:
    bool init();
    void run();
    void close();
};

#endif