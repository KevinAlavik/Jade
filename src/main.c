#include "Jade/Jade.h"

int main(int argc, char* argv[]) {
    JadeWindowConfig config = {
        .width = 640,
        .height = 480,
        .x = SDL_WINDOWPOS_UNDEFINED,
        .y = SDL_WINDOWPOS_UNDEFINED,
        .title = "Jade Test"
    };

    JadeWindow* window = JadeSpawnWindow(&config);
    if (window == NULL) {
        printf("Failed to create Jade window.\n");
        return 1;
    }

    JadeSetWindowBackground(window, 0, 0, 0);

    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    free(window->config_ptr);
    free(window);
    SDL_Quit();

    return 0;
}
