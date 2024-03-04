#include "Jade.h"

JadeWindow* JadeSpawnWindow(const JadeWindowConfig* config) {
    JadeWindow* window = (JadeWindow*)malloc(sizeof(JadeWindow));
    if (window == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    window->config_ptr = (JadeWindowConfig*)malloc(sizeof(JadeWindowConfig));
    if (window->config_ptr == NULL) {
        printf("Memory allocation failed.\n");
        free(window);
        return NULL;
    }
    *(window->config_ptr) = *config;

    window->window_ptr = SDL_CreateWindow(config->title, config->x, config->y, config->width, config->height, SDL_WINDOW_OPENGL);
    if (window->window_ptr == NULL) {
        printf("Unable to create window: %s\n", SDL_GetError());
        free(window->config_ptr);
        free(window);
        return NULL;
    }

    window->renderer_ptr = SDL_CreateRenderer(window->window_ptr, -1, SDL_RENDERER_ACCELERATED);
    if (window->renderer_ptr == NULL) {
        printf("Unable to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window->window_ptr);
        free(window->config_ptr);
        free(window);
        return NULL;
    }

    return window;
}

void JadeSetWindowBackground(JadeWindow* window, Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(window->renderer_ptr, r, g, b, 255);
    SDL_RenderClear(window->renderer_ptr);
    SDL_RenderPresent(window->renderer_ptr);
}
