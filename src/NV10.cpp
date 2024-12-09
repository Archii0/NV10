#include <SDL2/SDL.h>

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window =
        SDL_CreateWindow("Random Pixel Generator", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError()
                  << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Seed random number generator
    std::srand(std::time(nullptr));

    // Main loop for real-time rendering
    bool running = true;
    SDL_Event event;
    while (running) {
        // Handle events (like window close)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Create a random pixel grid (800x600)
        std::vector<SDL_Color> framebuffer(800 * 600);

        for (int i = 0; i < 800 * 600; ++i) {
            framebuffer[i] = SDL_Color{
                static_cast<Uint8>(std::rand() % 256),  // Red
                static_cast<Uint8>(std::rand() % 256),  // Green
                static_cast<Uint8>(std::rand() % 256),  // Blue
                255                                     // Alpha (opaque)
            };
        }

        // Create a surface to hold the framebuffer
        SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(
            framebuffer.data(), 800, 600, 32, 800 * sizeof(SDL_Color),
            0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);

        if (!surface) {
            std::cerr << "SDL_CreateRGBSurfaceFrom Error: " << SDL_GetError()
                      << std::endl;
            break;
        }

        // Create a texture from the surface (to be rendered by the GPU)
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!texture) {
            std::cerr << "SDL_CreateTextureFromSurface Error: "
                      << SDL_GetError() << std::endl;
            break;
        }

        // Clear the screen
        SDL_RenderClear(renderer);

        // Render the texture (display the framebuffer)
        SDL_RenderCopy(renderer, texture, nullptr, nullptr);

        // Present the rendered content to the screen
        SDL_RenderPresent(renderer);

        // Delay or sync with the display refresh rate (optional)
        SDL_Delay(16);  // ~60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
