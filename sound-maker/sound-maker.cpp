//
//  sound-maker.cpp
//  sound-maker
//
//  Created by Jayden Kusuma on 04/02/24.
//

#include "sound-maker.hpp"
#include "SDL2_ttf/SDL_ttf.h"
#include <iostream>

SDL_Renderer* SoundMaker::renderer = nullptr;
TTF_Font* font;


SoundMaker::SoundMaker()
{
    
}

SoundMaker::~SoundMaker()
{
    
}

void SoundMaker::InitSDL(const char* wT)
{
    //Initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    
    // Create Window
    window = SDL_CreateWindow(wT, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return;
    }
    
    // Create Renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    // Initialize SDL_ttf
    if (TTF_Init() != 0)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }
    isRunning = true;
}

void SoundMaker::Initialize()
{
    InitSDL("Sound Maker");
    font = TTF_OpenFont("ComicNeue-Regular.ttf", 128);
}

void SoundMaker::HandleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void SoundMaker::Update()
{
    
}

void SoundMaker::Render()
{
    SDL_RenderClear(renderer);
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Hello world!", {0, 0, 0, 255});
    if(!surface)
    {
        printf("Error creating surface! TTF_Error: %s\n", TTF_GetError());
        isRunning = false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(!texture)
    {
        printf("Error creating texture! TTF_Error: %s\n", TTF_GetError());
        isRunning = false;
    }
    SDL_Rect rect = {0, 0, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}

void SoundMaker::Clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

bool SoundMaker::Status()
{
    return isRunning;
}
