//
//  main.cpp
//  GGJ-15
//
//  Created by Shaun Ross Mitchell on 21/01/2015.
//  Copyright (c) 2015 shaunmitchell. All rights reserved.
//

#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char * arg[])
{
    // init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "ERROR SDL_Init" << std::endl;
        
        return -1;
    }
    
    bool init = true;
    
    // create a window
    SDL_Window * window = SDL_CreateWindow(
                                           "SDL 2 window",             // window title
                                           SDL_WINDOWPOS_CENTERED,     // x position, centered
                                           SDL_WINDOWPOS_CENTERED,     // y position, centered
                                           640,                        // width, in pixels
                                           480,                        // height, in pixels
                                           SDL_WINDOW_OPENGL      // flags
                                           );
    
    while(init)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        
        if(event.type == SDL_KEYDOWN)
        {
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_DestroyWindow(window);
                SDL_Quit();
                
                init = false;
            }
        }
    }
    
    return 0;
}