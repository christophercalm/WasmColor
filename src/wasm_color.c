#include <SDL.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include <stdlib.h>


#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 512
#define SQUARE_HEIGHT SCREEN_WIDTH / 8

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Surface *surface;

// int random(int min, int max){
//    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
// }

// void * create_game_grid(Uint8 rows, Uint8 cols) {
//     int grid_size = rows * cols;
//     int *game_grid = malloc(sizeof(int) * grid_size);
//     srand( (unsigned)time( NULL ) );
//     int random_index = random(0, grid_size);
//     game_grid[random_index] = 1;
//     return (game_grid);
// }

// void game_loop() {
//     int rows = 2;
//     int cols = 2;
//     int value_change_colors_factor = 40;
//     int score = 0;
//     int clicked = 0;
//     int level = 0;


// }

void drawRandomPixels() {
    if (SDL_MUSTLOCK(surface)) SDL_LockSurface(surface);

    // Uint8 * pixels = surface->pixels;
    
    // for (int i=0; i < 1048576; i++) {
    //     char randomByte = rand() % 255;
    //     pixels[i] = randomByte;
    // }

    // fill screen with white

    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));


    SDL_Rect rect = {0, 0, 100, 100}; // x, y, width, height
    for (Uint16 i = 0; i < SQUARE_HEIGHT; i++) {
        SDL_Rect rect = {i * SQUARE_HEIGHT, i * SQUARE_HEIGHT, SQUARE_HEIGHT - 1, SQUARE_HEIGHT - 1 }; // x, y, width, height
        SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
    }

    if (SDL_MUSTLOCK(surface)) SDL_UnlockSurface(surface);

    SDL_Texture *screenTexture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(screenTexture);
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SCREEN_HEIGHT, SCREEN_WIDTH, 0, &window, &renderer);
    surface = SDL_CreateRGBSurface(0, SCREEN_HEIGHT, SCREEN_WIDTH, 32, 0, 0, 0, 0);
    
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(drawRandomPixels, 0, 1);
    #else
    while(1) {        
        drawRandomPixels();
        SDL_Delay(16);
    }
    #endif 
}