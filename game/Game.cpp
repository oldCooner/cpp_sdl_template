#include "Game.h"

bool Game::init()
{
    if( SDL_CreateWindowAndRenderer( "cpp_sdl_template", 0, 0, SDL_WINDOW_FULLSCREEN, &pGameWindow, &pGameRenderer ) )
    {
        if( TTF_Init() )
        {
            SDL_SetRenderDrawColor( pGameRenderer, 0, 0, 0, 255 );

            SDL_SyncWindow( pGameWindow );
            SDL_GetWindowSize( pGameWindow, &iWindowWidth, &iWindowHeight );

            /*
                LOAD ALL TEXTURES HERE
            */
        } else
        {
            std::cerr << "Failed to intialize ttf module! SDL_Error: " << SDL_GetError() << "\n";
            return 0;
        }
    } else
    {
        std::cerr << "Failed to create window and renderer! SDL_Error: " << SDL_GetError() << "\n";
        return 0;
    }

    return 1;
}

void Game::close()
{
    SDL_DestroyRenderer(pGameRenderer);
    SDL_DestroyWindow(pGameWindow);

    pGameRenderer = nullptr;
    pGameWindow = nullptr;

    SDL_Quit();
}

void Game::run()
{
    SDL_Event sdlEvents;
    bool bGameRunning = 1;

    SDL_SetRenderDrawColor( pGameRenderer, 0, 0, 0, 255 );
    SDL_RenderClear(pGameRenderer);
    handleRendering();
    SDL_RenderPresent(pGameRenderer);

    while(bGameRunning)
    {
        while( SDL_PollEvent(&sdlEvents) != 0 )
        {
            if( sdlEvents.type == SDL_EVENT_QUIT )
            {
                bGameRunning = 0;
                break;
            } else
            {
                handleEvents(&sdlEvents);
            }
        }

        if(!bGameRunning)
            break;

        // Main Game Loop
        tick();

        SDL_SetRenderDrawColor( pGameRenderer, 0, 0, 0, 255 );
        SDL_RenderClear(pGameRenderer);
        handleRendering();
        SDL_RenderPresent(pGameRenderer);
    }

}

void Game::handleRendering()
{
    /*
        All Game Rendering can go here
    */
}

void Game::handleEvents(SDL_Event *pSdlEvents)
{
    /*
        EVENT HANDLING HERE
    */
}

void Game::tick()
{
    /*
        NEED TO HAPPEN ONCE PER FRAME? LOOK HERE
    */
}