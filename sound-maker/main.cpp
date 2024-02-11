#include <stdio.h>
#include "sound-maker.hpp"

SoundMaker* soundMaker = nullptr;

int main(int argc, const char* argv[])
{
    soundMaker = new SoundMaker();
    //Check SDL init status
    soundMaker->Initialize();
    while(soundMaker->Status())
    {
        // Handle Events
        soundMaker->HandleEvents();
        // Main event loop
        soundMaker->Update();
        //Render
        soundMaker->Render();
    }
    // Cleanup
    soundMaker->Clean();

    return 0;
}
