//
//  sound-maker.hpp
//  sound-maker
//
//  Created by Jayden Kusuma on 04/02/24.
//

#ifndef sound_maker_hpp
#define sound_maker_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_ttf/SDL_ttf.h"

class SoundMaker
{
public:
    static SDL_Renderer* renderer;
    
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;
    
    SoundMaker();
    ~SoundMaker();
    
    void Initialize();
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Status();
    
private:
    bool isRunning;
    SDL_Window* window;
    
    void InitSDL(const char* wT);
};

#endif /* sound_maker_hpp */
