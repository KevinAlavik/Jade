#ifndef __JADE_H__
#define __JADE_H__

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int width;
    int height;
    int x;
    int y;
    const char* title;
} JadeWindowConfig;

typedef struct {
    JadeWindowConfig* config_ptr;
    SDL_Window* window_ptr;
    SDL_Renderer* renderer_ptr;
} JadeWindow;

JadeWindow* JadeSpawnWindow(const JadeWindowConfig* config);
void JadeSetWindowBackground(JadeWindow* window, Uint8 r, Uint8 g, Uint8 b);

#endif // __JADE_H__
